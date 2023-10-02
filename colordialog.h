#ifndef COLORDIALOG_H
#define COLORDIALOG_H

#include <QDialog>
#include <QColor>
#include <QPalette>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QStringList>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDebug>
#include <stdio.h>

#include "newobjectmodeldialog.h"



QT_BEGIN_NAMESPACE
namespace Ui { class colorDialog; }
QT_END_NAMESPACE

class colorDialog : public QDialog
{
    Q_OBJECT

public:
    colorDialog(QWidget *parent = nullptr);
    ~colorDialog();


    QColor curntColor;
    QString projectName;

    bool isDarkBackround(QColor background);
    void updateColorPannel(QColor capColor);
    void updateColorTree();

    void XMLDataSave(QString filename = "mainTable.xml", QString animationTitle = "");

    bool XMLDataRead(QString filename = "mainTable.xml");

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::colorDialog *ui;

};
#endif // COLORDIALOG_H
