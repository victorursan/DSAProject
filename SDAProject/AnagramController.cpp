//
// Created by Victor Ursan on 6/1/15.
//

#include "AnagramController.h"

DynamicVector<string> AnagramController::anagramsForWord(string word) {
  for (int i = 0; i<repo->getAll().getSize(); i++){
    string key = repo->getAll().elementAtIndex(i);
    map.addValueAndKey(key, sortWord(key));
  }

  word = sortWord(word);
  DynamicVector<string> elements = DynamicVector<string>();
  Node<string, string> *first = map.getNodeForValue(word);
  while (first != NULL && first->getData()->getValue() == word) {
    elements.add(first->getData()->getKey());
    first = first->getNext();
  }
  return elements;
}

string AnagramController::sortWord(string word){
  sort(word.begin(), word.end());
  return word;
}


