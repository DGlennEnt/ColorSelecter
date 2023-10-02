#include "colordialog.h"
#include "ui_colordialog.h"
//#define toRGB0_1(x){}

colorDialog::colorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::colorDialog)
{
    ui->setupUi(this);
    projectName = "";
    curntColor.setRgb(255,255,255);
    updateColorPannel(curntColor);
    updateColorTree();
    XMLDataRead();
}

colorDialog::~colorDialog()
{
    delete ui;
}

bool colorDialog::isDarkBackround(QColor background)
{
//      I found something simuler to this on the Qt Forum by Gojir4 that shared it.
//      The topic was called "Best way to set text color for maximum contrast on background color?".
//      I adapted it to work with QColor class. I'm not sure if this already exists. I assume not!
//      In any case, it does the job I what
        double a = 1 - ( 0.299 * background.redF() + 0.587 * background.greenF() + 0.114 * background.blueF());
        return background.alphaF() > 0 && a >= 0.3;
}

void colorDialog::updateColorPannel(QColor capColor )
{
    QString textValue;
    QString setStileString;
    QColor textColor;
    if (isDarkBackround(capColor)) textColor.setRgb(255,255,255);
    else textColor.setRgb(0,0,0);

    colorDialog::ui->pushButton_3->setAutoFillBackground(true);

    setStileString.sprintf("QPushButton { \n "
                           "background-color: rgb(%d,%d,%d); \n"
                           "color: rgb(%d,%d,%d); \n"
                           "border-style: outset; \n"
                           "border-width: 2px;\n"
                           "border-radius: 10px;\n"
                           "border-color: black;\n"
                           "font: bold 20px; \n"
                           "min-width: 5em; \n"
                           "} \n"
                           "QPushButton:hover{ \n"
                           "border-color: rgb(170, 255, 127); \n"
                           "} \n"
                           "QPushButton:pressed { \n"
                           "border-style: inset; \n"
                           "}",capColor.red(),capColor.green(),capColor.blue(),textColor.red(),textColor.green(),textColor.blue());



    colorDialog::ui->pushButton_3->setStyleSheet(setStileString);
    colorDialog::ui->RGB255Red->setText(textValue.setNum(capColor.red()));
    colorDialog::ui->RGB255Gren->setText(textValue.setNum(capColor.green()));
    colorDialog::ui->RGB255Blue->setText(textValue.setNum(capColor.blue()));
    colorDialog::ui->RGB0_1Red->setText(textValue.setNum(capColor.redF()));
    colorDialog::ui->RGB0_1Gren->setText(textValue.setNum(capColor.greenF()));
    colorDialog::ui->RGB0_1Blue->setText(textValue.setNum(capColor.blueF()));
    colorDialog::ui->CMYK_Cyan->setText(textValue.setNum(capColor.cyan()));
    colorDialog::ui->CMYK_Meg->setText(textValue.setNum(capColor.magenta()));
    colorDialog::ui->CMYK_Yelow->setText(textValue.setNum(capColor.yellow()));
    colorDialog::ui->CMYK_Black->setText(textValue.setNum(capColor.black()));
    colorDialog::ui->CMYK_CyanF->setText(textValue.setNum(capColor.cyanF()));
    colorDialog::ui->CMYK_MegF->setText(textValue.setNum(capColor.magentaF()));
    colorDialog::ui->CMYK_YelowF->setText(textValue.setNum(capColor.yellowF()));
    colorDialog::ui->CMYK_BlackF->setText(textValue.setNum(capColor.blackF()));
    colorDialog::ui->HTML_Color->setText(capColor.name());
}

