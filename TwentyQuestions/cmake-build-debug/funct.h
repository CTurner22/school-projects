//
// Created by casey on 4/30/2019.
//

#ifndef TWENTYQUESTIONS_FUNCT_H
#define TWENTYQUESTIONS_FUNCT_H

#include <string>
using namespace std;

class node {
public:
    string data;
    node* left;
    node* right;
};


node* read_game_tree();
void read_preorder(node* tree, ifstream &fin);






#endif //TWENTYQUESTIONS_FUNCT_H
