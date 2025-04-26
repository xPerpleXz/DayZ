modded class PlayerBase extends ManBase
{
    override void Init()
    {
        if ( !GetGame().IsServer() || !GetGame().IsMultiplayer() ) {
			DayzPlayerItemBehaviorCfg heavyItemBehaviour = new DayzPlayerItemBehaviorCfg;
			heavyItemBehaviour.SetHeavyItems();
 
			GetDayZPlayerType().AddItemInHandsProfileIK("s1203_wheel", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,					 "dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_wheel.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("s1203_wheel_destroyed", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,					"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_wheel.anm");
            GetDayZPlayerType().AddItemInHandsProfileIK("s1203_door_1_1", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,					 "dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_wheel.anm");
			GetDayZPlayerType().AddItemInHandsProfileIK("s1203_door_2_1", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,					"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_wheel.anm");
            GetDayZPlayerType().AddItemInHandsProfileIK("s1203_door_1_2", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,					"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_wheel.anm");

			
			}
        super.Init();
    }
}
