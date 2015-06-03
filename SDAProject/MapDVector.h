//
// Created by Victor Ursan on 6/1/15.
//

#ifndef DSAPROJECT_MAPDVECTOR_H
#define DSAPROJECT_MAPDVECTOR_H

#include "DynamicVector.h"
#include "Map.h"

template<typename Key, typename Value>
class MapDVector: public Map<Key, Value> {
  //map implemented over Dynamic Vector
private:
  DynamicVector<Key> keys;
  DynamicVector<Value> values;
public:
  MapDVector();
  ~MapDVector();
  void addValueAndKey(Key key, Value value);
  void updateValueForKey(Key key, Value value);
  void updateKeyForValue(Value value, Key key);
  Value valueForKey(Key key);
  Key keyForValue(Value value);
  void removeKey(Key key);
  void removeValue(Value value);
  bool doesKeyExist(Key key);
  bool doesValueExist(Value value);
  DynamicVector<Key> getKeys();
  DynamicVector<Value> getValues();
};

template<typename Key, typename Value>
MapDVector<Key, Value>::MapDVector() {
  //initialize the map with 2 vectors
  keys = DynamicVector<Key>();
  values = DynamicVector<Value>();
}

template<typename Key, typename Value>
MapDVector<Key, Value>::~MapDVector() {
  //delete
}

template<typename Key, typename Value>
void MapDVector<Key, Value>::addValueAndKey(Key key, Value value) {
  //add a pair value, key to the map
  if (!doesKeyExist(key)) {
    keys.add(key);
    values.add(value);
  } else {
    //TO DO: SOMETHING
  }
}

template<typename Key, typename Value>
void MapDVector<Key, Value>::updateValueForKey(Key key, Value value) {
  // update the value for a specific key
  if (doesKeyExist(key)) {
    int i = keys.indexForElement(key);
    values.updateElement(i, value);
  }
}

template<typename Key, typename Value>
void MapDVector<Key, Value>::updateKeyForValue(Value value, Key key) {
  // update the first key for a specific value
  if (doesValueExist(value)) {
    int i = values.indexForElement(value);
    keys.updateElement(i, key);
  }
}

template<typename Key, typename Value>
Value MapDVector<Key, Value>::valueForKey(Key key) {
  // return the value for a specific key
  int i;
  i = keys.indexForElement(key);
  return values.elementAtIndex(i);
}

template<typename Key, typename Value>
Key MapDVector<Key, Value>::keyForValue(Value value) {
  // return the first key for a specific value
  int i;
  i = values.indexForElement(value);
  return keys.elementAtIndex(i);
}

template<typename Key, typename Value>
void MapDVector<Key, Value>::removeKey(Key key) {
  //remove a pair(key, value) with the specified key
  if (keys.doesContainElement(key)) {
    int i = keys.indexForElement(key);
    keys.removeAtIndex(i);
    values.removeAtIndex(i);
  }
}

template<typename Key, typename Value>
void MapDVector<Key, Value>::removeValue(Value value) {
  //remove the first pair(key, value) with the specified value
  if (values.doesContainElement(value)) {
    int i = values.indexForElement(value);
    values.removeAtIndex(i);
    keys.removeAtIndex(i);
  }
}

template<typename Key, typename Value>
bool MapDVector<Key, Value>::doesKeyExist(Key key) {
  // check if the specified key exist
  return keys.doesContainElement(key);
}

template<typename Key, typename Value>
bool MapDVector<Key, Value>::doesValueExist(Value value) {
  //check if the specified value exist
  return values.doesContainElement(value);
}

template<typename Key, typename Value>
DynamicVector<Key> MapDVector<Key, Value>::getKeys() {
  //return all the keys in the map
  return keys;
}

template<typename Key, typename Value>
DynamicVector<Value> MapDVector<Key, Value>::getValues() {
  //return all the values in the map
  return values;
}

#endif //DSAPROJECT_MAPDVECTOR_H
