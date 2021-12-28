#include "thread.h"
#include <QDebug>
#include <QTimer>
#include <QEventLoop>

ExampleThreads::ExampleThreads(bool &adr,PlayList str,QString Path2,qint64 number,int mod,int &Count) :
    num(number),
    Path(Path2),
    a(adr),
    mode(mod),
    List(str),
    count(Count)
{

}

void ExampleThreads::run()
{
   if(mode == 0)
   {
       List.Copy(num,Path,a,count);
   }
   if(mode == 1)
   {
       List.RandomCopy(num,Path,a,count);
   }
}

