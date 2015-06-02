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

void test_addPair_SSLL() {
  // void addPair(Pair<Key, Value> *data);
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

void test_removePair_SSLL() {
  //void removePair(Pair<Key, Value> *data);
  SortedList<string, string> lst = SortedList<string, string>();
  Pair<string, string> *p2 = new Pair<string, string>("ana2", "mere1");
  Pair<string, string> *p1 = new Pair<string, string>("ana", "mere");
  Pair<string, string> *p3 = new Pair<string, string>("ana3", "mere2");
  lst.addPair(p1);
  lst.addPair(p2);
  lst.addPair(p3);
  lst.removePair(p1);
  assert("mere1" == lst.findValueForKey("ana2"));
  assert("mere2" == lst.findValueForKey("ana3"));


}

void test_findValueForKey_SSLL() {
  //Value findValueForKey(Key key);
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

void test_findKeyForValue_SSLL() {
  //Key findKeyForValue(Value value);
  SortedList<string, string> lst = SortedList<string, string>();
  Pair<string, string> *p2 = new Pair<string, string>("ana2", "mere1");
  Pair<string, string> *p1 = new Pair<string, string>("ana", "mere");
  Pair<string, string> *p3 = new Pair<string, string>("ana3", "mere2");
  lst.addPair(p1);
  lst.addPair(p2);
  lst.addPair(p3);
  assert("ana" == lst.findKeyForValue("mere"));
  assert("ana2" == lst.findKeyForValue("mere1"));
  assert("ana3" == lst.findKeyForValue("mere2"));

}

void test_updateKeyForValue_SSLL() {
  //void updateKeyForValue(Value value, Key key);
  SortedList<string, string> lst = SortedList<string, string>();
  Pair<string, string> *p2 = new Pair<string, string>("ana2", "mere1");
  Pair<string, string> *p1 = new Pair<string, string>("ana", "mere");
  Pair<string, string> *p3 = new Pair<string, string>("ana3", "mere2");
  lst.addPair(p1);
  lst.addPair(p2);
  lst.addPair(p3);
  lst.updateKeyForValue("mere", "a");
  assert("mere" == lst.findValueForKey("a"));
  assert("mere1" == lst.findValueForKey("ana2"));
  assert("mere2" == lst.findValueForKey("ana3"));

}

void test_updateValueForKey_SSLL() {
  //void updateValueForKey(Key key, Value value);
  SortedList<string, string> lst = SortedList<string, string>();
  Pair<string, string> *p2 = new Pair<string, string>("ana2", "mere1");
  Pair<string, string> *p1 = new Pair<string, string>("ana", "mere");
  Pair<string, string> *p3 = new Pair<string, string>("ana3", "mere2");
  lst.addPair(p1);
  lst.addPair(p2);
  lst.addPair(p3);
  lst.updateValueForKey("ana", "mr");
  assert("mr" == lst.findValueForKey("ana"));
  assert("mere1" == lst.findValueForKey("ana2"));
  assert("mere2" == lst.findValueForKey("ana3"));

}

void test_doesKeyExist_SSLL() {
  // bool doesKeyExist(Key key);
  SortedList<string, string> lst = SortedList<string, string>();
  Pair<string, string> *p2 = new Pair<string, string>("ana2", "mere1");
  Pair<string, string> *p1 = new Pair<string, string>("ana", "mere");
  Pair<string, string> *p3 = new Pair<string, string>("ana3", "mere2");
  lst.addPair(p1);
  lst.addPair(p2);
  lst.addPair(p3);
  assert(lst.doesKeyExist("ana"));
}

void test_doesValueExist_SSLL() {
  // bool doesValueExist(Value value);
  SortedList<string, string> lst = SortedList<string, string>();
  Pair<string, string> *p2 = new Pair<string, string>("ana2", "mere1");
  Pair<string, string> *p1 = new Pair<string, string>("ana", "mere");
  Pair<string, string> *p3 = new Pair<string, string>("ana3", "mere2");
  lst.addPair(p1);
  lst.addPair(p2);
  lst.addPair(p3);
  assert(lst.doesValueExist("mere"));
}

void test_findFirstNode__SSLL() {
  // Node<Key, Value>* findFirstNode(Value value);
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


void test_ssll(){
  test_addPair_SSLL();
  test_removePair_SSLL();
  test_findValueForKey_SSLL();
  test_findKeyForValue_SSLL();
  test_updateKeyForValue_SSLL();
  test_updateValueForKey_SSLL();
  test_doesKeyExist_SSLL();
  test_doesValueExist_SSLL();
  test_findFirstNode__SSLL();
}


#endif
