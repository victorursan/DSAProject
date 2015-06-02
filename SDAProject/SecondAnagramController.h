//
//  SecondAnagramController.h
//  SDAProject
//
//  Created by Victor Ursan on 6/3/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#ifndef __SDAProject__SecondAnagramController__
#define __SDAProject__SecondAnagramController__

#include <stdio.h>
#include "MapHash.h"
#include "AbstractRepositoy.h"

using namespace std;

class SecondAnagramController {
  Map<string, string> *map = new MapHash<string, string>();
  AbstractRepository<string> *repo;

public:
  SecondAnagramController(AbstractRepository<string> *repo) {this->repo = repo;};
  DynamicVector<string> anagramsForWord(string word);
  string sortWord(string word);
};
#endif /* defined(__SDAProject__SecondAnagramController__) */
