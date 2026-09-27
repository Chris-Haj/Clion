//
// Created by chris on 1/3/23.
//

#ifndef WIS_EXERCISE_H
#define WIS_EXERCISE_H

#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

class Exercise {
private:
    int leftOperand;
    int rightOperand;
    int op;
    int maxValue;
    int minValue;
public:
    Exercise(int min = 0, int max = 10);

    int eval();

    string toString();

    Exercise *next();
};

#endif //WIS_EXERCISE_H
