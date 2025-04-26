class Van_01 extends Hatchback_02
{
	
	void Van_01()
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
			case "Van_01_Door_1_1":
				if ( GetAnimationPhase("DoorsDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "Van_01_Door_2_1":
				if ( GetAnimationPhase("DoorsCoDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
				case "Van_01_Door_2_2":
				if ( GetAnimationPhase("DoorsCargo1") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
				case "Van_01_Trunk_1":
				if ( GetAnimationPhase("DoorsCargo3") > 0.5 )
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
				if ( GetCarDoorsState( "Van_01_Door_1_1" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
			
			case 1:
				if ( GetCarDoorsState( "Van_01_Door_2_1" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
			
			
			case 2:
				if ( GetCarDoorsState( "Van_01_Door_2_2" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
			
			case 3:
				if ( GetCarDoorsState( "Van_01_Door_2_2" ) == CarDoorState.DOORS_CLOSED )
					return false;

			case 4:
				if ( GetCarDoorsState( "Van_01_Door_2_2" ) == CarDoorState.DOORS_CLOSED )
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
			case 2:
				return "doors_driver";
			case 1:
			case 3:
				return "doors_codriver";
		}
		
		return super.GetDoorSelectionNameFromSeatPos(posIdx);
	}
	
	override string GetDoorInvSlotNameFromSeatPos(int posIdx)
	{
		switch( posIdx )
		{
			case 0:
			case 2:
				return "Van_01_Door_1_1";
			case 1:
			case 3:
				return "Van_01_Door_2_1";
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
		case "doors_cargo1":
			return "DoorsCargo1";
		case "doors_cargo2":
			return "DoorsCargo2";
		case "doors_cargo3":
			return "DoorsCargo3";
		case "doors_hood":
			return "DoorsHood";
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
			case "seat_cargo2":
			case "seat_cargo3":
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
				return pDoorsSelection == "DoorsDriver";
	
			case 1:
				return pDoorsSelection == "DoorsCoDriver";
	
			case 2:
				return pDoorsSelection == "DoorsDriver";
	
			case 3:
				return pDoorsSelection == "DoorsCoDriver";
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
				if ( GetCarDoorsState( "Van_01_Door_1_1" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
				//-----
				if ( GetCarDoorsState( "Van_01_Door_2_1" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
			
				//-----
				if ( GetCarDoorsState( "Van_01_Door_2_2" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;

				
				if ( GetCarDoorsState( "Van_01_Trunk_1" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
				
				if ( GetCarDoorsState( "Van_01_Trunk_2" ) == CarDoorState.DOORS_CLOSED )
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