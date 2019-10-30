#ifndef CONTEXT_H
#define CONTEXT_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <memory.h>
#include <memory>
#include <string.h>
#include "utils.h"

class context
{
public:
    std::vector<std::string> _dirToOpen;
    std::vector<std::string> _typeToSupport;
    std::string _dictToOpen;
    std::vector<std::string> _dictToSave;
    uint32_t _itemNumsToDisplay;

    context(const std::string &configPath);
    void reInit(const std::string &configPath);
    void displayConfig();
};

#endif //CONTEXT_H