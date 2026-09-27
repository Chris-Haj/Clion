//
// Created by chris on 1/3/23.
//

#include "MathQuiz.h"

MathQuiz::MathQuiz(int size, int min, int max) : generator(size, min, max) {
    this->numCorrect = 0;
    this->numTotal = 0;
}

void MathQuiz::startQuiz() {
    srand(time(NULL));
    while (!generator.endOfEx()) {
        Exercise *exercise = generator.next();
        std::cout << exercise->toString() << " ";
        int answer;
        std::cin >> answer;
        if (answer == exercise->eval()) {
            std::cout << "Correct!" << std::endl;
            this->numCorrect++;
        } else {
            std::cout << "Incorrect." << std::endl;
        }
        this->numTotal++;
    }
    std::cout << "Quiz completed. Your score is " << this->numCorrect << " / " << this->numTotal << "." << std::endl;
    std::cout << "Save results to file? (y/n) ";
    char save;
    std::cin >> save;
    if (save == 'y') {
        std::cout << "Enter file name: ";
        std::string filename;
        std::cin >> filename;
        std::ofstream outfile(filename);
        if (outfile) {
            while (!generator.endOfEx()) {
                Exercise *exercise = generator.next();
                outfile << exercise->toString() << " = " << exercise->eval() << std::endl;
            }
            outfile << "Total: " << this->numCorrect << " / " << this->numTotal << std::endl;
            outfile.close();
        }
    }
}