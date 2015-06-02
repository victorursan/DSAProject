//
// Created by Victor Ursan on 5/31/15.
//

#include "Console.h"
#include "AnagramController.h"

using namespace std;

Console::~Console() {

};

void Console::run() {
    string word;
    cout<<"string: "<<endl;
    cin>>word;
    ctrl->anagramsForWord(word);
}
