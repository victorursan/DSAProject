//
// Created by Victor Ursan on 5/31/15.
//

#include "Console.h"
#include "AnagramController.h"
#include "DynamicVector.h"

using namespace std;

Console::~Console() {

};

void Console::run() {
  string word;
  cout<<"Word: "<<endl;
  cin>>word;
  DynamicVector<string> elements = ctrl->anagramsForWord(word);
  cout<<endl<<"Anagram words:"<<endl;
  for (int i = 0; i < elements.getSize(); i++) {
    cout<<i<<"."<<elements.elementAtIndex(i)<<endl;
  }
}
