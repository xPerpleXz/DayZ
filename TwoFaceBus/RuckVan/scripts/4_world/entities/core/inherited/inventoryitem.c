class van_01_wheel extends CarWheel 
{
	override void EEKilled(Object killer)
	{
			string newWheel = "";
			switch( GetType() )
			{
				case "Van_01_Wheel":
					newWheel = "Van_01_Wheel_ruined";
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

class Van_01_Wheel_ruined extends CarWheel {};
class van_01_door_1_1 extends CarDoor {};
class van_01_door_2_1 extends CarDoor {};
class van_01_door_2_2 extends CarDoor {};
class van_01_trunk_1 extends CarDoor {};
class van_01_trunk_2 extends CarDoor {};