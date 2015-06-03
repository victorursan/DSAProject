//
// Created by Victor Ursan on 6/1/15.
//

#ifndef DSAPROJECT_TESTMAPDVECTOR_H
#define DSAPROJECT_TESTMAPDVECTOR_H

#include <assert.h>
#include "MapDVector.h"

using namespace std;

void test_addValueAndKey_mapDVector() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.getKeys().getSize()==4);
}
//void addValueAndKey(Key key, Value value);

void test_updateValueForKey_mapDVector() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  map.updateValueForKey("2","iii");
  assert(map.valueForKey("2") == "iii");
}
//void updateValueForKey(Key key, Value value);

void test_UpdateKeyForValue_mapDVector() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  map.updateKeyForValue("una", "8");
  assert(map.valueForKey("8") == "una");
}
//void updateKeyForValue(Value value, Key key);

void test_valueForKey_mapDVector() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.valueForKey("2") == "una");
}
//Value valueForKey(Key key);

void test_keyForValue_mapDVector() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.keyForValue("ana") == "1");
}
//Key keyForValue(Value value);

void test_removeKey_mapDVector() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  map.removeKey("3");
  assert(map.getKeys().getSize() == 3);
}
//void removeKey(Key key);

void test_removeValue_mapDVector() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  map.removeValue("ana");
  assert(map.getKeys().getSize() == 3);
}
//void removeValue(Value value);

void test_doesKeyExist_mapDVector() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.doesKeyExist("3"));
}
//bool doesKeyExist(Key key);

void test_doesValueExist_mapDVector() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.doesValueExist("ana"));
}
//bool doesValueExist(Value value);

void test_getKeys_mapDVector() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.getKeys().elementAtIndex(3) == "4");
}
//DynamicVector<Key> getKeys();

void test_getValues_mapDVector() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.getValues().getSize() == 4);
}
//DynamicVector<Value> getValues();

void test_all_mapDVector() {
  test_addValueAndKey_mapDVector();
  test_doesKeyExist_mapDVector();
  test_doesValueExist_mapDVector();
  test_getKeys_mapDVector();
  test_getValues_mapDVector();
  test_removeKey_mapDVector();
  test_removeValue_mapDVector();
  test_updateValueForKey_mapDVector();
  test_UpdateKeyForValue_mapDVector();
  test_keyForValue_mapDVector();
  test_valueForKey_mapDVector();
}

#endif //DSAPROJECT_TESTMAPDVECTOR_H
