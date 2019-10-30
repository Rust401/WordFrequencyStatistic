#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include <vector>
#include <boost/filesystem.hpp>

std::vector<std::string> getFileNames(const std::string& dirName);

bool isLetter(char c);

bool isDigit(char c);

bool isNormal(char c);

bool isBlank(char c);

bool ifSuffixMatch(std::string& fileName,std::string& targetSuffix);

void split(const std::string& str, std::vector<std::string>& tokens,const std::string& delimiters=" ");

#endif//UTILS_H
