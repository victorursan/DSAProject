//
// Created by Victor Ursan on 6/1/15.
//

#ifndef DSAPROJECT_LINKEDLIST_H
#define DSAPROJECT_LINKEDLIST_H
#include <iostream>
using namespace std;

template <typename Key, typename Value>
class Pair {
  Key key;
  Value value;
public:
  Value sortValue(Value v) {return v;};
  Pair(Key key, Value value) {this->key = key; this->value = value;};
  Key getKey() {return key;};
  Value getValue() {return value;};
  void setKey(Key key) {this->key = key;};
  void setValue(Value value) {
    this->value = sortValue(value);
  };
};

template <typename Key, typename Value>
class Node {
  //public:
  Pair<Key, Value> *pair;
  Node<Key, Value> *next;
public:
  Node() {};
  void setData(Pair<Key, Value> * aData) { pair = aData; };
  void setNext(Node<Key, Value> * aNext) { next = aNext; };
  Pair<Key, Value> * getData() { return pair; };
  Node<Key, Value> * getNext() { return next; };
};

template <typename Key, typename Value>
class SortedList {
  //public:
  Node<Key, Value> *head;
  int length;

public:
  SortedList() {head = NULL; length = 0;};
  void removePair(Pair<Key, Value> *data);
  void addPair(Pair<Key, Value> *data);
  Value findValueForKey(Key key);
  Key findKeyForValue(Value value);
  void updateKeyForValue(Value value, Key key);
  void updateValueForKey(Key key, Value value);
  bool doesKeyExist(Key key);
  bool doesValueExist(Value value);
};

template <typename Key, typename Value>
void SortedList<Key, Value>::removePair(Pair<Key, Value> *data) {
  if(head == NULL) {
    return;
  }
  length--;
  if(head->getData()->getValue() == data->getValue() && length == 1) {
    head = NULL;
    return;
  }
  if(head->getData()->getValue() == data->getValue() && length > 1) {
    head = head->getNext();
    return;
  }
  Node<Key, Value> *tmp = head;
  while(tmp->getNext() != NULL ) {
    if (tmp->getNext()->getData()->getValue() == data->getValue()) {
      tmp->setNext(tmp->getNext()->getNext());
      return;
    }
    tmp = tmp->getNext();
  }
}

template <typename Key, typename Value>
void SortedList<Key, Value>::addPair(Pair<Key, Value> *data) {
  length++;
  if (head == NULL) {
    head = new Node<Key, Value>();
    head->setData(data);
    head->setNext(NULL);
    return;
  }
  Node<Key, Value> *tmp = head;
  if (tmp->getData()->getValue() >= data->getValue()) {
    head->setData(data);
    head->setNext(tmp);
    return;
  }
  while(tmp->getNext() != NULL) {
    if(tmp->getData()->getValue() <= data->getValue() && tmp->getNext()->getData()->getValue() > data->getValue()) {
      Node<Key, Value> *aux = tmp->getNext();
      Node<Key, Value> *newNode = new Node<Key, Value>();
      newNode->setData(data);
      newNode->setNext(aux);
      tmp->setNext(newNode);
      return;
    }
    tmp = tmp->getNext();
  }
  Node<Key, Value> *newNode = new Node<Key, Value>();
  newNode->setData(data);
  newNode->setNext(NULL);
  tmp->setNext(newNode);
}

template <typename Key, typename Value>
Value SortedList<Key, Value>::findValueForKey(Key key) {
  Node<Key, Value> *tmp = head;
  while (head != NULL) {
    if (tmp->getData()->getKey() == key) {
      return tmp->getData()->getValue();
    }
    tmp = tmp->getNext();
  }
  return 0;
}

template <typename Key, typename Value>
Key SortedList<Key, Value>::findKeyForValue(Value value) {
  Node<Key, Value> *tmp = head;
  while (head != NULL) {
    if (tmp->getData()->getValue() == value) {
      return tmp->getData()->getKey();
    }
    tmp = tmp->getNext();
  }
  return 0;
}

template <typename Key, typename Value>
void SortedList<Key, Value>::updateKeyForValue(Value value, Key key) {
  Node<Key, Value> *tmp = head;
  while (head != NULL) {
    if (tmp->getData()->getValue() == value) {
      tmp->getData()->setKey(key);
      return;
    }
    tmp = tmp->getNext();
  }
}

template <typename Key, typename Value>
void SortedList<Key, Value>::updateValueForKey(Key key, Value value) {
  Node<Key, Value> *tmp = head;
  while (head != NULL) {
    if (tmp->getData()->getKey() == key) {
      tmp->getData()->setValue(value);
      return;
    }
    tmp = tmp->getNext();
  }
}

template <typename Key, typename Value>
bool SortedList<Key, Value>::doesKeyExist(Key key) {
  Node<Key, Value> *tmp = head;
  while (head != NULL) {
    if (tmp->getData()->getKey() == key) {
      return 1;
    }
    tmp = tmp->getNext();
  }
  return 0;
}

template <typename Key, typename Value>
bool SortedList<Key, Value>::doesValueExist(Value value) {
  Node<Key, Value> *tmp = head;
  while (head != NULL) {
    if (tmp->getData()->getValue() == value) {
      return 1;
    }
    tmp = tmp->getNext();
  }
  return 0;
}



#endif //DSAPROJECT_LINKEDLIST_H