void colorDialog::updateColorTree()
{
     //colorDialog::ui->treeWidget->setColumnCount(2);
     colorDialog::ui->treeWidget->setColumnCount(2);
     colorDialog::ui->treeWidget->setColumnWidth(0,250);
     colorDialog::ui->treeWidget->expandAll();
     QStringList headLest;
     headLest << "3D Models" << "Color";
     colorDialog::ui->treeWidget->setHeaderLabels(headLest);

//  This is the test code to figure out the best way to use the treeWidget;
//  Normaly I would delete this, but I thought I'd leave it here for refarce.  Enjoy!

//     QTreeWidgetItem *root = new QTreeWidgetItem(colorDialog::ui->treeWidget);
//     root->setText(0,"Star Butterfly");
//     root->setText(1,"Object model");
//     //root->setExpanded(true);
//     colorDialog::ui->treeWidget->addTopLevelItem(root);

//     QTreeWidgetItem *ogjectSerface01 = new QTreeWidgetItem();
//     ogjectSerface01->setText(0,"Head");
//     ogjectSerface01->setText(1,"Object");
//     ogjectSerface01->setExpanded(true);
//     root->addChild(ogjectSerface01);

//     QTreeWidgetItem *colorSplach01 = new QTreeWidgetItem();
//     colorSplach01->setText(0,"Color 1");
//     colorSplach01->setText(1,"250,228,206");
//     QColor setColor;
//     setColor.setRgb(250,228,206);
//     colorSplach01->setBackgroundColor(1,setColor);
//     ogjectSerface01->addChild(colorSplach01);

//     QTreeWidgetItem *colorSplach02 = new QTreeWidgetItem();
//     colorSplach02->setText(0,"Color 2");
//     colorSplach02->setText(1,"246,150,148");
//     //QColor setColor;
//     setColor.setRgb(246,150,148);
//     colorSplach02->setBackgroundColor(1,setColor);
//     ogjectSerface01->addChild(colorSplach02);

//     QTreeWidgetItem *ogjectSerface02 = new QTreeWidgetItem();
//     ogjectSerface02->setText(0,"Eyes");
//     ogjectSerface02->setText(1,"Object");
//     ogjectSerface02->setExpanded(true);
//     root->addChild(ogjectSerface02);

//     QTreeWidgetItem *colorSplach03 = new QTreeWidgetItem();
//     colorSplach03->setText(0,"Color 1");
//     colorSplach03->setText(1,"253,251,240");
//     setColor.setRgb(253,251,240);
//     colorSplach03->setBackgroundColor(1,setColor);
//     ogjectSerface02->addChild(colorSplach03);

//     QTreeWidgetItem *colorSplach04 = new QTreeWidgetItem();
//     colorSplach04->setText(0,"Color 2");
//     colorSplach04->setText(1,"145,189,229");
//     setColor.setRgb(145,189,229);
//     colorSplach04->setBackgroundColor(1,setColor);
//     ogjectSerface02->addChild(colorSplach04);

//     QTreeWidgetItem *colorSplach05 = new QTreeWidgetItem();
//     colorSplach05->setText(0,"Color 3");
//     colorSplach05->setText(1,"0,0,2");
//     setColor.setRgb(0,0,2);
//     colorSplach05->setBackgroundColor(1,setColor);
//     ogjectSerface02->addChild(colorSplach05);

//     QTreeWidgetItem *ogjectSerface03 = new QTreeWidgetItem();
//     ogjectSerface03->setText(0,"Hair");
//     ogjectSerface03->setText(1,"Object");
//     ogjectSerface03->setExpanded(true);
//     root->addChild(ogjectSerface03);

//     QTreeWidgetItem *colorSplach06 = new QTreeWidgetItem();
//     colorSplach06->setText(0,"Color 1");
//     colorSplach06->setText(1,"248,225,124");
//     setColor.setRgb(248,225,124);
//     colorSplach06->setBackgroundColor(1,setColor);
//     ogjectSerface03->addChild(colorSplach06);

//     QTreeWidgetItem *ogjectSerface04 = new QTreeWidgetItem();
//     ogjectSerface04->setText(0,"Horns");
//     ogjectSerface04->setText(1,"Object");
//     ogjectSerface04->setExpanded(true);
//     root->addChild(ogjectSerface04);

//     QTreeWidgetItem *colorSplach07 = new QTreeWidgetItem();
//     colorSplach07->setText(0,"Color 1");
//     colorSplach07->setText(1,"202,59,109");
//     setColor.setRgb(202,59,109);
//     colorSplach07->setBackgroundColor(1,setColor);
//     ogjectSerface04->addChild(colorSplach07);



     colorDialog::ui->treeWidget->expandAll();




}

