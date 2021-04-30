#inlcude "Warlock.hpp"


Warlock::Warlock(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid) : 
    Entity(builder, inventory, uid)
{
    std::cout << Name() << " the warlock has entered the battle" << std::endl;
}


void Warlock::EldritchBlast(Entity *target)
{
    Attack(target, GetCharisma() * 1.5, "Eldritch Blast");
}

void Warlock::WeaponAttack(Entity *target)
{
    Attack(target, GetAgility() * 1.0, "Hand-Crossbow");
}

void Warlock::SacredFlame(Entity *target)
{
    int testdice = std::rand () % 20 + 1; // This may require a different line, unsure exactly how to implement rand here
    if(testdice >= 13)
    {
        Attack(target, GetCharisma() * 2.0, "Sacred Flame");
    }
    else
    {
        std::cout << "The target has dodged the attack" << std::endl; // This should have nothing happen to the target, if possible I'd like a test that uses Sacred Flame that way I can run it multiple times to verify that it is indeed random
    }
}

void Warlock::OutputStatus() const
{
    std::cout << Class() << ": " << this->Name()
                << "\n\tCurrent HP: " << this->CurrentHP()
                << "\n\tIntelligence: " << this->GetIntelligence()
                << std::endl;

    PrintInventory();
}

void Mage::UseAction(Entity * target, const std::string& spellName, const std::string & args)
{
    if(spellName == "eldritch_blast")
    {
        EldritchBlast(target);
        return;
    }
    if(spellName == "weapon_attack")
    {
        WeaponAttack(target);
        return;
    }
    if(spellName == "sacred_flame")
    {
        SacredFlame(target);
        return;
    }
    errorFindingAbility(spellName);
}