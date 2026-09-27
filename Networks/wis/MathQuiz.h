//
// Created by chris on 1/3/23.
//

#ifndef WIS_MATHQUIZ_H
#define WIS_MATHQUIZ_H

#include <iostream>
#include <fstream>
#include "ExGenerator.h"

using namespace std;

class MathQuiz {
private:
    ExGenerator generator;
    int numCorrect;
    int numTotal;

public:
    MathQuiz(int size = 10, int min = 0, int max = 10);

    void startQuiz();
};

#endif //WIS_MATHQUIZ_H
