//
// Created by Victor Ursan on 6/1/15.
//

#ifndef DSAPROJECT_DYNAMICVECTOR_H
#define DSAPROJECT_DYNAMICVECTOR_H

#include <stdlib.h>
#include <iostream>
//#include <CoreFoundation/CoreFoundation.h>

template<typename TElement>
class DynamicVector {
private:
    TElement *elements;
    int size = 0;
    int capacity = 10;

    void resize();
public:
    DynamicVector();

    ~DynamicVector();

    void add(TElement e);

    void removeAtIndex(int index);

    void updateElement(int index, TElement element);

    TElement elementAtIndex(int index);

    int indexForElement(TElement e);

    int getSize();

    bool isEmpty();

    bool doesContainElement(TElement e);
};

template<typename TElement>
DynamicVector::DynamicVector() {
    this->elements = new TElement[capacity]();
}

template<typename TElement>
DynamicVector::~DynamicVector() {
   // delete[] elements;
}

template<typename TElement>
void DynamicVector::add(TElement e) {
    if (size >= capacity - 2) {
        resize();
    }
    size++;
    this->elements = malloc(sizeof(TElement) * this->size);
    this->elements[size - 1] = e;
}

template<typename TElement>
void DynamicVector::removeAtIndex(int index) {
    for (int i = index; i < size; i++) {
        elements[i] = elements[i + 1];
    }
    size--;
}

template<typename TElement>
TElement DynamicVector::elementAtIndex(int index) {
    return elements[index];
}

template<typename TElement>
int DynamicVector::getSize() {
    return size;
}

template<typename TElement>
bool DynamicVector::isEmpty() {
    return size == 0;
}

template<typename TElement>
bool DynamicVector::doesContainElement(TElement e) {
    for (int i = 0; i < size; i++) {
        if (elements[i] == e) {
            return TRUE;
        }
    }
    return FALSE;
}

template<typename TElement>
void DynamicVector::resize() {
    int i = 0;
    capacity += 10;
    TElement *tmp = elements;
    elements = new TElement[capacity]();
    for (i = 0; i < size; i++) {
        elements[i] = tmp[i];
    }
    delete[] tmp;
}

template<typename TElement>
int DynamicVector::indexForElement(TElement e) {
    for (int i = 0; i < size; i++) {
        if (elements[i] == e) {
            return i;
        }
    }
    return -1;
}

template<typename TElement>
void DynamicVector::updateElement(int index, TElement element) {
    if (index < size) {
        element[index] = element;
    } else {
        //TO DO:
    }
}
#endif //DSAPROJECT_DYNAMICVECTOR_H
