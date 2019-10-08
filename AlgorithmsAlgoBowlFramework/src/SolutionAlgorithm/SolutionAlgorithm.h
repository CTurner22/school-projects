#ifndef ALGOBOWL_SOLUTIONALGORITHM_H
#define ALGOBOWL_SOLUTIONALGORITHM_H

#include "../ReadFiles/InputReader.h"

class solutionFinder{

        inputReader input;

    public:
        solutionFinder(const string &fileName);

        void solutionLogic();
        void outputToFile(const string &fileName);


};

#endif //ALGOBOWL_SOLUTIONALGORITHM_H
