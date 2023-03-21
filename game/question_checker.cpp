#include "question_checker.h"

char QuestionsChecker::keyUp(const char chr){
    return chr == 'V' || chr == 'F' ? chr : chr - ('a' - 'A');
}

bool QuestionsChecker::checkC(const char chr){
    return (chr == 'V');
}

bool QuestionsChecker::checkCombinations(const string tmp){
    return ((tmp == ";V\n") || (tmp == ";F\n") || (tmp == ";v\n") || (tmp == ";f\n")); 
}

pair<list<Question>, unsigned int> QuestionsChecker::getPhrases(const string ph){
    string str = ph;
    str+='\n';

    unsigned int i = 0, j = 0;

    list<Question> date;
    string temp = string();

    while(i<str.length()){
        if(str[i] == ';'){
            string tmp;
            for(int y = 0; y < 3; y++){
                tmp+=str[i];
                i++;
            }
            if(checkCombinations(tmp)) {
                date.push_back(Question(temp, checkC(keyUp(tmp[1]))));
            }
            else {
                j++;
            }
            temp = string();
        }
        else{
            temp+=str[i];
            i++;
        }
    }

    if(temp!="\n") j++;
    return {date, j};
}