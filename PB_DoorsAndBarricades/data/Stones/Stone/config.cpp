class CfgPatches
{
	class PB_Stone
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};

class cfgVehicles
{
	class Inventory_Base;
	class PB_Stone: Inventory_Base
	{
		displayName = "Big Stone";
		descriptionShort = "";
		scope = 2;
		visibilityModifier = 0.6;
		model="PB_DoorsAndBarricades\data\Stones\Stone\textures\stone.p3d";
		weight=50000;
		itemSize[]={5,5};
		canBeSplit=1;
		varQuantityDestroyOnMin=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=32;
		varStackMax=1;
		//quantityBar=1;
		absorbency=0.2;
		physLayer="item_large";
		rotationFlags=12;
	};
};	