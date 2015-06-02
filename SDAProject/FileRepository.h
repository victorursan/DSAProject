//
// Created by Victor Ursan on 6/2/15.
//

#ifndef DSAPROJECT_FILEREPOSITORY_H
#define DSAPROJECT_FILEREPOSITORY_H

#include <fstream>
#include "Repository.h"

using namespace std;

class FileRepository: public Repository<string>{
public:
    FileRepository() : Repository<string>() {
        loadEntities();
    }
private:
    void loadEntities();
};

void FileRepository::loadEntities() {
    ifstream fin("words");
    if (!fin.is_open()) {
        cout<<"error"<<endl;
    }
    while (fin.good()) {
        string p;
        fin >> p;
        Repository<string>::save(p);
    }
    fin.close();
}


#endif //DSAPROJECT_FILEREPOSITORY_H
