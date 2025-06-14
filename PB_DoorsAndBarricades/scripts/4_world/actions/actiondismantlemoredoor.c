class ActionDismantleMoreDoorCB : ActionContinuousBaseCB
{
	int dismantleTime;

	override void CreateActionComponent()
	{
		dismantleTime = g_Game.GetPBConfig().Get_MoreDoorDismantleTime();
		m_ActionData.m_ActionComponent = new CAContinuousTime( dismantleTime );
	}
};

class ActionDismantleMoreDoor: ActionContinuousBase
{
	void ActionDismantleMoreDoor()
	{
		m_CallbackClass = ActionDismantleMoreDoorCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
	}

	override string GetText()
	{
		return "Dismantle";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		MoreDoorBase base_building = MoreDoorBase.Cast( target_object );

		if( base_building && base_building.AllowDismantle() && base_building.CanOpenFence() )
		{
			return DismantleCondition( player, target, item, true );
		}
		return false;
	}

	override bool ActionConditionContinue( ActionData action_data )
	{
		return DismantleCondition( action_data.m_Player, action_data.m_Target, action_data.m_MainItem , false );
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		vector position = action_data.m_Player.GetPosition();
		MoreDoorBase base_building = MoreDoorBase.Cast( action_data.m_Target.GetObject() );

		base_building.Delete();
		ItemBase j_door = ItemBase.Cast(GetGame().CreateObject(base_building.j_moreDoorKit(), position, false ));
		MoreDoorKitBase returnGoods = MoreDoorKitBase.Cast( j_door );
		returnGoods.ReturnGoodsFromDismantle();
		//add damage to tool
		action_data.m_MainItem.DecreaseHealth( UADamageApplied.DISMANTLE, false );
	}

	//setup
	override bool SetupAction( PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL )
	{
		if( super.SetupAction( player, target, item, action_data, extra_data ) )
		{
			SetBuildingAnimation( item );
			return true;
		}
		return false;
	}

	protected void SetBuildingAnimation( ItemBase item )
	{
		switch( item.Type() )
		{
			case Shovel:
			case FieldShovel:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
				break;
			case Pliers:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
				break;
			default:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
				break;
		}
	}

	protected bool DismantleCondition( PlayerBase player, ActionTarget target, ItemBase item, bool camera_check )
	{
		if ( player && !player.IsLeaning() )
		{
			Object target_object = target.GetObject();
			MoreDoorBase base_building = MoreDoorBase.Cast( target_object );
			if ( base_building )
			{
				string part_name = target_object.GetActionComponentName( target.GetComponentIndex() );
				//camera and position checks
				if ( !base_building.IsFacingPlayer( player, part_name) && !player.GetInputController().CameraIsFreeLook() && base_building.HasProperDistance( part_name, player ) )
				{
					//Camera check (client-only)
					if ( camera_check )
					{
						if ( GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
						{
							if ( base_building.IsFacingCamera( part_name ) )
							{
								return false;
							}
						}
					}
					return true;
				}
			}
		}
		return false;
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		return " dismantled " + action_data.m_Target.GetObject().GetDisplayName() + " with " + action_data.m_MainItem.GetDisplayName();
	}
};


//Desmontar Poço = Well
class ActionDismantleWellCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 15 );
	}
};

class ActionDismantleWell: ActionContinuousBase
{
	void ActionDismantleWell()
	{
		m_CallbackClass = ActionDismantleWellCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
	}

	override string GetText()
	{
		return "Dismantle";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		PB_Well m_Well = PB_Well.Cast( target_object );
		if ( target_object )
		{
			if (m_Well)
			{
				return true;
			}
		}
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		Object target_object = action_data.m_Target.GetObject();
		PB_Well m_Well = PB_Well.Cast( target_object );

		int damageToTool = g_Game.GetPBConfig().Get_MoreDoorToolDamage();

		ItemBase m_Stone = ItemBase.Cast(target_object.GetGame().CreateObjectEx("PB_Brick", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
		m_Stone.SetQuantity(2);
		ItemBase m_Stone2 = ItemBase.Cast(target_object.GetGame().CreateObjectEx("PB_Brick", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
		m_Stone2.SetQuantity(2);
		ItemBase m_Stone3 = ItemBase.Cast(target_object.GetGame().CreateObjectEx("PB_Brick", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
		m_Stone3.SetQuantity(2);
		ItemBase m_Stone4 = ItemBase.Cast(target_object.GetGame().CreateObjectEx("PB_Brick", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
		m_Stone4.SetQuantity(2);
		ItemBase m_Stone5 = ItemBase.Cast(target_object.GetGame().CreateObjectEx("PB_Brick", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
		m_Stone5.SetQuantity(2);
		ItemBase m_Stone6 = ItemBase.Cast(target_object.GetGame().CreateObjectEx("PB_Brick", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
		m_Stone6.SetQuantity(2);
		ItemBase m_WoodPlank = ItemBase.Cast(target_object.GetGame().CreateObjectEx("WoodenPlank", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
		m_WoodPlank.SetQuantity(10);
		ItemBase m_WoodLog = ItemBase.Cast(target_object.GetGame().CreateObjectEx("WoodenLog", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
		m_WoodLog.SetQuantity(1);
		ItemBase m_Nail = ItemBase.Cast(target_object.GetGame().CreateObjectEx("Nail", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
		m_Nail.SetQuantity(16);

		m_Well.Delete();

		action_data.m_MainItem.DecreaseHealth( damageToTool, false );
	}
};
