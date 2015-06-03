//
//  testDynamicVector.h
//  SDAProject
//
//  Created by Victor Ursan on 6/3/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#ifndef SDAProject_testDynamicVector_h
#define SDAProject_testDynamicVector_h

#include <stdio.h>
#include <assert.h>

void test_add_DynamicVector() {
  //void add(TElement e);
  DynamicVector<int> store = DynamicVector<int>();
  store.add(1);
  store.add(2);
  store.add(3);
  store.add(4);
  assert(store.getSize() == 4);
}

void test_removeAtIndex_DynamicVector() {
  //void removeAtIndex(int index);
  DynamicVector<int> store = DynamicVector<int>();
  store.add(1);
  store.add(2);
  store.add(3);
  store.add(4);
  store.removeAtIndex(2);
  assert(store.getSize() == 3);

}

void test_removeElement_DynamicVector() {
  //void removeElement(TElement e);
  DynamicVector<int> store = DynamicVector<int>();
  store.add(1);
  store.add(2);
  store.add(3);
  store.add(4);
  store.removeElement(3);
  assert(store.getSize() == 3);

}

void test_updateElement_DynamicVector() {
  //void updateElement(int index, TElement element);
  DynamicVector<int> store = DynamicVector<int>();
  store.add(1);
  store.add(2);
  store.add(3);
  store.add(4);
  store.updateElement(2, 4);
  assert(store.elementAtIndex(2) == 4);

}

void test_elementAtIndex_DynamicVector() {
  //TElement elementAtIndex(int index);
  DynamicVector<int> store = DynamicVector<int>();
  store.add(1);
  store.add(2);
  store.add(3);
  store.add(4);
  assert(store.elementAtIndex(2) == 3);

}

void test_indexForElement_DynamicVector() {
  //int indexForElement(TElement e);
  DynamicVector<int> store = DynamicVector<int>();
  store.add(1);
  store.add(2);
  store.add(3);
  store.add(4);
  assert(store.indexForElement(2) == 1);

}

void test_getSize_DynamicVector() {
  //int getSize();
  DynamicVector<int> store = DynamicVector<int>();
  store.add(1);
  store.add(2);
  store.add(3);
  store.add(4);
  assert(store.getSize() == 4);

}

void test_isEmpty_DynamicVector() {
  //bool isEmpty();
  DynamicVector<int> store = DynamicVector<int>();
  store.add(1);
  store.add(2);
  store.add(3);
  store.add(4);
  assert(!store.isEmpty());
}

void test_doesContainElement_DynamicVector() {
  //bool doesContainElement(TElement e);
  DynamicVector<int> store = DynamicVector<int>();
  store.add(1);
  store.add(2);
  store.add(3);
  store.add(4);
  assert(store.doesContainElement(2));
}



void test_DynamicVector() {
  test_add_DynamicVector();
  test_removeAtIndex_DynamicVector();
  test_removeElement_DynamicVector();
  test_updateElement_DynamicVector();
  test_elementAtIndex_DynamicVector();
  test_indexForElement_DynamicVector();
  test_getSize_DynamicVector();
  test_isEmpty_DynamicVector();
  test_doesContainElement_DynamicVector();
}


#endif
