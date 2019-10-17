#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<map>
#include<memory.h>
#include<memory>
#include<string.h>

#define MAXSIZE 300000
const std::string defaultPath="./WordLibrary/default.wl";


bool cmp(const std::pair<std::string,uint32_t> a,const std::pair<std::string,uint32_t> b){
    return a.second>b.second;
}

class WordMap
{
private:
    std::map<std::string,uint32_t> _coreMap;
    std::string _pathToSave;
    std::string _pathToOpen;
public:
    WordMap(const std::string toSave=defaultPath,const std::string toOpen=defaultPath):
    _pathToSave(toSave),_pathToOpen(toOpen){dictInit();}
    void setSavePath(const std::string toSave){_pathToSave=toSave;}
    void setOpenPath(const std::string toOpen){_pathToOpen=toOpen;}
    void addWord(const std::string dudeToAdd);
    void removeWord(const std::string dudeToRemove);
    void showFrequency(uint32_t itemNumber);
    void saveFile();

private:
    void dictInit();
    void reallySave();
};