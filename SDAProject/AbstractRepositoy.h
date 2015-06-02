//
// Created by Victor Ursan on 6/2/15.
//

#ifndef DSAPROJECT_ABSTRACTREPOSITOY_H
#define DSAPROJECT_ABSTRACTREPOSITOY_H

#include "DynamicVector.h"

template<typename Entity>
class AbstractRepository {
public:
    virtual void save(Entity e)=0;
    virtual void remove(int id)=0;
    virtual DynamicVector<Entity> getAll()=0;
    virtual int size()=0;
    virtual ~AbstractRepository() {
    }
};
#endif //DSAPROJECT_ABSTRACTREPOSITOY_H
