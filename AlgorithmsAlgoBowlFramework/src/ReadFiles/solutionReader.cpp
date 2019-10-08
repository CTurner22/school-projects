#include "solutionReader.h"
#include "InputReader.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

int solutionReader::getBestWeight() {
    return bestWeight;
}

vector<int> solutionReader::getSetIds() {
    return setIds;
}

solutionReader::solutionReader(const string &fileName) {

    ifstream file (fileName);
    string line;

    if (file.is_open()){

        // read in bestWeight solution achieved
        file >> bestWeight;
        getline (file, line);


        // read in setsIds
        getline (file, line);
        stringstream s(line);
        int tempId;

        while(!s.eof()){
            s >> tempId;
           setIds.push_back(tempId);
        }

        file.close();

    } else {
        cerr << "Could not open " << fileName;
    }


}

solutionReader::solutionReader() {
    bestWeight = 0;
}
