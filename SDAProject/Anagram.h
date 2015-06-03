//
//  Anagram.h
//  SDAProject
//
//  Created by Victor Ursan on 6/3/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#ifndef SDAProject_Anagram_h
#define SDAProject_Anagram_h

#include <stdio.h>
#include "DynamicVector.h"

using namespace std;

class Anagram {
public:
  virtual DynamicVector<string> anagramsForWord(string word) = 0;
  virtual string sortWord(string word) = 0;
};

#endif
