#include "parser.h"
#include "WordMap.h"
#include "context.h"
#include "utils.h"

int main()
{
    context Context("./config/default.rconfig");
    Context.displayConfig();

    Parser worker;
    //find the target directory to passer
    worker.addDirect("./InputText");
    worker.parseAll();
    //get the result of current parser
    std::vector<std::string>& wordVector=worker.getWordsVector();


    WordMap aMap;
    aMap.setSavePath("./WordLibrary/default.wl");
    for(auto word:wordVector){
        aMap.addWord(word);
    }
    aMap.showFrequency(30);
    aMap.saveFile();
}




