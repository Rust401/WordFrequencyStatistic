#include "parser.h"
#include "WordMap.h"
#include "utils.h"

int main()
{
    Parser worker;
    worker.addDirect("./InputText");
    worker.parseAll();
    std::vector<std::string>& wordVector=worker.getWordsVector();
    WordMap dude;
    dude.setSavePath("./WordLibrary/default.wl");
    for(auto hajier:wordVector){
        dude.addWord(hajier);
    }
    dude.showFrequency(20);
    dude.saveFile();
}




