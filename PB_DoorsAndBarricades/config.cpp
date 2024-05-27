class CfgPatches
{
	class PB_DoorsAndBarricades
	{
		units[]=
		{
			"PB_PlankDoor_Kit",
			"PB_WoodDoor_Kit",
			"PB_MetalDoor_Kit",
			"PB_PlankBarricade_Kit",
			//"PB_PlankDoorBarricade_Kit",
			"PB_Well_Kit",
			//"PB_PlankWindow_Kit",
			//"PB_WoodGate_Kit",
			"PB_WoodWall_Kit",
			////////////////////////////////////////////
			///////////////OLDNAGS KITS//////////////////////
			////////////////////////////////////////////
			"BB_BaseWall_Kit",
			"BB_SmallShack_Kit",
			"BB_MediumShack_Kit",
			"BB_LargeShack_Kit",
			"BB_HugeShack_Kit",
			"BB_WatchTower_Kit",
			"BB_Garage_Kit",
			////////////////////////////////////////////
			///////////////OLDNAGS//////////////////////
			////////////////////////////////////////////
			"PB_PlankDoor",
			"PB_WoodDoor",
			"PB_MetalDoor",
			"PB_PlankBarricade",
			//"PB_MetalBarricade",
			//"PB_BrickBarricade",
			//"PB_PlankDoorBarricade",
			//"PB_MetalDoorBarricade",
			//"PB_BrickDoorBarricade",
			"PB_Well",
			//"PB_PlankWindow",
			//"PB_MetalWindow",
			//"PB_WoodGate",
			//"PB_MetalGate",
			"PB_WoodWall",
			//"PB_MetalWall",
			////////////////////////////////////////////
			///////////////OLDNAGS BASEPARTS//////////////////////
			////////////////////////////////////////////
			"BB_BaseWall",
			"BB_SmallShack",
			"BB_MediumShack",
			"BB_LargeShack",
			"BB_HugeShack",
			"BB_WatchTower",
			"BB_Garage"
			////////////////////////////////////////////
			///////////////OLDNAGS//////////////////////
			////////////////////////////////////////////
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Camping",
			"DZ_Scripts",
			"DZ_Gear_Tools",
			"DZ_Gear_Containers",
			"DZ_Weapons_Melee",
			"DZ_Gear_Medical",
			"DZ_Gear_Consumables"
		};
	};
};
class CfgMods
{
	class PB_DoorsAndBarricades
	{
		type = "mod";
		author = "spahgettah edits by oldnag";
		dir = "PB_DoorsAndBarricades";
		name = "PB_DoorsAndBarricades";
		dependencies[] =
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] =
				{
					"PB_DoorsAndBarricades/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] =
				{
					"PB_DoorsAndBarricades/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] =
				{
					"PB_DoorsAndBarricades/Scripts/5_Mission"
				};
			};
		};
	};
};
class CfgVehicles
{
	class Fence;
	class Inventory_Base;
	class Container_Base;
	class MoreDoorBase: Fence
	{
		scope = 0;
		displayName = "Door";
		descriptionShort = "$STR_CfgVehicles_Fence1";
		bounding = "BSphere";
		overrideDrawArea = "3.0";
		forceFarBubble = "true";
		handheld = "false";
		lootCategory = "Crafted";
		carveNavmesh = 1;
		weight = 10000;
		itemSize[] = {2,3};
		hiddenSelections[] =
		{
			"door1",
			"door2",
			"door3",
			"door4"
		};
		physLayer = "item_large";
		createProxyPhysicsOnInit = "false";
		createdProxiesOnInit[] = {"Deployed"};
		rotationFlags = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
		attachments[] =
		{
			"Att_CombinationLock"
		};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Base";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "cat_bb_base";
				selection = "wall";
			};
			class Attachments
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Attachments";
				description = "";
				attachmentSlots[] =
				{
					"Wall_Camonet",
					"Wall_Barbedwire_1",
					"Wall_Barbedwire_2"
				};
				icon = "cat_bb_attachments";
				selection = "wall";
			};
			class Material
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Materials";
				description = "";
				attachmentSlots[] =
				{
					"Material_Nails",
					"Material_WoodenPlanks",
					"Material_MetalSheets",
					"Material_MetalWire"
				};
				icon = "cat_bb_material";
				selection = "wall";
			};
		};
		class AnimationSources
		{
			class AnimSourceShown
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class AnimSourceHidden
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1;
			};
			class AnimRotate
			{
				source = "user";
				component = "Door1";
				animPeriod = 1.0;
				initPhase = 0;
				initOpened = 0.5;
			};
			class Wall_Interact_Rotate: AnimRotate{};
			class Wall_Barbedwire_1_Mounted_Rotate: AnimRotate{};
			class Wall_Barbedwire_2_Mounted_Rotate: AnimRotate{};
			class Wall_Camonet_Rotate: AnimRotate{};
			class Wall_Gate_Rotate: AnimRotate{};
			class Wall_Base_Down_Rotate: AnimRotate{};
			class Wall_Base_Up_Rotate: AnimRotate{};
			class Wall_Wood_Down_Rotate: AnimRotate{};
			class Wall_Wood_Up_Rotate: AnimRotate{};
			class Wall_Metal_Down_Rotate: AnimRotate{};
			class Wall_Metal_Up_Rotate: AnimRotate{};
			class Material_WoodenLogs: AnimSourceHidden{};
			class Material_MetalWire: AnimSourceHidden{};
			class Wall_Barbedwire_1: AnimSourceHidden{};
			class Wall_Barbedwire_1_Mounted: AnimSourceHidden{};
			class Wall_Barbedwire_2: AnimSourceHidden{};
			class Wall_Barbedwire_2_Mounted: AnimSourceHidden{};
			class Wall_Camonet: AnimSourceHidden{};
			class Deployed: AnimSourceHidden{};
			class Base: AnimSourceHidden{};
			class Wall_Platform: AnimSourceHidden{};
			class Wall_Platform_Stairs_Left: AnimSourceHidden{};
			class Wall_Platform_Stairs_Right: AnimSourceHidden{};
			class Wall_Gate: AnimSourceHidden{};
			class Wall_Base_Down: AnimSourceHidden{};
			class Wall_Base_Up: AnimSourceHidden{};
			class Wall_Metal_Down: AnimSourceHidden{};
			class Wall_Metal_Up: AnimSourceHidden{};
			class Wall_Wood_Down: AnimSourceHidden{};
			class Wall_Wood_Up: AnimSourceHidden{};
			class Windown2: AnimRotate{};
			class Fechadura: AnimRotate{};
		};
		class Construction
		{
			class wall
			{
				class wall_gate
				{
					name = "$STR_CfgVehicles_Construction_Part_Gate";
					is_gate = 1;
					id = 5;
					required_parts[] = {};
					conflicted_parts[] = {};
					collision_data[] = {};
					build_action_type = 1;
					dismantle_action_type = 1;
					material_type = 5;
				};
			};
		};
		class PointLights
		{
			class PointLight
			{
				color[] = {1,1,1,0.05};
				ambient[] = {0.01,0.01,0.01,0.01};
				position = "light";
				hitpoint = "bulb";
				selection = "bulb";
				size = 0;
				radius = 5;
				brightness = 0.001;
				dayLight = 1;
				heatHazeRadius = 0;
				heatHazePower = 0;
				fireEffect = 0;
				fireEffectOctaves = 0;
				fireEffectPersistence = 0;
				fireEffectFract = 0;
			};
		};
	};
	class MoreDoorKitBase: Container_Base
	{
		scope = 0;
		carveNavmesh = 1;
		itemSize[] = {6,3};
		itemBehaviour = 0;
		heavyItem = 1;
		physLayer = "item_large";
		simulation = "inventoryItem";
		rotationFlags = 2;
		isMeleeWeapon = 0;
		hiddenSelectionsTextures[] = {};
		hiddenSelectionsMaterials[] = {};
		handheld = "true";
		weight = 3000;
		useEntityHierarchy = "true";
		//placement = "ForceSlopeOnTerrain";
		absorbency = 0;
		attachments[] =
		{
			"Material_Nails",
			"Material_WoodenPlanks",
			"Material_MetalSheets",
			"Material_WoodenLogs",
			"Material_MetalWire",
			"Slot_Brick"
		};
	};
	
	//KIT PORTA DE MADEIRA - T2

	class PB_WoodDoor_Kit: MoreDoorKitBase
	{
		scope = 2;
		displayName = "Wood Door Kit | T2 |";
		descriptionShort = "Planks: 18 | Nails: 36 | MetalWire: 1 | Items must be exact, otherwise you will lose them after placing.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		attachments[] =
		{
			"Material_L2W2_Nails",
			"Material_L2W3_WoodenPlanks",
			"Material_MetalWire"
		};
	};

	//KIT PORTA DE PLANK - T1
	class PB_PlankDoor_Kit: MoreDoorKitBase
	{
		scope = 2;
		displayName = "Plank Door Kit | T1 |";
		descriptionShort = "Planks: 10 | Nails: 20 | MetalWire: 1 | Items must be exact, otherwise you will lose them after placing.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		attachments[] =
		{
			"Material_L2W1_Nails",
			"Material_L2W2_WoodenPlanks",
			"Material_MetalWire"
		};
	};

	//KIT PORTA DE METAL - T3
	class PB_MetalDoor_Kit: MoreDoorKitBase
	{
		scope = 2;
		displayName = "Metal Door Kit | T3 |";
		descriptionShort = "Planks: 20 | Nails: 75 | SmallMetalSheet: 16 | MetalWire: 1 | Items must be exact, otherwise you will lose them after placing.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		attachments[] =
		{
			"Material_L2W3_Nails",
			"Material_WoodenPlanks",
			"MetalSheets3",
			"Material_MetalWire"
		};
	};

	//KIT Barricada de Plank - T1
	class PB_PlankBarricade_Kit: MoreDoorKitBase
	{
		scope = 2;
		displayName = "Plank Barricade Kit | T1 |";
		descriptionShort = "Planks: 10 | Nails: 20 |  Use this to block your windows!  | Items must be exact, otherwise you will lose them after placing.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		attachments[] =
		{
			"Material_L2W1_Nails",
			"Material_L2W2_WoodenPlanks"
		};
	};

	//kit Wall - Kit Parede de Madeira - T1
	class PB_WoodWall_Kit: MoreDoorKitBase
	{
		scope = 2;
		displayName = "Wood Wall Kit | T1 |";
		descriptionShort = "Nails: 36 | WoodenLog: 4 | Items must be exact, otherwise you will lose them after placing.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		attachments[] =
		{
			"Material_L2W2_Nails",
			"Material_L1_WoodenLogs"
		};
	};
	
	//KIT Barricada de Plank para Porta - T1
	/* Disabled until new models have been made.
	class PB_PlankDoorBarricade_Kit: MoreDoorKitBase
	{
		scope = 2;
		displayName = "Plank Door Barricade Kit | T1 |";
		descriptionShort = "Planks: 10 | Nails: 20 |  Use this to block your Doors!  | Items must be exact, otherwise you will lose them after placing.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		attachments[] =
		{
			"Material_L2W1_Nails",
			"Material_L2W2_WoodenPlanks"
		};
	};
	*/

	//KIT WELL - POÇO DE AGUA PB_Well
	class PB_Well_Kit: MoreDoorKitBase
	{
		scope = 2;
		displayName = "Well Kit";
		descriptionShort = "Brick: 40 | Nails: 36 | WoodenLog: 2 | Planks: 20 | Items must be exact, otherwise you will lose them after placing.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		attachments[] =
		{
			"Material_L2W2_Nails",
			"Material_WoodenPlanks",
			"Material_WoodenLogs",
			"Slot_Brick"
		};
	};

	//KIT GATE - Portao de Madeira - T1
	/* Disabled until new models have been made.
	class PB_WoodGate_Kit: MoreDoorKitBase
	{
		scope = 2;
		displayName = "Wood Gate Kit | T1 |";
		descriptionShort = "Nails: 36 | WoodenLog: 2 | MetalWire: 1 | Planks: 20 | Items must be exact, otherwise you will lose them after placing.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		attachments[] =
		{
			"Material_L2W2_Nails",
			"Material_WoodenLogs",
			"Material_MetalWire",
			"Material_WoodenPlanks"
		};
	};

	//KIT Janela de Plank - T1
	class PB_PlankWindow_Kit: MoreDoorKitBase
	{
		scope = 2;
		displayName = "Plank Window Kit | T1 |";
		descriptionShort = "Planks: 10 | Nails: 20 | MetalWire: 1 |  Use this to block your windows!  | Items must be exact, otherwise you will lose them after placing.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		attachments[] =
		{
			"Material_L2W1_Nails",
			"Material_L2W2_WoodenPlanks",
			"Material_MetalWire"
		};
	};
	*/
	////////////////////////////////////////////
	///////////////OLDNAGS//////////////////////
	////////////////////////////////////////////
	class BB_SmallShackBlueprint: Inventory_Base
	{
		scope = 2;
		displayName = "Small Shack Blueprint";
		descriptionShort = "A blueprint for making a small shack.";
		model = "PB_DoorsAndBarricades\data\Fractal\Blueprint.p3d";
		itemSize[] = {3,1};
		varStackMax = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
	};
	class BB_MediumShackBlueprint: Inventory_Base
	{
		scope = 2;
		displayName = "Medium Shack Blueprint";
		descriptionShort = "A blueprint for making a medium sized shack.";
		model = "PB_DoorsAndBarricades\data\Fractal\Blueprint.p3d";
		itemSize[] = {3,1};
		varStackMax = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
	};
	class BB_LargeShackBlueprint: Inventory_Base
	{
		scope = 2;
		displayName = "Large Shack Blueprint";
		descriptionShort = "A blueprint for making a large shack.";
		model = "PB_DoorsAndBarricades\data\Fractal\Blueprint.p3d";
		itemSize[] = {3,1};
		varStackMax = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
	};
	class BB_HugeShackBlueprint: Inventory_Base
	{
		scope = 2;
		displayName = "Huge Shack Blueprint";
		descriptionShort = "A blueprint for making a huge shack.";
		model = "PB_DoorsAndBarricades\data\Fractal\Blueprint.p3d";
		itemSize[] = {3,1};
		varStackMax = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
	};
	class BB_WatchTowerBlueprint: Inventory_Base
	{
		scope = 2;
		displayName = "Watch Tower Blueprint";
		descriptionShort = "A blueprint for making a watchtower.";
		model = "PB_DoorsAndBarricades\data\Fractal\Blueprint.p3d";
		itemSize[] = {3,1};
		varStackMax = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
	};
	class BB_GarageBlueprint: Inventory_Base
	{
		scope = 2;
		displayName = "Garage Blueprint";
		descriptionShort = "A blueprint for making a garage.";
		model = "PB_DoorsAndBarricades\data\Fractal\Blueprint.p3d";
		itemSize[] = {3,1};
		varStackMax = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
	};
	class BB_ToolBox: Inventory_Base
	{
		scope = 2;
		displayName = "Toolbox";
		descriptionShort = "Used in creation of shack kits.";
		model = "PB_DoorsAndBarricades\data\Fractal\ToolBox.p3d";
		itemSize[] = {4,3};
		varStackMax = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
				};
			};
		};
	};
	class BB_BaseWall_Kit: MoreDoorKitBase
	{
		scope = 2;
		displayName = "Base Wall Kit";
		descriptionShort = "A kit to create a wall fortification.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		attachments[] =
		{
			"Material_L2W2_Nails",
			"Material_WoodenLogs"
		};
	};
	class BB_SmallShack_Kit: MoreDoorKitBase
	{
		scope = 2;
		displayName = "Small Shack Kit";
		descriptionShort = "A kit to create a small shack.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		attachments[] =
		{
			"Material_L3W1_Nails",
			"Material_L3W1_MetalSheets",
			"MetalSheets1",
			"Material_L3W1_WoodenPlanks",
			"Material_L3W2_WoodenPlanks"
		};
	};
	class BB_MediumShack_Kit: MoreDoorKitBase
	{
		scope = 2;
		displayName = "Medium Shack Kit";
		descriptionShort = "A kit to create a medium sized shack.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		attachments[] =
		{
			"Material_L3W1_Nails",
			"Material_L2W3_Nails",
			"Material_L2W1_MetalSheets",
			"MetalSheets2",
			"Material_L3W1_WoodenPlanks",
			"Material_L3W2_WoodenPlanks",
		};
	};
	class BB_LargeShack_Kit: MoreDoorKitBase
	{
		scope = 2;
		displayName = "Large Shack Kit";
		descriptionShort = "A kit to create a large sized shack.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		attachments[] =
		{
			"Material_L3W1_Nails",
			"Material_L3W2_Nails",
			"Material_L2W3_Nails",
			"Material_L2W2_MetalSheets",
			"MetalSheets3",
			"Material_L3W1_WoodenPlanks",
			"Material_L3W2_WoodenPlanks",
			"Material_L3W3_WoodenPlanks"
		};
	};
	class BB_HugeShack_Kit: MoreDoorKitBase
	{
		scope = 2;
		displayName = "Huge Shack Kit";
		descriptionShort = "A kit to create a large sized shack.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		attachments[] =
		{
			"Material_L3W1_Nails",
			"Material_L3W2_Nails",
			"Material_L3W3_Nails",
			"Material_L2W1_MetalSheets",
			"Material_L2W2_MetalSheets",
			"MetalSheets3",
			"Material_L3W1_WoodenPlanks",
			"Material_L3W2_WoodenPlanks",
			"Material_L3W3_WoodenPlanks",
			"Material_L2W2_WoodenPlanks"
		};
	};
	class BB_WatchTower_Kit: MoreDoorKitBase
	{
		scope = 2;
		displayName = "Watch Tower Kit";
		descriptionShort = "A kit to create a watch tower.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		attachments[] =
		{
			"Material_L3W1_Nails",
			"Material_L3W2_Nails",
			"Material_L3W3_Nails",
			"Material_L2W1_MetalSheets",
			"Material_L2W2_MetalSheets",
			"MetalSheets4",
			"Material_L3W1_WoodenPlanks",
			"Material_L3W2_WoodenPlanks",
			"Material_L3W3_WoodenPlanks",
			"Material_L2W2_WoodenPlanks"
		};
	};
	class BB_Garage_Kit: MoreDoorKitBase
	{
		scope = 2;
		displayName = "Garage Kit";
		descriptionShort = "A kit to create a large sized garage.";
		model = "\DZ\gear\camping\wooden_case.p3d";
		attachments[] =
		{
			"Material_L3W1_Nails",
			"Material_L3W2_Nails",
			"Material_L2W3_Nails",
			"Material_L2W2_MetalSheets",
			"MetalSheets3",
			"Material_L3W1_WoodenPlanks",
			"Material_L3W2_WoodenPlanks",
			"Material_L3W3_WoodenPlanks"
		};
	};
	////////////////////////////////////////////
	///////////////OLDNAGS//////////////////////
	////////////////////////////////////////////

	//Porta de MAdeira T2

	class PB_WoodDoor: MoreDoorBase
	{
		scope = 2;
		displayName = "Wood Door | T2 |";
		descriptionShort = "Wood Door | T2 |.";
		model = "PB_DoorsAndBarricades\data\Wood\WoodDoor.p3d";
		attachments[] =
		{
			"Att_CombinationLock"
		};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Base";
				description = "";
				attachmentSlots[] =
				{
					"Att_CombinationLock"
				};
				icon = "cat_bb_base";
				selection = "wall";
			};
		};
	};
	
	class PB_PlankDoor: MoreDoorBase
	{
		scope = 2;
		displayName = "Plank Door | T1 |";
		descriptionShort = "Plank Door | T1 |";
		model = "PB_DoorsAndBarricades\data\Wood\WoodPlankDoor.p3d";
		attachments[] =
		{
			"Att_CombinationLock"
		};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Base";
				description = "";
				attachmentSlots[] =
				{
					"Att_CombinationLock"
				};
				icon = "cat_bb_base";
				selection = "wall";
			};
		};
	};

	//Porta de Metal T3
	class PB_MetalDoor: MoreDoorBase
	{
		scope = 2;
		displayName = "Metal Door";
		descriptionShort = "Metal Door";
		model = "PB_DoorsAndBarricades\data\Metal\MetalDoor.p3d";
		attachments[] = {"Att_CombinationLock"};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Base";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "cat_bb_base";
				selection = "wall";
			};
		};
	};

	//Barricada de Madeira T1
	class PB_PlankBarricade: MoreDoorBase
	{
		scope = 2;
		displayName = "Plank Barricade | T1 |";
		descriptionShort = "Just A Barricade, you must be bored if your bothering to read the description on some door...";
		model = "PB_DoorsAndBarricades\data\Wood\PlankBarricade.p3d";
		attachments[] = {"MetalSheets1"};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "Upgrade";
				description = "";
				attachmentSlots[] = {"MetalSheets1"};
				icon = "cat_bb_material";
				selection = "wall";
			};
		};
	};
	/* Disabled until new models have been made.
	//Barricada de Metal T2
	class PB_MetalBarricade: MoreDoorBase
	{
		scope = 2;
		displayName = "Metal Barricade | T2 |";
		descriptionShort = "Just A Barricade, you must be bored if your bothering to read the description on some door...";
		model = "PB_DoorsAndBarricades\data\Metal\MetalBarricade.p3d";
		attachments[] = {"Slot_Brick10"};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "Upgrade";
				description = "";
				attachmentSlots[] = {"Slot_Brick10"};
				icon = "cat_bb_material";
				selection = "wall";
			};
		};
	};

	//Brick - Barricada de pedra T3

	class PB_BrickBarricade: MoreDoorBase
	{
		scope = 2;
		displayName = "Brick Barricade | T3 |";
		descriptionShort = "Just A Barricade, you must be bored if your bothering to read the description on some door...";
		model = "PB_DoorsAndBarricades\data\Brick\BrickBarricade.p3d";
		class GUIInventoryAttachmentsProps{};
	};
	*/

	//PAREDES
	//Brick parede de Pedra T3
	class PB_WoodWall: MoreDoorBase
	{
		scope = 2;
		displayName = "Wood Wall | T1 |";
		descriptionShort = "Just A Wall, you must be bored if your bothering to read the description on some door...";
		model = "PB_DoorsAndBarricades\data\Wood\WoodWall.p3d";
		//attachments[] = {"MetalSheets4"};
		class GUIInventoryAttachmentsProps
		{
			/*
			class Base
			{
				name = "Upgrade";
				description = "";
				attachmentSlots[] = {"MetalSheets4"};
				icon = "cat_bb_material";
				selection = "wall";
			};
			*/
		};
	};

	//Barricada Madeira para Porta - T1
	/* Disabled until new models have been made.
	class PB_MetalWall: MoreDoorBase
	{
		scope = 2;
		displayName = "Metal Wall | T2 |";
		descriptionShort = "Just A Wall, you must be bored if your bothering to read the description on some door...";
		model = "PB_DoorsAndBarricades\data\Metal\MetalWall.p3d";
		attachments[] = {"Slot_Brick"};
		class GUIInventoryAttachmentsProps
		{
			/*class Base //Aguardar o p3d da Parede de pedra ser arrumada
			{
				name = "Upgrade";
				description = "";
				attachmentSlots[] = {"Slot_Brick"};
				icon = "cat_bb_material";
				selection = "wall";
			};*/ /*
		};
	};
*/
	//Barricada Madeira para Porta - T1
	/* Disabled until new models have been made.
	class PB_PlankDoorBarricade: MoreDoorBase
	{
		scope = 2;
		displayName = "Plank Door Barricade | T1 |";
		descriptionShort = "Just A Barricade, you must be bored if your bothering to read the description on some door...";
		model = "PB_DoorsAndBarricades\data\Wood\WoodDoorBarricade.p3d";
		attachments[] = {"MetalSheets2"};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "Upgrade";
				description = "";
				attachmentSlots[] = {"MetalSheets2"};
				icon = "cat_bb_material";
				selection = "wall";
			};
		};
	};

	//Barricada Metal para Porta - T2
	class PB_MetalDoorBarricade: MoreDoorBase
	{
		scope = 2;
		displayName = "Metal Door Barricade | T2 |";
		descriptionShort = "Just A Barricade, you must be bored if your bothering to read the description on some door...";
		model = "PB_DoorsAndBarricades\data\Metal\MetalDoorBarricade.p3d";
		attachments[] = {"Slot_Brick18"};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "Upgrade";
				description = "";
				attachmentSlots[] = {"Slot_Brick18"};
				icon = "cat_bb_material";
				selection = "wall";
			};
		};
	};

	//Barricada de Pedra para Porta - T3
	class PB_BrickDoorBarricade: MoreDoorBase
	{
		scope = 2;
		displayName = "Brick Door Barricade | T3 |";
		descriptionShort = "Just A Barricade, you must be bored if your bothering to read the description on some door...";
		model = "PB_DoorsAndBarricades\data\Brick\BrickDoorBarricade.p3d";
		attachments[] = {"Stones"};
		class GUIInventoryAttachmentsProps{};
	};
	*/
	//Well - Poço
	class PB_Well: Inventory_Base
	{
		scope = 2;
		displayName = "Stone Well";
		descriptionShort = "A Stone Well to drink water";
		model = "PB_DoorsAndBarricades\data\Well\Well.p3d";
		weight = 10000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		physLayer = "item_large";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0;
					};
				};
			};
		};
	};

	//Janela de Plank - T1
	/* Disabled until new models have been made.
	class PB_PlankWindow: MoreDoorBase
	{
		scope = 2;
		displayName = "Plank Window | T1 |";
		descriptionShort = "Plank Window | T1 |";
		model = "PB_DoorsAndBarricades\data\Windows\PlankWindow.p3d";
		attachments[] =
		{
			"MetalSheets1",
			"Att_CombinationLock"
		};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "Upgrade";
				description = "";
				attachmentSlots[] = {"MetalSheets1"};
				icon = "cat_bb_material";
				selection = "wall";
			};
			class Lock
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Base";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "cat_bb_base";
				selection = "wall";
			};
		};
	};

	//Janela de Metal - T2
	
	class PB_MetalWindow: MoreDoorBase
	{
		scope = 2;
		displayName = "Metal Window | T2 |";
		descriptionShort = "Metal Window | T2 |";
		model = "PB_DoorsAndBarricades\data\Windows\MetalWindow.p3d";
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Base";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "cat_bb_base";
				selection = "wall";
			};
		};
	};
	
	
	class PB_WoodGate: MoreDoorBase
	{
		scope = 2;
		displayName = "Wood Gate | T1 |";
		descriptionShort = "Wood Gate | T1 |";
		model = "PB_DoorsAndBarricades\data\Gates\WoodGate.p3d";
		attachments[] =
		{
			"Att_CombinationLock",
			"MetalSheets4"
		};
		class GUIInventoryAttachmentsProps
		{
			class Lock
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Base";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "cat_bb_base";
				selection = "wall";
			};
			class Base
			{
				name = "Upgrade";
				description = "";
				attachmentSlots[] = {"MetalSheets4"};
				icon = "cat_bb_material";
				selection = "wall";
			};
		};
	};
	
	//MetalGate
	class PB_MetalGate: MoreDoorBase
	{
		scope = 2;
		displayName = "Metal Gate | T2 |";
		descriptionShort = "Metal Gate | T2 |";
		model = "PB_DoorsAndBarricades\data\Gates\MetalGate.p3d";
		attachments[] = {"Att_CombinationLock"};
		class GUIInventoryAttachmentsProps
		{
			class Base
			{
				name = "$STR_CfgVehicles_Fence_Att_Category_Base";
				description = "";
				attachmentSlots[] = {"Att_CombinationLock"};
				icon = "cat_bb_base";
				selection = "wall";
			};
		};
	};
	*/
	////////////////////////////////////////////
	///////////////OLDNAGS//////////////////////
	////////////////////////////////////////////


	class BB_BaseWall: MoreDoorBase
	{
		scope = 2;
		displayName = "Wall Fortification";
		descriptionShort = "A wall to protect your camp.";
		model = "PB_DoorsAndBarricades\data\Fractal\Base_Wall.p3d";
		attachments[] = {};
		class GUIInventoryAttachmentsProps{};
		alignHologramToTerain=0;
	};
	class BB_SmallShack: MoreDoorBase
	{
		scope = 2;
		displayName = "Small Shack";
		descriptionShort = "A nice small shack.";
		model = "PB_DoorsAndBarricades\data\Fractal\Shack_01.p3d";
		attachments[] = {};
		class GUIInventoryAttachmentsProps{};
		alignHologramToTerain=0;
	};
	class BB_MediumShack: MoreDoorBase
	{
		scope = 2;
		displayName = "Medium Shack";
		descriptionShort = "A medium sized shack.";
		model = "PB_DoorsAndBarricades\data\Fractal\Shack_02.p3d";
		attachments[] = {};
		class GUIInventoryAttachmentsProps{};
		alignHologramToTerain=0;
	};
	class BB_LargeShack: MoreDoorBase
	{
		scope = 2;
		displayName = "Large Shack";
		descriptionShort = "A large sized shack.";
		model = "PB_DoorsAndBarricades\data\Fractal\Shack_03.p3d";
		attachments[] = {};
		class GUIInventoryAttachmentsProps{};
		alignHologramToTerain=0;
	};
	class BB_HugeShack: MoreDoorBase
	{
		scope = 2;
		displayName = "Huge Shack";
		descriptionShort = "A Huge sized shack.";
		model = "PB_DoorsAndBarricades\data\Fractal\Shack_04.p3d";
		attachments[] = {};
		class GUIInventoryAttachmentsProps{};
		alignHologramToTerain=0;
	};
	class BB_WatchTower: MoreDoorBase
	{
		scope = 2;
		displayName = "Watch Tower";
		descriptionShort = "A watch tower.";
		model = "PB_DoorsAndBarricades\data\Fractal\Tower.p3d";
		attachments[] = {};
		class GUIInventoryAttachmentsProps{};
	};
	class BB_Garage: MoreDoorBase
	{
		scope = 2;
		displayName = "Garage";
		descriptionShort = "A large sized garage.";
		model = "PB_DoorsAndBarricades\data\Fractal\Garage.p3d";
		attachments[] = {};
		class GUIInventoryAttachmentsProps{};
	};
	////////////////////////////////////////////
	///////////////OLDNAGS//////////////////////
	////////////////////////////////////////////
};
class CfgSlots
{
	class Slot_MetalSheets1
	{
		name = "MetalSheets1";
		displayName = "Small Metal Sheet";
		ghosticon = "set:dayz_inventory image:plates";
		stackMax = 4;
	};
	class Slot_MetalSheets2
	{
		name = "MetalSheets2";
		displayName = "Small Metal Sheet";
		ghosticon = "set:dayz_inventory image:plates";
		stackMax = 8;
	};
	class Slot_MetalSheets3
	{
		name = "MetalSheets3";
		displayName = "Small Metal Sheet";
		ghosticon = "set:dayz_inventory image:plates";
		stackMax = 16;
	};
	class Slot_MetalSheets4
	{
		name = "MetalSheets4";
		displayName = "Small Metal Sheet";
		ghosticon = "set:dayz_inventory image:plates";
		stackMax = 24;
	};

