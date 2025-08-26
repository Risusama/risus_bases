class MoreDoorKitBase extends ItemBase
{
	ref protected EffectSound 						m_DeployLoopSound;
	Object											moreDoorKit;
	//protected bool m_hasThings;

	string slotNails = "Material_Nails";
	string slotPlanks = "Material_WoodenPlanks";
	string slotMetal = "Material_MetalSheets";
	string slotLogs = "Material_WoodenLogs";
	string slotLogs2 = "Material_L1_WoodenLogs";
	string slotWire = "Material_MetalWire";
	string slotStone = "Slot_Brick";

	string slotPlanks10 = "Material_L2W2_WoodenPlanks";
	string slotPlanks20 = "Material_L2W3_WoodenPlanks";

	////////////////////////////////////////////
	///////////////OLDNAGS//////////////////////
	////////////////////////////////////////////

	string slotPlanks20_2 = "Material_L3W1_WoodenPlanks";
	string slotPlanks20_3 = "Material_L3W2_WoodenPlanks";
	string slotPlanks20_4 = "Material_L3W3_WoodenPlanks";

	string slotNails99_1 = "Material_L3W1_Nails";
	string slotNails99_2 = "Material_L3W2_Nails";
	string slotNails99_3 = "Material_L3W3_Nails";

	string slotMetalSheets5 = "Material_L3W1_MetalSheets";
	string slotMetalSheets10 = "Material_L2W1_MetalSheets";
	string slotMetalSheets20 = "Material_L2W2_MetalSheets";

	////////////////////////////////////////////
	///////////////OLDNAGS//////////////////////
	////////////////////////////////////////////

	string slotNails20 = "Material_L2W1_Nails";
	string slotNails36 = "Material_L2W2_Nails";
	string slotNails75 = "Material_L2W3_Nails";

	string slotMetal4 = "MetalSheets1";
	string slotMetal8 = "MetalSheets2";
	string slotMetal16 = "MetalSheets3";
	string slotMetal24 = "MetalSheets4";

	int slot_id;
	int slot_id2;
	int slot_id3;
	int slot_id4;
	/////////////////////////////////////////////
	int slot_id5;
	int slot_id6;
	int slot_id7;
	int slot_id8;
	int slot_id9;
	int slot_id10;
	int slot_id11;
	/////////////////////////////////////////////

	ItemBase slotCast;
	ItemBase slotCast2;
	ItemBase slotCast3;
	ItemBase slotCast4;
	/////////////////////////////////////////////
	ItemBase slotCast5;
	ItemBase slotCast6;
	ItemBase slotCast7;
	ItemBase slotCast8;
	ItemBase slotCast9;
	ItemBase slotCast10;
	ItemBase slotCast11;
	/////////////////////////////////////////////

	int plankCost;
	int plankCost2;
	int plankCost3;
	int plankCost4;
	int nailCost;
	int nailCost2;
	int nailCost3;
	int nailCost4;
	int metalCost;
	int metalsheetsCost;
	int metalsheetsCost2;

	int logCost;
	int wireCost;
	int stoneCost;

	int j_Count;
	int j_Count2;
	int j_Count3;
	int j_Count4;
	/////////////////////////////////////////////
	int j_Count5;
	int j_Count6;
	int j_Count7;
	int j_Count8;
	int j_Count9;
	int j_Count10;
	int j_Count11;
	/////////////////////////////////////////////
	void MoreDoorKitBase()
	{
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
	}

	bool hasTheGoodStuff()
	{
		return false;
	}

	string j_Door()
	{
		return "SodaCan_Spite";
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if ( IsDeploySound() )
		{
			PlayDeploySound();
		}

		if ( CanPlayDeployLoopSound() )
		{
			PlayDeployLoopSound();
		}

		if ( m_DeployLoopSound && !CanPlayDeployLoopSound() )
		{
			StopDeployLoopSound();
		}
	}

	override bool CanPutInCargo( EntityAI parent )
	{
		if ( IsEmpty() )
		{
			return true;
		}
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return true;
	}

	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		return true;
	}

	override bool CanReleaseCargo(EntityAI cargo)
	{
		return true;
	}

	void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods.SetQuantity(10);
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods2.SetQuantity(10);
		GetInventory().CreateAttachment( "MetalWire" );
		ItemBase j_goods3 = ItemBase.Cast(GetInventory().CreateAttachment("Stone" ));
		j_goods3.SetQuantity(10);
	}

	//================================================================
	// ADVANCED PLACEMENT
	//================================================================

    override bool CanBePlaced( Man player, vector position ) // Comes from entityai.c, not inventoryitem.c
    {
        //Print("RisusBasesDebug - in CanBePlaced");
        if (hasTheGoodStuff())
        {    
            //Print("RisusBasesDebug - in CanBePlaced - hasTheGoodStuff - return true");
            return true;
        }
        //Print("RisusBasesDebug - in CanBePlaced - !hasTheGoodStuff - return false");
        return false;
    }

	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player );

		if ( GetGame().IsServer() && hasTheGoodStuff() )
		{
			EntityAI moreDoorObject = EntityAI.Cast(GetGame().CreateObjectEx(j_Door(), position, ECE_PLACE_ON_SURFACE));
			moreDoorObject.SetPosition(position);
			moreDoorObject.SetOrientation(orientation);
		}
		SetIsDeploySound(true);
		SetLifetime(3888000);
	}

	override bool IsBasebuildingKit()
	{
		return true;
	}

	override bool IsDeployable()
	{
		return true;
	}

	override string GetDeploySoundset()
	{
		return "putDown_FenceKit_SoundSet";
	}

	override string GetLoopDeploySoundset()
	{
		return "BarbedWire_Deploy_loop_SoundSet";
	}

	void PlayDeployLoopSound()
	{
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			m_DeployLoopSound = SEffectManager.PlaySound( GetLoopDeploySoundset(), GetPosition() );
		}
	}

	void StopDeployLoopSound()
	{
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			m_DeployLoopSound.SoundStop();
			delete m_DeployLoopSound;
		}
	}

	override bool IsContainer()
	{
		return true;
	}

	// override bool IsHeavyBehaviour()
	// {
	// 	return true;
	// }

	// override bool IsTwoHandedBehaviour()
	// {
	// 	return true;
	// }

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}
};