void colorDialog::XMLDataSave(QString filename, QString animationTitle)
{
    QFile testfile(filename);
    testfile.open(QFile::WriteOnly | QFile::Text);
    QXmlStreamWriter stream(&testfile);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    // First we set up the top layer and call it "colorList" for now.
    stream.writeStartElement("colorList");
    stream.writeAttribute("Name",animationTitle);
    // Next, we start the first loop.
    // This one is for the character or Object models.
    for(int i=0; i< colorDialog::ui->treeWidget->topLevelItemCount();i++)
    {
        QTreeWidgetItem *capTreeItem = colorDialog::ui->treeWidget->topLevelItem(i);
        stream.writeStartElement("ObjectModel");
        stream.writeAttribute("Name",capTreeItem->text(0));
        // We name each Object Model by the Character or object name we have.
        // Then we prepare for the second loop.
        // This one is to interrogate the children in the Tree View Widget.
        for(int j=0; j< capTreeItem->childCount(); j++)
         {
             QTreeWidgetItem *capTreeChildItem = capTreeItem->child(j);
             stream.writeStartElement("Object");
             stream.writeAttribute("Name",capTreeChildItem->text(0));
             // Like the Object Model we name the children, Usually by the body parts.
             // But wait, not even the children's children are safe,
             // as this is where we identify all the colors for the Object.
             for(int k=0; k < capTreeChildItem->childCount(); k++)
             {
                stream.writeTextElement("Color", capTreeChildItem->child(k)->text(1));
             }
             // Well, after all this mess, we must do the paperwork and tiddy up things.
                 stream.writeEndElement();
         }
         stream.writeEndElement();
    }
    stream.writeEndElement();
    // After the last loose end is dealt with, we close the document and we are done.
    stream.writeEndDocument();
    testfile.close();
}

bool colorDialog::XMLDataRead(QString filename)
{
    QFile file(filename);
   if(!file.open(QFile::ReadOnly | QFile::Text))
   {
       QString errorMsg = "The file:";
       errorMsg.append(filename);
       errorMsg.append("cannot be opened\n You may what to create the file\n and try to reload");
       QMessageBox::warning(this,filename, errorMsg,QMessageBox::Ok);
       return false;
   }
   colorDialog::ui->treeWidget->clear();
    QXmlStreamReader reader(&file);
    while(!reader.atEnd() && !reader.hasError())
    {
        QXmlStreamReader::TokenType token = reader.readNext();
        if( token == QXmlStreamReader::StartDocument)
        {
            continue;
        }
        if( token == QXmlStreamReader::StartElement)
        {
            if(reader.name() == "colorList")
            {
                QString titleName = reader.attributes().value("Name").toString();
                if(!titleName.isEmpty())
                {
                  QString title = "Color Selector Pallet List and Converter -";
                  title.append(titleName);
                  colorDialog::setWindowTitle(title);
                  projectName = titleName;
                }

                continue;

            }
            if(reader.name() == "ObjectModel")
            {
                QString atb = reader.attributes().value("Name").toString();
                QTreeWidgetItem *objectModelIrem = new QTreeWidgetItem(colorDialog::ui->treeWidget);
                objectModelIrem->setText(0,atb);
                objectModelIrem->setText(1,"Object model");
                //qDebug() << atb << " : Object model";
                while(!(reader.tokenType() == QXmlStreamReader::EndElement))
                {
                    reader.readNext();
                    if(reader.name() == "Object")
                    {
                        QString atb2 = reader.attributes().value("Name").toString();
                        QTreeWidgetItem *objectPartIrem = new QTreeWidgetItem();
                        objectPartIrem->setText(0,atb2);
                        objectPartIrem->setText(1,"Object");
                        //qDebug() << atb2 << " : Object";
                        reader.readNext();
                        //qDebug() << "End of Object Dec";
                        int i = 1;
                        while(!(reader.tokenType() == QXmlStreamReader::EndElement && reader.name() == "Object"))
                        {
                            if (reader.name() == "Color")
                            {
                                QString atb3 = reader.readElementText();
                                QString colorTag;
                                QColor capColor;
                                QColor textColor;
                                int red,green,blue;

                                QTreeWidgetItem *partColor = new QTreeWidgetItem();
                                colorTag.sprintf("Color %d",objectPartIrem->childCount()+1);
                                partColor->setText(0,colorTag);
                                partColor->setText(1,atb3);
                                sscanf_s(atb3.toStdString().c_str(),"%d,%d,%d",&red,&green,&blue);
                                capColor.setRgb(red,green,blue);
                                partColor->setBackgroundColor(1,capColor);
                                if (isDarkBackround(capColor)) textColor.setRgb(255,255,255);
                                else textColor.setRgb(0,0,0);
                                partColor->setTextColor(1,textColor);
                                //qDebug() << "Color "<< i <<":" << atb3;
                                i++;
                              objectPartIrem->addChild(partColor);
                            }
                            reader.readNext();
                        }
                        reader.readNext();
                        //qDebug() << "End of Object";
                        objectModelIrem->addChild(objectPartIrem);
                    }
                }
                reader.readNext();
                //qDebug() << "End of ObjectModel";
                colorDialog::ui->treeWidget->addTopLevelItem(objectModelIrem);
            }
        }
    }
    colorDialog::ui->treeWidget->expandAll();
    return true;
}


