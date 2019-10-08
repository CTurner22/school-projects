# include "CreateInput/InputGenerator.h"
# include "ReadFiles/InputReader.h"
# include "SolutionAlgorithm/SolutionAlgorithm.h"
# include "CheckSolution/CheckSolution.h"

int main() {
    /*
     * We`ll obviously have to change main to accommodate the different steps that we have to do, but
     * this just allows for easy testing to start with
     */


    //creates a random input
    inputGenerator inputCreate(1000, 500);
    inputCreate.outputToFile("InputTest.txt");

    // pass the input to the actual algorithm logic
    solutionFinder algo("InputTest.txt");
    algo.outputToFile("OutputTest.txt");

    // verify the output file
    verifySolution verify("InputTest.txt", "OutputTest.txt");
    verify.isValid();
}