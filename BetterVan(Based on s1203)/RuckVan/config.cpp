class CfgPatches
{
	class dbo_s1203
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Scripts",
			"DZ_Data",
			"DZ_Gear_Containers",
			"DZ_Sounds_Effects",
			"DZ_Vehicles_Wheeled",
			"DZ_Vehicles_Parts"
		};
	};
};
class CfgMods
{
	class dbo_s1203
	{
		dir="dbo_s1203";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="dbo_s1203";
		credits="DeanosBeano";
		author="DeanosBeano";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"dbo/vehicles/dbo_s1203/scripts/4_world"
				};
			};
		};
	};
};
class CfgSlots
{
	class Slot_s1203_wheel_1_1
	{
		name="s1203_wheel_1_1";
		displayName="Front Left wheel";
		selection="wheel_1_1";
		ghostIcon="";
	};
	class Slot_s1203_wheel_1_2
	{
		name="s1203_wheel_1_2";
		displayName="Rear Left wheel";
		selection="wheel_1_2";
		ghostIcon="";
	};
	class Slot_s1203_wheel_2_1
	{
		name="s1203_wheel_2_1";
		displayName="Front Right wheel";
		selection="wheel_2_1";
		ghostIcon="";
	};
	class Slot_s1203_wheel_2_2
	{
		name="s1203_wheel_2_2";
		displayName="Rear Right wheel";
		selection="wheel_2_2";
		ghostIcon="";
	};
	class Slot_s1203_door_1_1
	{
		name="s1203_door_1_1";
		displayName="Drivers Door";
		selection="Doors_driver";
		ghostIcon="doorfront";
	};
	class Slot_s1203_door_1_2
	{
		name="s1203_door_1_2";
		displayName="Passenger Door";
		selection="Doors_codriver";
		ghostIcon="doorfront";
	};
	class Slot_s1203_door_2_1
	{
		name="s1203_door_2_1";
		displayName="middle Door";
		selection="Doors_Cargo2";
		ghostIcon="doorfront";
	};
	class Slot_s1203_door_3_1
	{
		name="s1203_door_3_1";
		displayName="Rear Door";
		selection="Doors_trunk";
		ghostIcon="trunk";
	};
	class Slot_sea_chest
	{
		name="sea_chest";
		displayName="S1203 sea_chest";
		selection="sea_chest";
		ghostIcon="cat_common_cargo";
	};
	class Slot_CanisterGasoline
	{
		name="CanisterGasoline";
		displayName="CanisterGasoline";
		selection="CanisterGasoline";
		ghostIcon="gascanister";
	};
	class Slot_55galDrum_1
	{
		name="55galDrum_1";
		displayName="s1203 55galDrum_1";
		selection="55galDrum_1";
		ghostIcon="";
	};
	class Slot_55galDrum_2
	{
		name="55galDrum_2";
		displayName="s1203 55galDrum_2";
		selection="55galDrum_2";
		ghostIcon="";
	};
};
class cfgvehicles
{
	class Bottle_Base;
	class CanisterGasoline: Bottle_Base
	{
		inventorySlot="CanisterGasoline";
	};
	class Container_Base;
	class SeaChest: Container_Base
	{
		inventorySlot[]=
		{
			"sea_chest"
		};
	};
	class Barrel_ColorBase: Container_Base
	{
		inventorySlot[]=
		{
			"55galDrum_1",
			"55galDrum_2"
		};
	};
	class CarWheel;
	class s1203_wheel: CarWheel
	{
		scope=2;
		displayName="s1203 wheel";
		model="dbo\vehicles\dbo_s1203\proxy\s1203_wheel.p3d";
		weight=20000;
		itemSize[]={6,6};
		inventorySlot[]=
		{
			"s1203_wheel_1_1",
			"s1203_wheel_1_2",
			"s1203_wheel_2_1",
			"s1203_wheel_2_2"
		};
		rotationFlags=4;
		physLayer="item_large";
		radiusByDamage[]={0,0.361,0.30000001,0.2,0.99980003,0.15000001,0.99989998,0.1};
		radius=0.361;
		width=0.2;
		tyreRollResistance=0.015;
		tyreTread=0.80000001;
		tyre="TYRE_DEFAULT";
	};
	class s1203_wheel_destroyed: CarWheel
	{
		scope=2;
		displayName="s1203 wheel Damaged";
		model="dbo\vehicles\dbo_s1203\proxy\s1203_wheel_destroyed.p3d";
		weight=10000;
		inventorySlot[]=
		{
			"s1203_wheel_1_1",
			"s1203_wheel_1_2",
			"s1203_wheel_2_1",
			"s1203_wheel_2_2"
		};
		rotationFlags=4;
		radius=0.2;
		width=0.17;
		tyreRollResistance=1;
		tyreRollDrag=70;
		tyreRoughness=1;
		tyreTread=0.5;
	};
	class HatchbackDoors_Driver;
	class s1203_door_1_1: HatchbackDoors_Driver
	{
		scope=2;
		displayName="Doors_Driver";
		descriptionShort="Doors_Driver";
		Model="dbo\vehicles\dbo_s1203\proxy\s1203_door_1_1.p3d";
		weight=15000;
		itemSize[]={10,10};
		itemBehaviour=0;
		inventorySlot="s1203_door_1_1";
		rotationFlags=8;
		physLayer="item_large";
	};
	class s1203_door_1_2: HatchbackDoors_Driver
	{
		scope=2;
		displayName="Doors_CoDriver";
		descriptionShort="Doors_CoDriver";
		Model="dbo\vehicles\dbo_s1203\proxy\s1203_door_1_2.p3d";
		weight=15000;
		itemSize[]={10,10};
		itemBehaviour=0;
		inventorySlot="s1203_door_1_2";
		rotationFlags=8;
		physLayer="item_large";
	};
	class s1203_door_2_1: HatchbackDoors_Driver
	{
		scope=2;
		displayName="Doors_Middle";
		descriptionShort="Sliding George";
		Model="dbo\vehicles\dbo_s1203\proxy\s1203_door_2_1.p3d";
		weight=15000;
		itemSize[]={10,10};
		itemBehaviour=0;
		inventorySlot="s1203_door_2_1";
		rotationFlags=8;
		physLayer="item_large";
	};
	class s1203A_door_1_1: HatchbackDoors_Driver
	{
		scope=2;
		displayName="Doors_Driver";
		descriptionShort="Doors_Driver";
		Model="dbo\vehicles\dbo_s1203\proxy\s1203A_door_1_1.p3d";
		weight=15000;
		itemSize[]={10,10};
		itemBehaviour=0;
		inventorySlot="s1203_door_1_1";
		rotationFlags=8;
		physLayer="item_large";
	};
	class s1203A_door_1_2: HatchbackDoors_Driver
	{
		scope=2;
		displayName="Doors_CoDriver";
		descriptionShort="Doors_CoDriver";
		Model="dbo\vehicles\dbo_s1203\proxy\s1203A_door_1_2.p3d";
		weight=15000;
		itemSize[]={10,10};
		itemBehaviour=0;
		inventorySlot="s1203_door_1_2";
		rotationFlags=8;
		physLayer="item_large";
	};
	class s1203A_door_2_1: HatchbackDoors_Driver
	{
		scope=2;
		displayName="Doors_Middle";
		descriptionShort="Sliding George";
		Model="dbo\vehicles\dbo_s1203\proxy\s1203A_door_2_1.p3d";
		weight=15000;
		itemSize[]={10,10};
		itemBehaviour=0;
		inventorySlot="s1203_door_2_1";
		rotationFlags=8;
		physLayer="item_large";
	};
	class HatchbackTrunk;
	class s1203A_door_3_1: HatchbackTrunk
	{
		scope=2;
		displayName="Rear Door";
		descriptionShort="s1203A Rear Door";
		Model="dbo\vehicles\dbo_s1203\proxy\s1203A_door_3_1.p3d";
		weight=15000;
		inventorySlot[]=
		{
			"s1203_door_3_1"
		};
		rotationFlags=1;
	};
	class s1203_door_3_1: HatchbackTrunk
	{
		scope=2;
		displayName="Rear Door";
		descriptionShort="S1203 Rear Door";
		Model="dbo\vehicles\dbo_s1203\proxy\s1203_door_3_1.p3d";
		weight=15000;
		inventorySlot[]=
		{
			"s1203_door_3_1"
		};
		rotationFlags=1;
	};
	class carscript;
	class s1203_base: carscript
	{
		scope=0;
		displayname="dbo base";
		Model="";
		InteractActions[]=
		{
			"AT_ANIMATE_SEATS",
			"AT_GETIN_TRANSPORT"
		};
		attachments[]=
		{
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug",
			"s1203_door_1_1",
			"s1203_door_1_2",
			"s1203_door_2_1",
			"s1203_door_3_1",
			"s1203_wheel_1_1",
			"s1203_wheel_1_2",
			"s1203_wheel_2_1",
			"s1203_wheel_2_2"
		};
		class Crew
		{
			class Driver
			{
				actionSel="seat_driver";
				proxyPos="crewDriver";
				getInPos="pos_driver";
				getInDir="pos_driver_dir";
				isDriver=1;
			};
			class CoDriver
			{
				isDriver=0;
				actionSel="seat_codriver";
				proxyPos="crewCoDriver";
				getInPos="pos_codriver";
				getInDir="pos_codriver_dir";
			};
			class Cargo1
			{
				actionSel="seat_cargo1";
				proxyPos="crewCargo1";
				getInPos="pos cargo 3";
				getInDir="pos cargo dir 3";
			};
			class Cargo2
			{
				actionSel="seat_cargo2";
				proxyPos="crewCargo2";
				getInPos="pos cargo 3";
				getInDir="pos cargo dir 3";
			};
			class Cargo3
			{
				actionSel="seat_cargo3";
				proxyPos="crewCargo3";
				getInPos="pos cargo 3";
				getInDir="pos cargo dir 3";
			};
		};
		class Cargo
		{
			itemsCargoSize[]={7,10};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
		class AnimationSources
		{
			class DoorsDriver
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
			class DoorsCoDriver: DoorsDriver
			{
			};
			class DoorsHood: DoorsDriver
			{
			};
			class DoorsTrunk: DoorsDriver
			{
			};
			class HideDestroyed_1_1
			{
				source="user";
				initPhase=0;
				animPeriod=0.001;
			};
			class HideDestroyed_1_2
			{
				source="user";
				initPhase=0;
				animPeriod=0.001;
			};
			class HideDestroyed_2_1
			{
				source="user";
				initPhase=0;
				animPeriod=0.001;
			};
			class HideDestroyed_2_2
			{
				source="user";
				initPhase=0;
				animPeriod=0.001;
			};
			class AnimHitWheel_1_1
			{
				source="Hit";
				hitpoint="HitWheel_1_1";
				raw=1;
			};
			class AnimHitWheel_1_2: AnimHitWheel_1_1
			{
				hitpoint="HitWheel_1_2";
			};
			class AnimHitWheel_2_1: AnimHitWheel_1_1
			{
				hitpoint="HitWheel_2_1";
			};
			class AnimHitWheel_2_2: AnimHitWheel_1_1
			{
				hitpoint="HitWheel_2_2";
			};
			class HitDoorsHood: AnimHitWheel_1_1
			{
				hitpoint="HitDoorsHood";
			};
			class HitDoorsTrunk: AnimHitWheel_1_1
			{
				hitpoint="HitDoorsTrunk";
			};
			class HitDoorsDrivers: AnimHitWheel_1_1
			{
				hitpoint="HitDoorsDriver";
			};
			class HitDoorsCoDrivers: AnimHitWheel_1_1
			{
				hitpoint="HitDoorsCoDriver";
			};
			class HitDoorsCargo: AnimHitWheel_1_1
			{
				hitpoint="HitDoorsCargo";
			};
			class SeatDriver
			{
				source="user";
				initPhase=0;
				animPeriod=0.80000001;
			};
			class SeatCoDriver
			{
				source="user";
				initPhase=0;
				animPeriod=0.80000001;
			};
			class DoorsCargo1
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
			class DoorsCargo2
			{
				source="user";
				initPhase=0;
				animPeriod=0.5;
			};
			class damper_1_1
			{
				source="user";
				initPhase=0.5;
				animPeriod=1;
			};
			class damper_2_1: damper_1_1
			{
			};
			class damper_1_2: damper_1_1
			{
			};
			class damper_2_2: damper_1_2
			{
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name="$STR_attachment_Engine0";
				description="";
				icon="cat_vehicle_engine";
				attachmentSlots[]=
				{
					"CarBattery",
					"CarRadiator",
					"SparkPlug",
					"Reflector_1_1",
					"Reflector_2_1"
				};
			};
			class Body
			{
				name="$STR_attachment_Body0";
				description="";
				icon="cat_vehicle_body";
				attachmentSlots[]=
				{
					"s1203_door_1_1",
					"s1203_door_1_2",
					"s1203_door_2_1",
					"s1203_door_3_1"
				};
			};
			class Chassis
			{
				name="$STR_attachment_Chassis0";
				description="";
				icon="cat_vehicle_chassis";
				attachmentSlots[]=
				{
					"s1203_wheel_1_1",
					"s1203_wheel_1_2",
					"s1203_wheel_2_1",
					"s1203_wheel_2_2"
				};
			};
			class Storage
			{
				name="Storage";
				description="";
				icon="trunk";
				attachmentSlots[]=
				{
					"55galDrum_1",
					"55galDrum_2",
					"CanisterGasoline",
					"sea_chest"
				};
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1000;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
			class DamageZones
			{
				class Chassis
				{
					class Health
					{
						hitpoints=3000;
						transferToGlobalCoef=1;
					};
					componentNames[]=
					{
						"dmgZone_chassis"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]={};
				};
				class Front
				{
					class Health
					{
						hitpoints=1500;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								{}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								{}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								{}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Radiator",
						"Fender_1_1",
						"Fender_2_1",
						"Engine",
						"Reflector_1_1",
						"Reflector_2_1",
						"WindowFront"
					};
					transferToZonesThreshold[]={0.5,0.80000001,0.80000001,0.5,1,1,0.1};
					transferToZonesCoefs[]={0.80000001,0.60000002,0.60000002,0.60000002,0.050000001,0.050000001,0.69999999};
					memoryPoints[]=
					{
						"dmgZone_front"
					};
					componentNames[]=
					{
						"dmgZone_front"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]={};
				};
				class Radiator
				{
					class Health
					{
						hitpoints=100000;
						transferToGlobalCoef=0;
					};
					memoryPoints[]={};
					componentNames[]={};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"CarRadiator"
					};
				};
				class DoorsDriver
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					memoryPoints[]=
					{
						"dmgZone_doorsDriver"
					};
					componentNames[]={};
					fatalInjuryCoef=-1;
					inventorySlots[]={};
				};
				class DoorsCoDriver
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					memoryPoints[]=
					{
						"dmgZone_doorsCoDriver"
					};
					componentNames[]={};
					fatalInjuryCoef=-1;
					inventorySlots[]={};
				};
				class Back
				{
					class Health
					{
						hitpoints=1500;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								{}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								{}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								{}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Fender_1_2",
						"Fender_2_2",
						"WindowLR",
						"WindowRR"
					};
					transferToZonesCoefs[]={0.30000001,0.30000001,0.2,0.2};
					memoryPoints[]=
					{
						"dmgZone_back"
					};
					componentNames[]=
					{
						"dmgZone_back"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]={};
				};
				class Roof
				{
					class Health
					{
						hitpoints=700;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								{}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								{}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								{}
							}
						};
					};
					memoryPoints[]=
					{
						"dmgZone_roof"
					};
					componentNames[]=
					{
						"dmgZone_roof"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]={};
				};
				class Fender_1_1
				{
					class Health
					{
						hitpoints=1200;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								{}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								{}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								{}
							}
						};
					};
					transferToZonesNames[]=
					{
						"Front",
						"Engine",
						"Reflector_1_1",
						"CarRadiator",
						"WindowFront"
					};
					transferToZonesThreshold[]={0.2,0.89999998,0.89999998,0.2,0.5};
					transferToZonesCoefs[]={0.30000001,0.30000001,0.60000002,0.5,0.40000001};
					memoryPoints[]=
					{
						"dmgZone_fender_1_1"
					};
					componentNames[]=
					{
						"dmgZone_fender_1_1"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"atv_wheel_1_1"
					};
				};
				class Fender_1_2: Fender_1_1
				{
					transferToZonesNames[]=
					{
						"Back",
						"FuelTank",
						"WindowLR"
					};
					transferToZonesThreshold[]={0.2,0.2,0.2};
					transferToZonesCoefs[]={0.30000001,0.2,0.69999999};
					memoryPoints[]=
					{
						"dmgZone_fender_1_2"
					};
					componentNames[]=
					{
						"dmgZone_fender_1_2"
					};
					inventorySlots[]=
					{
						"atv_wheel_1_2"
					};
				};
				class Fender_2_1: Fender_1_1
				{
					transferToZonesNames[]=
					{
						"Front",
						"Engine",
						"Reflector_1_1",
						"CarRadiator",
						"WindowFront",
						"Battery"
					};
					transferToZonesThreshold[]={0.2,0.89999998,0.89999998,0.2,0.5,0.5};
					transferToZonesCoefs[]={0.30000001,0.30000001,0.60000002,0.5,0.40000001,0.69999999};
					memoryPoints[]=
					{
						"dmgZone_fender_2_1"
					};
					componentNames[]=
					{
						"dmgZone_fender_2_1"
					};
					inventorySlots[]=
					{
						"atv_wheel_2_1"
					};
				};
				class Fender_2_2: Fender_1_1
				{
					transferToZonesNames[]=
					{
						"Back",
						"FuelTank",
						"WindowRR"
					};
					transferToZonesThreshold[]={0.2,0.2,0.2};
					transferToZonesCoefs[]={0.30000001,0.2,0.69999999};
					memoryPoints[]=
					{
						"dmgZone_fender_2_2"
					};
					componentNames[]=
					{
						"dmgZone_fender_2_2"
					};
					inventorySlots[]=
					{
						"atv_wheel_2_2"
					};
				};
				class WindowFront
				{
					class Health
					{
						hitpoints=50;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								{}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\data\glass_i_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								{}
							}
						};
					};
					memoryPoints[]=
					{
						"dmgZone_windowFront"
					};
					componentNames[]=
					{
						"dmgZone_windowFront"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]={};
				};
				class WindowLR
				{
					class Health
					{
						hitpoints=50;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								{}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\data\auta_skla_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								
								{
									""
								}
							}
						};
					};
					memoryPoints[]=
					{
						"dmgZone_windowLeft"
					};
					componentNames[]=
					{
						"dmgZone_windowLeft"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]={};
				};
				class WindowRR: WindowLR
				{
					memoryPoints[]=
					{
						"dmgZone_windowRight"
					};
					componentNames[]=
					{
						"dmgZone_windowRight"
					};
				};
				class Engine
				{
					class Health
					{
						hitpoints=1000;
						transferToGlobalCoef=1;
						healthLevels[]=
						{
							
							{
								1,
								{}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								{}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								{}
							}
						};
					};
					memoryPoints[]=
					{
						"dmgZone_engine"
					};
					componentNames[]=
					{
						"dmgZone_engine"
					};
					fatalInjuryCoef=0.001;
					inventorySlots[]=
					{
						"CarBattery",
						"SparkPlug",
						"EngineBelt",
						"CarRadiator"
					};
				};
				class FuelTank
				{
					class Health
					{
						hitpoints=600;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								{}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								{}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								{}
							}
						};
					};
					componentNames[]=
					{
						"dmgZone_fuelTank"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]={};
				};
				class Reflector_1_1
				{
					class Health
					{
						hitpoints=50;
						transferToGlobalCoef=0;
						healthLevels[]=
						{
							
							{
								1,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\headlights_glass.rvmat"
								}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								
								{
									"dz\vehicles\wheeled\offroadhatchback\data\glass_i_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								
								{
									"dz\vehicles\wheeled\data\glass_i_destruct.rvmat"
								}
							}
						};
					};
					memoryPoints[]=
					{
						"dmgZone_lights_1_1"
					};
					componentNames[]=
					{
						"dmgZone_lights_1_1"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Reflector_1_1"
					};
				};
				class Reflector_2_1: Reflector_1_1
				{
					memoryPoints[]=
					{
						"dmgZone_lights_2_1"
					};
					componentNames[]=
					{
						"dmgZone_lights_2_1"
					};
					inventorySlots[]=
					{
						"Reflector_2_1"
					};
				};
			};
		};
		class ObstacleGenerator
		{
			carve=1;
			timeToStationary=5;
			moveThreshold=0.5;
			class Shapes
			{
				class Cylindric
				{
					class Cyl1
					{
						radius=1;
						height=1.5;
						center[]={0,0,0.69999999};
					};
					class Cyl3
					{
						radius=1;
						height=1.5;
						center[]={0,0,-0.69999999};
					};
				};
			};
		};
		class SimulationModule
		{
			drive="DRIVE_AWD";
			airDragCoefficient=0.995;
			braking[]={0,0.1,1,0.80000001,2.5,0.89999998,3,1};
			class Steering
			{
				increaseSpeed[]={0,45,60,23,100,12};
				decreaseSpeed[]={0,80,60,40,90,20};
				centeringSpeed[]={0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime=1;
				defaultThrust=0.85000002;
				gentleThrust=0.69999999;
				turboCoef=4;
				gentleCoef=0.75;
			};
			class Engine
			{
				inertia=0.15000001;
				torqueMax=114;
				torqueRpm=3400;
				powerMax=53.700001;
				powerRpm=5400;
				rpmIdle=850;
				rpmMin=900;
				rpmClutch=1350;
				rpmRedline=6000;
				rpmMax=8000;
			};
			class Gearbox
			{
				reverse=3.526;
				ratios[]={3.6670001,2.0999999,1.3609999,1};
				timeToUncoupleClutch=0.30000001;
				timeToCoupleClutch=0.44999999;
				maxClutchTorque=260;
			};
			class Axles
			{
				class Front
				{
					maxSteeringAngle=30;
					finalRatio=4.0999999;
					brakeBias=0.60000002;
					brakeForce=4000;
					wheelHubMass=5;
					wheelHubRadius=0.15000001;
					class Suspension
					{
						swayBar=1700;
						stiffness=40000;
						compression=2100;
						damping=7500;
						travelMaxUp=0.088200003;
						travelMaxDown=0.083300002;
					};
					class Wheels
					{
						class Left
						{
							animTurn="turnfrontleft";
							animRotation="wheelfrontleft";
							wheelHub="wheel_1_1_damper_land";
							animDamper="damper_1_1";
							inventorySlot="s1203_wheel_1_1";
						};
						class Right
						{
							animTurn="turnfrontright";
							animRotation="wheelfrontright";
							wheelHub="wheel_2_1_damper_land";
							animDamper="damper_2_1";
							inventorySlot="s1203_wheel_2_1";
						};
					};
				};
				class Rear
				{
					maxSteeringAngle=0;
					finalRatio=4.0999999;
					brakeBias=0.40000001;
					brakeForce=3800;
					wheelHubMass=5;
					wheelHubRadius=0.15000001;
					class Suspension
					{
						swayBar=1800;
						stiffness=40000;
						compression=2200;
						damping=7600;
						travelMaxUp=0.1587;
						travelMaxDown=0.1059;
					};
					class Wheels
					{
						class Left
						{
							animTurn="turnbackleft";
							animRotation="wheelbackleft";
							wheelHub="wheel_1_2_damper_land";
							animDamper="damper_1_2";
							inventorySlot="s1203_wheel_1_2";
						};
						class Right
						{
							animTurn="turnbacktright";
							animRotation="wheelbackright";
							wheelHub="wheel_2_2_damper_land";
							animDamper="damper_2_2";
							inventorySlot="s1203_wheel_2_2";
						};
					};
				};
			};
		};
		engineVitalParts[]=
		{
			"SparkPlug",
			"CarBattery"
		};
		dashboardMatOn="dbo\vehicles\dbo_s1203\data\s1203_lights_e.rvmat";
		dashboardMatOff="dbo\vehicles\dbo_s1203\data\s1203_mat.rvmat";
		brakeReflectorMatOn="dbo\vehicles\dbo_s1203\data\brake_lights_e.rvmat";
		brakeReflectorMatOff="dbo\vehicles\dbo_s1203\data\s1203_mat.rvmat";
		frontReflectorMatOn="dbo\vehicles\dbo_s1203\data\s1203_lights.rvmat";
		frontReflectorMatOff="dbo\vehicles\dbo_s1203\data\s1203_mat.rvmat";
		ReverseReflectorMatOn="dbo\vehicles\dbo_s1203\data\s1203_lights.rvmat";
		ReverseReflectorMatOff="dbo\vehicles\dbo_s1203\data\s1203_mat.rvmat";
		TailReflectorMatOn="dbo\vehicles\dbo_s1203\data\brake_lights_e.rvmat";
		TailReflectorMatOff="dbo\vehicles\dbo_s1203\data\s1203_mat.rvmat";
		hiddenSelections[]=
		{
			"light_1_1",
			"light_2_1",
			"light_brake_1_2",
			"light_brake_2_2",
			"light_reverse_1_2",
			"light_reverse_2_2",
			"light_1_2",
			"light_2_2",
			"light_dashboard"
		};
		hiddenSelectionsTextures[]=
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			""
		};
		hiddenSelectionsMaterials[]=
		{
			"dbo\vehicles\dbo_s1203\data\s1203_lights.rvmat",
			"dbo\vehicles\dbo_s1203\data\s1203_lights.rvmat",
			"dbo\vehicles\dbo_s1203\data\s1203_lights.rvmat",
			"dbo\vehicles\dbo_s1203\data\s1203_lights.rvmat",
			"dbo\vehicles\dbo_s1203\data\s1203_lights.rvmat",
			"dbo\vehicles\dbo_s1203\data\s1203_lights.rvmat",
			"dbo\vehicles\dbo_s1203\data\s1203_lights.rvmat",
			"dbo\vehicles\dbo_s1203\data\s1203_lights.rvmat",
			"dbo\vehicles\dbo_s1203\data\s1203_lights.rvmat"
		};
		class Sounds
		{
			thrust=0.60000002;
			thrustTurbo=1;
			thrustGentle=0.30000001;
			thrustSmoothCoef=0.02;
			camposSmoothCoef=0.029999999;
			soundSetsFilter[]=
			{
				"offroad_Engine_Offload_Ext_Rpm1_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm2_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm3_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm4_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm5_SoundSet",
				"offroad_Engine_Ext_Rpm0_SoundSet",
				"offroad_Engine_Ext_Rpm1_SoundSet",
				"offroad_Engine_Ext_Rpm2_SoundSet",
				"offroad_Engine_Ext_Rpm3_SoundSet",
				"offroad_Engine_Ext_Rpm4_SoundSet",
				"offroad_Engine_Ext_Rpm5_SoundSet",
				"offroad_Engine_Ext_Broken_SoundSet",
				"offroad_Tires_rock_slow_Ext_SoundSet",
				"offroad_Tires_rock_fast_Ext_SoundSet",
				"offroad_Tires_grass_slow_Ext_SoundSet",
				"offroad_Tires_grass_fast_Ext_SoundSet",
				"offroad_Tires_gravel_slow_Ext_SoundSet",
				"offroad_Tires_gravel_fast_Ext_SoundSet",
				"offroad_Tires_gravel_dust_fast_Ext_SoundSet",
				"offroad_Tires_asphalt_slow_Ext_SoundSet",
				"offroad_Tires_asphalt_fast_Ext_SoundSet",
				"offroad_Tires_water_slow_Ext_SoundSet",
				"offroad_Tires_water_fast_Ext_SoundSet",
				"Offroad_skid_dirt_SoundSet",
				"offroad_dirt_turn_SoundSet",
				"offroad_Rain_Ext_SoundSet",
				"offroad_damper_left_SoundSet",
				"offroad_damper_right_SoundSet"
			};
			soundSetsInt[]=
			{
				"Offroad_Tires_Asphalt_Fast_General_Int_SoundSet",
				"Offroad_Wind_SoundSet"
			};
		};
	};
	class dbo_s1203: s1203_base
	{
		scope=2;
		InteractActions[]={1048,1035};
		displayname="s1203";
		Model="\dbo\vehicles\dbo_s1203\dbo_s1203.p3d";
		maxspeed=40;
		attachments[]=
		{
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug",
			"CanisterGasoline",
			"55galDrum_1",
			"55galDrum_2",
			"sea_chest",
			"s1203_door_1_1",
			"s1203_door_2_1",
			"s1203_door_3_1",
			"s1203_door_1_2",
			"s1203_wheel_1_1",
			"s1203_wheel_1_2",
			"s1203_wheel_2_1",
			"s1203_wheel_2_2"
		};
		class Sounds
		{
			thrust=0.60000002;
			thrustTurbo=1;
			thrustGentle=0.30000001;
			thrustSmoothCoef=0.02;
			camposSmoothCoef=0.029999999;
			soundSetsFilter[]=
			{
				"offroad_Engine_Offload_Ext_Rpm1_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm2_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm3_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm4_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm5_SoundSet",
				"offroad_Engine_Ext_Rpm0_SoundSet",
				"offroad_Engine_Ext_Rpm1_SoundSet",
				"offroad_Engine_Ext_Rpm2_SoundSet",
				"offroad_Engine_Ext_Rpm3_SoundSet",
				"offroad_Engine_Ext_Rpm4_SoundSet",
				"offroad_Engine_Ext_Rpm5_SoundSet",
				"offroad_Engine_Ext_Broken_SoundSet",
				"offroad_Tires_rock_slow_Ext_SoundSet",
				"offroad_Tires_rock_fast_Ext_SoundSet",
				"offroad_Tires_grass_slow_Ext_SoundSet",
				"offroad_Tires_grass_fast_Ext_SoundSet",
				"offroad_Tires_gravel_slow_Ext_SoundSet",
				"offroad_Tires_gravel_fast_Ext_SoundSet",
				"offroad_Tires_gravel_dust_fast_Ext_SoundSet",
				"offroad_Tires_asphalt_slow_Ext_SoundSet",
				"offroad_Tires_asphalt_fast_Ext_SoundSet",
				"offroad_Tires_water_slow_Ext_SoundSet",
				"offroad_Tires_water_fast_Ext_SoundSet",
				"Offroad_skid_dirt_SoundSet",
				"offroad_dirt_turn_SoundSet",
				"offroad_Rain_Ext_SoundSet",
				"offroad_damper_left_SoundSet",
				"offroad_damper_right_SoundSet"
			};
			soundSetsInt[]=
			{
				"Offroad_Tires_Asphalt_Fast_General_Int_SoundSet",
				"Offroad_Wind_SoundSet"
			};
		};
	};
	class dbo_s1203_ambulance: s1203_base
	{
		scope=0;
		InteractActions[]={1048,1035};
		displayname="dbo_s1203_ambulance";
		Model="\dbo\vehicles\dbo_s1203\dbo_s1203_ambulance.p3d";
		maxspeed=40;
		attachments[]=
		{
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug",
			"s1203_door_1_1",
			"s1203_door_2_1",
			"s1203_door_3_1",
			"s1203_door_1_2",
			"s1203_wheel_1_1",
			"s1203_wheel_1_2",
			"s1203_wheel_2_1",
			"s1203_wheel_2_2"
		};
		class Sounds
		{
			thrust=0.60000002;
			thrustTurbo=1;
			thrustGentle=0.30000001;
			thrustSmoothCoef=0.02;
			camposSmoothCoef=0.029999999;
			soundSetsFilter[]=
			{
				"offroad_Engine_Offload_Ext_Rpm1_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm2_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm3_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm4_SoundSet",
				"offroad_Engine_Offload_Ext_Rpm5_SoundSet",
				"offroad_Engine_Ext_Rpm0_SoundSet",
				"offroad_Engine_Ext_Rpm1_SoundSet",
				"offroad_Engine_Ext_Rpm2_SoundSet",
				"offroad_Engine_Ext_Rpm3_SoundSet",
				"offroad_Engine_Ext_Rpm4_SoundSet",
				"offroad_Engine_Ext_Rpm5_SoundSet",
				"offroad_Engine_Ext_Broken_SoundSet",
				"offroad_Tires_rock_slow_Ext_SoundSet",
				"offroad_Tires_rock_fast_Ext_SoundSet",
				"offroad_Tires_grass_slow_Ext_SoundSet",
				"offroad_Tires_grass_fast_Ext_SoundSet",
				"offroad_Tires_gravel_slow_Ext_SoundSet",
				"offroad_Tires_gravel_fast_Ext_SoundSet",
				"offroad_Tires_gravel_dust_fast_Ext_SoundSet",
				"offroad_Tires_asphalt_slow_Ext_SoundSet",
				"offroad_Tires_asphalt_fast_Ext_SoundSet",
				"offroad_Tires_water_slow_Ext_SoundSet",
				"offroad_Tires_water_fast_Ext_SoundSet",
				"Offroad_skid_dirt_SoundSet",
				"offroad_dirt_turn_SoundSet",
				"offroad_Rain_Ext_SoundSet",
				"offroad_damper_left_SoundSet",
				"offroad_damper_right_SoundSet"
			};
			soundSetsInt[]=
			{
				"Offroad_Tires_Asphalt_Fast_General_Int_SoundSet",
				"Offroad_Wind_SoundSet"
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyPart
	{
		scope=2;
		simulation="ProxyInventory";
		model="";
		inventorySlot="";
		autocenter=0;
		animated=0;
		shadow=1;
		reversed=1;
	};
	class ProxyAttachment;
	class ProxyVehiclePart: ProxyAttachment
	{
		scope=2;
		simulation="ProxyInventory";
		autocenter=0;
		animated=0;
		shadow=1;
		reversed=0;
	};
	class Proxys1203_wheel: ProxyVehiclePart
	{
		model="dbo\vehicles\dbo_s1203\proxy\s1203_wheel.p3d";
		inventorySlot[]=
		{
			"s1203_wheel_1_1",
			"s1203_wheel_1_2",
			"s1203_wheel_2_1",
			"s1203_wheel_2_2"
		};
	};
	class Proxys1203_wheel_destroyed: ProxyVehiclePart
	{
		model="dbo\vehicles\dbo_s1203\proxy\s1203_wheel_destroyed.p3d";
		inventorySlot[]=
		{
			"s1203_wheel_1_1",
			"s1203_wheel_1_2",
			"s1203_wheel_2_1",
			"s1203_wheel_2_2"
		};
	};
	class Proxys1203_door_1_1: ProxyVehiclePart
	{
		Model="dbo\vehicles\dbo_s1203\proxy\s1203_door_1_1.p3d";
		inventorySlot="s1203_door_1_1";
	};
	class Proxys1203_door_2_1: ProxyVehiclePart
	{
		Model="dbo\vehicles\dbo_s1203\proxy\s1203_door_2_1.p3d";
		inventorySlot="s1203_door_2_1";
	};
	class Proxys1203_door_1_2: ProxyVehiclePart
	{
		Model="dbo\vehicles\dbo_s1203\proxy\s1203_door_1_2.p3d";
		inventorySlot="s1203_door_1_2";
	};
	class Proxys1203_door_3_1: ProxyVehiclePart
	{
		Model="dbo\vehicles\dbo_s1203\proxy\s1203_door_3_1.p3d";
		inventorySlot="s1203_door_3_1";
	};
	class Proxysea_chest: ProxyVehiclePart
	{
		model="\DZ\gear\camping\sea_chest.p3d";
		inventorySlot="sea_chest";
	};
	class Proxy55galDrum: ProxyVehiclePart
	{
		model="DZ\gear\containers\55galdrum.p3d";
		inventorySlot[]=
		{
			"55galDrum_1",
			"55galDrum_2"
		};
	};
	class ProxyJerryCan: ProxyVehiclePart
	{
		model="\DZ\vehicles\parts\jerrycan.p3d";
		inventorySlot="CanisterGasoline";
	};
	class Proxys1203A_door_1_1: ProxyVehiclePart
	{
		Model="dbo\vehicles\dbo_s1203\proxy\s1203A_door_1_1.p3d";
		inventorySlot="s1203_door_1_1";
	};
	class Proxys1203A_door_2_1: ProxyVehiclePart
	{
		Model="dbo\vehicles\dbo_s1203\proxy\s1203A_door_2_1.p3d";
		inventorySlot="s1203_door_2_1";
	};
	class Proxys1203A_door_1_2: ProxyVehiclePart
	{
		Model="dbo\vehicles\dbo_s1203\proxy\s1203A_door_1_2.p3d";
		inventorySlot="s1203_door_1_2";
	};
	class Proxys1203A_door_3_1: ProxyVehiclePart
	{
		Model="dbo\vehicles\dbo_s1203\proxy\s1203A_door_3_1.p3d";
		inventorySlot="s1203_door_3_1";
	};
};
