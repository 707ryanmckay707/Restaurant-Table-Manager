// Created by Jorge Calderon

#ifndef PARTYUPDATERMAIN_H
#define PARTYUPDATERMAIN_H

#include <iostream>
#include "Updater.h"
#include <QString>


class PartyUpdater : public Updater {
public:
    PartyUpdater();
    void updateName(int id, QString newName);
    void updateSize(int id, int newSize);
    void updateNameAndSize(int id, QString newName, int newSize);
    void addParty(QString newName, int newSize);
    void deleteParty(int id);
    void sitParty(int id, int tableNum);
};

#endif // PARTYUPDATERMAIN_H
