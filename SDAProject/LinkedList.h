//
// Created by Victor Ursan on 6/1/15.
//

#ifndef DSAPROJECT_LINKEDLIST_H
#define DSAPROJECT_LINKEDLIST_H
#include <iostream>
using namespace std;

template <typename Key, typename Value>
class Pair {
  //a pair ok Key, Value for the Map
  Key key;
  Value value;
public:
  Pair(Key key, Value value) {this->key = key; this->value = value;};
  Key getKey() {return key;};
  Value getValue() {return value;};
  void setKey(Key key) {this->key = key;};
  void setValue(Value value) {
    this->value = value;
  };
};

template <typename Key, typename Value>
class Node {
  // a node for the Single lnked list with a pair(key, value)
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
  Node<Key, Value>* findFirstNode(Value value);
};

template <typename Key, typename Value>
void SortedList<Key, Value>::removePair(Pair<Key, Value> *data) {
  //remove a pair(key, value) from the list
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
  //add a pair to the list (sorted)
  length++;
  if (head == NULL) {
    head = new Node<Key, Value>();
    head->setData(data);
    head->setNext(NULL);
    return;
  }
  Node<Key, Value> *tmp = head;
  if (tmp->getData()->getValue() >= data->getValue()) {
    Node<Key, Value> *newNode = new Node<Key, Value>();
    newNode->setData(head->getData());
    newNode->setNext(head->getNext());
    head->setData(data);
    head->setNext(newNode);
    return;
  }
  while(tmp->getNext() != NULL) {
    if(tmp->getData()->getValue() <= data->getValue()) {
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
  return;
}

template <typename Key, typename Value>
Value SortedList<Key, Value>::findValueForKey(Key key) {
  //find the value for a specified key in the list
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
  //find the key for a specified value in the list
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
  //update the key for a specified value
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
  //update the value for a specified key
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
  //check if a specified key exists in the list
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
  //check if a specified value exists in the list
  Node<Key, Value> *tmp = head;
  while (head != NULL) {
    if (tmp->getData()->getValue() == value) {
      return 1;
    }
    tmp = tmp->getNext();
  }
  return 0;
}

template <typename Key, typename Value>
Node<Key, Value>* SortedList<Key, Value>::findFirstNode(Value value){
  // finds the first node that contains the specified value
  Node<Key, Value> *node = head;
  while(node != NULL){
    if(node->getData()->getValue() == value){
      return node;
    }
    node = node->getNext();
  }
  return node;
}

#endif //DSAPROJECT_LINKEDLIST_H
