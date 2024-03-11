#include "armoryviewer.h"

ArmoryViewer::ArmoryViewer()
{
    init();
}

QString ArmoryViewer::getFaction(const ArmoryData &armoryData, QString lang) const
{
    lang = lang.toLower();
    return _factions[{armoryData.faction(), lang}];
}

void ArmoryViewer::setFaction(ArmoryData &armoryData, QString newClass)
{
    armoryData.setFaction(Faction(_factions.key(newClass).first));
}

QString ArmoryViewer::getStatus(const ArmoryData &armoryData, QString lang) const
{
    lang = lang.toLower();
    return _statuses[{armoryData.status(), lang}];
}

void ArmoryViewer::setStatus(ArmoryData &armoryData, QString newStatus)
{
    armoryData.setStatus(Status(_statuses.key(newStatus).first));
}

QString ArmoryViewer::getClass(const ArmoryData &armoryData, QString lang) const
{
    lang = lang.toLower();
    return _classes[{armoryData.getClass(), lang}];
}

void ArmoryViewer::setClass(ArmoryData &armoryData, QString newClass)
{
    newClass    = newClass.toLower();

    if (newClass == "воин") armoryData.setClass(Class::Warrior);
    if (newClass == "паладин") armoryData.setClass(Class::Paladin);
    if (newClass == "охотник") armoryData.setClass(Class::Hunter);
    if (newClass == "разбойник") armoryData.setClass(Class::Rogue);
    if (newClass == "жрец") armoryData.setClass(Class::Priest);
    if (newClass == "шаман") armoryData.setClass(Class::Shaman);
    if (newClass == "чернокнижник") armoryData.setClass(Class::Warlock);
    if (newClass == "монах") armoryData.setClass(Class::Monk);
    if (newClass == "друид") armoryData.setClass(Class::Druid);
    if (newClass == "рыцарь смерти") armoryData.setClass(Class::DeathKnight);
}

QString ArmoryViewer::getRace(const ArmoryData &armoryData, QString lang) const
{
    lang = lang.toLower();
    return _races[{armoryData.race(), lang}];
}

void ArmoryViewer::setRace(ArmoryData &armoryData, QString newClass)
{
    armoryData.setRace(Race(_races.key(newClass).first));
}

QString ArmoryViewer::getRealm(const ArmoryData &armoryData, QString lang) const
{
    lang = lang.toLower();
    return _realms[armoryData.realm()];
}

void ArmoryViewer::init()
{
    _realms[3]  = "FUN";
    _realms[5]  = "x5";
    _realms[10] = "x100";

    _factions[{Faction::Alliance, "ru"}]    = "Альянс";
    _factions[{Faction::Horde, "ru"}]       = "Орда";
    _factions[{Faction::None, "ru"}]        = "Без фракции";

    _statuses[{Status::Unknown, "ru"}]      = "Неизвестно";
    _statuses[{Status::Humiliated, "ru"}]   = "Попущен";
    _statuses[{Status::Terminated, "ru"}]   = "Ликвидирован";
    _statuses[{Status::Amnestied, "ru"}]    = "Амнистирован";
    _statuses[{Status::Sold, "ru"}]         = "Продан";

    _classes[{Class::Warrior, "ru"}]        = "Воин";
    _classes[{Class::Paladin, "ru"}]        = "Паладин";
    _classes[{Class::Hunter, "ru"}]         = "Охотник";
    _classes[{Class::Rogue, "ru"}]          = "Разбойник";
    _classes[{Class::Priest, "ru"}]         = "Жрец";
    _classes[{Class::DeathKnight, "ru"}]    = "Рыцарь Смерти";
    _classes[{Class::Shaman, "ru"}]         = "Шаман";
    _classes[{Class::Mage, "ru"}]           = "Маг";
    _classes[{Class::Warlock, "ru"}]        = "Чернокнижник";
    _classes[{Class::Monk, "ru"}]           = "Монах";
    _classes[{Class::Druid, "ru"}]          = "Друид";

    _races[{Race::Human, "ru"}]             = "Человек";
    _races[{Race::Dwarft, "ru"}]            = "Дворф";
    _races[{Race::NightElf, "ru"}]          = "Ночной эльф";
    _races[{Race::Gnome, "ru"}]             = "Гном";
    _races[{Race::Draenei, "ru"}]           = "Дреней";
    _races[{Race::Worgen, "ru"}]            = "Ворген";
    _races[{Race::Orc, "ru"}]               = "Орк";
    _races[{Race::Undead, "ru"}]            = "Нежить";
    _races[{Race::Tauren, "ru"}]            = "Таурен";
    _races[{Race::Troll, "ru"}]             = "Тролль";
    _races[{Race::BloodElf, "ru"}]          = "Эльф крови";
    _races[{Race::Goblin, "ru"}]            = "Гоблин";
    _races[{Race::Pandaren, "ru"}]          = "Пандарен";
}
