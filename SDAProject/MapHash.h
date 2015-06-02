//
// Created by Victor Ursan on 6/2/15.
//

#ifndef DSAPROJECT_MAPHASH_H
#define DSAPROJECT_MAPHASH_H

#include "Map.h"
#include "LinkedList.h"
#include "string.h"

#define TABLE_SIZE 122

template <typename Key, typename Value>
class MapHash: Map<Key, Value> {
  SortedList<Key, Value> lst[TABLE_SIZE];

  DynamicVector<Key> keys;

  int hash_function(string key);

  int hash_value(string key);

public:
  DynamicVector<Key> keysAndValuesForHash( int has);

  void addValueAndKey(Key key, Value value);

  void updateValueForKey(Key key, Value value);

  Value valueForKey(Key key);

  Key keyForValue(Value value);

  void removeKey(Key key);

  void removeValue(Value value);

  bool doesKeyExist(Key key);

  bool doesValueExist(Value value);

  DynamicVector<Key> getKeys();

  DynamicVector<Value> getValues();

  Node<Key, Value>* getNodeForValue(Value value);
};

template <typename Key, typename Value>
int MapHash<Key, Value>::hash_function(string key) {
  int sum = 0;
  for (auto k : key) {
    sum += (int)k;
  }
  return sum;
}

template <typename Key, typename Value>
int MapHash<Key, Value>::hash_value(string key) {
  return hash_function(key) % TABLE_SIZE;
}

template <typename Key, typename Value>
void MapHash<Key, Value>::addValueAndKey(Key key, Value value) {
  keys.add(key);
  Pair<Key, Value> *pair = new Pair<Key, Value>(key, value);
  int hash_int = hash_value(key);
  this->lst[hash_int].addPair(pair);
}

template <typename Key, typename Value>
void MapHash<Key, Value>::updateValueForKey(Key key, Value value) {
  int hash_int = hash_value(key);
  this->lst[hash_int].updateValueForKey(key, value);
}

template <typename Key, typename Value>
Value MapHash<Key, Value>::valueForKey(Key key) {
  int hash_int = hash_value(key);
  return this->lst[hash_int].findValueForKey(key);
}

template <typename Key, typename Value>
Key MapHash<Key, Value>::keyForValue(Value value) {
  int hash_int = hash_value(value);
  return lst[hash_int].findKeyForValue(value);
}

template <typename Key, typename Value>
void MapHash<Key, Value>::removeKey(Key key) {
  Value val = this->lst->findValueForKey(key);
  Pair<Key, Value> *p = new Pair<Key, Value>(key, val);
  this->lst->removePair(p);
}

template <typename Key, typename Value>
void MapHash<Key, Value>::removeValue(Value value) {
  Key key = this->lst->findKeyForValue(value);
  keys.removeElement(key);
  Pair<Key, Value> *p = new Pair<Key, Value>(key, value);
  this->lst->removePair(p);
}

template <typename Key, typename Value>
bool MapHash<Key, Value>::doesKeyExist(Key key) {
  bool ok = this->lst->doesKeyExist(key);
  return ok;
}

template <typename Key, typename Value>
bool MapHash<Key, Value>::doesValueExist(Value value) {
  int hash_int = hash_value(value);
  bool ok = lst[hash_int].doesValueExist(value);
  return ok;
}

template <typename Key, typename Value>
DynamicVector<Key> MapHash<Key, Value>::getKeys() {
  return keys;
}

template <typename Key, typename Value>
DynamicVector<Value> MapHash<Key, Value>::getValues() {
  DynamicVector<Value> new_values = DynamicVector<Value>();
  for(int i = 0; i < keys.getSize(); i++) {
    Key key = keys.elementAtIndex(i);
    Value value = lst[hash_value(key)].findValueForKey(key);
    new_values.add(value);
  }
  return new_values;
}

template <typename Key, typename Value>
Node<Key, Value>* MapHash<Key, Value>::getNodeForValue(Value value) {
  return lst[hash_value(value)].findFirstNode(value);
}

#endif //DSAPROJECT_MAPHASH_H
