//
// Created by Victor Ursan on 6/2/15.
//

#ifndef DSAPROJECT_MAPHASH_H
#define DSAPROJECT_MAPHASH_H

#include "Map.h"
#include "LinkedList.h"
#include "string.h"

template <typename Key, typename Value>
class MapHash: Map<Key, Value> {
  SortedList<Key, Value> lst[199];

  DynamicVector<Key> keys;
public:
  long int has_function(string key);

  DynamicVector<Key> keysAndValuesForhas(long int has);

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
};

template <typename Key, typename Value>
long int MapHash<Key, Value>::has_function(string key) {
  long int i = 1;
  if (strrchr(&key[0], 'a') != NULL)
    i += 2^1;
  if (strrchr(&key[0], 'b') != NULL)
    i += 2^2;
  if (strrchr(&key[0], 'c') != NULL)
    i += 2^3;
  if (strrchr(&key[0], 'd') != NULL)
    i += 2^4;
  if (strrchr(&key[0], 'e') != NULL)
    i += 2^5;
  if (strrchr(&key[0], 'f') != NULL)
    i += 2^6;
  if (strrchr(&key[0], 'g') != NULL)
    i += 2^7;
  if (strrchr(&key[0], 'h') != NULL)
    i += 2^8;
  if (strrchr(&key[0], 'i') != NULL)
    i += 2^9;
  if (strrchr(&key[0], 'j') != NULL)
    i += 2^10;
  if (strrchr(&key[0], 'k') != NULL)
    i += 2^11;
  if (strrchr(&key[0], 'l') != NULL)
    i += 2^12;
  if (strrchr(&key[0], 'm') != NULL)
    i += 2^13;
  if (strrchr(&key[0], 'n') != NULL)
    i += 2^14;
  if (strrchr(&key[0], 'o') != NULL)
    i += 2^15;
  if (strrchr(&key[0], 'p') != NULL)
    i += 2^16;
  if (strrchr(&key[0], 'q') != NULL)
    i += 2^17;
  if (strrchr(&key[0], 'r') != NULL)
    i += 2^18;
  if (strrchr(&key[0], 's') != NULL)
    i += 2^19;
  if (strrchr(&key[0], 't') != NULL)
    i += 2^20;
  if (strrchr(&key[0], 'u') != NULL)
    i += 2^21;
  if (strrchr(&key[0], 'v') != NULL)
    i += 2^22;
  if (strrchr(&key[0], 'w') != NULL)
    i += 2^23;
  if (strrchr(&key[0], 'x') != NULL)
    i += 2^24;
  if (strrchr(&key[0], 'y') != NULL)
    i += 2^25;
  if (strrchr(&key[0], 'z') != NULL)
    i += 2^26;
  return i;
}


template <typename Key, typename Value>
void MapHash<Key, Value>::addValueAndKey(Key key, Value value) {
  Pair<Key, Value> *pair = new Pair<Key, Value>(key, value);
  keys.add(key);
  long int hash_int = has_function(key);
  this->lst[hash_int].addPair(pair);
}

template <typename Key, typename Value>
void MapHash<Key, Value>::updateValueForKey(Key key, Value value) {
  long int hash_int = has_function(key);
  this->lst[hash_int].updateValueForKey(key, value);
}

template <typename Key, typename Value>
Value MapHash<Key, Value>::valueForKey(Key key) {
  long int hash_int = has_function(key);
  return this->lst[hash_int].findValueForKey(key);
}

template <typename Key, typename Value>
Key MapHash<Key, Value>::keyForValue(Value value) {
  return lst->findKeyForValue(value);
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
  bool ok = lst->doesValueExist(value);
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
    new_values.add(lst->findValueForKey(keys.elementAtIndex(i)));
  }
  return new_values;
}

template <typename Key, typename Value>
DynamicVector<Key> MapHash<Key, Value>::keysAndValuesForhas(long int has) {
  DynamicVector<Key> values = keys;
  return values;
}

#endif //DSAPROJECT_MAPHASH_H
