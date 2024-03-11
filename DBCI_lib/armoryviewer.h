#ifndef ARMORYVIEWER_H
#define ARMORYVIEWER_H

#include "DBCI_lib_global.h"
#include "armorydata.h"
#include <QObject>

class DBCI_LIB_EXPORT ArmoryViewer
{
public:
    ArmoryViewer();

    QString getFaction(const ArmoryData &armoryData, QString lang = "ru") const;
    void setFaction(ArmoryData &armoryData, QString newClass);
    QString getStatus(const ArmoryData &armoryData, QString lang = "ru") const;
    void setStatus(ArmoryData &armoryData, QString newStatus);
    QString getClass(const ArmoryData &armoryData, QString lang = "ru") const;
    void setClass(ArmoryData &armoryData, QString newClass);
    QString getRace(const ArmoryData &armoryData, QString lang = "ru") const;
    void setRace(ArmoryData &armoryData, QString newRace);
    QString getRealm(const ArmoryData &armoryData, QString lang = "ru") const;


private:
    void init();

protected:
    QMap<QPair<int, QString>, QString> _factions;
    QMap<QPair<int, QString>, QString> _statuses;
    QMap<QPair<int, QString>, QString> _classes;
    QMap<QPair<int, QString>, QString> _races;
    QMap<int, QString> _realms;
};

#endif // ARMORYVIEWER_H
