//
// Created by chris on 1/3/23.
//

#include "Exercise.h"

Exercise::Exercise(int min, int max) {

    this->leftOperand = (rand() % ((max - min + 1) + min));
    this->rightOperand = (rand() % ((max - min + 1) + min));
    this->op = rand() % 2 + 1;
    this->maxValue = max;
    this->minValue = min;
}

int Exercise::eval() {
    if (this->op == 1) {
        return this->leftOperand + this->rightOperand;
    }
    return this->leftOperand - this->rightOperand;
}

string Exercise::toString() {
    if (this->op == 1) {
        return std::to_string(this->leftOperand) + " + " + std::to_string(this->rightOperand) + " =";
    }
    return std::to_string(this->leftOperand) + " - " + std::to_string(this->rightOperand) + " =";
}