#ifndef PARSER_H
#define PARSER_H

#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<map>
#include<memory.h>
#include<memory>
#include<string.h>


class Parser
{
public:
    std::vector<std::string> _parseredWords;
    std::vector<std::string> _pathsToHandle;
    char* _currentPosition;
    char* _bufferHead;
    uint32_t _bufferSize;
public:
    Parser(const std::string& Input="");
    virtual ~Parser();
    virtual std::string addFile(const std::string& path);
    virtual void addDirect(const std::string& dir);
    virtual void addFilePath(const std::string& path);
    virtual void beginParse();
    virtual void parseAll();
    virtual std::vector<std::string>& getWordsVector();
private:
    virtual void display();
    virtual void coreParse(char* choosenBufferHead);
    virtual void anotherParse(const std::string& Input);
};

#endif//PARSER_H