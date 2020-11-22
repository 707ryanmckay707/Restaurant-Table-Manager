#ifndef EDITPARTYDIALOG_H
#define EDITPARTYDIALOG_H

#include <QDialog>
#include "../../Party.h"

QT_BEGIN_NAMESPACE
namespace Ui { class EditPartyDialog; }
QT_END_NAMESPACE

class EditPartyDialog : public QDialog
{
    Q_OBJECT

public:
    EditPartyDialog(QWidget *parent = nullptr, Party **Party = nullptr);
    ~EditPartyDialog();

private slots:
void on_confirmButton_clicked();
void on_cancelButton_clicked();

private:
    Party **myParty;
    Ui::EditPartyDialog *ui;
};
#endif // EDITPARTYDIALOG_H
