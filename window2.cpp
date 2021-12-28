#include "window2.h"
#include "ui_window2.h"
#include <QFileDialog>
#include <QStandardItemModel>
#include <QStringList>
#include <QVariant>
#include <QStandardItem>
#include "SourceMain.h"
#include <QMessageBox>
#include <QMdiArea>
#include "dialog.h"
#include <QTimer>
#include "thread.h"
Window2::Window2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window2)
{
    ui->setupUi(this);
    ui->label_2->hide();
    ui->label_3->hide();
    ui->comboBox_2->hide();
    ui->comboBox_3->hide();
    ui->checkBox->hide();
    ui->checkBox_2->hide();
    window1 = new Dialog(this,a);
}

Window2::~Window2()
{
    delete ui;
}



void Window2:: SetQlist(QStringList str)
{
    StrArtist=str;
    checkboxArt = new QStandardItemModel;
    for (int i = 0; i < StrArtist.count(); i++)
    {
        QStandardItem *item = new QStandardItem();
        item->setText(StrArtist[i]);
        item->setCheckable(true);
        item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        item->setData(Qt::Unchecked, Qt::CheckStateRole);
       checkboxArt->setItem(i, item);
    }
    ui->comboBox_2->setModel(checkboxArt);
}

 void Window2:: SetQlistGenre(QStringList str)
 {
     StrGenre=str;
     checkboxGenre = new QStandardItemModel;
     for (int i = 0; i < StrGenre.count(); i++)
     {
         QStandardItem *item = new QStandardItem();
         item->setText(StrGenre[i]);
         item->setCheckable(true);
         item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
         item->setData(Qt::Unchecked, Qt::CheckStateRole);
         checkboxGenre->setItem(i, item);
     }
     ui->comboBox_3->setModel(checkboxGenre);
 }

void Window2::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Исполнитель")
    {
         ui->label_3->hide();
         ui->comboBox_3->hide();
         ui->checkBox_2->hide();
         ui->label_2->show();
         ui->comboBox_2->show();
         ui->checkBox->show();
    }
    if(arg1 == "Жанр")
    {
         ui->label_2->hide();
         ui->comboBox_2->hide();
         ui->checkBox->hide();
         ui->label_3->show();
         ui->comboBox_3->show();
         ui->checkBox_2->show();
    }
    if(arg1 == "Без фильтров")
    {
         ui->label_2->hide();
         ui->comboBox_2->hide();
         ui->label_3->hide();
         ui->comboBox_3->hide();
         ui->checkBox->hide();
         ui->checkBox_2->hide();
    }
}

void Window2:: SetPath2(QString path)
{
    Path2=path;
}

void Window2:: SetList(PlayList a)
{
    List=a;
}

void Window2:: SetNumber(qint64 a)
{
    NumberCopy=a;
}

void Window2:: SetBool(bool a)
{
    FullCopy=a;
}

void Window2::on_pushButton_2_clicked()
{
    qobject_cast<QWidget *>(parent())->show();
    hide();
}


