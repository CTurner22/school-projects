#ifndef ALGOBOWL_INPUTGENERATOR_H
#define ALGOBOWL_INPUTGENERATOR_H

#include <string>
#include <set>
#include <map>

using namespace std;

class inputGenerator{

    private:

        // constant restrictions
        const int MAX_N_VALUE = 1000;
        const int MAX_M_VALUE = 500;
        const int MAX_SET_VALUE = 5000;
        const int MAX_WEIGHT_VALUE = 1000;


        // n size of universal set and m number of subsets
        int n;
        int m;

        // universal set U and map of subsets and weights
        map<int, int> U;
        map<set<int>,int> subsets;

        void createInput();

    public:
        inputGenerator(int N, int M);
        void outputToFile(const string &fileName);

};




#endif //ALGOBOWL_INPUTGENERATOR_H
