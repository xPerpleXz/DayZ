class van_01_wheel extends CarWheel {
	override void EEKilled(Object killer)
	{
		string newWheel = "";
		switch( GetType() )
		{
			case "van_01_wheel":
				newWheel = "van_01_wheel_ruined";
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
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		#ifndef SERVER
		EffectSound effect = SEffectManager.PlaySound(m_AttachSound, GetPosition());
		effect.SetAutodestroy(true);
		#endif
	}
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent, slot_id);
		
		#ifndef SERVER
		EffectSound effect = SEffectManager.PlaySound(m_DetachSound, GetPosition());
		effect.SetAutodestroy(true);
		#endif
	}
};

class van_01_wheel extends CarWheel {};
class van_01_wheel_ruined extends CarWheel_Ruined {};

//-------------------------------------
class van_01_door_1_1 extends CarDoor {};
class van_01_door_2_1 extends CarDoor {};
class van_01_door_2_2 extends CarDoor {};
class van_01_trunk_1 extends CarDoor {};
class van_01_trunk_2 extends CarDoor {};








