modded class Hologram
{	
	override string ProjectionBasedOnParent()
	{
		MoreDoorKitBase item_in_hands = MoreDoorKitBase.Cast( m_Player.GetHumanInventory().GetEntityInHands() );

		if (item_in_hands)
		{
			return item_in_hands.j_Door();
		}

		return super.ProjectionBasedOnParent();
	}

	override EntityAI PlaceEntity( EntityAI entity_for_placing )
	{
		if (entity_for_placing.IsInherited(MoreDoorBase))
		{
			return entity_for_placing;
		}

		return super.PlaceEntity(entity_for_placing);
	}		

	override void EvaluateCollision(ItemBase action_item = null)
	{	
		ItemBase item_in_hands = m_Parent;

		if (item_in_hands.IsInherited(MoreDoorKitBase))
		{
			SetIsColliding(false);
			return;
		}

		super.EvaluateCollision();
	}
}