//Plank Door Kit - T1
class PB_PlankDoor_Kit extends MoreDoorKitBase
{
	override bool hasTheGoodStuff()
	{
		plankCost = 10;
		nailCost = 20;

		slot_id = InventorySlots.GetSlotIdFromString(slotNails20);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotPlanks10);
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL )
		{
			if( j_Count >= nailCost && j_Count2 >= plankCost )
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override string j_Door()
	{
		if ( hasTheGoodStuff() )
		{
			return "PB_PlankDoor";
		}
		return "PB_PlankDoor_Kit";
	}

	override void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods.SetQuantity(5);
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods2.SetQuantity(10);
		GetInventory().CreateAttachment( "MetalWire" );
	}
};

//Wood Door Kit - T2
class PB_WoodDoor_Kit extends MoreDoorKitBase
{
	override bool hasTheGoodStuff()
	{
		plankCost = 18;
		nailCost = 36;

		slot_id = InventorySlots.GetSlotIdFromString(slotNails36);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotPlanks20);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotWire);
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL )
		{
			if( j_Count >= nailCost && j_Count2 >= plankCost )
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override string j_Door()
	{
		if ( hasTheGoodStuff() )
		{
			return "PB_WoodDoor";
		}
		return "PB_WoodDoor_Kit";
	}

	override void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods.SetQuantity(9);
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods2.SetQuantity(16);
		GetInventory().CreateAttachment( "MetalWire" );
	}
};

