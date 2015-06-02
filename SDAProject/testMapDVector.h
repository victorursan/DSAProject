//
// Created by Victor Ursan on 6/1/15.
//

#ifndef DSAPROJECT_TESTMAPDVECTOR_H
#define DSAPROJECT_TESTMAPDVECTOR_H

#include <assert.h>
#include "MapDVector.h"

using namespace std;

void test_addValueAndKey() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.getKeys().getSize()==4);
}
//void addValueAndKey(Key key, Value value);

void test_updateValueForKey() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  map.updateValueForKey("2","iii");
  assert(map.valueForKey("2") == "iii");
}
//void updateValueForKey(Key key, Value value);

void test_UpdateKeyForValue() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  map.updateKeyForValue("una", "8");
  assert(map.valueForKey("8") == "una");
}
//void updateKeyForValue(Value value, Key key);

void test_valueForKey() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.valueForKey("2") == "una");
}
//Value valueForKey(Key key);

void test_keyForValue() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.keyForValue("ana") == "1");
}
//Key keyForValue(Value value);

void test_removeKey() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  map.removeKey("3");
  assert(map.getKeys().getSize() == 3);
}
//void removeKey(Key key);

void test_removeValue() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  map.removeValue("ana");
  assert(map.getKeys().getSize() == 3);
}
//void removeValue(Value value);

void test_doesKeyExist() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.doesKeyExist("3"));
}
//bool doesKeyExist(Key key);

void test_doesValueExist() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.doesValueExist("ana"));
}
//bool doesValueExist(Value value);

void test_getKeys() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.getKeys().elementAtIndex(3) == "4");
}
//DynamicVector<Key> getKeys();

void test_getValues() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.getValues().getSize() == 4);
}
//DynamicVector<Value> getValues();

void test_all() {
  test_addValueAndKey();
  test_doesKeyExist();
  test_doesValueExist();
  test_getKeys();
  test_getValues();
  test_removeKey();
  test_removeValue();
  test_updateValueForKey();
  test_UpdateKeyForValue();
  test_keyForValue();
  test_valueForKey();
}

#endif //DSAPROJECT_TESTMAPDVECTOR_H
