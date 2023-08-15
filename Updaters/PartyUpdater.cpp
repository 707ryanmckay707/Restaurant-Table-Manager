//
// Created by Jorge Calderon
//

#include "PartyUpdater.h"

#include <QString>
#include <QUrl>
#include <QNetworkRequest>
#include <QDebug>


void PartyUpdater::updateName(int id, QString newName){
    QString idAsQStringQ = QString::number(id);
    QString url = "http://localhost:3000/api/party/"
                  + idAsQStringQ + "/" + newName + "/updatename";
    QUrl qrl(url);
    manager->get(QNetworkRequest(qrl));
}

void PartyUpdater::updateSize(int id, int newSize){
    QString idAsQStringQ = QString::number(id);
    QString url = "http://localhost:3000/api/party/"
                  + idAsQStringQ + "/" + newSize + "updatesize";
    QUrl qrl(url);
    manager->get(QNetworkRequest(qrl));
}

void PartyUpdater::updateNameAndSize(int id, QString newName, int newSize){
    QString idAsQStringQ = QString::number(id);
    QString sizeAsQStringQ = QString::number(newSize);
    QString url = "http://localhost:3000/api/party/"
                  + idAsQStringQ + "/" + newName + "/"
                  + sizeAsQStringQ + "/updatenameandsize";
    QUrl qrl(url);
    manager->get(QNetworkRequest(qrl));
}

void PartyUpdater::addParty(QString newName, int newSize){
    QString sizeAsQStringQ = QString::number(newSize);
    QString url = "http://localhost:3000/api/party/1/"
                  + newName + "/" + sizeAsQStringQ + "/add";
    QUrl qrl(url);
    manager->get(QNetworkRequest(qrl));
}

void PartyUpdater::deleteParty(int id){
    QString idAsQStringQ = QString::number(id);
    QString url = "http://localhost:3000/api/party/"
                  + idAsQStringQ + "/delete";
    QUrl qrl(url);
    manager->get(QNetworkRequest(qrl));
}

void PartyUpdater::sitParty(int id, int tableNum){
    QString idAsQStringQ = QString::number(id);
    QString tableNumAsQStringQ = QString::number(tableNum);
    QString url = "http://localhost:3000/api/party/1/"
                  + idAsQStringQ + "/" + tableNumAsQStringQ + "/sitparty";
    QUrl qrl(url);
    manager->get(QNetworkRequest(qrl));
}

PartyUpdater::PartyUpdater()
{

}