//Metal Door Kit - T3
class PB_MetalDoor_Kit extends MoreDoorKitBase
{
	override bool hasTheGoodStuff()
	{
		plankCost = 20;
		nailCost = 75;
		metalCost = 16;

		slot_id = InventorySlots.GetSlotIdFromString(slotNails75);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotPlanks);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotWire);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotMetal16);
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );

		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();
		j_Count4 = slotCast4.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL)
		{
			if( j_Count >= nailCost && j_Count2 >= plankCost && j_Count4 >=metalCost )
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override string j_Door()
	{
		if ( hasTheGoodStuff() )
		{
			return "PB_MetalDoor";
		}
		return "PB_MetalDoor_Kit";
	}

	override void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods.SetQuantity(10);
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods2.SetQuantity(45);
		ItemBase j_goods3 = ItemBase.Cast(GetInventory().CreateAttachment("PB_SmallMetalPlate" ));
		j_goods3.SetQuantity(6);
		GetInventory().CreateAttachment( "MetalWire" );
	}
};

//Plank Barricade Kit - T1
class PB_PlankBarricade_Kit extends MoreDoorKitBase
{
	override bool hasTheGoodStuff()
	{
		plankCost = 10;
		nailCost = 20;

		slot_id = InventorySlots.GetSlotIdFromString(slotNails20);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotPlanks10);
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL )
		{
			if( j_Count >= nailCost && j_Count2 >= plankCost )
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override string j_Door()
	{
		if ( hasTheGoodStuff() )
		{
			return "PB_PlankBarricade";
		}
		return "PB_PlankBarricade_Kit";
	}

	override void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods.SetQuantity(5);
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods2.SetQuantity(10);
	}
};

//Wood Wall Kit - T1
class PB_WoodWall_Kit extends MoreDoorKitBase
{
	override bool hasTheGoodStuff()
	{
		nailCost = 36;
		logCost = 4;

		slot_id = InventorySlots.GetSlotIdFromString(slotNails36);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotLogs2);

		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );

		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL )
		{
			if( j_Count >= nailCost && j_Count2 >= logCost )
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override string j_Door()
	{
		if ( hasTheGoodStuff() )
		{
			return "PB_WoodWall";
		}
		return "PB_WoodWall_Kit";
	}

	override void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods2.SetQuantity(20);
	}
};

//Plank Door Barricade Kit - T1
class PB_PlankDoorBarricade_Kit extends MoreDoorKitBase
{
	override bool hasTheGoodStuff()
	{
		plankCost = 10;
		nailCost = 20;

		slot_id = InventorySlots.GetSlotIdFromString(slotNails20);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotPlanks10);
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL )
		{
			if( j_Count >= nailCost && j_Count2 >= plankCost )
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override string j_Door()
	{
		if ( hasTheGoodStuff() )
		{
			return "PB_PlankDoorBarricade";
		}
		return "PB_PlankDoorBarricade_Kit";
	}

	override void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods.SetQuantity(5);
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods2.SetQuantity(10);
	}
};

//Well Kit
class PB_Well_Kit extends MoreDoorKitBase
{
	override bool hasTheGoodStuff()
	{
		logCost = 2;
		nailCost = 36;
		stoneCost = 40;
		plankCost = 20;

		slot_id = InventorySlots.GetSlotIdFromString(slotNails36);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotLogs);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotStone);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotPlanks);
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );
		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();
		j_Count3 = slotCast3.GetQuantity();
		j_Count4 = slotCast4.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL )
		{
			if( j_Count >= nailCost && j_Count2 >= logCost && j_Count3 >= stoneCost && j_Count4 >= plankCost)
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override string j_Door()
	{
		if ( hasTheGoodStuff() )
		{
			return "PB_Well";
		}
		return "PB_Well_Kit";
	}

	/*override void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods.SetQuantity(8);
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods2.SetQuantity(16);
		ItemBase j_goods3 = ItemBase.Cast(GetInventory().CreateAttachment("Stone" ));
		j_goods3.SetQuantity(18);
	}*/
};

//Plank Window Kit - T1
class PB_PlankWindow_Kit extends MoreDoorKitBase
{
	override bool hasTheGoodStuff()
	{
		plankCost = 10;
		nailCost = 20;

		slot_id = InventorySlots.GetSlotIdFromString(slotNails20);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotPlanks10);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotWire);
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL )
		{
			if( j_Count >= nailCost && j_Count2 >= plankCost )
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override string j_Door()
	{
		if ( hasTheGoodStuff() )
		{
			return "PB_PlankWindow";
		}
		return "PB_PlankWindow_Kit";
	}

	override void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods.SetQuantity(5);
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods2.SetQuantity(10);
		GetInventory().CreateAttachment( "MetalWire" );
	}
};

