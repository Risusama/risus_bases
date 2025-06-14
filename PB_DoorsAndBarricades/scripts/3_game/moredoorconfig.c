class PBConfig
{
	//static const string MODCONFIG_ROOT_FOLDER = "$profile:MoreDoors/";
    //static const string CONFIG_PATH = MODCONFIG_ROOT_FOLDER + "MoorDoors_Settings.json";
	static const string MODCONFIG_ROOT_FOLDER = "$profile:PBDoors/";
    static const string CONFIG_PATH = MODCONFIG_ROOT_FOLDER + "PBDoors_Settings.json";

	private bool CanDestroyPBDoor = true;
	private bool CanCutComboLock = true;
	private bool CanCraftDoorKits = true;
	private bool CanCraftBarricadesKits = true;
	private bool CanCraftShackKits = true;
	private ref array<string> RaidToolsT1eT2;
	private ref array<string> RaidToolsT3;
	private ref array<string> CarDestroyPartsTools;
	private int PB_DestroyTime;
    private int PB_DismantleTime;
	private int PB_ToolDamage;
	//Door T1 = Plank / T2 = Wood / T3 = Metal
	private int T1DoorDestroyTime;
	private int T2DoorDestroyTime;
	private int T3DoorDestroyTime;
	//Barricades and walls T1 = Plank / T2 = Metal / T3 = Brick
	private int T1BarricadeAndWallDestroyTime;
	private int T2BarricadeAndWallDestroyTime;
	private int T3BarricadeAndWallDestroyTime;
	//Dial lock destroy time
	private int DialLockDestroyTime;
	//Gates and Walls
	private int T1GateWallDestroyTime;
	private int T2GateWallDestroyTime;
	//private int MoreDoorMetalBarricadeDestroyTime;
	//Add a new Integer to be the destruction value


	void PBConfig()
	{
		if (!GetGame().IsServer()) return;

		if (!FileExist(MODCONFIG_ROOT_FOLDER))
        {
            Print("[MoreDoorConfg] '" + MODCONFIG_ROOT_FOLDER + "' does NOT exist, creating directory!");
            MakeDirectory(MODCONFIG_ROOT_FOLDER);
        }

        if (!FileExist(CONFIG_PATH))
        {
            Print("[PBConfig] '" + CONFIG_PATH + "' does NOT exist, creating default config!");
            Default();
            return;
        }

        Load();
    }

	bool Load()
    {
        if (FileExist(CONFIG_PATH))
        {
            Print("[PBConfig] '" + CONFIG_PATH + "' found, loading existing config!");
            JsonFileLoader<PBConfig>.JsonLoadFile(CONFIG_PATH, this);
            return true;
        }
        return false;
    }

	protected void Save()
    {
        JsonFileLoader<PBConfig>.JsonSaveFile(CONFIG_PATH, this);
    }

	protected void Default()
    {
		CanDestroyPBDoor = true;
		CanCutComboLock = true;
		CanCraftDoorKits = true;
		CanCraftBarricadesKits = true;
		CanCraftShackKits = true;
		CanCraftDoorKits = true;
		CanCraftDoorKits = true;

		RaidToolsT1eT2 = {"Sledgehammer", "FirefighterAxe", "WoodAxe"};
		RaidToolsT3 = {"Sledgehammer"};
		CarDestroyPartsTools = {"Sledgehammer"};
		PB_DismantleTime = 25;
		PB_ToolDamage = 25;
		PB_DestroyTime = 600;
		//Door T1 = Plank / T2 = Wood / T3 = Metal
		T1DoorDestroyTime = 180;	//180
		T2DoorDestroyTime = 600;	//600
		T3DoorDestroyTime = 1200;	//1200
		//Barricades and walls T1 = Plank / T2 = Metal / T3 = Brick
		T1BarricadeAndWallDestroyTime = 180;	//180
		T2BarricadeAndWallDestroyTime =	600;	//600
		T3BarricadeAndWallDestroyTime =	1200;	//1200
		//Gates and Walls
		T1GateWallDestroyTime = 600;
		T2GateWallDestroyTime = 1200;
		//Dial lock destroy time
		DialLockDestroyTime = 180;
		//Records the time of destruction, to create a new one add a new line here
		//MoreDoorMetalBarricadeDestroyTime = 1200;
		Save();
	}

	bool Get_CanDestroyMoreDoor()
	{
		return CanDestroyPBDoor;
	}

	bool Get_CanCutComboLock()
	{
		return CanCutComboLock;
	}

	bool Get_CanCraftDoorKits()
	{
		return CanCraftDoorKits;
	}

	bool Get_CanCraftBarricadesKits()
	{
		return CanCraftBarricadesKits;
	}

	bool Get_CanCraftShackKits()
	{
		return CanCraftShackKits;
	}

	ref array<string> Get_RaidToolsT1eT2()
	{
		return RaidToolsT1eT2;
	}

	ref array<string> Get_RaidToolsT3()
	{
		return RaidToolsT3;
	}

	ref array<string> Get_DestroyCarPartsTools()
	{
		return CarDestroyPartsTools;
	}

	int Get_MoreDoorDestroyTime(string item)
	{
		int destroyTime = -1;
		switch( item )
		{
			/*	Add Item Name in Case and Destroy time
			case "MoreDoor-------":
				destroyTime = MoreDoorMetalBarricadeDestroyTime;
				break;*/
			//Doors
			//T1
			case "PB_PlankDoor":
				destroyTime = T1DoorDestroyTime;
				break;
			//T2
			case "PB_WoodDoor":
				destroyTime = T2DoorDestroyTime;
				break;
			//T3
			case "PB_MetalDoor":
				destroyTime = T3DoorDestroyTime;
				break;
			//Barricades
			//T1
			case "PB_PlankBarricade":
				destroyTime = T1BarricadeAndWallDestroyTime;
				break;
			//T2
			case "PB_MetalBarricade":
				destroyTime = T2BarricadeAndWallDestroyTime;
				break;
			//T3
			case "PB_BrickBarricade":
				destroyTime = T3BarricadeAndWallDestroyTime;
				break;
			//Walls
			//T1
			case "PB_WoodWall":
				destroyTime = T1GateWallDestroyTime;
				break;
			//T2
			case "PB_MetalWall":
				destroyTime = T2GateWallDestroyTime;
				break;
			//T3
			//case "PB_BrickWall":
			//	destroyTime = T3BarricadeAndWallDestroyTime;
			//	break;
			//GATES
			//T1
			case "PB_WoodGate":
				destroyTime = T1GateWallDestroyTime;
				break;
			//T2
			case "PB_MetalGate":
				destroyTime = T2GateWallDestroyTime;
				break;
			//Door Barricades
			//T1
			case "PB_PlankDoorBarricade":
				destroyTime = T1BarricadeAndWallDestroyTime;
				break;
			//T2
			case "PB_MetalDoorBarricade":
				destroyTime = T2BarricadeAndWallDestroyTime;
				break;
			//T3
			case "PB_BrickDoorBarricade":
				destroyTime = T3BarricadeAndWallDestroyTime;
				break;
			//Window Barricades
			//T1
			case "PB_PlankWindow":
				destroyTime = T1BarricadeAndWallDestroyTime;
				break;
			//T2
			case "PB_MetalWindow":
				destroyTime = T2BarricadeAndWallDestroyTime;
				break;
			//Default if there is no predefined time
			default:
				destroyTime = PB_DestroyTime;
				break;
		}
		return destroyTime;
	}

	int Get_MoreDoorDismantleTime()
	{
		return PB_DismantleTime;
	}

	int Get_DialLockDestroyTime()
	{
		return DialLockDestroyTime;
	}

	int Get_MoreDoorToolDamage()
	{
		return PB_ToolDamage;
	}
};
