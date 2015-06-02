//
//  testMapHash.h
//  SDAProject
//
//  Created by Victor Ursan on 6/3/15.
//  Copyright (c) 2015 Victor Ursan. All rights reserved.
//

#ifndef SDAProject_testMapHash_h
#define SDAProject_testMapHash_h

using namespace std;

void test_addValueAndKey_mapHash() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.getKeys().getSize()==4);
}
//void addValueAndKey(Key key, Value value);

void test_updateValueForKey_mapHash() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  map.updateValueForKey("2","iii");
  assert(map.valueForKey("2") == "iii");
}
//void updateValueForKey(Key key, Value value);

void test_UpdateKeyForValue_mapHash() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  map.updateKeyForValue("una", "8");
  assert(map.valueForKey("8") == "una");
}
//void updateKeyForValue(Value value, Key key);

void test_valueForKey_mapHash() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.valueForKey("2") == "una");
}
//Value valueForKey(Key key);

void test_keyForValue_mapHash() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.keyForValue("ana") == "1");
}
//Key keyForValue(Value value);

void test_removeKey_mapHash() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  map.removeKey("3");
  assert(map.getKeys().getSize() == 3);
}
//void removeKey(Key key);

void test_removeValue_mapHash() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  map.removeValue("ana");
  assert(map.getKeys().getSize() == 3);
}
//void removeValue(Value value);

void test_doesKeyExist_mapHash() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.doesKeyExist("3"));
}
//bool doesKeyExist(Key key);

void test_doesValueExist_mapHash() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.doesValueExist("ana"));
}
//bool doesValueExist(Value value);

void test_getKeys_mapHash() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.getKeys().elementAtIndex(3) == "4");
}
//DynamicVector<Key> getKeys();

void test_getValues_mapHash() {
  MapDVector<string, string> map = MapDVector<string, string> ();
  map.addValueAndKey("1", "ana");
  map.addValueAndKey("2", "una");
  map.addValueAndKey("3", "yna");
  map.addValueAndKey("4", "tna");
  assert(map.getValues().getSize() == 4);
}
//DynamicVector<Value> getValues();

void test_all_mapHash() {
  test_addValueAndKey_mapHash();
  test_doesKeyExist_mapHash();
  test_doesValueExist_mapHash();
  test_getKeys_mapHash();
  test_getValues_mapHash();
  test_removeKey_mapHash();
  test_removeValue_mapHash();
  test_updateValueForKey_mapHash();
  test_UpdateKeyForValue_mapHash();
  test_keyForValue_mapHash();
  test_valueForKey_mapHash();
}

#endif
