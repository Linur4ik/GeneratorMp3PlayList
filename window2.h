#ifndef WINDOW2_H
#define WINDOW2_H
#include <QDialog>
#include <QStringList>
#include "SourceMain.h"
#include <QStringList>
#include <QStandardItemModel>
#include "dialog.h"
namespace Ui {
class Window2;
}

class Window2 : public QDialog
{
    Q_OBJECT

public:
    explicit Window2(QWidget *parent = nullptr);
    void SetQlist(QStringList);
    void SetQlistGenre(QStringList);
    void SetPath2(QString);
    void SetList(PlayList);
    void SetNumber(qint64);
    void SetBool(bool);
    ~Window2();

private slots:

    void on_comboBox_currentTextChanged(const QString &arg1);


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    QStringList CreateListArt();
    QString CreateListGen();

private:
    Ui::Window2 *ui;
    QStringList StrGenre,StrArtist;
    QString Path2;
    PlayList List;
    bool FullCopy;
    qint64 NumberCopy;
    QStandardItemModel *checkboxArt;
    QStandardItemModel *checkboxGenre;
    Dialog *window1;
    bool val=true;
    bool &a=val;
};

#endif // WINDOW2_H
