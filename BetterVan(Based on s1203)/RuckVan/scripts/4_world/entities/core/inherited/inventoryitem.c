class s1203_wheel extends CarWheel {
	override void EEKilled(Object killer)
	{
		string newWheel = "";
		switch( GetType() )
		{
			case "s1203_wheel":
				newWheel = "s1203_wheel_destroyed";
			break;
		}
		if ( newWheel != "" )
		{
			ReplaceWheelLambda lambda = new ReplaceWheelLambda ( this, newWheel, NULL);
			lambda.SetTransferParams(true, true, true);
			GetInventory().ReplaceItemWithNew(InventoryMode.SERVER, lambda);
		}
	}

	override int GetMeleeTargetType()
	{
		return EMeleeTargetType.NONALIGNABLE;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDetach);
		AddAction(ActionAttachOnSelection);
	}
};
modded class CanisterGasoline extends Bottle_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionAttachOnSelection);
		AddAction(ActionDetach);
	}
};
modded class SeaChest extends Container_Base
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionAttachOnSelection);
		AddAction(ActionDetach);
	}
};
modded class Barrel_ColorBase extends Container_Base
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionAttachOnSelection);
		AddAction(ActionDetach);
		
	}
};

class s1203_wheel_destroyed extends CarWheel {};
class s1203_door_1_1 extends CarDoor {};
class s1203_door_1_2 extends CarDoor {};
class s1203_door_2_1 extends CarDoor {};
class s1203_door_3_1 extends CarDoor {};