#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void replaceSpace(char *str, int length) {
    int len = 0, sum = 0;
    char *temp = str;
    while (*temp != '\0') {
        if (*temp == ' ')
            sum++;
        len++;
        temp++;
    }
    cout << sum << " " << len << endl;
    if ((len + 2 * sum) > length || sum == 0)
        return;

    int newindex = len + 2 * sum - 1;
    int oldindex = len - 1;
    for (; oldindex >= 0; oldindex--) {
        if (sum == 0)
            break;

        if (str[oldindex] == ' ') {
            sum--;
            str[newindex--] = '0';
            str[newindex--] = '2';
            str[newindex--] = '%';
        } else
            str[newindex--] = str[oldindex];
    }
    cout << str << endl;
}


typedef struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;

    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
} RandomListNode;

RandomListNode *Clone(RandomListNode *pHead) {
    if (pHead == NULL)
        return NULL;

    RandomListNode *temp = pHead;
    while (temp != NULL) {
        RandomListNode *node = new RandomListNode(temp->label);
        node->next = temp->next;
        temp->next = node;
        temp = node->next;
    }

    temp = pHead;
    while (temp != NULL) {
        if (temp->random != NULL)
            temp->next->random = temp->random->next;
        temp = temp->next->next;
    }

    pHead = pHead->next;
    temp = pHead;
    while (temp->next != NULL) {
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return pHead;
}

RandomListNode *constructRandomList(int array[], int len) {
    RandomListNode *root = new RandomListNode(array[0]);
    RandomListNode *current = root;
    RandomListNode **m = new RandomListNode *[len / 2];
    m[array[0] - 1] = root;
    for (int i = 1; i < len / 2; i++) {
        RandomListNode *node = new RandomListNode(array[i]);
        m[array[i] - 1] = node;
        current->next = node;
        current = node;
    }

    current = root;
    for (int j = 0; j < len / 2 && current != NULL; ++j) {
        RandomListNode *node = current;
        int val = array[j + len / 2];
        node->random = m[val - 1];
        current = current->next;
    }

    return root;
}

int NumberOf1Between1AndN_Solution(int n) {
    if (n < 10)
        return 1;
    int round = n;
    int res = 0;
    for (int i = 10; n * 10 / i != 0; i *= 10) {
        if (i == 10) {
            res += round / 10;
            if (round % 10 > 0)
                res += 1;
        } else {
            res += round / 10 * (i / 10);
            if (round % 10 == 1)
                res += (n % (i / 10) + 1);
            if (round % 10 > 1)
                res += i / 10;
        }
        round /= 10;

    }
    return res;

}

int sumofmn(int m, int n) {
    return (m + n) * (n - m + 1) / 2;
}

vector<vector<int> > FindContinuousSequence(int sum) {
    vector<vector<int> > res;
    vector<int> v;
    int i = 1, j = 2;
    v.push_back(i);
    v.push_back(j);
    while (j <= (sum + 1) / 2 && i < j) {
        if (sumofmn(i, j) < sum) {
            v.push_back(++j);
        } else if (sumofmn(i, j) > sum) {
            v.erase(v.begin());
            i++;
        } else {
            res.push_back(v);
            v.erase(v.begin());
            v.push_back(++j);
            i++;
        }
    }
    return res;
}

int StrToInt(string str) {
    if (str.empty())
        return 0;
    int sum = 0;
    int i = 0;
    if (str[0] == '+' || str[0] == '-')
        i = 1;

    for (; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9')
            sum = sum * 10 + (str[i] - '0');
        else
            return 0;
    }

    if (str[0] == '-')
        return -sum;
    else
        return sum;
}

typedef struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
} ListNode;

ListNode *constructListNode(int array[], int len) {
    ListNode *p = new ListNode(array[0]);
    ListNode *current = p;
    for (int i = 1; i < len; i++) {
        ListNode *node = new ListNode(array[i]);
        current->next = node;
        current = node;
    }
    return p;
}

int main() {
    /*
    char str[100] = " ";
    replaceSpace(str,100);
    cout << str << endl;

    int array[] = {1, 2, 3, 4, 5, 4, 3, 5, 2, 1};
    RandomListNode *pHead = constructRandomList(array, 10);
    RandomListNode *head = Clone(pHead);

    cout<<NumberOf1Between1AndN_Solution(9)<<endl;
    */
    //vector<vector<int> > res = FindContinuousSequence(3);
    /*
    vector<int> vv;
    vv.push_back(1);
    vv.push_back(2);
     */
    //cout << StrToInt("-2147483647") << endl;
    int array[] = {1, 1, 1, 1, 1, 1, 1};
    ListNode *p = constructListNode(array, 7);
    return 0;
}