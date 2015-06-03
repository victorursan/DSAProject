//
// Created by Victor Ursan on 5/31/15.
//

#ifndef DSAPROJECT_MAP_H
#define DSAPROJECT_MAP_H

#include <stdlib.h>
#include <iostream>
#include "DynamicVector.h"

using namespace std;

template<typename Key, typename Value>
class Map {
  //the interface for the Map
public:
    virtual void addValueAndKey(Key key, Value value) = 0;
    virtual void updateValueForKey(Key key, Value value) = 0;
    virtual Value valueForKey(Key key) = 0;
    virtual Key keyForValue(Value value) = 0;
    virtual void removeKey(Key key) = 0;
    virtual void removeValue(Value value) = 0;
    virtual bool doesKeyExist(Key key) = 0;
    virtual bool doesValueExist(Value value) = 0;
    virtual DynamicVector<Key> getKeys() = 0;
    virtual DynamicVector<Value> getValues() = 0;
};


#endif //DSAPROJECT_MAP_H
