#ifndef ARMORYENUMS_H
#define ARMORYENUMS_H

enum Faction
{
    None        = 0,
    Alliance    = 1,
    Horde       = 2,
};

enum Race
{
    Human       = 1,
    Dwarft      = 2,
    NightElf    = 3,
    Gnome       = 4,
    Draenei     = 5,
    Worgen      = 6,

    Orc         = 7,
    Undead      = 8,
    Tauren      = 9,
    Troll       = 10,
    BloodElf    = 11,
    Goblin      = 12,

    Pandaren    = 0,
};

enum Status
{
    Unknown     = 0,
    Humiliated  = 1,
    Terminated  = 2,
    Amnestied   = 3,
    Sold        = 4,
};

enum Class
{
    Warrior     = 1,
    Paladin     = 2,
    Hunter      = 3,
    Rogue       = 4,
    Priest      = 5,
    DeathKnight = 6,
    Shaman      = 7,
    Mage        = 8,
    Warlock     = 9,
    Monk        = 10,
    Druid       = 11,
};

#endif // ARMORYENUMS_H
