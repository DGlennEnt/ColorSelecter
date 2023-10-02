#ifndef NEWOBJECTMODELDIALOG_H
#define NEWOBJECTMODELDIALOG_H

#include <QDialog>
#include <QTreeWidget>
#include <QTreeWidgetItem>

namespace Ui {
class newObjectModelDialog;
}

class newObjectModelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newObjectModelDialog(QWidget *parent = nullptr, QString *item = nullptr, QString dlgTxt = "Need to Put somthing Here", QString windowTitle = "Window Title For Sale");
    ~newObjectModelDialog();
   QString *newRoot;

private slots:

    void on_buttonBox_accepted();

    void on_lineEdit_returnPressed();

    void on_buttonBox_rejected();

private:
    Ui::newObjectModelDialog *ui;
};

#endif // NEWOBJECTMODELDIALOG_H
