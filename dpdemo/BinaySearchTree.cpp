//
// Created by dwj on 2017/6/30.
//
#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : left(NULL), right(NULL) {

    }

    TreeNode(int value) : left(NULL), right(NULL) {
        this->value = value;
    }
};
bool insert(TreeNode *p, int value);
void insertWrapper(TreeNode *&p,int value){
    if (p == NULL){
        TreeNode *node = new TreeNode(value);
        p = node;
    }
    else
        insert(p,value);
}


bool insert(TreeNode *p, int value) {
    TreeNode *node = new TreeNode(value);


    while ((p!=NULL)) {
        if (value == p->value)
            return false;
        else if (value > p->value){

            if(p->right == NULL){
                p->right = node;
                return true;
            }else{
                p = p->right;
            };


        }
        else {
            if(p->left == NULL){
                p->left = node;
                return true;
            }else{
                p = p->left;
            }
        }
            p = p->left;
    }

}

void inorder(TreeNode *p) {
    if (p == NULL) {
        // cout << p->value << "\t";
        return;
    }

    inorder(p->left);
    cout << p->value << "\t";
    inorder(p->right);
}

/*
class A {
public:
    A() {
        cout << "execute construct function" << endl;
    }

    A(const A &a) {
        cout << "execute copy function" << endl;
    }
};

void test(string str) {
    // str[0] = 'x';
    //str = "abcd";
}


class S : public string {
    string(const string & str){
        cout << "execute copy function" << endl;
    }
};
*/
int main() {
    //string str = "1234abc";
    //test(str);
    // cout << str << endl;
    //A a;
    // test(a);
    //A b = a;
    int array[3] = {3, 2, 4};
//    TreeNode* root = new TreeNode();
    TreeNode *root = NULL;
//    insertWrapper(root,2);

    for (int i = 0; i < 3; i++) {
        insertWrapper(root, array[i]);
    }

    //cout << "a" << endl;
    inorder( root);
    return 0;
}


