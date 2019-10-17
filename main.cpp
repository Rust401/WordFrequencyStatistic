#include "parser.h"
#include "WordMap.h"

int main()
{
    Parser worker;
    std::string input=worker.addFile("./InputText/test1.txt");
    worker.anotherParse(input);
    std::vector<std::string>& wordVector=worker.getWordsVector();
    WordMap dude;
    dude.setSavePath("./WordLibrary/default.wl");
    for(auto hajier:wordVector){
        dude.addWord(hajier);
    }
    dude.showFrequency(10);
    dude.saveFile();
}