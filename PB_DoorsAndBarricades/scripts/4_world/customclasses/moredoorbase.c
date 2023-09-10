class MoreDoorBase extends Fence
{
	bool HasGate()
	{
		return true;
	}

	override bool HasHinges()
	{
		return true;
	}

	bool IsMoreDoor()
	{
		return true;
	}
	//Teste de Tier de ferramentas de raid
	bool IsTier1e2()
	{
		return false;
	}

	bool IsTier3()
	{
		return false;
	}
	///////
	override void AfterStoreLoad()
	{
		SetGateState( true );
		SetBaseState( true );
	}

	string j_moreDoorKit()
	{
		return "MoreDoorSmallKit";
	}

	bool AllowDismantle()
	{
		return true;
	}

	bool AllowDestruction()
	{
		return true;
	}

	bool IsMetalDoor()
	{
		return false;
	}

	override bool CanCloseFence()
	{
		if ( IsOpened() )
		{
			return true;
		}

		return false;
	}

    override void OpenFence()
	{
		//server or single player
		if ( GetGame().IsServer() )
		{
			SetAnimationPhase( "Windown2", 					1 );
			SetAnimationPhase( "Fechadura", 					1 );
			SetAnimationPhase( "Wall_Gate_Rotate", 					1 );
			SetOpenedState( true );

			//regenerate navmesh
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdateNavmesh, GATE_ROTATION_TIME_APPROX, false );

			//synchronize
			SynchronizeBaseState();
		}

		//client or single player
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			//play sound
			SoundGateOpenStart();
		}
	}

	override void CloseFence()
	{
		//server or single player
		if ( GetGame().IsServer() )
		{
			SetAnimationPhase( "Windown2", 					0 );
			SetAnimationPhase( "Fechadura", 					0 );
			SetAnimationPhase( "Wall_Gate_Rotate", 					0 );
			//
			
			//

			SetOpenedState( false );

			//regenerate navmesh
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( UpdateNavmesh, GATE_ROTATION_TIME_APPROX, false );

			//synchronize
			SynchronizeBaseState();
		}

		//client or single player
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			//play sound
			SoundGateCloseStart();
		}
	};

	override void SetPartsAfterStoreLoad()
	{
		//update server data
		SetPartsFromSyncData();

		//set base state
		SetBaseState( true ) ;

		//synchronize after load
		SynchronizeBaseState();
	}

	override bool NameOverride(out string output)
    {
        return false;
    }

    override bool CanDisplayAttachmentSlot( int slot_id )
	{
		return true;
	}

	override bool CanDisplayAttachmentCategory( string category_name )
	{
		return true;
	}

	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		return true;
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionDialCombinationLockOnMoreDoor);
		AddAction(ActionNextCombinationLockDialOnMoreDoor);
		AddAction(ActionOpenMoreDoor);
		AddAction(ActionCloseMoreDoor);
		RemoveAction(ActionFoldBaseBuildingObject);
		RemoveAction(ActionOpenFence);
		RemoveAction(ActionCloseFence);
	}

};

//PLANK DOOR - T1
class PB_PlankDoor extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "PB_PlankDoor_Kit";
	}

	override bool IsTier1e2()
	{
		return true;
	}
};

//WOOD DOOR - T2
class PB_WoodDoor extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "PB_WoodDoor_Kit";
	}

	override bool IsTier1e2()
	{
		return true;
	}
};

//METAL DOOR - T3
class PB_MetalDoor extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "PB_MetalDoor_Kit";
	}

	override bool IsMetalDoor()
	{
		return true;
	}

	override bool IsTier3()
	{
		return true;
	}
};

//PLANK BARRICADE - T1
class PB_PlankBarricade extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "PB_PlankBarricade_Kit";
	}

	override void SetActions()
	{

	}

	override bool IsTier1e2()
	{
		return true;
	}

	bool hasTheGoodStuff()
	{
		int metalCost = 4;

		int slot_id = InventorySlots.GetSlotIdFromString("MetalSheets1");
		ItemBase slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );

		if( slotCast != NULL )
		{
			int j_Count = slotCast.GetQuantity();
			if( j_Count >= metalCost )
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override void UpdateAttachmentPhysics( string slot_name, bool is_locked )
	{

	}

	override void UpdateAttachmentVisuals( string slot_name, bool is_locked )
	{

	}



};

//METAL BARRICADE - T2
class PB_MetalBarricade extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "PB_PlankBarricade_Kit";
	}

	override bool IsTier1e2()
	{
		return true;
	}

	override void EEItemDetached ( EntityAI item, string slot_name )
    {

    }

	override void SetActions()
	{

	}

	bool hasTheGoodStuff()
	{
		int stoneCost = 10;

		int slot_id = InventorySlots.GetSlotIdFromString("Slot_Brick10");
		ItemBase slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );

		if( slotCast != NULL )
		{
			int j_Count = slotCast.GetQuantity();
			if( j_Count >= stoneCost )
			{
				return true;
			}
			return false;
		}
		return false;
	}
};

