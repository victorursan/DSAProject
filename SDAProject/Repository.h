//
// Created by Victor Ursan on 6/1/15.
//

#ifndef DSAPROJECT_REPOSITORY_H
#define DSAPROJECT_REPOSITORY_H

#include <stdio.h>
#include <sstream>
#include "AbstractRepositoy.h"

template <typename T>
class Repository : public AbstractRepository<T> {
    DynamicVector<T> store;
public:
    Repository();
    ~Repository();

    virtual void save(T e);
    virtual void remove(int id);
    virtual DynamicVector<T> getAll();
    virtual int size();
    virtual T findById(int id);
};

template <typename T>
Repository<T>::Repository() {
    /* Initializes repository
     */
    //  EntityValidator<Participant>* validator = new ParticipantValidator;
    store = DynamicVector<T>();
}


template <typename T>
Repository<T>::~Repository() {
    /* Destroy repository
     */
    //  delete this;
}

template <typename T>
DynamicVector<T> Repository<T>::getAll() {
    /* Get all the elemts

     returns: a vector with all the elements
     */
    return this->store;
}

template <typename T>
void Repository<T>::save(T p) {
    /* Save a element

     param: p - add a element of type T to the repository
     */
    store.add(p);
}

template <typename T>
void Repository<T>::remove(int id) {
    /* Remove element at position

     param: id - position from where to remove an element
     */
        store.removeAtIndex(id);
}

template <typename T>
T Repository<T>::findById(int id) {
    /* Find element at position

     param: id - position of the element

     returns: element at the position id
     */
        return store.elementAtIndex(id);
}

template <class T>
int Repository<T>::size() {
    /* The size of the Repository

     returns: the size of the repository
     */
    return store.getSize();
}

#endif //DSAPROJECT_REPOSITORY_H
