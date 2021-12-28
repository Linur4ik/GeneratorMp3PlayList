#ifndef SOURCEMAIN_H
#define SOURCEMAIN_H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
//#include <filesystem>
#include <fstream>
#include <vector>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include <QDir>
#include <QDirIterator>
#include "iconvlite.h"
#include <QStorageInfo>
#include <QDebug>

using namespace std;
string ReturnGenre(char);
void PrintAllGenre(vector<char>);
void PrintAllArtist(vector<string>);
 char StringToCharGenre(string);


class MP3
{
    friend class PlayList;
private:
    QString WayFile;
    QString NameFile;
    QString Tag;
    qint64 Ves;
    string Name;
    string Artist;
    string Album;
    string Year;
    string Comment;
    char Genre;
    bool Check = false;
public:
    void ScanTag();
    void PrintTag();
    void SetWay(QString);
};

class PlayList
{
    friend class MP3;
private:
    vector <MP3> List;
    int Size;
    qint64 SizeFile;
public:
    void Checker();
    void PrintSizeFile() { cout << "Size:" << SizeFile / 1024 / 1024 << endl; }
    void CreateList(QString);
    void PrintPlaylist();
    int SizePlaylist();
    PlayList SeekGenre(char);
    PlayList SeekArtist(QString);
    vector<string> ReturnAllGenre();
    vector<string> ReturnAllArtist();
    int Copy(int, QString,bool &,int&);
    PlayList operator + (PlayList);
    int RandomCopy(int, QString, bool &,int&);
    PlayList GenerateArtList(QStringList);
    PlayList GenerateGenList(QString);
    vector<char>ReturnAllGenreChar();

};

#endif // SOURCEMAIN_H
