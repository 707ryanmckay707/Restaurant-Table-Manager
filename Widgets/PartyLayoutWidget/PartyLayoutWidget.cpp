// Created by Ryan McKay

#include "PartyLayoutWidget.h"
#include "../../Windows/EditPartyDialog/EditPartyDialog.h"
#include <QString>
#include <QPushButton>

PartyLayoutWidget::PartyLayoutWidget(Party* inParty)
{
    party = inParty;

    nameLabel.setText("Name: " + party->getName());
    nameLabel.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    addWidget(&nameLabel, 0, 0);

    sizeLabel.setText("Size: " + QString::number(party->getSize(), 10));
    sizeLabel.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    addWidget(&sizeLabel, 0, 1);

    editButton.setText("Edit");
    editButton.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    addWidget(&editButton, 1, 0);
    connect(&editButton, &QPushButton::clicked, this, &PartyLayoutWidget::onEditButtonClicked);

    sitButton.setText("Sit");
    sitButton.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    addWidget(&sitButton, 1, 1);
    connect(&sitButton, &QPushButton::clicked, this, &PartyLayoutWidget::onSitButtonClicked);

    deleteButton.setText("Delete");
    deleteButton.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    addWidget(&deleteButton, 1, 2);
    connect(&deleteButton, &QPushButton::clicked, this, &PartyLayoutWidget::onDeleteButtonClicked);
}


void PartyLayoutWidget::onEditButtonClicked()
{
    emit editButtonClicked(this);
}

void PartyLayoutWidget::onSitButtonClicked()
{
    emit sitButtonClicked(this);
}

void PartyLayoutWidget::onDeleteButtonClicked()
{
    emit deleteButtonClicked(this);
}

void PartyLayoutWidget::updateParty(QString newName, int newSize)
{
    party->setName(newName);
    party->setSize(newSize);
    nameLabel.setText("Name: " + party->getName());
    sizeLabel.setText("Size: " + QString::number(party->getSize(), 10));
}

PartyLayoutWidget::~PartyLayoutWidget()
{
    if (party)
    {
        delete party;
        party = 0;
    }
    disconnect(&editButton, &QPushButton::clicked, this, &PartyLayoutWidget::onEditButtonClicked);
    disconnect(&sitButton, &QPushButton::clicked, this, &PartyLayoutWidget::onSitButtonClicked);
    disconnect(&deleteButton, &QPushButton::clicked, this, &PartyLayoutWidget::onDeleteButtonClicked);
}
