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
  void swap(char *a, char *b ) {
    //swap 2 characters between them
    char temp = *a;
    *a = *b;
    *b = temp;
  }
public:
  virtual DynamicVector<string> anagramsForWord(string word) = 0;
  virtual string sortWord(string word) = 0;
  void sortChar(char *word) {
    //sort a char* aplhabetically
    for (unsigned int i = 0; i < strlen(word) - 1; i++)
      for (unsigned int j = i + 1; j < strlen(word); j++)
        if (word[i] > word[j])
          swap(&word[i], &word[j]);
  }

};

#endif
