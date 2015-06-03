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
  void removeElement(TElement e);
  void updateElement(int index, TElement element);
  TElement elementAtIndex(int index);
  int indexForElement(TElement e);
  int getSize();
  bool isEmpty();
  bool doesContainElement(TElement e);
};

template<typename TElement>
DynamicVector<TElement>::DynamicVector() {
  //create the array of elements
  this->elements = new TElement[capacity]();
}

template<typename TElement>
DynamicVector<TElement>::~DynamicVector() {
//   delete[] elements;
}

template<typename TElement>
void DynamicVector<TElement>::add(TElement e) {
  //check if the DVector has enouch space and add an element
  if (size >= capacity - 2) {
    resize();
  }
  this->elements[size] = e;
  size++;

}

template<typename TElement>
void DynamicVector<TElement>::removeAtIndex(int index) {
  //remove an element from a specific index
  for (int i = index; i < size; i++) {
    elements[i] = elements[i + 1];
  }
  size--;
}

template<typename TElement>
void DynamicVector<TElement>::removeElement(TElement e) {
  //remove an element with the specified value
  for (int i = 0; i < size; i++) {
    if(elements[i] == e) {
      removeAtIndex(i);
      break;
    }
  }
}

template<typename TElement>
TElement DynamicVector<TElement>::elementAtIndex(int index) {
  //returns an element from the specified index;
  return elements[index];
}

template<typename TElement>
int DynamicVector<TElement>::getSize() {
  //returns the size of the DVector
  return size;
}

template<typename TElement>
bool DynamicVector<TElement>::isEmpty() {
  //checks if the DVector is empty
  return size == 0;
}

template<typename TElement>
bool DynamicVector<TElement>::doesContainElement(TElement e) {
  //checks if the DVector contains the element e;
  for (int i = 0; i < size; i++) {
    if (elements[i] == e) {
      return 1;
    }
  }
  return 0;
}

template<typename TElement>
void DynamicVector<TElement>::resize() {
  //resize the DVector if the capacity doesn't is not good
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
  //returns the index for and element e
  for (int i = 0; i < size; i++) {
    if (elements[i] == e) {
      return i;
    }
  }
  return -1;
}

template<typename TElement>
void DynamicVector<TElement>::updateElement(int index, TElement element) {
  //update an element at "index" with "element"
  if (index < size) {
    elements[index] = element;
  } else {
    //TO DO:
  }
}
#endif //DSAPROJECT_DYNAMICVECTOR_H
