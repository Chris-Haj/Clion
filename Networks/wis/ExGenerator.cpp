//
// Created by chris on 1/3/23.
//

#include "ExGenerator.h"

ExGenerator::ExGenerator(int size, int min, int max) {

    this->exercises = new Exercise *[size];
    this->numOfEx = size;
    this->current = 0;
    for (int i = 0; i < size; i++) {
        this->exercises[i] = new Exercise(min, max);
    }

}

int ExGenerator::getNumOfEx() {
    return this->numOfEx;
}

int ExGenerator::getCurrent() {
    return this->current;
}

Exercise *ExGenerator::next() {
    if (this->current >= this->numOfEx) {
        return NULL;
    }
    return this->exercises[this->current++];
}

bool ExGenerator::endOfEx() {
    return this->current >= this->numOfEx;
}

ExGenerator::~ExGenerator() {
    for (int i = 0; i < this->numOfEx; i++) {
        delete this->exercises[i];
    }
    delete[] this->exercises;
}
