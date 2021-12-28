#ifndef SOURCEMAIN_CPP
#define SOURCEMAIN_CPP
#include "SourceMain.h"


void MP3::SetWay(QString a)
{
    WayFile = a;
}

void MP3::ScanTag()
{
   QFile file(WayFile);
   if(!file.exists())
   {
        qDebug() << "ERROR";
        return;
   }
    file.open(QIODevice::ReadOnly);
    //qDebug() << file.seek(file.size()-128);
    //qDebug() << cp2utf(file.read(128).toStdString()).c_str();
    if(!file.seek(file.size()-128))
    {
        qDebug() << "ERROR";
        return; // перенос и проверка

    }
    string str = file.read(128).toStdString();

    int i=0,t=0;
    char TitleTag[3];
    for (t = 0; t <= 2; t++)
    {
        TitleTag[t] = str[i];
        i++;
    }
    if (TitleTag[0] == 'T' && TitleTag[1] == 'A' && TitleTag[2] == 'G') //printf("YEAH");
    {
        //qDebug() << cp2utf(str).c_str();
        char ptr[31];
        //qDebug() << "Okey";
        Check = true;
        for (t = 0; t < 30; t++)
        {
            ptr[t] = str[i];
            i++;
        }

        Name = cp2utf((string)ptr);

        //qDebug() << Name.c_str();


        for (t = 0; t < 30; t++)
        {
            ptr[t] = str[i];
            i++;
        }

         Artist = cp2utf((string)ptr);
        for (t = 0; t < 30; t++)
        {
            ptr[t] = str[i];
            i++;
        }

         Album = cp2utf((string)ptr);
         char ptrYear[5];
        for (t = 0; t < 4; t++)
        {
            ptrYear[t] = str[i];
            i++;
        }

         Year = cp2utf((string)ptrYear);
        for (t = 0; t < 30; t++)
        {
            ptr[t] = str[i];
            i++;
        }

         Comment = cp2utf((string)ptr);
        Genre = str[i];
    }
}


void MP3::PrintTag()
{
    if (Check)
    {
        qDebug() << "Name:" << Name.c_str();
        qDebug() << "Artist:" << Artist.c_str();
        qDebug() << "Album:" << Album.c_str();
        qDebug() << "Year:" << Year.c_str();
        qDebug() << "Genre:" << (int)Genre;
        //PrintGenre(Genre);
        qDebug() << "Comment:" << Comment.c_str();
        //cout << "Ves:" << 18446744073709551614 / 1024 / 1024 / 1024 << endl;
        //cout << filesystem :: file_size(filesystem :: path(WayFile)) << endl;
    }
}

string ReturnGenre(char a)
{
    if (a > 80 || a < 0) return "Other";
    string TAB[80] = { "Blues","Classic Rock", "Country", "Dance","Disco","Funk","Grunge","Hip - Hop", "Jazz", "Metal", "New Age", "Oldies", "Other", "Pop",
    "R & B","Rap","Reggae","Rock","Techno","Industrial","Alternative","Ska","Death Metal","Pranks","Soundtrack","Euro - Techno",
        "Ambient","Trip - Hop","Vocal","Jazz + Funk","Fusion","Trance","Classical","Instrumental","Acid","House",
        "Game","Sound Clip","Gospel","Noise","AlternRock","Bass","Soul","Punk","Space","Meditative","Instrumental Pop",
        "Instrumental Rock","Ethnic","Gothic","Darkwave","Techno - Industrial","Electronic","Pop - Folk"
        ,"Eurodance","Dream","Southern Rock","Comedy","Cult","Gangsta","Top 40","Christian Rap","Pop / Funk",
        "Jungle","Native American","Cabaret","New Wave","Psychadelic","Rave","Showtunes","Trailer","Lo - Fi",
        "Tribal","Acid Punk","Acid Jazz","Polka","Retro","Musical","Rock & Roll","Hard Rock" };
    return TAB[a];
}

void PrintAllGenre(vector<char> a)
{
    for (auto& i : a)
    {
        cout << (int)i << endl;
    }
}

