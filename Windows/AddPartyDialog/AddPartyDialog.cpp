// Created by Matthew Coady
// (addpartydialog.ui also created by Matthew Coady)

#include "AddPartyDialog.h"
#include "ui_AddPartyDialog.h"
#include <iostream>
#include "../../Party.h"

AddPartyDialog::AddPartyDialog(QString& partyName, int& partySize, QWidget *parent)
    : QDialog(parent)
    , myPartyName(partyName)
    , myPartySize(partySize)
    , ui(new Ui::AddPartyDialog)
{
    ui->setupUi(this);

    // set warning text to red
    QPalette palette = ui->warning->palette();
    palette.setColor(ui->warning->backgroundRole(), Qt::white);
    palette.setColor(ui->warning->foregroundRole(), Qt::red);
    ui->warning->setPalette(palette);
}

AddPartyDialog::~AddPartyDialog()
{
    delete ui;
}


void AddPartyDialog::on_confirmButton_clicked()
{
    bool flag, isOnlyLetters;
    int party_size = (ui->input_2->toPlainText()).toInt(&flag);
    QString party_name = ui->input_1->toPlainText();

    // test if the string contains only letters
    for (int i=0; i < party_name.length(); i++)
    {
        if ((party_name.at(i) >= 65 && party_name.at(i) <= 90) || (party_name.at(i) >= 97 && party_name.at(i) <= 122))
        {
            isOnlyLetters = true;
        }
        else
        {
            isOnlyLetters = false;
        }
    }

    if(!flag)
    {
        ui->warning->setText("!! You must enter a valid integer value (1-99) as the party size.");
        ui->input_2->clear();
    }
    else if (party_name == NULL || party_size == NULL)
    {
        ui->warning->setText("!! You must fill out the required information before you submit.");
    }
    else if(party_size >= 100 || party_size < 1)
    {
        ui->warning->setText("!! You must enter a valid integer value (1-99) as the party size.");
        ui->input_2->clear();
    }
    else if(party_name.length() < 0 || party_name.length() >= 31 || !isOnlyLetters)
    {
        ui->warning->setText("!! You must enter a valid string (between 1-30 LETTERS) as the party name.");
        ui->input_1->clear();
    }
    else
    {
        myPartyName = party_name;
        myPartySize = party_size;
        this->accept();
        this->close();
    }
}

void AddPartyDialog::on_cancelButton_clicked()
{
    this->reject();
    this->close();
}
