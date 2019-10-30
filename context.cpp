#include "context.h"
#include "utils.h"

context::context(const std::string& configPath){
    reInit(configPath);
}

void context::reInit(const std::string& configPath){
    FILE* fp=fopen(configPath.c_str(),"r");
    if(fp==nullptr){
        perror("open failed");
        exit(1);
    }
    char* buffer=new char[500];
    if(buffer==nullptr){
        perror("memory error");
        exit(1);
    }
    uint32_t byteSize=fread(buffer,1,500,fp);
    *(buffer+byteSize)='\0';
    std::string input=buffer;

    std::vector<std::string> lines;
    split(input,lines,";");
    
    //dirToOpen
    std::string::size_type slow=lines[0].find_first_of("\"");
    std::string::size_type fast=lines[0].find_last_of("\"");
    std::string dirs=lines[0].substr(slow+1,fast-slow-1);
    split(dirs,_dirToOpen,",");

    //typeToSupport
    slow=lines[1].find_first_of("\"");
    fast=lines[1].find_last_of("\"");
    std::string types=lines[1].substr(slow+1,fast-slow-1);
    split(types,_typeToSupport,",");

    //dictToOpen
    slow=lines[2].find_first_of("\"");
    fast=lines[2].find_last_of("\"");
    _dictToOpen=lines[2].substr(slow+1,fast-slow-1);

    //dictToSave
    slow=lines[3].find_first_of("\"");
    fast=lines[3].find_last_of("\"");
    std::string dicts=lines[3].substr(slow+1,fast-slow-1);
    split(dicts,_dictToSave,",");

    //itemNumsToDisplay
    slow=lines[4].find_first_of("\"");
    fast=lines[4].find_last_of("\"");
    std::string num=lines[4].substr(slow+1,fast-slow-1);
    _itemNumsToDisplay=atoi(num.c_str());

    fclose(fp);
    delete[] buffer;
}

void context::displayConfig(){
    //dirToOpen
    std::cout<<"dirToOpen:\t\t";
    for(auto dude:_dirToOpen){
        std::cout<<dude<<" ";
    }
    std::cout<<std::endl;

    //typeToSupport
    std::cout<<"typeToSupport:\t\t";
    for(auto dude:_typeToSupport){
        std::cout<<dude<<" ";
    }
    std::cout<<std::endl;

    //dictToOpen
    std::cout<<"dictToOpen:\t\t"<<_dictToOpen<<std::endl;

    //typeToSupport
    std::cout<<"dictToSave:\t\t";
    for(auto dude:_dictToSave){
        std::cout<<dude<<" ";
    }
    std::cout<<std::endl;

    //itemNumsToDisplay
    std::cout<<"itemNumsToDisplay:\t"<<_itemNumsToDisplay<<std::endl;
}
