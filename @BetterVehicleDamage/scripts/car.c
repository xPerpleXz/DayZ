modded class Car : Transport
{
    override void EEHitBy(EntityAI src, int component, string zone, string ammo, vector pos, float dmg)
    {
        float reducedDamage = dmg * 0.3; // Reduziert den Schaden auf 30%
        super.EEHitBy(src, component, zone, ammo, pos, reducedDamage);
    }
}
