//
// Created by Victor Ursan on 5/31/15.
//

#ifndef DSAPROJECT_CONSOLE_H
#define DSAPROJECT_CONSOLE_H


#include "AnagramController.h"

class Console {
    Anagram *ctrl;

public:
    Console(Anagram* ctrl) {this->ctrl = ctrl;};
    ~Console();

    void run();
};

#endif //DSAPROJECT_CONSOLE_H