//BRICK BARRICADE - T3
class PB_BrickBarricade extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "PB_PlankBarricade_Kit";
	}

	override bool IsTier3()
	{
		return true;
	}

	override void EEItemDetached ( EntityAI item, string slot_name )
    {

    }

	override void SetActions()
	{

	}
};

//WOOD WALL - T1
class PB_WoodWall extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "PB_WoodWall_Kit";
	}

	override bool IsTier1e2()
	{
		return true;
	}

	override void EEItemDetached ( EntityAI item, string slot_name )
    {

    }

	override void SetActions()
	{

	}

	bool hasTheGoodStuff()
	{
		int metalCost = 24;

		int slot_id = InventorySlots.GetSlotIdFromString("MetalSheets4");
		ItemBase slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );

		if( slotCast != NULL )
		{
			int j_Count = slotCast.GetQuantity();
			if( j_Count >= metalCost )
			{
				return true;
			}
			return false;
		}
		return false;
	}
};

//METAL WALL - T2
class PB_MetalWall extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "PB_WoodWall_Kit";
	}

	override bool IsTier1e2()
	{
		return true;
	}

	override void EEItemDetached ( EntityAI item, string slot_name )
    {

    }

	override void SetActions()
	{

	}

	bool hasTheGoodStuff()
	{
		int stoneCost = 40;

		int slot_id = InventorySlots.GetSlotIdFromString("Slot_Brick");
		ItemBase slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );

		if( slotCast != NULL )
		{
			int j_Count = slotCast.GetQuantity();
			if( j_Count >= stoneCost )
			{
				return true;
			}
			return false;
		}
		return false;
	}
};

//BRICK WALL - T3
/*class PB_BrickWall extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "PB_WoodWall_Kit";
	}

	override bool IsTier3()
	{
		return true;
	}

	override void EEItemDetached ( EntityAI item, string slot_name )
    {

    }

	override void SetActions()
	{

	}
};*/

//PLANK DOOR BARRICADE - T1
class PB_PlankDoorBarricade extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "PB_PlankDoorBarricade_Kit";
	}

	override void SetActions()
	{

	}

	override bool IsTier1e2()
	{
		return true;
	}

	bool hasTheGoodStuff()
	{
		int metalCost = 8;

		int slot_id = InventorySlots.GetSlotIdFromString("MetalSheets2");
		ItemBase slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );

		if( slotCast != NULL )
		{
			int j_Count = slotCast.GetQuantity();
			if( j_Count >= metalCost )
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override void UpdateAttachmentPhysics( string slot_name, bool is_locked )
	{

	}

	override void UpdateAttachmentVisuals( string slot_name, bool is_locked )
	{

	}



};

//METAL DOOR BARRICADE - T2
class PB_MetalDoorBarricade extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "PB_PlankDoorBarricade_Kit";
	}

	override void SetActions()
	{

	}

	override bool IsTier1e2()
	{
		return true;
	}

	bool hasTheGoodStuff()
	{
		int stoneCost = 18;

		int slot_id = InventorySlots.GetSlotIdFromString("Slot_Brick18");
		ItemBase slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );

		if( slotCast != NULL )
		{
			int j_Count = slotCast.GetQuantity();
			if( j_Count >= stoneCost )
			{
				return true;
			}
			return false;
		}
		return false;
	}


	override void UpdateAttachmentPhysics( string slot_name, bool is_locked )
	{

	}

	override void UpdateAttachmentVisuals( string slot_name, bool is_locked )
	{

	}
};

//Brick DOOR BARRICADE - T3
class PB_BrickDoorBarricade extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "PB_PlankDoorBarricade_Kit";
	}

	override void SetActions()
	{

	}

	override bool IsTier3()
	{
		return true;
	}

	override void UpdateAttachmentPhysics( string slot_name, bool is_locked )
	{

	}

	override void UpdateAttachmentVisuals( string slot_name, bool is_locked )
	{

	}

};

//Well - Poço de agua
class PB_Well extends ItemBase
{
	override bool IsWell()
	{
		return true;
	}
	
	override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }
	
	override bool CanPutInCargo( EntityAI parent )
	{
        return false;
    }
	
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
        return false;
    }
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionWashHandsWellOne);
		AddAction(ActionDrinkWellContinuous);
	}
};

