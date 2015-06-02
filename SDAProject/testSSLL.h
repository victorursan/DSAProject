//
//  testSSLL.h
//  SDAProject
//
//  Created by Victor Ursan on 6/2/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#ifndef SDAProject_testSSLL_h
#define SDAProject_testSSLL_h

#include <assert.h>
#include "LinkedList.h"

using namespace std;

void test_insert() {
  SortedList<string, string> lst = SortedList<string, string>();
  Pair<string, string> *p2 = new Pair<string, string>("ana2", "suge1");
  Pair<string, string> *p1 = new Pair<string, string>("ana", "suge");
  Pair<string, string> *p3 = new Pair<string, string>("ana3", "suge2");
  lst.addPair(p1);
  lst.addPair(p2);
  lst.addPair(p3);
  assert("suge" == lst.findValueForKey("ana"));
  assert("suge1" == lst.findValueForKey("ana2"));
  assert("suge2" == lst.findValueForKey("ana3"));
}

void test_ssll(){
  test_insert();
}


#endif
