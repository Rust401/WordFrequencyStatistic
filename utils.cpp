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

bool ifSuffixMatch(std::string& fileName,std::string& targetSuffix){
    uint8_t pos=fileName.find_last_of('.');
    std::string suffix=fileName.substr(pos);
    for(auto& c:suffix){
        if(c>='A'&&c<='Z'){
            c=c-'A'+'a';
        }
    }
    for(auto& c:targetSuffix){
        if(c>='A'&&c<='Z'){
            c=c-'A'+'a';
        }
    }
    if(suffix.compare("."+targetSuffix)){
        return false;
    }else{
        return true;
    }
}

void split(const std::string& str, std::vector<std::string>& tokens,const std::string& delimiters){
    std::string::size_type lastPos=str.find_first_not_of(delimiters,0);
    std::string::size_type pos=str.find_first_of(delimiters,lastPos);
    while(std::string::npos!=lastPos||std::string::npos!=pos){
        tokens.push_back(str.substr(lastPos,pos-lastPos));
        lastPos=str.find_first_not_of(delimiters,pos);
        pos=str.find_first_of(delimiters,lastPos);
    }
}