void PrintAllArtist(vector<string>a)
{
    for (auto& i : a)
    {
        cout << i << endl;
    }
}



int PlayList::RandomCopy(int N, QString path,bool &a,int &count)
{
    if (SizePlaylist() <= 0 || N <= 0) {a=false; return count;}
    if (!QFileInfo::exists(path)) {a=false; return count;}
    QString It;
    QStorageInfo q(path);
    int k, i;
    for (int n = 0; n < N; n++)
    {
        i = rand() % Size;
        if (q.bytesAvailable() <= List[i].Ves){a=false; return count;}
        k = 1;
        It = path + "/" + List[i % Size].NameFile;
        while (QFileInfo::exists(It))
        {
            It = path + "/" + "(" + QString::fromStdString(to_string(k)) + ")" + List[i % Size].NameFile;
            k++;
        }

        if (k != 1)
            QFile :: rename(path + "/" + List[i % Size].NameFile, It);
        if (QFileInfo::exists(List[i % Size].WayFile) && !QFileInfo::exists(path + "/" + List[i % Size].NameFile))
        {
             //qDebug() << It.toStdString().c_str();
            // qDebug() << (List[i % Size].WayFile).toStdString().c_str();
            // qDebug() << path.toStdString().c_str();
            if(QFile::copy(List[i % Size].WayFile, path+"/"+List[i % Size].NameFile)) count++;
        }
        if(!a) break;
        if(a) continue;
    }
    return count;
}

PlayList PlayList :: operator+(PlayList a)
{
    PlayList b;
    if (b.List.max_size() < List.size() + a.List.size()) return b;
    for (auto& i : List)
    {
        b.List.push_back(i);
    }
    for (auto& i : a.List)
    {
        b.List.push_back(i);
    }
    return b;
}

int PlayList::Copy(int N, QString path,bool &a,int &count)
{
    if (SizePlaylist() <= 0 || N <= 0) {a=false; return count;}
    if (!QFileInfo::exists(path)) {a=false; return count;}
    QString It;
    QStorageInfo q(path);
    int k, i;
    for (int i = 0; i < N; i++)
    {
        if (q.bytesAvailable() <= List[i % Size].Ves){ a=false; return count; }
        k = 1;
        It = path + "/" + List[i % Size].NameFile;
        while (QFileInfo::exists(It))
        {
            It = path + "/" + "(" + QString::fromStdString(to_string(k)) + ")" + List[i % Size].NameFile;
            k++;
        }

        if (k != 1)
            QFile :: rename(path + "/" + List[i % Size].NameFile, It);
        if (QFileInfo::exists(List[i % Size].WayFile) && !QFileInfo::exists(path + "/" + List[i % Size].NameFile))
        {
             //qDebug() << It.toStdString().c_str();
            // qDebug() << (List[i % Size].WayFile).toStdString().c_str();
            // qDebug() << path.toStdString().c_str();
            if(QFile::copy(List[i % Size].WayFile, path+"/"+List[i % Size].NameFile)) count++;// qDebug() << "Okey";
        }
        if(!a) break;
    }
    return count;
}


vector<char> PlayList::ReturnAllGenreChar()
{
    vector<char>AllGenre;
    vector<char>::iterator it;
    for (auto& i : List)
    {
        it = find(AllGenre.begin(), AllGenre.end(), i.Genre);
        if (it == AllGenre.end()) AllGenre.push_back(i.Genre);
    }
    return AllGenre;
}


vector<string> PlayList::ReturnAllGenre()
{
    vector<string>AllGenre;
    vector<string>::iterator it;
    for (auto& i : List)
    {
        it = find(AllGenre.begin(), AllGenre.end(), ReturnGenre(i.Genre));
        if (it == AllGenre.end()) AllGenre.push_back(ReturnGenre(i.Genre));
    }
    return AllGenre;
}

vector<string> PlayList::ReturnAllArtist()
{
    vector<string>AllArtist;
    vector<string>::iterator it;
    for (auto& i : List)
    {
        it = find(AllArtist.begin(), AllArtist.end(), i.Artist);
        if (it == AllArtist.end()) AllArtist.push_back(i.Artist);
    }
    return AllArtist;
}


