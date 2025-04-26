class dbo_s1203 extends Hatchback_02
{
	
	void dbo_s1203()
	{
		m_dmgContactCoef = 0.060;
	}	

    override float GetActionDistanceFuel()
    {
        return 3.2;
    }
	
	override float GetActionDistanceCoolant()
    {
        return 4.2;
    }
	
	
	override float GetActionDistanceOil()
    {
        return 4.2;
    }
	
	override int GetAnimInstance()
	{
		return VehicleAnimInstances.HATCHBACK;
	}
	
// Override for car-specific light type
		override CarRearLightBase CreateRearLight()
	{
		return CarRearLightBase.Cast( ScriptedLightBase.CreateLight(s1203RearLight) );
	}
	
	override CarLightBase CreateFrontLight()
	{
		return CarLightBase.Cast( ScriptedLightBase.CreateLight(s1203FrontLight) );
	}

	
	override int GetCarDoorsState( string slotType )
	{
		CarDoor carDoor;

		Class.CastTo( carDoor, FindAttachmentBySlotName( slotType ) );
		if ( !carDoor )
			return CarDoorState.DOORS_MISSING;
	
		switch( slotType )
		{
			case "s1203_door_1_1":
				if ( GetAnimationPhase("DoorsDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "s1203_door_1_2":
				if ( GetAnimationPhase("DoorsCoDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
				case "s1203_door_2_1":
				if ( GetAnimationPhase("DoorsCargo2") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
				case "s1203_door_2_2":
				if ( GetAnimationPhase("DoorsCargo1") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			
				case "s1203_door_Hood":
				if ( GetAnimationPhase("DoorsHood") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
				break;
				
			case "s1203_door_3_1":
				if ( GetAnimationPhase("DoorsTrunk") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
				break;
		}

		return CarDoorState.DOORS_MISSING;
	}
	override bool CrewCanGetThrough( int posIdx )
	{
		switch( posIdx )
		{
			case 0:
				if ( GetCarDoorsState( "s1203_door_1_1" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
			
			case 1:
				if ( GetCarDoorsState( "s1203_door_1_2" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
			
			
			case 2:
				if ( GetCarDoorsState( "s1203_door_2_1" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
			
			case 3:
				if ( GetCarDoorsState( "s1203_door_2_2" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
			

			
		}

		return false;
	}
	
	override string GetDoorSelectionNameFromSeatPos(int posIdx)
	{
		switch( posIdx )
		{
		case 0:
			return "doors_driver";
		break;
		case 1:
			return "doors_codriver";
		break;
         case 2:
			return "doors_cargo2";
		break;
		case 3:
			return "doors_cargo2";
		break;

		
		}
		
		return super.GetDoorSelectionNameFromSeatPos(posIdx);
	}
	
	override string GetDoorInvSlotNameFromSeatPos(int posIdx)
	{
		switch( posIdx )
		{
		case 0:
			return "s1203_door_1_1";
		break;
		case 1:
			return "s1203_door_1_2";
		break;
		
		case 2:
			return "s1203_door_2_1";
		break;
			case 3:
			return "s1203_door_2_1";
		break;

		
		
		}
		
		return super.GetDoorInvSlotNameFromSeatPos(posIdx);
	}
	
		override string GetAnimSourceFromSelection( string selection )
	{
		switch( selection )
		{
		case "doors_driver":
			return "DoorsDriver";
		case "doors_codriver":
			return "DoorsCoDriver";
		case "doors_cargo2":
			return "DoorsCargo2";
		case "doors_hood":
			return "DoorsHood";
		case "doors_trunk":
			return "DoorsTrunk";
		}

		return "";
	}
		override string GetDoorConditionPointFromSelection( string selection )
	{
		switch( selection )
		{
		case "seat_driver":
			return "seat_con_1_1";
		break;
		case "seat_codriver":
			return "seat_con_2_1";
		break;
		case "seat_cargo1":
			return "seat_con_2_2";
		break;
		case "seat_cargo2":
			return "seat_con_1_2";
		break;
		
		
		}
		

		
		return "";
	}

		override int GetSeatAnimationType( int posIdx )
	{
		switch( posIdx )
		{
		case 0:
			return DayZPlayerConstants.VEHICLESEAT_DRIVER;
		case 1:
			return DayZPlayerConstants.VEHICLESEAT_CODRIVER;
		case 2:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_R;
		case 3:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_R;

		}

		return 0;
	}
	override bool CanReachSeatFromSeat( int currentSeat, int nextSeat )
	{
		switch( currentSeat )
		{
		case 0:
			if ( nextSeat == 1 )
				return true;
			break;
		case 1:
			if ( nextSeat == 0 )
				return true;
			break;
			
			case 2:
			if ( nextSeat == 3 )
				return true;
			break;
			
			case 3:
			if ( nextSeat == 2 )
				return true;
			break;

			
		}
		return false;
	}

	override bool CanReachDoorsFromSeat( string pDoorsSelection, int pCurrentSeat )
	{
		switch( pCurrentSeat )
		{
		case 0:
			if (pDoorsSelection == "DoorsDriver")
			{
				return true;
			}
		break;
		case 1:
			if (pDoorsSelection == "DoorsCoDriver")
			{
				return true;
			}
		break;
	case 2:
			if (pDoorsSelection == "DoorsCargo2")
			{
				return true;
			}
		break;
		case 3:
			if (pDoorsSelection == "DoorsCargo2")
			{
				return true;
			}
		break;
		
		case 4:
			if (pDoorsSelection == "DoorsCargo2")
			{
				return true;
			}
		break;

		}
		
		return false;		
	}
	
	override float OnSound( CarSoundCtrl ctrl, float oldValue )
	{
		switch ( ctrl )
		{
			case CarSoundCtrl.DOORS:
				float newValue = 0;
				
				//-----
				if ( GetCarDoorsState( "s1203_door_1_1" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;

				//-----
				if ( GetCarDoorsState( "s1203_door_1_2" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
			
				//-----
				if ( GetCarDoorsState( "s1203_door_2_1" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;

				
				if ( GetCarDoorsState( "s1203_door_Hood" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
				
				if ( GetCarDoorsState( "s1203_door_3_1" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;

				if ( newValue > 1 )
					newValue = 1;
			
				return newValue;
			break;
		}

		return oldValue;
	}
}

class dbo_s1203_ambulance extends dbo_s1203
{ }