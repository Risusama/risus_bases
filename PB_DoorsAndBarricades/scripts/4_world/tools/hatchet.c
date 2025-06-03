modded class Hatchet extends ToolBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDismantleMoreDoor);
	}
};

modded class Crowbar
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDismantleMoreDoor);
	}
};

modded class Hammer
{
	override void SetActions()
	{
		super.SetActions();
		//Window Barricades
		AddAction(ActionUpgradeBarricade);
		AddAction(ActionUpgradeBarricadeT3);
		//Door Barricades
		AddAction(ActionUpgradeDoorBarricade);
		AddAction(ActionUpgradeDoorBarricadeT3);
		//Windows
		AddAction(ActionUpgradeWindow);
		//Walls
		AddAction(ActionUpgradeWall);
		//AddAction(ActionUpgradeWallT3);
		//Gates
		AddAction(ActionUpgradeGate);
	}
};

modded class Shovel
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDismantleWell);
	}
};