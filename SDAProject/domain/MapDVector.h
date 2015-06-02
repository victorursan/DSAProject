//
// Created by Victor Ursan on 6/1/15.
//

#ifndef DSAPROJECT_MAPDVECTOR_H
#define DSAPROJECT_MAPDVECTOR_H

#include "DynamicVector.h"
#include "Map.h"

template<typename Key, typename Value>
class MapDVector: Map<Key, Value> {
private:
    DynamicVector<Key> keys;
    DynamicVector<Value> values;
public:
    MapDVector();

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
MapDVector::MapDVector() {
    keys = DynamicVector<Key>();
    values = DynamicVector<Value>();
}

template<typename Key, typename Value>
void MapDVector::addValueAndKey(Key key, Value value) {
    if (!doesKeyExist(key)) {
        keys.add(key);
        values.add(value);
    } else {
        //TO DO: SOMETHING
    }
}

template<typename Key, typename Value>
void MapDVector::updateValueForKey(Key key, Value value) {
    if (doesKeyExist(key)) {
        int i = keys.indexForElement(key);
        values.updateElement(i, value);
    }
}

template<typename Key, typename Value>
void MapDVector::updateKeyForValue(Value value, Key key) {
    if (doesValueExist(value)) {
        int i = values.indexForElement(value);
        keys.updateElement(i, key);
    }
}

template<typename Key, typename Value>
Value MapDVector::valueForKey(Key key) {
    int i;
    i = keys.indexForElement(key);
    return values.elementAtIndex(i);
}

template<typename Key, typename Value>
Key MapDVector::keyForValue(Value value) {
    int i;
    i = values.indexForElement(value);
    return keys.elementAtIndex(i);
}

template<typename Key, typename Value>
void MapDVector::removeKey(Key key) {
    if (keys.doesContainElement(key)) {
        int i = keys.indexForElement(key);
        keys.removeAtIndex(i);
        values.removeAtIndex(i);
    } else {
        //TO DO:
    }
}

template<typename Key, typename Value>
void MapDVector::removeValue(Value value) {
    if (values.doesContainElement(value)) {
        int i = values.indexForElement(value);
        values.removeAtIndex(i);
        keys.removeAtIndex(i);
    } else {
        //TO DO:
    }
}

template<typename Key, typename Value>
bool MapDVector::doesKeyExist(Key key) {
    return keys.doesContainElement(key);
}

template<typename Key, typename Value>
bool MapDVector::doesValueExist(Value value) {
    return values.doesContainElement(value);
}

template<typename Key, typename Value>
DynamicVector<Key> MapDVector::getKeys() {
    return keys;
}

template<typename Key, typename Value>
DynamicVector<Value> MapDVector::getValues() {
    return values;
}

#endif //DSAPROJECT_MAPDVECTOR_H
