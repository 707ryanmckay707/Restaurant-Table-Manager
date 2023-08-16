// Created by Ryan McKay

#include "TableUpdater.h"
#include "../TableStatusEnum/TableStatusEnum.h"
#include "../TableStatusEnum/TableStatusEnumGlobalFunctions.h"
#include <QString>
#include <QUrl>
#include <QNetworkRequest>

TableUpdater::TableUpdater(QObject *parent)
    : Updater{parent}
{

}

void TableUpdater::updateTableStatus(int restId, int tableNumber, TableStatus tableStatus)
{
    QString url = "http://localhost:3000/api/table/"
                  + QString::number(restId) + "/"
                  + QString::number(tableNumber) + "/"
                  + getTableStatusQString(tableStatus)
                  + "/updatestatus";
    QUrl qUrl(url);
    manager->get(QNetworkRequest(qUrl));
}
