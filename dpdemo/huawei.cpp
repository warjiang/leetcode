#include <iostream>
#include <set>
#include <cstring>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    //组合数
public:
    set<int> s;
    unordered_set<int> ss;
    /*
    void swap(int *a, int *b) {
        int m;
        m = *a;
        *a = *b;
        *b = m;
    }
    */
    int makeNum(int arr[], int start, int end) {
        int num = 0;
        for (int i = start; i <= end; i++) {
            num = num * 10 + arr[i];
        }
        return num;
    }

    void perm(int list[], int k, int m) {
        int i;
        if (k > m) {
            cout << makeNum(list, 0, m) << endl;
            //s.insert(makeNum(list,0,m));
            ss.insert(makeNum(list, 0, m));
        } else {
            for (i = k; i <= m; i++) {
                //swap(&list[k], &list[i]);
                perm(list, k + 1, m);
                //swap(&list[k], &list[i]);
            }
        }
    }

    int *copyArray(int old[], int len) {
        int n[len];
        memset(n, 0, sizeof(n));
        for (int i = 0; i < len; i++) {
            n[i] = old[i];
        }
        return n;
    }

    void findAllRange(int arr[], int arrLen, int len) {
        for (int i = 0; i < len; i++) {
            //int* c = copyArray(arr,arrLen);
            //perm(c,i,);
        }
    }

    int *vector2arr(vector<int> v) {
        unsigned long vector_len = v.size();
        int newarr[vector_len];
        memset(newarr, 0, sizeof(newarr));
        for (int i = 0; i < vector_len; i++) {
            newarr[i] = v[i];
        }
        return newarr;
    }

    void findCombination(int arr[], int arrLen) {
        vector<vector<int> > v;
        vector<int> temp;
        temp.push_back(arr[0]);
        v.push_back(temp);
        for (int i = 1; i < arrLen; i++) {
            unsigned long l = v.size();

            for (int j = 0; j < l; j++) {
                vector<int> tt = v[j];
                tt.push_back(arr[i]);
                v.push_back(tt);
            }
            vector<int> temp1;
            temp1.push_back(arr[i]);
            v.push_back(temp1);
        }

        for (int i = 0; i < v.size(); i++) {
            vector<int> tt = v[i];
            //int *a = vector2arr(tt);
            //for(int j = 0;j<tt.size();j++){
            //    cout << a[j] << "\t";
            //}
            int a[tt.size()];
            for (int j = 0; j < tt.size(); j++) {
                //cout << v[i][j] << "\t";
                a[j] = v[i][j];
            }
            perm(a, 0, tt.size() - 1);

        }
        cout << "size:" << ss.size() << endl;
    }


    vector<vector<int> > getAllCombination(int arr[], int len) {
        vector<vector<int> > combinations;
        vector<int> a;
        a.push_back(arr[0]);
        combinations.push_back(a);
        for (int i = 1; i < len; i++) {
            unsigned long l = combinations.size();
            for (unsigned long j = 0; j < l; j++) {
                vector<int> temp = combinations[j];
                temp.push_back(arr[i]);
                combinations.push_back(temp);
            }
            vector<int> b;
            b.push_back(arr[i]);
            combinations.push_back(b);
        }
        return combinations;
    }

    vector<vector<int> >p;
    void permutation(int *arr,int start,int len){
        if(start == len-1){
            //根据当前序列构造序列
            vector<int> temp;
            for(int i = 0;i<len;i++){
                temp.push_back(arr[i]);
            }
            p.push_back(temp);
        }
        for(int i = start;i<len;i++){
            swap(arr[start],arr[i]);
            permutation(arr,start+1,len);
            swap(arr[i],arr[start]);
        }
    }

};


int main() {
    int arr[] = {1, 4, 8};
    Solution s = Solution();
    /*
    vector<vector<int> > c = s.getAllCombination(arr, 3);
    for (int i = 0; i < c.size(); i++) {
        for (int j = 0; j < c[i].size(); j++) {
            cout << c[i][j] << "\t";
        }
        cout << endl;
    }
     */
    s.permutation(arr,0,3);
    for(int i = 0;i<s.p.size();i++){
        for(int  j = 0;j<s.p[i].size();j++){
            cout << s.p[i][j] << "\t";
        }
        cout << endl;
    }
    //s.findCombination(arr, 3);
    //s.perm(arr,0,1);

    //int *a1 = s.copyArray(arr,3);
    //s.perm(a1,1,0);
    //int *a2 = s.copyArray(arr,3);
    //s.perm(a2,1,1);
    //int *a3 = s.copyArray(arr,3);
    //s.perm(a3,1,2);

    //int *a4 = s.copyArray(arr,3);
    //s.perm(a4,0,0);
    //int *a5 = s.copyArray(arr,3);
    //s.perm(a5,0,1);
    //int *a6 = s.copyArray(arr,3);
    //s.perm(a6,2,0);
    /*
    int *a1 = s.copyArray(arr,3);
    s.perm(a1,0,0);
    int *a2 = s.copyArray(arr,3);
    s.perm(a2,0,1);
    int *a3 = s.copyArray(arr,3);
    s.perm(a3,0,2);
    int *a4 = s.copyArray(arr,3);
    s.perm(a4,1,0);
    int *a5 = s.copyArray(arr,3);
    s.perm(a5,1,1);
    int *a6 = s.copyArray(arr,3);
    s.perm(a6,1,2);
    int *a7 = s.copyArray(arr,3);
    s.perm(a7,2,0);
    int *a8 = s.copyArray(arr,3);
    s.perm(a8,2,2);
    int *a9 = s.copyArray(arr,3);
    s.perm(a9,2,2);
    */
    //s.Permutation("abc");
    /*
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    */
    return 0;
}
