//
// Created by Victor Ursan on 6/1/15.
//

#ifndef DSAPROJECT_DYNAMICVECTOR_H
#define DSAPROJECT_DYNAMICVECTOR_H

#include <stdlib.h>
#include <iostream>

template<typename TElement>
class DynamicVector {
private:
    TElement *elements;
    int size = 0;
    int capacity = 10;

    void resize();
public:
    DynamicVector();
  DynamicVector(TElement t) {};

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
DynamicVector<TElement>::DynamicVector() {
    this->elements = new TElement[capacity]();
}

template<typename TElement>
DynamicVector<TElement>::~DynamicVector() {
   // delete[] elements;
}

template<typename TElement>
void DynamicVector<TElement>::add(TElement e) {
    if (size >= capacity - 2) {
        resize();
    }
    size++;
    this->elements[size - 1] = e;
}

template<typename TElement>
void DynamicVector<TElement>::removeAtIndex(int index) {
    for (int i = index; i < size; i++) {
        elements[i] = elements[i + 1];
    }
    size--;
}

template<typename TElement>
TElement DynamicVector<TElement>::elementAtIndex(int index) {
    return elements[index];
}

template<typename TElement>
int DynamicVector<TElement>::getSize() {
    return size;
}

template<typename TElement>
bool DynamicVector<TElement>::isEmpty() {
    return size == 0;
}

template<typename TElement>
bool DynamicVector<TElement>::doesContainElement(TElement e) {
    for (int i = 0; i < size; i++) {
        if (elements[i] == e) {
            return 1;
        }
    }
    return 0;
}

template<typename TElement>
void DynamicVector<TElement>::resize() {
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
int DynamicVector<TElement>::indexForElement(TElement e) {
    for (int i = 0; i < size; i++) {
        if (elements[i] == e) {
            return i;
        }
    }
    return -1;
}

template<typename TElement>
void DynamicVector<TElement>::updateElement(int index, TElement element) {
    if (index < size) {
        elements[index] = element;
    } else {
        //TO DO:
    }
}
#endif //DSAPROJECT_DYNAMICVECTOR_H