void colorDialog::on_pushButton_2_clicked()
{
    if(colorDialog::ui->treeWidget->currentItem())
    {
        QTreeWidgetItem *currentItem = colorDialog::ui->treeWidget->currentItem();
        QString textCurrentItem = currentItem->text(0);
        if (textCurrentItem.contains("Color"))
        {
            int ret = QMessageBox::warning(this, tr("Replace this Color Swatch"),
                                           tr("This will replace the default assigned color.\n"
                                              "Do you want to make this change?"),
                                           QMessageBox::Yes
                                           | QMessageBox::No | QMessageBox::Cancel,
                                           QMessageBox::Yes);
            if(ret == QMessageBox::Yes )
            {
                currentItem->setBackgroundColor(1,curntColor);
                QString addtext;
                addtext.sprintf("%d,%d,%d",curntColor.red(),curntColor.green(),curntColor.blue());
                currentItem->setText(1,addtext);
            }
        }
        else QMessageBox::warning(this, tr("Need To select Color"),
                                  tr("Color Swatch is not selected.\n Please select a Color Swatch that you wish to change!"),
                                  QMessageBox::Ok,
                                  QMessageBox::Ok);

    }
    else QMessageBox::warning(this, tr("Need To select Color"),
                              tr("Nothing on the Tree is selected.\n Please select a Color Swatch that you wish to change!"),
                              QMessageBox::Ok,
                              QMessageBox::Ok);


}

void colorDialog::on_pushButton_3_clicked()
{
   // QColor capColor = QColorDialog::getColor(curntColor,this,"Select Color for Chart");
    //bool ok = true;
    QColor capColor = QColorDialog::getColor(Qt::white,this);
    if(capColor.isValid())
    {
        updateColorPannel(capColor);
        curntColor = capColor;
    }
}

void colorDialog::on_pushButton_clicked()
{
  QString newName;

  newObjectModelDialog newObjetmodel(this,&newName, "Enter New ObjectModel Name","New Object Model Dialog");
  newObjetmodel.exec();
  if( !newName.isEmpty())
  {
     QTreeWidgetItem *additem = new QTreeWidgetItem(colorDialog::ui->treeWidget);
     additem->setText(0,newName);
     additem->setText(1,"Object model");
     additem->setExpanded(true);
     colorDialog::ui->treeWidget->addTopLevelItem(additem);
     colorDialog::ui->treeWidget->expandAll();
     colorDialog::ui->treeWidget->setCurrentItem(additem);

  }
}

void colorDialog::on_pushButton_4_clicked()
{
   QTreeWidgetItem *currentItem = colorDialog::ui->treeWidget->currentItem();
   QString textCurrentItem = currentItem->text(1);
   if (textCurrentItem.contains("Object model"))
   {
       QString newName;
       newObjectModelDialog newObjetmodel(this,&newName, "Enter New Object Name","New Object Element Dialog");
       newObjetmodel.exec();
       if( !newName.isEmpty())
       {
           QTreeWidgetItem *additem = new QTreeWidgetItem();
           additem->setText(0,newName);
           additem->setText(1,"Object");
           additem->setExpanded(true);
           currentItem->addChild(additem);
           colorDialog::ui->treeWidget->setCurrentItem(currentItem);
       }

   }
   if (textCurrentItem.contains("Object")&& !textCurrentItem.contains("model"))
   {
       QColor capColor = QColorDialog::getColor();
       if(capColor.isValid())
       {
           QString addtext1,addtext2;
           addtext1.sprintf("Color %d",currentItem->childCount()+1);
           addtext2.sprintf("%d,%d,%d",capColor.red(),capColor.green(),capColor.blue());
           QTreeWidgetItem *colorSplach = new QTreeWidgetItem();
           colorSplach->setText(0,addtext1);
           colorSplach->setText(1,addtext2);
           colorSplach->setBackgroundColor(1,capColor);
           currentItem->addChild(colorSplach);
           curntColor = capColor;
           updateColorPannel(capColor);
       }
   }
   colorDialog::ui->treeWidget->expandAll();
}



void colorDialog::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{

    QString textCurrentItem = item->text(0);
    if(textCurrentItem.contains("Color"))
    {
        QColor capColor = item->backgroundColor(1);
        curntColor = capColor;
        updateColorPannel(capColor);
    }
}