//Wood Gate Kit
class PB_WoodGate_Kit extends MoreDoorKitBase
{
	override bool hasTheGoodStuff()
	{
		plankCost = 20;
		nailCost = 36;
		logCost = 2;

		slot_id = InventorySlots.GetSlotIdFromString(slotNails36);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotPlanks);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotWire);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotLogs);
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );
		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();
		j_Count4 = slotCast4.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL)
		{
			if( j_Count >= nailCost && j_Count2 >= plankCost && j_Count4 >= logCost)
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override string j_Door()
	{
		if ( hasTheGoodStuff() )
		{
			return "PB_WoodGate";
		}
		return "PB_WoodGate_Kit";
	}

	override void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods.SetQuantity(10);
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods2.SetQuantity(10);
		GetInventory().CreateAttachment( "MetalWire" );
	}
};
////////////////////////////////////////////
///////////////OLDNAGS//////////////////////
////////////////////////////////////////////

//Base Wall Kit
class BB_BaseWall_Kit extends MoreDoorKitBase
{
	override bool hasTheGoodStuff()
	{
		nailCost = 36;
		logCost = 2;

		slot_id = InventorySlots.GetSlotIdFromString(slotNails36);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotLogs);

		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );

		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL )
		{
			if( j_Count >= nailCost && j_Count2 >= logCost )
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override string j_Door()
	{
		if ( hasTheGoodStuff() )
		{
			return "BB_BaseWall";
		}
		return "BB_BaseWall_Kit";
	}

	override void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods2.SetQuantity(20);
	}
};
//Small Shack Kit
class BB_SmallShack_Kit extends MoreDoorKitBase
{
	override bool hasTheGoodStuff()
	{
		nailCost = 99;
		metalsheetsCost = 5;
		metalCost = 4;
		plankCost = 20;
		plankCost2 = 20;

		slot_id = InventorySlots.GetSlotIdFromString(slotNails99_1);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotMetalSheets5);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotMetal4);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotPlanks20_2);
		slot_id5 = InventorySlots.GetSlotIdFromString(slotPlanks20_3);
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );
		slotCast5 = ItemBase.Cast( GetInventory().FindAttachment(slot_id5) );
		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();
		j_Count3 = slotCast3.GetQuantity();
		j_Count4 = slotCast4.GetQuantity();
		j_Count5 = slotCast5.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL && slotCast5 != NULL )
		{
			if( j_Count >= nailCost && j_Count2 >= metalsheetsCost && j_Count3 >= metalCost && j_Count4 >= plankCost && j_Count5 >= plankCost2)
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override string j_Door()
	{
		if ( hasTheGoodStuff() )
		{
			return "BB_SmallShack";
		}
		return "BB_SmallShack_Kit";
	}

	override void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods.SetQuantity(20);
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods2.SetQuantity(20);
		ItemBase j_goods3 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods3.SetQuantity(99);
		ItemBase j_goods4 = ItemBase.Cast(GetInventory().CreateAttachment("PB_SmallMetalPlate" ));
		j_goods4.SetQuantity(4);
		ItemBase j_goods5 = ItemBase.Cast(GetInventory().CreateAttachment("MetalPlate" ));
		j_goods5.SetQuantity(5);
	}
};
//Medium Shack Kit
class BB_MediumShack_Kit extends MoreDoorKitBase
{
	override bool hasTheGoodStuff()
	{
		nailCost = 99;
		nailCost2= 75;
		metalsheetsCost = 10;
		metalCost = 8;
		plankCost = 20;
		plankCost2 = 20;
		plankCost3 = 10;

		slot_id = InventorySlots.GetSlotIdFromString(slotNails99_1);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotNails75);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotMetalSheets10);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotMetal8);
		slot_id5 = InventorySlots.GetSlotIdFromString(slotPlanks20_2);
		slot_id6 = InventorySlots.GetSlotIdFromString(slotPlanks20_3);
		slot_id7 = InventorySlots.GetSlotIdFromString(slotPlanks10);
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );
		slotCast5 = ItemBase.Cast( GetInventory().FindAttachment(slot_id5) );
		slotCast6 = ItemBase.Cast( GetInventory().FindAttachment(slot_id5) );
		slotCast7 = ItemBase.Cast( GetInventory().FindAttachment(slot_id5) );
		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();
		j_Count3 = slotCast3.GetQuantity();
		j_Count4 = slotCast4.GetQuantity();
		j_Count5 = slotCast5.GetQuantity();
		j_Count6 = slotCast5.GetQuantity();
		j_Count7 = slotCast5.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL && slotCast5 != NULL && slotCast6 != NULL && slotCast7 != NULL)
		{
			if( j_Count >= nailCost && j_Count2 >= nailCost2 && j_Count3 >= metalsheetsCost && j_Count4 >= metalCost && j_Count5 >= plankCost && j_Count6 >= plankCost2 && j_Count7 >= plankCost3)
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override string j_Door()
	{
		if ( hasTheGoodStuff() )
		{
			return "BB_MediumShack";
		}
		return "BB_MediumShack_Kit";
	}

	override void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods.SetQuantity(20);
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods2.SetQuantity(20);
		ItemBase j_goods3 = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods3.SetQuantity(10);
		ItemBase j_goods4 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods4.SetQuantity(99);
		ItemBase j_goods5 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods5.SetQuantity(75);
		ItemBase j_goods6 = ItemBase.Cast(GetInventory().CreateAttachment("PB_SmallMetalPlate" ));
		j_goods6.SetQuantity(8);
		ItemBase j_goods7 = ItemBase.Cast(GetInventory().CreateAttachment("MetalPlate" ));
		j_goods7.SetQuantity(10);
	}
};
//Large Shack Kit
class BB_LargeShack_Kit extends MoreDoorKitBase
{
	override bool hasTheGoodStuff()
	{
		nailCost = 99;
		nailCost2= 99;
		nailCost3= 75;
		metalsheetsCost = 20;
		metalCost = 16;
		plankCost = 20;
		plankCost2 = 20;
		plankCost3 = 20;

		slot_id = InventorySlots.GetSlotIdFromString(slotNails99_1);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotNails99_2);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotNails75);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotMetalSheets20);
		slot_id5 = InventorySlots.GetSlotIdFromString(slotMetal16);
		slot_id6 = InventorySlots.GetSlotIdFromString(slotPlanks20_2);
		slot_id7 = InventorySlots.GetSlotIdFromString(slotPlanks20_3);
		slot_id8 = InventorySlots.GetSlotIdFromString(slotPlanks20_4);
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );
		slotCast5 = ItemBase.Cast( GetInventory().FindAttachment(slot_id5) );
		slotCast6 = ItemBase.Cast( GetInventory().FindAttachment(slot_id6) );
		slotCast7 = ItemBase.Cast( GetInventory().FindAttachment(slot_id7) );
		slotCast8 = ItemBase.Cast( GetInventory().FindAttachment(slot_id8) );
		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();
		j_Count3 = slotCast3.GetQuantity();
		j_Count4 = slotCast4.GetQuantity();
		j_Count5 = slotCast5.GetQuantity();
		j_Count6 = slotCast6.GetQuantity();
		j_Count7 = slotCast7.GetQuantity();
		j_Count8 = slotCast8.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL && slotCast5 != NULL && slotCast6 != NULL && slotCast7 != NULL && slotCast8 != NULL)
		{
			if( j_Count >= nailCost && j_Count2 >= nailCost2 && j_Count3 >= nailCost3 && j_Count4 >= metalsheetsCost && j_Count5 >= metalCost && j_Count6 >= plankCost && j_Count7 >= plankCost2 && j_Count8 >= plankCost3)
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override string j_Door()
	{
		if ( hasTheGoodStuff() )
		{
			return "BB_LargeShack";
		}
		return "BB_LargeShack_Kit";
	}

	override void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods.SetQuantity(20);
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods2.SetQuantity(20);
		ItemBase j_goods3 = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods3.SetQuantity(20);
		ItemBase j_goods4 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods4.SetQuantity(99);
		ItemBase j_goods5 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods5.SetQuantity(99);
		ItemBase j_goods6 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods6.SetQuantity(75);
		ItemBase j_goods7 = ItemBase.Cast(GetInventory().CreateAttachment("PB_SmallMetalPlate" ));
		j_goods7.SetQuantity(16);
		ItemBase j_goods8 = ItemBase.Cast(GetInventory().CreateAttachment("MetalPlate" ));
		j_goods8.SetQuantity(20);
	}
};
//Huge Shack Kit
class BB_HugeShack_Kit extends MoreDoorKitBase
{
	override bool hasTheGoodStuff()
	{
		nailCost = 99;
		nailCost2= 99;
		nailCost3= 99;
		metalsheetsCost = 10;
		metalsheetsCost2 = 20;
		metalCost = 16;
		plankCost = 20;
		plankCost2 = 20;
		plankCost3 = 20;
		plankCost4 = 10;

		slot_id = InventorySlots.GetSlotIdFromString(slotNails99_1);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotNails99_2);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotNails99_3);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotMetalSheets10);
		slot_id5 = InventorySlots.GetSlotIdFromString(slotMetalSheets20);
		slot_id6 = InventorySlots.GetSlotIdFromString(slotMetal16);
		slot_id7 = InventorySlots.GetSlotIdFromString(slotPlanks20_2);
		slot_id8 = InventorySlots.GetSlotIdFromString(slotPlanks20_3);
		slot_id9 = InventorySlots.GetSlotIdFromString(slotPlanks20_4);
		slot_id10 = InventorySlots.GetSlotIdFromString(slotPlanks10);
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );
		slotCast5 = ItemBase.Cast( GetInventory().FindAttachment(slot_id5) );
		slotCast6 = ItemBase.Cast( GetInventory().FindAttachment(slot_id6) );
		slotCast7 = ItemBase.Cast( GetInventory().FindAttachment(slot_id7) );
		slotCast8 = ItemBase.Cast( GetInventory().FindAttachment(slot_id8) );
		slotCast9 = ItemBase.Cast( GetInventory().FindAttachment(slot_id9) );
		slotCast10 = ItemBase.Cast( GetInventory().FindAttachment(slot_id10) );
		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();
		j_Count3 = slotCast3.GetQuantity();
		j_Count4 = slotCast4.GetQuantity();
		j_Count5 = slotCast5.GetQuantity();
		j_Count6 = slotCast6.GetQuantity();
		j_Count7 = slotCast7.GetQuantity();
		j_Count8 = slotCast8.GetQuantity();
		j_Count9 = slotCast9.GetQuantity();
		j_Count10 = slotCast10.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL && slotCast5 != NULL && slotCast6 != NULL && slotCast7 != NULL && slotCast8 != NULL && slotCast9 != NULL && slotCast10 != NULL)
		{
			if( j_Count >= nailCost && j_Count2 >= nailCost2 && j_Count3 >= nailCost3 && j_Count4 >= metalsheetsCost && j_Count5 >= metalsheetsCost2 && j_Count6 >= metalCost && j_Count7 >= plankCost && j_Count8 >= plankCost2 && j_Count9 >= plankCost3 && j_Count10 >= plankCost4)
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override string j_Door()
	{
		if ( hasTheGoodStuff() )
		{
			return "BB_HugeShack";
		}
		return "BB_HugeShack_Kit";
	}

	override void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods.SetQuantity(20);
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods2.SetQuantity(20);
		ItemBase j_goods3 = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods3.SetQuantity(20);
		ItemBase j_goods4 = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods4.SetQuantity(20);
		ItemBase j_goods5 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods5.SetQuantity(99);
		ItemBase j_goods6 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods6.SetQuantity(99);
		ItemBase j_goods7 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods7.SetQuantity(99);
		ItemBase j_goods8 = ItemBase.Cast(GetInventory().CreateAttachment("PB_SmallMetalPlate" ));
		j_goods8.SetQuantity(24);
		ItemBase j_goods9 = ItemBase.Cast(GetInventory().CreateAttachment("MetalPlate" ));
		j_goods9.SetQuantity(20);
		ItemBase j_goods10 = ItemBase.Cast(GetInventory().CreateAttachment("MetalPlate" ));
		j_goods10.SetQuantity(10);
	}
};
//Watchtower Kit
class BB_WatchTower_Kit extends MoreDoorKitBase
{
	override bool hasTheGoodStuff()
	{
		nailCost = 99;
		nailCost2= 99;
		nailCost3= 99;
		metalsheetsCost = 10;
		metalsheetsCost2 = 20;
		metalCost = 24;
		plankCost = 20;
		plankCost2 = 20;
		plankCost3 = 20;
		plankCost4 = 10;

		slot_id = InventorySlots.GetSlotIdFromString(slotNails99_1);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotNails99_2);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotNails99_3);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotMetalSheets10);
		slot_id5 = InventorySlots.GetSlotIdFromString(slotMetalSheets20);
		slot_id6 = InventorySlots.GetSlotIdFromString(slotMetal24);
		slot_id7 = InventorySlots.GetSlotIdFromString(slotPlanks20_2);
		slot_id8 = InventorySlots.GetSlotIdFromString(slotPlanks20_3);
		slot_id9 = InventorySlots.GetSlotIdFromString(slotPlanks20_4);
		slot_id10 = InventorySlots.GetSlotIdFromString(slotPlanks10);
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );
		slotCast5 = ItemBase.Cast( GetInventory().FindAttachment(slot_id5) );
		slotCast6 = ItemBase.Cast( GetInventory().FindAttachment(slot_id6) );
		slotCast7 = ItemBase.Cast( GetInventory().FindAttachment(slot_id7) );
		slotCast8 = ItemBase.Cast( GetInventory().FindAttachment(slot_id8) );
		slotCast9 = ItemBase.Cast( GetInventory().FindAttachment(slot_id9) );
		slotCast10 = ItemBase.Cast( GetInventory().FindAttachment(slot_id10) );
		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();
		j_Count3 = slotCast3.GetQuantity();
		j_Count4 = slotCast4.GetQuantity();
		j_Count5 = slotCast5.GetQuantity();
		j_Count6 = slotCast6.GetQuantity();
		j_Count7 = slotCast7.GetQuantity();
		j_Count8 = slotCast8.GetQuantity();
		j_Count9 = slotCast9.GetQuantity();
		j_Count10 = slotCast10.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL && slotCast5 != NULL && slotCast6 != NULL && slotCast7 != NULL && slotCast8 != NULL && slotCast9 != NULL && slotCast10 != NULL)
		{
			if( j_Count >= nailCost && j_Count2 >= nailCost2 && j_Count3 >= nailCost3 && j_Count4 >= metalsheetsCost && j_Count5 >= metalsheetsCost2 && j_Count6 >= metalCost && j_Count7 >= plankCost && j_Count8 >= plankCost2 && j_Count9 >= plankCost3 && j_Count10 >= plankCost4)
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override string j_Door()
	{
		if ( hasTheGoodStuff() )
		{
			return "BB_WatchTower";
		}
		return "BB_WatchTower_Kit";
	}

	override void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods.SetQuantity(20);
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods2.SetQuantity(20);
		ItemBase j_goods3 = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods3.SetQuantity(20);
		ItemBase j_goods4 = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods4.SetQuantity(20);
		ItemBase j_goods5 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods5.SetQuantity(99);
		ItemBase j_goods6 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods6.SetQuantity(99);
		ItemBase j_goods7 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods7.SetQuantity(99);
		ItemBase j_goods8 = ItemBase.Cast(GetInventory().CreateAttachment("PB_SmallMetalPlate" ));
		j_goods8.SetQuantity(24);
		ItemBase j_goods9 = ItemBase.Cast(GetInventory().CreateAttachment("MetalPlate" ));
		j_goods9.SetQuantity(20);
		ItemBase j_goods10 = ItemBase.Cast(GetInventory().CreateAttachment("MetalPlate" ));
		j_goods10.SetQuantity(10);
	}
};
//Garage Kit
class BB_Garage_Kit extends MoreDoorKitBase
{
	override bool hasTheGoodStuff()
	{
		nailCost = 99;
		nailCost2= 99;
		nailCost3= 75;
		metalsheetsCost = 20;
		metalCost = 16;
		plankCost = 20;
		plankCost2 = 20;
		plankCost3 = 20;

		slot_id = InventorySlots.GetSlotIdFromString(slotNails99_1);
		slot_id2 = InventorySlots.GetSlotIdFromString(slotNails99_2);
		slot_id3 = InventorySlots.GetSlotIdFromString(slotNails75);
		slot_id4 = InventorySlots.GetSlotIdFromString(slotMetalSheets20);
		slot_id5 = InventorySlots.GetSlotIdFromString(slotMetal16);
		slot_id6 = InventorySlots.GetSlotIdFromString(slotPlanks20_2);
		slot_id7 = InventorySlots.GetSlotIdFromString(slotPlanks20_3);
		slot_id8 = InventorySlots.GetSlotIdFromString(slotPlanks20_4);
		slotCast = ItemBase.Cast( GetInventory().FindAttachment(slot_id) );
		slotCast2 = ItemBase.Cast( GetInventory().FindAttachment(slot_id2) );
		slotCast3 = ItemBase.Cast( GetInventory().FindAttachment(slot_id3) );
		slotCast4 = ItemBase.Cast( GetInventory().FindAttachment(slot_id4) );
		slotCast5 = ItemBase.Cast( GetInventory().FindAttachment(slot_id5) );
		slotCast6 = ItemBase.Cast( GetInventory().FindAttachment(slot_id6) );
		slotCast7 = ItemBase.Cast( GetInventory().FindAttachment(slot_id7) );
		slotCast8 = ItemBase.Cast( GetInventory().FindAttachment(slot_id8) );
		j_Count = slotCast.GetQuantity();
		j_Count2 = slotCast2.GetQuantity();
		j_Count3 = slotCast3.GetQuantity();
		j_Count4 = slotCast4.GetQuantity();
		j_Count5 = slotCast5.GetQuantity();
		j_Count6 = slotCast6.GetQuantity();
		j_Count7 = slotCast7.GetQuantity();
		j_Count8 = slotCast8.GetQuantity();

		if( slotCast != NULL && slotCast2 != NULL && slotCast3 != NULL && slotCast4 != NULL && slotCast5 != NULL && slotCast6 != NULL && slotCast7 != NULL && slotCast8 != NULL)
		{
			if( j_Count >= nailCost && j_Count2 >= nailCost2 && j_Count3 >= nailCost3 && j_Count4 >= metalsheetsCost && j_Count5 >= metalCost && j_Count6 >= plankCost && j_Count7 >= plankCost2 && j_Count8 >= plankCost3)
			{
				return true;
			}
			return false;
		}
		return false;
	}

	override string j_Door()
	{
		if ( hasTheGoodStuff() )
		{
			return "BB_Garage";
		}
		return "BB_Garage_Kit";
	}

	override void ReturnGoodsFromDismantle()
	{
		ItemBase j_goods = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods.SetQuantity(20);
		ItemBase j_goods2 = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods2.SetQuantity(20);
		ItemBase j_goods3 = ItemBase.Cast(GetInventory().CreateAttachment("WoodenPlank" ));
		j_goods3.SetQuantity(20);
		ItemBase j_goods4 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods4.SetQuantity(99);
		ItemBase j_goods5 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods5.SetQuantity(99);
		ItemBase j_goods6 = ItemBase.Cast(GetInventory().CreateAttachment("Nail" ));
		j_goods6.SetQuantity(75);
		ItemBase j_goods7 = ItemBase.Cast(GetInventory().CreateAttachment("PB_SmallMetalPlate" ));
		j_goods7.SetQuantity(16);
		ItemBase j_goods8 = ItemBase.Cast(GetInventory().CreateAttachment("MetalPlate" ));
		j_goods8.SetQuantity(20);
	}
};