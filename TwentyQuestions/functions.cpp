//
// Created by casey on 4/30/2019.
//

#include "functions.h"

#include <fstream>

node* read_game_tree(){
    ifstream f;
    f.open("animal.txt");
    node* ans = new node;

    read_preorder(ans,f);

    f.close();
    return ans;
}
void read_preorder(node* tree, ifstream &fin){
    if(fin.eof()){
        return;
    }
    string type;
    type+=fin.get();
    type+=fin.get();

    getline(fin,tree->data);
    if(type == "#A"){
        return;
    }
    else{
        node* branch = new node;
        tree->left = branch;
        read_preorder(branch,fin);
    }
    if(!fin.eof()){
        node* branch = new node;
        tree->right = branch;
        read_preorder(branch,fin);
    }
}
