//
// Created by Victor Ursan on 6/1/15.
//

#include "AnagramController.h"

DynamicVector<string> AnagramController::anagramsForWord(string word) {
  DynamicVector<string> r = repo->getAll();
  for (int i = 0; i< r.getSize(); i++) {
    map.addValueAndKey(r.elementAtIndex(i) , i);
  }
  long int has  = map.has_function(word);
  DynamicVector<string> values = map.keysAndValuesForhas(has);
  print(word, values);
  return DynamicVector<string>();

}
void print(string word, DynamicVector<string> values) {
  DynamicVector<string> new_string;
  string s = word;
  cout<<endl;
  sort(s.begin(), s.end());
  while(next_permutation(s.begin(), s.end())) {
    if (values.doesContainElement(s)) {
      cout << s << endl;
    }
  }
}

