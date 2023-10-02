#include "newobjectmodeldialog.h"
#include "ui_newobjectmodeldialog.h"

newObjectModelDialog::newObjectModelDialog(QWidget *parent, QString *item, QString dlgTxt, QString windowTitle) :
    QDialog(parent),
    ui(new Ui::newObjectModelDialog)
{
    ui->setupUi(this);
    newRoot = item;
    newObjectModelDialog::ui->label->setText(dlgTxt);
    newObjectModelDialog::ui->lineEdit->setText(*newRoot);
    newObjectModelDialog::setWindowTitle(windowTitle);
}

newObjectModelDialog::~newObjectModelDialog()
{
    delete ui;
}



void newObjectModelDialog::on_buttonBox_accepted()
{
    QString newObjectName;
    newObjectName = newObjectModelDialog::ui->lineEdit->text();
    if (!newObjectName.isEmpty())
    {
        newRoot->clear();
        newRoot->append(newObjectName);

    }
}

void newObjectModelDialog::on_lineEdit_returnPressed()
{
    QString newObjectName;
    newObjectName = newObjectModelDialog::ui->lineEdit->text();
    if (!newObjectName.isEmpty())
    {
        //newRoot->append(newObjectName);

    }
}

void newObjectModelDialog::on_buttonBox_rejected()
{
    newRoot->clear();
}
