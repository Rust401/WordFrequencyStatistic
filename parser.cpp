#include "parser.h"
#include "utils.h"

bool isLetter(char c){
    return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
}

bool isDigit(char c){
    return (c>='0')&&(c<='9');
}

bool isNormal(char c){
    return isLetter(c)||isDigit(c);
}

bool isBlank(char c){
    return c=='\t'||c=='\n'||c=='\r'||c==' ';
}

bool isTxt(const std::string fileName){
    uint8_t pos=fileName.find_last_of('.');
    std::string suffix=fileName.substr(pos);
    if(suffix.compare(".txt")){
        return false;
    }else{
        return true;
    }
}


Parser::Parser(const std::string& Input){
    _bufferHead=new char[Input.length()+1];
    _bufferSize=Input.length()+1;
    if(_bufferHead==nullptr){
        perror("memory error");
        exit(1);
    }
    memset(_bufferHead,0,Input.length()+1);
    strcpy(_bufferHead,Input.c_str());
    *(_bufferHead+_bufferSize-1)='\0';
    _currentPosition=_bufferHead;
}

Parser::~Parser(){delete[] _bufferHead;}

std::string Parser::readFileToString(const std::string& inputPath){
    const char* path=inputPath.c_str();
    FILE* fp=fopen(path,"r");
    if(fp==nullptr){
        perror("open failed");
        exit(1);
    }
    char* buffer=new char[300000];
    if(buffer==nullptr){
        perror("memory error");
        exit(1);
    }
    uint32_t byteSize=fread(buffer,1,300000,fp);
    *(buffer+byteSize)='\0';
    std::string input=buffer;
    delete[] buffer;
    fclose(fp);
    return input;
}

void Parser::addDirect(const std::string& inputPath){
    auto tmpDirec=getFileNames(inputPath);
    for(auto dude:tmpDirec){
        if(isTxt(dude)){
            _pathsToHandle.push_back(dude);
            std::cout<<dude<<" added"<<std::endl;
        }else{
            continue;
        }
    }
}

void Parser::addFilePath(const std::string& inputPath){
    _pathsToHandle.push_back(inputPath);
}

void Parser::beginParse(){
    coreParse(_bufferHead);
    //display();
}

void Parser::parseAll(){
    for(auto dude:_pathsToHandle){
        anotherParse(readFileToString("./InputText/"+dude));
    }
}

void Parser::anotherParse(const std::string& Input){
    char* newbufferHead=new char[Input.length()+1];
    _bufferSize=Input.length()+1;
    if(newbufferHead==nullptr){
        perror("memory error");
        exit(1);
    }
    memset(newbufferHead,0,Input.length()+1);
    strcpy(newbufferHead,Input.c_str());
    *(newbufferHead+_bufferSize-1)='\0';
    _currentPosition=newbufferHead;
    coreParse(newbufferHead);
    //display();
    delete[] newbufferHead;
}

std::vector<std::string>& Parser::getWordsVector(){
    return _parseredWords;
}

void Parser::display(){
    for(auto dude:_parseredWords){
        std::cout<<dude<<std::endl;
    }
}

void Parser::coreParse(char* choosenBufferHead){
    char* border=choosenBufferHead+_bufferSize;
    while(_currentPosition<border){
        if(isblank(*_currentPosition)){
            ++_currentPosition;
            continue;
        }else if(isNormal((*_currentPosition))){
            char* tail=_currentPosition;
            while(isNormal(*tail)){
                ++tail;
            }
            char tmp=*tail;
            *tail='\0';
            std::string currentWord=_currentPosition;
            _parseredWords.push_back(currentWord);
            *tail=tmp;
            _currentPosition=tail;
        }else{
            ++_currentPosition;
        }
    }
}
