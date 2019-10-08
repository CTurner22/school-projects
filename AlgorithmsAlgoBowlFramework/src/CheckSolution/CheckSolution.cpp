#include "CheckSolution.h"

verifySolution::verifySolution(const string &inputFileName, const string &solutionFileName) {
    input =  inputReader(inputFileName);
    solution = solutionReader(solutionFileName);
}

bool verifySolution::isValid() {
    return (weightSumCorrect() && coverIsCorrect());
}

bool verifySolution::weightSumCorrect() {
    // check if all the set weights add up to what solution says they do

    int actualSum = 0;
    map<int,int> weights = input.getWeights();

    for(int id : solution.getSetIds()){
        actualSum+=weights.at(id);
    }

    return (actualSum == solution.getBestWeight());
}

bool verifySolution::coverIsCorrect() {
    // check if all subsets actually cover all elements of universal set

    map<int,set<int>> subSets = input.getSubsets();
    set<int> unionSet;

    for(int id : solution.getSetIds()){
        for(int element : subSets.at(id)){
            unionSet.insert(element);
        }
    }

    return (unionSet.size() == input.getN());
}
