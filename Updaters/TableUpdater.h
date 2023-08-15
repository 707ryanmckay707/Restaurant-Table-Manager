// Created by Ryan McKay

#ifndef TABLEUPDATER_H
#define TABLEUPDATER_H

#include "Updater.h"

class TableUpdater : public Updater
{
public:
    explicit TableUpdater(QObject *parent = nullptr);
};

#endif // TABLEUPDATER_H
