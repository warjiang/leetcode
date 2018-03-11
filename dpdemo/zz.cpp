#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool check(char str[]) {
    stack<char> s;
    bool flag = true;
    while (*str != '\0') {
        if (*str == ')') {
            flag = false;
            while (!s.empty()) {
                char c = s.top();
                if (c == '(') {
                    flag = true;
                    s.pop();
                    break;
                }
                s.pop();
            }
            str++;
        } else if (*str == '}') {
            flag = false;
            while (!s.empty()) {
                char c = s.top();
                if (c == '{') {
                    flag = true;
                    s.pop();
                    break;
                }
                s.pop();
            }
            str++;
        } else if (*str == ']') {
            flag = false;
            while (!s.empty()) {
                char c = s.top();
                if (c == '[') {
                    flag = true;
                    s.pop();
                    break;
                }
                s.pop();
            }
            str++;
        }
        if (*str != '\0') {
            s.push(*str);
            str++;
        }

    }
    while (!s.empty()) {
        char c = s.top();
        if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']') {
            return false;
        }
        s.pop();
    }
    return flag;
}

// input 表示答应队列，为1~9（优先级）组成的数组
// len 表示input 长度
typedef struct pair {
    int key;
    int value;

    pair(int key, int value) {
        this->key = key;
        this->value = value;
    }
} Pair;

bool Comp(const Pair &a, const Pair &b) {
    return a.value > b.value;
}

void printOrder(const int input[], int len, int output[]) {
    vector<Pair> v;
    for (int i = 0; i < len; ++i) {
        v.push_back(Pair(i, input[i]));
    }
    sort(v.begin(), v.end(), Comp);
    int index = 0;
    for (vector<Pair>::iterator it = v.begin(); it != v.end(); it++) {
        output[index] = (*it).key;
        index++;
    }
    //cout << "finished" << endl;

}

int getMaximumApples(int m, int n, vector<vector<int> > matrix) {
    vector<vector<int> > ret(m, vector<int>(n));
    ret[0][0] = matrix[0][0];
    for (int i = 1; i < n; ++i) {
        ret[0][i] = ret[0][i-1] + matrix[0][i];
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            ret[i][j] = matrix[i][j] + max(ret[i - 1][j], ret[i][j - 1]);
        }
    }
    return ret[m - 1][n - 1];
}

int main() {
    /*
    // TEST CAST1
    char s[] = "(1+2)/(0.5+1)";
    cout << check(s) << endl;
    char s1[] = "(1+2)/(0.5+1";
    cout << check(s1) << endl;
    char s2[] = "(1+2)/0.5+1)";
    cout << check(s2) << endl;
    char s3[] = "1+2)/0.5+1)";
    cout << check(s3) << endl;
    char s4[] = "{(1+2)/0.5+1}";
    cout << check(s4) << endl;

    int input[] = {9, 3, 5};
    int output[] = {-1, -1, -1};
    printOrder(input, 3, output);
    int input1[] = {9, 3, 5, 9};
    int output1[] = {-1, -1, -1, -1};
    printOrder(input1, 4, output1);
    */
    int input2[] = {9, 3, 9, 5};
    int output2[] = {-1, -1, -1, -1};
    printOrder(input2, 4, output2);

    /*
    int matrix1[2][5] = {{1, 2, 3, 40},
                         {6, 7, 8, 90}};
    vector<vector<int> > matrix(2, vector<int>(5));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = matrix1[i][j];
        }
    }
    cout << getMaximumApples(2, 5, matrix) << endl;
     */
    return 0;
}