void colorDialog::on_pushButton_5_clicked()
{
    //XMLDataSave();
    QString filename = QFileDialog::getOpenFileName(this,"Load Pallet File","",tr("XML Files (*.xml *.*)"));
    if (!filename.isEmpty()) XMLDataRead(filename);


//    QFile testfile("test2.xml");
//    testfile.open(QFile::WriteOnly | QFile::Text);
//    //QXmlStreamReader xmlWriter(&testfile);
//    //xmlWriter.setAutoFormatting(true);
//    QXmlStreamWriter stream(&testfile);
//        stream.setAutoFormatting(true);
//        stream.writeStartDocument();

//        stream.writeStartElement("colorList");
//        stream.writeStartElement("ObjectModel");
//        stream.writeAttribute("Name","Star Butterfly");
//        stream.writeStartElement("Object");
//        stream.writeAttribute("Name","Head");
//        stream.writeTextElement("Color1", "250,228,206");
//        stream.writeTextElement("Color2", "246,150,148");
//        stream.writeEndElement();
//        stream.writeStartElement("Object");
//        stream.writeAttribute("Name","Eyes");
//        stream.writeTextElement("Color1","253,251,240");
//        stream.writeTextElement("Color2","145,189,229");
//        stream.writeTextElement("Color3","0,0,2");
//        stream.writeEndElement();
//        stream.writeStartElement("Object");
//        stream.writeAttribute("Name","Hair");
//        stream.writeTextElement("Color1","248,225,124");
//        stream.writeEndElement();
//        stream.writeStartElement("Object");
//        stream.writeAttribute("Name","Horns");
//        stream.writeTextElement("Color1","202,59,109");
//        stream.writeEndElement();
//        stream.writeEndElement();
//        stream.writeEndElement();

//        stream.writeEndDocument();
//        testfile.close();

}

void colorDialog::on_pushButton_6_clicked()
{
    QString newName = projectName;
    QString textNote;
    if(newName.isEmpty())
        textNote = "Enter Project name!";
    else
        textNote = "Change Project Name?";

    newObjectModelDialog newObjetmodel(this,&newName, textNote,"New Project List Dialog");
    newObjetmodel.exec();
    if(!newName.isEmpty())
    {
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Project File Name"),"",tr("XML Files (*.xml *.*)"));
    if(!fileName.isEmpty()) XMLDataSave(fileName,newName);
    }
}

void colorDialog::on_pushButton_7_clicked()
{
    QString newName;
    newObjectModelDialog newObjetmodel(this,&newName,"Enter New Project Name!","New Project List Dialog");
    newObjetmodel.exec();
    if(!newName.isEmpty())
    {

        QString newName2;
        newObjectModelDialog newObjetmodel(this,&newName2, "Enter New ObjectModel Name","New Object Model Dialog");
        newObjetmodel.exec();
        if( !newName2.isEmpty())
        {
           colorDialog::ui->treeWidget->clear();
           updateColorTree();
           projectName = newName;
           QTreeWidgetItem *additem = new QTreeWidgetItem(colorDialog::ui->treeWidget);
           additem->setText(0,newName2);
           additem->setText(1,"Object model");
           additem->setExpanded(true);
           colorDialog::ui->treeWidget->addTopLevelItem(additem);
           colorDialog::ui->treeWidget->expandAll();
           colorDialog::ui->treeWidget->setCurrentItem(additem);
           QString title = "Color Selector Pallet List and Converter -";
           title.append(projectName);
           colorDialog::setWindowTitle(title);
        }

    }
}

void colorDialog::on_pushButton_8_clicked()
{
    int ret = QMessageBox::warning(this, tr("Save this Project as Default"),
                                   tr("This will replace the old default Project to this one.\n"
                                      "Are you shure you want to make this change?"),
                                   QMessageBox::Yes
                                   | QMessageBox::No | QMessageBox::Cancel,
                                   QMessageBox::Yes);
    if(ret == QMessageBox::Yes )
    {
        XMLDataSave("mainTable.xml",projectName);
    }

}

void colorDialog::on_pushButton_9_clicked()
{
    QMessageBox::about(this,tr("About this Program"),tr("<h2>Color Selector Pallet List and Converter</h2>"
                                                        "<p>Copyright &copy 2021 D Glenn Ent."
                                                        "<p>Color Palet Database and Converter"
                                                        "<P>A Specal Thanks to Rob Rutherford for his help!"));
   // QMessageBox::aboutQt(this);
}
