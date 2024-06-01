
modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);

        actions.Insert( ActionNextCombinationLockDialOnMoreDoor);
        actions.Insert( ActionCloseMoreDoor);
        actions.Insert( ActionOpenMoreDoor);
        actions.Insert( ActionDialCombinationLockOnMoreDoor);
        actions.Insert( ActionDismantleMoreDoor);
        actions.Insert( ActionDestroyCombinationLockMoreDoor);
        //
        actions.Insert( ActionUpgradeBarricade);
        actions.Insert( ActionUpgradeBarricadeT3 );
        //
        actions.Insert( ActionUpgradeDoorBarricade );
        actions.Insert( ActionUpgradeDoorBarricadeT3 );
        //
        actions.Insert( ActionUpgradeWindow );
        //
        actions.Insert( ActionDestroyT1eT2);
        actions.Insert( ActionDestroyT3 );
        //
        actions.Insert( ActionDismantleWell );
        //
        actions.Insert( ActionUpgradeWall );
        //
        actions.Insert( ActionUpgradeGate );
        //actions.Insert( ActionUpgradeWallT3 );
        //actions.Insert( ActionDisableMoreDoorDismantle);
    }
};
