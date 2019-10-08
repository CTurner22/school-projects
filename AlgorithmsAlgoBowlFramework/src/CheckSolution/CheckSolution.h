#ifndef ALGOBOWL_CHECKSOLUTION_H
#define ALGOBOWL_CHECKSOLUTION_H

#include "../ReadFiles/InputReader.h"
#include "../ReadFiles/solutionReader.h"
#include <string>

using namespace std;

class verifySolution{

    private:
        inputReader input;
        solutionReader solution;

        bool weightSumCorrect();
        bool coverIsCorrect();

    public:
        verifySolution(const string &inputFileName, const string &solutionFileName);
        bool isValid();

};

#endif //ALGOBOWL_CHECKSOLUTION_H
