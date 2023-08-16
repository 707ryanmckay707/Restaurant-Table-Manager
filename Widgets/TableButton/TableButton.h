// Created by Ryan McKay

#ifndef TABLE_H
#define TABLE_H

#include <QPushButton>
#include "../../TableStatusEnum/TableStatusEnum.h"
#include "../../Party.h"

class TableButton : public QPushButton
{
    Q_OBJECT
public:
    TableButton(int inTableNum);
    void sitParty(Party* partyToSit);
    void setOpenFromDNE();
    void deleteTable();
    int getTableNum() {return tableNum;};
    TableStatus getTableStatus() {return tableStatus;};
    ~TableButton();
public slots:
    void onClicked();
signals:
    void tableStatusChanged(TableStatus oldStatus, TableStatus newStatus);
private:
    Party* party;
    int tableNum;
    TableStatus tableStatus;
};

#endif // TABLE_H