//JANELA PLANK - T1
class PB_PlankWindow extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "PB_PlankWindow_Kit";
	}

	override bool IsTier1e2()
	{
		return true;
	}

	bool hasTheGoodStuff()
	{
		int metalCost = 4;

		int slot_id = InventorySlots.GetSlotIdFromString("MetalSheets1");
		ItemBase slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );

		if( slotCast != NULL )
		{
			int j_Count = slotCast.GetQuantity();
			if( j_Count >= metalCost )
			{
				return true;
			}
			return false;
		}
		return false;
	}
};

//JANELA METAL - T2
class PB_MetalWindow extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "PB_PlankWindow_Kit";
	}

	override bool IsTier1e2()
	{
		return true;
	}

};

//GATE WOOD - T1
class PB_WoodGate extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "PB_WoodGate_Kit";
	}

	override bool IsTier1e2()
	{
		return true;
	}

	bool hasTheGoodStuff()
	{
		int metalCost = 24;

		int slot_id = InventorySlots.GetSlotIdFromString("MetalSheets4");
		ItemBase slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );

		if( slotCast != NULL )
		{
			int j_Count = slotCast.GetQuantity();
			if( j_Count >= metalCost )
			{
				return true;
			}
			return false;
		}
		return false;
	}
};

//GATE METAL - T2
class PB_MetalGate extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "PB_WoodGate_Kit";
	}

	override bool IsTier1e2()
	{
		return true;
	}
};

//METAL PEQUENO - SMALL METAL PLATE
class PB_SmallMetalPlate extends Inventory_Base
{
	override bool CanPutInCargo( EntityAI parent )
    {
        return true;
    }

	override bool CanPutIntoHands(EntityAI parent)
    {
        return true;
    }
};

////////////////////////////////////////////
///////////////OLDNAGS//////////////////////
////////////////////////////////////////////
 class BB_BaseWall extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "BB_BaseWall_Kit";
	}
	override bool AllowDismantle()
	{
		return true;
	}
		override void SetActions()
	{
		super.SetActions();

		RemoveAction(ActionOpenMoreDoor);
		RemoveAction(ActionCloseMoreDoor);
		RemoveAction(ActionFoldBaseBuildingObject);
		RemoveAction(ActionOpenFence);
		RemoveAction(ActionCloseFence);
	}
};
 class BB_SmallShack extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "BB_SmallShack_Kit";
	}
	
	override bool AllowDismantle()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();

		RemoveAction(ActionOpenMoreDoor);
		RemoveAction(ActionCloseMoreDoor);
		RemoveAction(ActionFoldBaseBuildingObject);
		RemoveAction(ActionOpenFence);
		RemoveAction(ActionCloseFence);
	}
};
class BB_MediumShack extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "BB_MediumShack_Kit";
	}
	
	override bool AllowDismantle()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();

		RemoveAction(ActionOpenMoreDoor);
		RemoveAction(ActionCloseMoreDoor);
		RemoveAction(ActionFoldBaseBuildingObject);
		RemoveAction(ActionOpenFence);
		RemoveAction(ActionCloseFence);
	}
};
class BB_LargeShack extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "BB_LargeShack_Kit";
	}
	
	override bool AllowDismantle()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();

		RemoveAction(ActionOpenMoreDoor);
		RemoveAction(ActionCloseMoreDoor);
		RemoveAction(ActionFoldBaseBuildingObject);
		RemoveAction(ActionOpenFence);
		RemoveAction(ActionCloseFence);
	}
};
class BB_HugeShack extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "BB_HugeShack_Kit";
	}
	
	override bool AllowDismantle()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();

		RemoveAction(ActionOpenMoreDoor);
		RemoveAction(ActionCloseMoreDoor);
		RemoveAction(ActionFoldBaseBuildingObject);
		RemoveAction(ActionOpenFence);
		RemoveAction(ActionCloseFence);
	}
};
class BB_Garage extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "BB_Garage_Kit";
	}
	
	override bool AllowDismantle()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();

		RemoveAction(ActionOpenMoreDoor);
		RemoveAction(ActionCloseMoreDoor);
		RemoveAction(ActionFoldBaseBuildingObject);
		RemoveAction(ActionOpenFence);
		RemoveAction(ActionCloseFence);
	}
};
 class BB_WatchTower extends MoreDoorBase
{
	override string j_moreDoorKit()
	{
		return "BB_WatchTower_Kit";
	}
	override bool AllowDismantle()
	{
		return true;
	}
		override void SetActions()
	{
		super.SetActions();

		RemoveAction(ActionOpenMoreDoor);
		RemoveAction(ActionCloseMoreDoor);
		RemoveAction(ActionFoldBaseBuildingObject);
		RemoveAction(ActionOpenFence);
		RemoveAction(ActionCloseFence);
	}
};
////////////////////////////////////////////
///////////////OLDNAGS//////////////////////
////////////////////////////////////////////