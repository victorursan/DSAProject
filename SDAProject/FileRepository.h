//
// Created by Victor Ursan on 6/2/15.
//

#ifndef DSAPROJECT_FILEREPOSITORY_H
#define DSAPROJECT_FILEREPOSITORY_H

#include <fstream>
#include <string.h>
#include "Repository.h"

using namespace std;

class FileRepository: public Repository<string>{
private:
  char *filename;
  void loadEntities();

public:
  FileRepository(char *filename = (char*)"words") : Repository<string>() {
    //open the file wit the given name and load it
    this->filename = (char *) malloc(sizeof(char) * strlen(filename));
    strcpy(this->filename, filename);
    loadEntities();
  }
};

void FileRepository::loadEntities() {
  // load all the words in a DVector
  ifstream fin(filename);
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
