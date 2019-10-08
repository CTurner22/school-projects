#ifndef ALGOBOWL_SOLUTIONREADER_H
#define ALGOBOWL_SOLUTIONREADER_H

# include <vector>
# include <string>
using namespace std;

class solutionReader{

private:

    int bestWeight;
    vector<int> setIds;

public:
    solutionReader();
    solutionReader(const string &fileName);
    int getBestWeight();
    vector<int> getSetIds();


};


#endif //ALGOBOWL_SOLUTIONREADER_H
