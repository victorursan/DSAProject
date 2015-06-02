//
// Created by Victor Ursan on 6/1/15.
//

#ifndef DSAPROJECT_ANAGRAMCONTROLLER_H
#define DSAPROJECT_ANAGRAMCONTROLLER_H


#include "MapHash.h"
#include "AbstractRepositoy.h"

using namespace std;

class AnagramController {
  MapHash<string , int> map;
  AbstractRepository<string> *repo;

public:
  AnagramController(AbstractRepository<string> *repo) {this->repo = repo;};
  DynamicVector<string> anagramsForWord(string word);
  string sortWord(string word);
};
void print(string word, DynamicVector<string> );

#endif //DSAPROJECT_ANAGRAMCONTROLLER_H
