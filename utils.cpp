#include "utils.h"

using namespace boost::filesystem;

std::vector<std::string> getFileNames(const std::string& dirName){
    std::vector<std::string> result;
    path curDir(dirName);
    for (auto i = directory_iterator(curDir); i != directory_iterator(); i++)
    {
        if (!is_directory(i->path())){
            result.push_back(i->path().filename().string());
        }else{
            continue;
        }
    }
    return result;
}

