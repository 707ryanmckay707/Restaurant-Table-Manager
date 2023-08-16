// Created by Ryan McKay

#ifndef TABLEUPDATER_H
#define TABLEUPDATER_H

#include "Updater.h"
#include "../TableStatusEnum/TableStatusEnum.h"

class TableUpdater : public Updater
{
public:
    explicit TableUpdater(QObject *parent = nullptr);
    void updateTableStatus(int restId, int tableNumber, TableStatus tableStatus);
    void updateTableStatusAndRemoveParty(int restId, int tableNumber, TableStatus tableStatus, int partyID);
};

#endif // TABLEUPDATER_H
