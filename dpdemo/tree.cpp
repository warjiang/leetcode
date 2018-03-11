//
// Created by dwj on 2017/6/25.
//

#include "tree.h"
#include <iostream>

using namespace std;

int main() {
    tree t("demo");
    cout << "hello tree" << endl;
}

tree::tree(string filepath) {
    this->filepath = filepath;
    // cout << "filepath" << &(filepath)<< endl;
    // cout << "this->filepath" << &(this->filepath)<< endl;
}