void Window2::on_pushButton_clicked()
{
    val=true;
    int count=0;
    int &b=count;
    window1->SetMax(NumberCopy);
    window1->SetStopper(a);
    QEventLoop loop;
    if(ui->comboBox->currentText() == "Без фильтров")
    {
        if(!FullCopy)
        {
            hide();
            window1->show();
            QTimer::singleShot(1000, &loop, SLOT(quit()));
            loop.exec();
            ExampleThreads s(a,List,Path2,NumberCopy,0,b);
            s.start();
            window1->Button();
            while(1)
            {
                QTimer::singleShot(109, &loop, SLOT(quit()));
                loop.exec();
                if(!val) break;
                window1->Setter(count);
                if(count==NumberCopy) break;
            }
            s.wait();
         }
        else // Заполнить диск
        {
            hide();
            window1->show();
            QTimer::singleShot(1000, &loop, SLOT(quit()));
            loop.exec();
            ExampleThreads s(a,List,Path2,50,1,b);
            QStorageInfo info(Path2);
            quint64 Max=info.bytesFree();
            window1->SetMax(Max);
            s.start();
             window1->Button();
            while(a)
            {
                QTimer::singleShot(109, &loop, SLOT(quit()));
                loop.exec();
                info.refresh();
                window1->Setter(Max-info.bytesFree());
                if(!s.isRunning()) s.start();
            }
             s.wait();
        }
    }
    if(ui->comboBox->currentText() == "Исполнитель")
    {
        if(CreateListArt().size() == 0) // Не выбраны артисты
        {
            QMessageBox :: critical(this,"Ошибка","Укажите артистов!");
            return;
        }

       if(ui->checkBox->checkState() == Qt::Checked) // Отобрать только по выбранным артистам
       {
           if(!FullCopy)
           {
               hide();
               window1->show();
               QTimer::singleShot(1000, &loop, SLOT(quit()));
               loop.exec();
               ExampleThreads s(a,List.GenerateArtList(CreateListArt()),Path2,NumberCopy,0,b);
               s.start();
               window1->Button();
               while(1)
               {
                   QTimer::singleShot(109, &loop, SLOT(quit()));
                   loop.exec();
                   if(!val) break;
                   window1->Setter(count);
                   if(count==NumberCopy) break;
               }
               s.wait();
           }
           //else "FULLCOPY"
           else // Заполнить диск
           {
               hide();
               window1->show();
               QTimer::singleShot(1000, &loop, SLOT(quit()));
               loop.exec();
               ExampleThreads s(a,List.GenerateArtList(CreateListArt()),Path2,50,1,b);
               QStorageInfo info(Path2);
               quint64 Max=info.bytesFree();
               window1->SetMax(Max);
               s.start();
                window1->Button();
               while(a)
               {
                   QTimer::singleShot(109, &loop, SLOT(quit()));
                   loop.exec();
                   info.refresh();
                   window1->Setter(Max-info.bytesFree());
                   if(!s.isRunning()) s.start();
               }
                s.wait();
           }
       }
       else // Отобрать по артистам + рандом
       {
           if(!FullCopy)
           {
               hide();
               window1->show();
               QTimer::singleShot(1000, &loop, SLOT(quit()));
               loop.exec();
               ExampleThreads s(a,(List+List.GenerateArtList(CreateListArt())),Path2,NumberCopy,1,b);
               s.start();
               window1->Button();
               while(1)
               {
                   QTimer::singleShot(109, &loop, SLOT(quit()));
                   loop.exec();
                   if(!val) break;
                   window1->Setter(count);
                   if(count==NumberCopy) break;
               }
               s.wait();
            }
           else // Заполнить диск
           {
               hide();
               window1->show();
               QTimer::singleShot(1000, &loop, SLOT(quit()));
               loop.exec();
               ExampleThreads s(a,(List+List.GenerateArtList(CreateListArt())),Path2,50,1,b);
               QStorageInfo info(Path2);
               quint64 Max=info.bytesFree();
               window1->SetMax(Max);
               s.start();
                window1->Button();
               while(a)
               {
                   QTimer::singleShot(109, &loop, SLOT(quit()));
                   loop.exec();
                   info.refresh();
                   window1->Setter(Max-info.bytesFree());
                   if(!s.isRunning()) s.start();
               }
                s.wait();
           }
       }
    }
    if(ui->comboBox->currentText() == "Жанр")
    {
        if(CreateListGen().size() == 0) // Не выбраны артисты
        {
            QMessageBox :: critical(this,"Ошибка","Укажите жанры!");
            return;
        }      
        if(ui->checkBox_2->checkState() == Qt::Checked) // Отобрать только по выбранным жанрам
        {
            if(!FullCopy)
            {
                hide();
                window1->show();
                QTimer::singleShot(1000, &loop, SLOT(quit()));
                loop.exec();
                ExampleThreads s(a,(List.GenerateGenList(CreateListGen())),Path2,NumberCopy,0,b);
                s.start();
                window1->Button();
                while(1)
                {
                    QTimer::singleShot(109, &loop, SLOT(quit()));
                    loop.exec();
                    qDebug() << val;
                    if(!val) break;
                    window1->Setter(count);
                    if(count==NumberCopy) break;
                }
                s.wait();
            }
            else // Заполнить диск
            {
                hide();
                window1->show();
                QTimer::singleShot(1000, &loop, SLOT(quit()));
                loop.exec();
                ExampleThreads s(a,(List.GenerateGenList(CreateListGen())),Path2,50,1,b);
                QStorageInfo info(Path2);
                quint64 Max=info.bytesFree();
                window1->SetMax(Max);
                s.start();
                 window1->Button();
                while(a)
                {
                    QTimer::singleShot(109, &loop, SLOT(quit()));
                    loop.exec();
                    info.refresh();
                    window1->Setter(Max-info.bytesFree());
                    if(!s.isRunning()) s.start();
                }
                 s.wait();
            }
        }
        else // Отобрать по выбранным жанрам + рандом
        {
            if(!FullCopy)
            {
                hide();
                window1->show();
                QTimer::singleShot(1000, &loop, SLOT(quit()));
                loop.exec();
                ExampleThreads s(a,(List+List.GenerateGenList(CreateListGen())),Path2,NumberCopy,1,b);
                s.start();
                window1->Button();
                while(1)
                {
                   QTimer::singleShot(109, &loop, SLOT(quit()));
                   loop.exec();
                   qDebug() << val;
                   if(!val) break;
                   window1->Setter(count);
                   if(count==NumberCopy) break;
                 }
                 s.wait();
            }
            else // Заполнить диск
            {
                hide();
                window1->show();
                QTimer::singleShot(1000, &loop, SLOT(quit()));
                loop.exec();
                ExampleThreads s(a,(List+List.GenerateGenList(CreateListGen())),Path2,50,1,b);
                QStorageInfo info(Path2);
                quint64 Max=info.bytesFree();
                window1->SetMax(Max);
                s.start();
                 window1->Button();
                while(a)
                {
                    QTimer::singleShot(109, &loop, SLOT(quit()));
                    loop.exec();
                    info.refresh();
                    window1->Setter(Max-info.bytesFree());
                    if(!s.isRunning()) s.start();
                }
                 s.wait();
            }
        }
    }
    window1->ShowButton();
    if(FullCopy) window1->End(count,0);
    else window1->End(count,NumberCopy);
}

QStringList Window2:: CreateListArt()
{
    QStringList a;
   // checkboxArt->findItems(Qt::Checked);
    QStandardItem *Item;
    for(int i=0; (Item=checkboxArt->item(i)) != nullptr;i++)
    {
        if(Item->checkState() == Qt::Checked) a.push_back(Item->text());
    }
    return a;
}

QString Window2:: CreateListGen()
{
    QString str;
    QStandardItem *Item;
    for(int i=0; (Item=checkboxGenre->item(i)) != nullptr;i++)
    {
        if(Item->checkState() == Qt::Checked) str.push_back(StringToCharGenre(Item->text().toStdString()));
    }
    return str;
}
