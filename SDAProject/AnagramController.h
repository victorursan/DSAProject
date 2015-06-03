//
// Created by Victor Ursan on 6/1/15.
//

#ifndef DSAPROJECT_ANAGRAMCONTROLLER_H
#define DSAPROJECT_ANAGRAMCONTROLLER_H

#include "Anagram.h"
#include "MapHash.h"
#include "AbstractRepositoy.h"

using namespace std;

class AnagramController : public Anagram {
  MapHash<string, string> map = MapHash<string, string>();
  AbstractRepository<string> *repo;
public:
  AnagramController(AbstractRepository<string> *repo) {this->repo = repo;};
  DynamicVector<string> anagramsForWord(string word);
  string sortWord(string word);
};
#endif //DSAPROJECT_ANAGRAMCONTROLLER_H
