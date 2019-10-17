#include "WordMap.h"

bool cmp(const std::pair<std::string,uint32_t> a,const std::pair<std::string,uint32_t> b){
    return a.second>b.second;
}

void WordMap::addWord(const std::string dudeToAdd){
    if(_coreMap.count(dudeToAdd)){
        ++_coreMap[dudeToAdd];
    }else{
        _coreMap.insert({dudeToAdd,1});
    }
}

void WordMap::removeWord(const std::string dudeToRemove){
    if(_coreMap.count(dudeToRemove)){
        _coreMap.erase(dudeToRemove);
    }
}

void WordMap::showFrequency(const uint32_t itemNumber){
    std::vector<std::pair<std::string,uint32_t>> tmpVector(_coreMap.begin(),_coreMap.end());
    std::sort(tmpVector.begin(),tmpVector.end(),cmp);
    int n=(itemNumber>tmpVector.size())?tmpVector.size():itemNumber;
    for(int i=0;i<n;++i){
        printf("%s\t\t%u\n",tmpVector[i].first.c_str(),tmpVector[i].second);
    }
}

void WordMap::saveFile(){
    reallySave();
}

void WordMap::dictInit(){
    char *buffer=new char[MAXSIZE];
    if(buffer==nullptr){
        perror("memory error");
        exit(1);
    }
    memset(buffer,0,MAXSIZE);
    
    FILE* fp;
    fp=fopen(_pathToOpen.c_str(),"rb");
    if(fp==nullptr){
        perror("open failed");
        exit(1);
    }

    fread(buffer,1,MAXSIZE,fp);
    char* p=buffer;
    while((*p)!='\0'){
        std::string tmpString=p;
        uint32_t tmpNumber=*(uint32_t*)(p+26);
        _coreMap.insert({tmpString,tmpNumber});
        p+=30;
    }
    printf("Loading successfully!\n");
    delete[] buffer;
    fclose(fp);
}



void WordMap::reallySave(){
    std::vector<std::pair<std::string,uint32_t>> tmpVector(_coreMap.begin(),_coreMap.end());
    std::sort(tmpVector.begin(),tmpVector.end(),cmp);
    char* buffer=new char[MAXSIZE];
    if(buffer==nullptr){
        perror("memory error");
        exit(1);
    }
    memset(buffer,0,MAXSIZE);
    char* p=buffer;
    for(int i=0;i<tmpVector.size();++i){
        strcpy(p,tmpVector[i].first.c_str());
        *(p+25)='\0';
        *(uint32_t*)(p+26)=tmpVector[i].second;
        p+=30;
    }
    FILE* fp=fopen(_pathToSave.c_str(),"wb");
    if(fp==nullptr){
        perror("open Failed");
        exit(1);
    }
    fwrite(buffer,1,MAXSIZE,fp);
    fclose(fp);
    delete[] buffer;
}

