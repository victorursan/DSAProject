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
  Pair<string, string> *p2 = new Pair<string, string>("ana2", "mere1");
  Pair<string, string> *p1 = new Pair<string, string>("ana", "mere");
  Pair<string, string> *p3 = new Pair<string, string>("ana3", "mere2");
  lst.addPair(p1);
  lst.addPair(p2);
  lst.addPair(p3);
  assert("mere" == lst.findValueForKey("ana"));
  assert("mere1" == lst.findValueForKey("ana2"));
  assert("mere2" == lst.findValueForKey("ana3"));
}

/*
 void removePair(Pair<Key, Value> *data);
 void addPair(Pair<Key, Value> *data);
 Value findValueForKey(Key key);
 Key findKeyForValue(Value value);
 void updateKeyForValue(Value value, Key key);
 void updateValueForKey(Key key, Value value);
 bool doesKeyExist(Key key);
 bool doesValueExist(Value value);
 Node<Key, Value>* findFirstNode(Value value);

 */

void test_ssll(){
  test_insert();
}


#endif
