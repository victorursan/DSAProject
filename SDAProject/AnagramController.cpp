//
// Created by Victor Ursan on 6/1/15.
//

#include "AnagramController.h"

DynamicVector<string> AnagramController::anagramsForWord(string word) {
  //add the word as the key and the sorted word as value in the dictionary
  for (int i = 0; i<repo->getAll().getSize(); i++){
    string key = repo->getAll().elementAtIndex(i);
    map.addValueAndKey(key, sortWord(key));
  }

  word = sortWord(word);
  DynamicVector<string> elements = DynamicVector<string>();
  Node<string, string> *first = map.getNodeForValue(word);
  //find the first node that has as value, the desired sorted word and
  //add the key to the elements
  while (first != NULL && first->getData()->getValue() == word) {
    elements.add(first->getData()->getKey());
    first = first->getNext();
  }
  return elements;
}

string AnagramController::sortWord(string word){
  // sort the word alphabetically
  sortChar(&word[0]);
  return word;
}
