class ActionDestroyCombinationLockMoreDoorCB : ActionContinuousBaseCB
{
	int DialLockTime;

	override void CreateActionComponent()
	{
		DialLockTime = g_Game.GetPBConfig().Get_DialLockDestroyTime();
		m_ActionData.m_ActionComponent = new CAContinuousTime( DialLockTime );
	}

};

class ActionDestroyCombinationLockMoreDoor: ActionContinuousBase
{
	void ActionDestroyCombinationLockMoreDoor()
	{
		m_CallbackClass = ActionDestroyCombinationLockMoreDoorCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;
	}

	override void CreateConditionComponents()
	{
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINonRuined;
	}

	override string GetText()
	{
		return "#destroy_combination_lock";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		string selection = target_object.GetActionComponentName( target.GetComponentIndex() );
		MoreDoorBase fence = MoreDoorBase.Cast( target_object );
		if ( fence && fence.IsLocked() && g_Game.GetPBConfig().Get_CanCutComboLock() )
		{
			return true;
		}
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		MoreDoorBase fence = MoreDoorBase.Cast( action_data.m_Target.GetObject() );
		if ( fence )
		{
			CombinationLock combination_lock = fence.GetCombinationLock();
			if ( combination_lock )
			{
				combination_lock.UnlockServer( action_data.m_Player, fence );
				GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( combination_lock.DestroyLock, 200, false );
			}
		}

		action_data.m_MainItem.DecreaseHealth( UADamageApplied.SAW_LOCK, false );

		//soft skills
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}

	override string GetAdminLogMessage(ActionData action_data)
	{
		return " destroyed combination lock with " + action_data.m_MainItem.GetDisplayName();
	}
};