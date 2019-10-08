#include <string>
#include <set>
#include <map>

#ifndef ALGOBOWL_INPUTREADER_H
#define ALGOBOWL_INPUTREADER_H

using namespace std;

class inputReader{

    private:
        // n size of universal set and m number of subsets
        int n;
        int m;

       // weights and subsets are stored with incrementing id as a key
        map<int,int> subSetWeights;
        map<int, set<int>> subSets;


    public:
        inputReader();
        inputReader(const string &fileName);
        int getM();
        int getN();
        map<int,set<int>> getSubsets();
        map<int,int> getWeights();

};

#endif //ALGOBOWL_INPUTREADER_H