	//Planks

	class Slot_Material_L2W2_WoodenPlanks
	{
		name = "Material_L2W2_WoodenPlanks";
		displayName = "Wooden planks";
		ghosticon = "set:dayz_inventory image:planks";
		stackMax = 10;
	};

	//Nails

	class Slot_Material_L2W1_Nails
	{
		name = "Material_L2W1_Nails";
		displayName = "Nails";
		ghosticon = "nails";
		stackMax = 20;
	};
	class Slot_Material_L2W2_Nails
	{
		name = "Material_L2W2_Nails";
		displayName = "Nails";
		ghosticon = "nails";
		stackMax = 36;
	};
	class Slot_Material_L2W3_Nails
	{
		name = "Material_L2W3_Nails";
		displayName = "Nails";
		ghosticon = "nails";
		stackMax = 75;
	};
	////////////////////////////////////////////
	///////////////OLDNAGS//////////////////////
	////////////////////////////////////////////
	class Slot_Material_L3W1_Nails
	{
		name = "Material_L3W1_Nails";
		displayName = "Nails";
		ghosticon = "nails";
		stackMax = 99;
	};
	class Slot_Material_L3W2_Nails
	{
		name = "Material_L3W2_Nails";
		displayName = "Nails";
		ghosticon = "nails";
		stackMax = 99;
	};
	class Slot_Material_L3W3_Nails
	{
		name = "Material_L3W3_Nails";
		displayName = "Nails";
		ghosticon = "nails";
		stackMax = 99;
	};
	class Slot_Material_L3W1_MetalSheets
	{
		name = "Material_L3W1_MetalSheets";
		displayName = "Metal sheets";
		ghosticon = "plates";
		stackMax = 5;
	};
	class Slot_Material_L2W1_MetalSheets
	{
		name = "Material_L2W1_MetalSheets";
		displayName = "Metal sheets";
		ghosticon = "plates";
		stackMax = 10;
	};
	class Slot_Material_L2W2_MetalSheets
	{
		name = "Material_L2W2_MetalSheets";
		displayName = "Metal sheets";
		ghosticon = "plates";
		stackMax = 20;
	};
	class Slot_Material_L2W1_WoodenPlanks
	{
		name = "Material_L2W1_WoodenPlanks";
		displayName = "Wooden planks";
		ghosticon = "planks";
		stackMax = 20;
	};
	class Slot_Material_L3W1_WoodenPlanks
	{
		name = "Material_L3W1_WoodenPlanks";
		displayName = "Wooden planks";
		ghosticon = "planks";
		stackMax = 20;
	};
	class Slot_Material_L3W2_WoodenPlanks
	{
		name = "Material_L3W2_WoodenPlanks";
		displayName = "Wooden planks";
		ghosticon = "planks";
		stackMax = 20;
	};
	class Slot_Material_L3W3_WoodenPlanks
	{
		name = "Material_L3W3_WoodenPlanks";
		displayName = "Wooden planks";
		ghosticon = "planks";
		stackMax = 20;
	};
	////////////////////////////////////////////
	///////////////OLDNAGS//////////////////////
	////////////////////////////////////////////
};
