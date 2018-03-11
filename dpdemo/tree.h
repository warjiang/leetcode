//
// Created by dwj on 2017/6/25.
//

#ifndef DPDEMO_TREE_H
#define DPDEMO_TREE_H

#include <iostream>
#include <cstring>
using namespace std;

struct node {
    int value;
    node* p;
};
class tree {
private:
    node* head;
    string filepath;
public:
    tree(string filepath);

};


#endif //DPDEMO_TREE_H
