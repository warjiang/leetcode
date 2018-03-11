//
// Created by dwj on 2017/6/26.
//
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <stack>

using namespace std;

typedef struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {

    }
} TreeLinkNode;

class Solution {
private:

public:
    TreeLinkNode *pRoot;
    TreeLinkNode *pNode;
    Solution(string filePath) {
        ifstream infile;
        infile.open(filePath);
        assert(infile.is_open());
        string s;
        getline(infile, s);
        infile.close();
        vector<int> v;

        unsigned long currentIndex = 0;
        string::size_type n = s.find(",", currentIndex);
        while (n != string::npos) {
            string tmp = s.substr(currentIndex, n - currentIndex);
            if (tmp != "#") {
                v.push_back(stoi(tmp));
            } else {
                v.push_back(-1);
            }
            currentIndex = n + 1;
            n = s.find(",", currentIndex);
        }
        string tmp = s.substr(currentIndex);
        if (tmp != "#") {
            v.push_back(stoi(tmp));
        } else {
            v.push_back(-1);
        }
        //TreeLinkNode *pRoot = new TreeLinkNode(v[0]);
        TreeLinkNode *pRoot = new TreeLinkNode(v[0]);
        pRoot->left = makeTree(pRoot, v, 1);
        pRoot->right = makeTree(pRoot, v, 2);

        TreeLinkNode *pNode = PreOrderTraverseFindPNode(pRoot);
        //cout << "demo" << endl;

        this->pRoot = pRoot;
        this->pNode = pNode;

    }

    TreeLinkNode *PreOrderTraverseFindPNode(TreeLinkNode *T) {
        if (T) {
            if (T->val == 8) {
                return T;
            }
            PreOrderTraverseFindPNode(T->left);
            PreOrderTraverseFindPNode(T->right);
        }
    }

    TreeLinkNode *makeTree(TreeLinkNode *t, vector<int> v, int i) {
        if (i >= v.size() || v[i] == -1) {
            return NULL;
        }
        TreeLinkNode *p = new TreeLinkNode(v[i]);
        p->next = t;
        p->left = makeTree(p, v, 2 * i + 1);
        p->right = makeTree(p, v, 2 * i + 2);
        return p;
    }

    TreeLinkNode *GetNext(TreeLinkNode *pNode) {
        if (pNode == NULL)
            return NULL;
        TreeLinkNode *pRoot = pNode;
        vector<TreeLinkNode *> v;
        while (pRoot->next != NULL)
            pRoot = pRoot->next;

        TreeLinkNode *node = pRoot;
        stack<TreeLinkNode *> s;
        while (node != NULL || !s.empty()) {
            while (node != NULL) {
                s.push(node);
                node = node->left;
            }
            if (!s.empty()) {
                node = s.top();
                v.push_back(node);
                s.pop();
                node = node->right;
            }
        }
        vector<TreeLinkNode *>::iterator it;
        for (it = v.begin(); it != v.end(); it++) {
            if (*it == pNode) {
                break;
            }
        }
        if (it == v.end() - 1) {
            return NULL;
        } else {
            return *(++it);
        }
        /*
        int i = 0;
        for(;i<v.size()-1;i++){
            if (v[i] == pNode){
                break;
            }
        }
        if(i == v.size()-1){
            return NULL;
        }else{
            return v[i+1];
        }
        */
    }
};

int main() {
    Solution s("/Users/dingwenjiang/Desktop/dev/leetcode/dpdemo/tmp.txt");
    TreeLinkNode* p = s.GetNext(s.pNode);
    cout << p->val << endl;
    return 0;
}