PlayList PlayList::SeekArtist(QString a)
{
    PlayList b;
    for (auto& i : List)
    {
        if ((a == QString :: fromStdString(i.Artist)))
        {
            b.List.push_back(i);
            //i.PrintTag();
        }
    }
    return b;
}


PlayList PlayList::SeekGenre(char a)
{
    PlayList b;
    if (a <= 80 && a >= 0)
    {
        for (auto& i : List)
        {
            if (i.Genre == a)
            {
                b.List.push_back(i);
                //i.PrintTag();
            }
        }
    }
    return b;
}

int PlayList::SizePlaylist()
{
    //if(List.empty()) return 0;
    Size = List.size();
    return Size;
}

void PlayList::PrintPlaylist()
{
    for (int i = 0; i < List.size(); i++)
    {
        List[i].PrintTag();
        cout << endl;
    }
}

void PlayList::Checker()
{
    for (int i = 0; i < List.size(); i++)
    {
        if (!List[i].Check)
        {
            SizeFile -= List[i].Ves;
            List.erase(List.begin() + i);
            i--;
        }
    }
}



void PlayList::CreateList(QString path)
{
   //if (!filesystem::exists("C:\\Users\\Linnur\\Desktop\\Music\\МакSим - Дискография (2006-2018)-mp3.320")) return;
    if(!QFileInfo::exists(path) || path.isNull() || path.isEmpty() || !QDir::isAbsolutePath(path)) return;
    //
    QDirIterator audioFileIt(path, {"*.mp3"}, QDir::Files);
    while(audioFileIt.hasNext())
    {
        audioFileIt.next();
        MP3 a;
        a.NameFile=audioFileIt.fileName();
        a.Tag=audioFileIt.fileInfo().suffix();
        a.Ves=audioFileIt.fileInfo().size();
        SizeFile+=a.Ves;
        a.SetWay(audioFileIt.filePath());
        a.ScanTag();
       // a.PrintTag();
        if(a.Check) List.push_back(a);
        // a.ScanTag() - Добавить
        //qDebug() << a.WayFile;
        //qDebug() << audioFileIt.fileName();
        //qDebug() << audioFileIt.fileInfo().size();

       //qDebug() << audioFileIt.next();

       //qDebug() << "\n";
    }

}

    PlayList PlayList ::GenerateArtList(QStringList list)
    {
        PlayList a;
        for(int i=0; i < list.size(); i++)
        {
             a=a+ SeekArtist(list.at(i));
        }
        return a;
    }

    PlayList PlayList ::GenerateGenList(QString str)
    {
        PlayList a;
        for(int i=0;i<str.size();i++)
        {
            a=a+SeekGenre(str.at(i).toLatin1());
        }
        return a;
    }

    char StringToCharGenre(string str)
    {
        string TAB[80] = { "Blues","Classic Rock", "Country", "Dance","Disco","Funk","Grunge","Hip - Hop", "Jazz", "Metal", "New Age", "Oldies", "Other", "Pop",
        "R & B","Rap","Reggae","Rock","Techno","Industrial","Alternative","Ska","Death Metal","Pranks","Soundtrack","Euro - Techno",
            "Ambient","Trip - Hop","Vocal","Jazz + Funk","Fusion","Trance","Classical","Instrumental","Acid","House",
            "Game","Sound Clip","Gospel","Noise","AlternRock","Bass","Soul","Punk","Space","Meditative","Instrumental Pop",
            "Instrumental Rock","Ethnic","Gothic","Darkwave","Techno - Industrial","Electronic","Pop - Folk"
            ,"Eurodance","Dream","Southern Rock","Comedy","Cult","Gangsta","Top 40","Christian Rap","Pop / Funk",
            "Jungle","Native American","Cabaret","New Wave","Psychadelic","Rave","Showtunes","Trailer","Lo - Fi",
            "Tribal","Acid Punk","Acid Jazz","Polka","Retro","Musical","Rock & Roll","Hard Rock" };
        for(int i=0;i<80;i++)
        {
            if(str == TAB[i]) return i;
        }
    }

#endif
