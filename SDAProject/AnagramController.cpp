//
// Created by Victor Ursan on 6/1/15.
//

#include "AnagramController.h"

DynamicVector<string> AnagramController::anagramsForWord(string word) {
  MapHash<string, string> map = MapHash<string, string>();

  for (int i = 0; i<repo->getAll().getSize(); i++){
    string key = repo->getAll().elementAtIndex(i);
    map.addValueAndKey(key, sortWord(key));
  }

  word = sortWord(word);
  DynamicVector<string> elements = DynamicVector<string>();
  Node<string, string> *first = map.getTable(word);
  cout<<"am iesit"<<endl;
  while (first != NULL && first->getData()->getValue() == word) {
    elements.add(first->getData()->getKey());
    first = first->getNext();
  }
  return elements;
}

string AnagramController::sortWord(string word){
  string smth = word;
  sort(smth.begin(), smth.end());
  return smth;
}


