//
// Created by chris on 1/3/23.
//

#ifndef WIS_EXGENERATOR_H
#define WIS_EXGENERATOR_H


#include "Exercise.h"

class ExGenerator {
private:
    Exercise **exercises;
    int numOfEx;
    int current;

public:

    ExGenerator(int size = 10, int min = 0, int max = 10);

    int getNumOfEx();

    int getCurrent();

    Exercise *next();

    bool endOfEx();

    ~ExGenerator();
};
#endif //WIS_EXGENERATOR_H
