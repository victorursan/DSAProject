//
//  SecondAnagramController.cpp
//  SDAProject
//
//  Created by Victor Ursan on 6/3/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#include "SecondAnagramController.h"

DynamicVector<string> SecondAnagramController::anagramsForWord(string word) {
  for (int i = 0; i<repo->getAll().getSize(); i++){
    string key = repo->getAll().elementAtIndex(i);
    map->addValueAndKey(key, sortWord(key));
  }

  word = sortWord(word);
  DynamicVector<string> elements = DynamicVector<string>();
//  Node<string, string> *first = map->getNodeForValue(word);
//  while (first != NULL && first->getData()->getValue() == word) {
//    elements.add(first->getData()->getKey());
//    first = first->getNext();
//  }
  return elements;
}

string SecondAnagramController::sortWord(string word){
  string smth = word;
  sort(smth.begin(), smth.end());
  return smth;
}
