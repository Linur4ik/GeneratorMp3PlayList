#ifndef EXAMPLETHREADS_H
#define EXAMPLETHREADS_H

#include <QThread>
#include "SourceMain.h"

class ExampleThreads : public QThread
{
public:
    explicit ExampleThreads(bool &adr,PlayList str,QString Path2,qint64 number,int mod,int& Count);

    // Переопределяем метод run(), в котором будет
    // располагаться выполняемый код
    void run();
private:
    bool &a;
    PlayList List;
    QString Path;
    qint64 num;
    int mode;
    int& count;// кол-во скопированного
};

#endif // EXAMPLETHREADS_H
