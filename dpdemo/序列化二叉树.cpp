//
// Created by dwj on 2017/7/1.
//

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    char *Serialize(TreeNode *root) {

    }

    TreeNode *Deserialize(char *str) {
        vector<int> v;
        int left = 0, right = 0;
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == ',') {
                right = i;
                char tmp[right - left];
                strncpy(tmp, str + left, right - left);
                //cout << atoi(tmp) << endl;
                v.push_back(atoi(tmp));
                left = right + 1;

            }
        }
        TreeNode* pRoot=NULL;
        return createTree(pRoot,v,0);

    }

    TreeNode *createTree(TreeNode *node, vector<int> num, int index) {
        if (num[index] == 0)
            return NULL;

        node = new TreeNode(num[index]);
        createTree(node->left, num, ++index);
        createTree(node->right, num, ++index);

    }
};


int main() {
    Solution s;
    char *a ="1,2,3,4,10,5";
    s.Deserialize(a);
    return 0;
}