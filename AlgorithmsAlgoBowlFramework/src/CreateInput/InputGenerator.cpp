#include <string>
#include <set>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "InputGenerator.h"

using namespace std;

inputGenerator::inputGenerator(const int N, const int M){

    if(N <= MAX_N_VALUE && M <= MAX_M_VALUE){
        srand(time(0));
        n = N;
        m = M;

        createInput();
    }

}

void inputGenerator::createInput(){

    // create main universal set U with n elements
    while(U.size() <= n){
        U.insert({rand() % MAX_SET_VALUE, 0});
    }


    // create m number of subsets and insert into larger map of subsets and weights
    for(int i=0; i < m; i ++ ){
        set<int> temp;

        // add some random amount less than n of U elements to sub set
        for( int i=0; i < (rand() % n) + 1; i++) {

            // access random key of map
            auto it = U.begin();
            advance( it, rand() % n);

            // insert element
            temp.insert(it->first);

            // keep track of elements used in subsets
            it->second++;
        }

        subsets.insert({temp,(rand() % MAX_WEIGHT_VALUE) + 1});
    }


    // check if any element of U is not in a subset, if not fix it to ensure input is possible
    for (pair<int, int> element : U) {
         if (element.second == 0){

             // access random key of map
             auto it = subsets.begin();
             advance( it, rand() % m);

             // create new subset
             set<int> newSet = it->first;
             newSet.insert(element.first);

             // insert new subset
            subsets.insert({newSet, it->second});

            // delete old subset
            subsets.erase(it);
         }
    }

}

void inputGenerator::outputToFile(const string &fileName){

    // open file
    ofstream outfile;
    outfile.open(fileName);

    // size of original set
    outfile << n << '\n';

    // number of subsets
    outfile << m << endl;

    for( pair<set<int>, int> element : subsets ){

        //print set
        string setLine = "";
        for(int subElement : element.first){
            setLine += to_string(subElement) + " ";
        }
        setLine.pop_back();
        outfile << setLine << '\n';

        // print weight
        outfile << element.second << '\n';
    }

    outfile.close();
 }




