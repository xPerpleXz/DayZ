<#
.SYNOPSIS
    Automatisiert die Portfreigabe für einen DayZ-Server und eine Website auf Windows Server 2025 inklusive Portweiterleitung in einer Fritz!Box 7520.

.PARAMETER ServerIP
    Die lokale IPv4-Adresse des Servers.

.PARAMETER FritzBoxUser
    Benutzername für die Fritz!Box (mit Rechten zur Konfiguration).

.PARAMETER FritzBoxPassword
    Passwort des Benutzers.

.EXAMPLE
    .\Setup-DayZFirewallAndFritzBox.ps1 -ServerIP "192.168.178.100" -FritzBoxUser "admin" -FritzBoxPassword "Passwort123"
#>

param (
    [Parameter(Mandatory=$true)][string]$ServerIP,
    [Parameter(Mandatory=$true)][string]$FritzBoxUser,
    [Parameter(Mandatory=$true)][string]$FritzBoxPassword
)

### Abschnitt 1: Lokale Windows-Firewallregeln hinzufügen ###
Write-Host "Konfiguriere Windows-Firewallregeln..." -ForegroundColor Cyan

$dayzPorts = @(
    @{Name="DayZ_GamePort_2302";    Port=2302;    Protocol="UDP"},
    @{Name="DayZ_SteamQuery_2303";  Port=2303;    Protocol="UDP"},
    @{Name="DayZ_GamePort2_2304";   Port=2304;    Protocol="UDP"},
    @{Name="DayZ_GamePort3_2305";   Port=2305;    Protocol="UDP"},
    @{Name="DayZ_SteamMaster_27016";Port=27016;   Protocol="UDP"},
    @{Name="DayZ_BattlEye_2344";    Port=2344;    Protocol="UDP"},
    @{Name="DayZ_CFTools_2345";     Port=2345;    Protocol="TCP"}
)

$webPorts = @(
    @{Name="Web_HTTP_80";           Port=80;      Protocol="TCP"},
    @{Name="Web_HTTPS_443";         Port=443;     Protocol="TCP"}
)

$allPorts = $dayzPorts + $webPorts

foreach ($port in $allPorts) {
    New-NetFirewallRule -DisplayName $port.Name `
        -Direction Inbound `
        -Protocol $port.Protocol `
        -LocalPort $port.Port `
        -Action Allow `
        -Profile Any `
        -Enabled True -ErrorAction SilentlyContinue
}

### Abschnitt 2: Portfreigaben in der Fritz!Box einrichten ###
Write-Host "Authentifiziere bei der Fritz!Box..." -ForegroundColor Cyan

# TR-064 Zugriff aufbauen
function Get-FritzBoxSessionID {
    $loginURL = "http://fritz.box/login_sid.lua"
    $xml = Invoke-WebRequest -Uri $loginURL -UseBasicParsing | Select-Object -ExpandProperty Content | [xml]

    if ($xml.SessionInfo.SID -ne "0000000000000000") {
        return $xml.SessionInfo.SID
    }

    $challenge = $xml.SessionInfo.Challenge
    $response = "$challenge-$($challenge + $FritzBoxPassword | [System.Text.Encoding]::Unicode.GetBytes | % { $_.ToString("x2") } -join '')"
    
    $loginPost = Invoke-WebRequest -Uri "$loginURL?username=$FritzBoxUser&response=$response" -UseBasicParsing | Select-Object -ExpandProperty Content | [xml]
    
    if ($loginPost.SessionInfo.SID -eq "0000000000000000") {
        throw "Fehlerhafte Anmeldung an der Fritz!Box – prüfen Sie Benutzername und Passwort."
    }

    return $loginPost.SessionInfo.SID
}

# Ports in Fritz!Box über TR-064 API öffnen
function Add-FritzBoxPortForwarding {
    param (
        [string]$SID,
        [string]$Port,
        [string]$Protocol,
        [string]$Description
    )

    $upnpUrl = "http://fritz.box:49000/upnp/control/wanpppconn1"
    $soapBody = @"
<?xml version="1.0"?>
<SOAP-ENV:Envelope xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/" 
                   SOAP-ENV:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/">
  <SOAP-ENV:Body>
    <u:AddPortMapping xmlns:u="urn:schemas-upnp-org:service:WANPPPConnection:1">
      <NewRemoteHost></NewRemoteHost>
      <NewExternalPort>$Port</NewExternalPort>
      <NewProtocol>$Protocol</NewProtocol>
      <NewInternalPort>$Port</NewInternalPort>
      <NewInternalClient>$ServerIP</NewInternalClient>
      <NewEnabled>1</NewEnabled>
      <NewPortMappingDescription>$Description</NewPortMappingDescription>
      <NewLeaseDuration>0</NewLeaseDuration>
    </u:AddPortMapping>
  </SOAP-ENV:Body>
</SOAP-ENV:Envelope>
"@

    Invoke-WebRequest -Uri $upnpUrl `
        -Method POST `
        -Headers @{"SOAPACTION" = '"urn:schemas-upnp-org:service:WANPPPConnection:1#AddPortMapping"'} `
        -ContentType "text/xml; charset=""utf-8""" `
        -Body $soapBody `
        -ErrorAction Stop | Out-Null
}

try {
    $sessionID = Get-FritzBoxSessionID

    foreach ($entry in $allPorts) {
        $proto = $entry.Protocol
        $desc = $entry.Name
        $port = $entry.Port

        Write-Host "Richte Portweiterleitung ein: $port/$proto ($desc)" -ForegroundColor Yellow
        Add-FritzBoxPortForwarding -SID $sessionID -Port $port -Protocol $proto -Description $desc
    }

    Write-Host "Alle Portweiterleitungen erfolgreich eingerichtet." -ForegroundColor Green
}
catch {
    Write-Error "Ein Fehler ist aufgetreten: $_"
}

