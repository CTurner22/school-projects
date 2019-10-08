#include "InputReader.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

inputReader::inputReader(const string &fileName) {

    ifstream file (fileName);
    string line;
    int id = 1;

    if (file.is_open()){

        // read in size and number of sets
        file >> n >> m;
        getline (file, line);


        // read in sets and weights
        for(int i=0; i < m; i++) {
           getline (file, line);
           stringstream s(line);

           set<int> tempSet;
           int tempElement;
           int weight = 0;

           //read in set
           while(!s.eof()){
               s >> tempElement;
               tempSet.insert(tempElement);
           }

           //read in weight
           file >> weight;
           getline (file, line);

           //save it
           subSets.insert({id ,tempSet});
           subSetWeights.insert({id ,weight});
           id++;
        }

        file.close();

    } else {
        cerr << "Could not open " << fileName;
    }


}

map<int, set<int>> inputReader::getSubsets() {
    return subSets;
}

int inputReader::getN() {
    return n;
}

int inputReader::getM() {
    return m;
}

map<int, int> inputReader::getWeights() {
    return subSetWeights;
}

inputReader::inputReader() {
    m = 0;
    n = 0;
}
