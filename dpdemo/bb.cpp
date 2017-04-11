#include <iostream>
#include <set>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
    //组合数
public:
    set<int> s;
    void swap(int *a, int *b) {
        int m;
        m = *a;
        *a = *b;
        *b = m;
    }
    int makeNum(int arr[],int start,int end){
        int num = 0;
        for(int i = start;i<=end;i++){
            num = num * 10 + arr[i];
        }
        return num;
    }
    void perm(int list[], int k, int m) {
        int i;
        if (k > m) {
            cout << makeNum(list,0,m) << endl;
            s.insert(makeNum(list,0,m));
        } else {
            for (i = k; i <= m; i++) {
                swap(&list[k], &list[i]);
                perm(list, k + 1, m);
                swap(&list[k], &list[i]);
            }
        }
    }
    int* copyArray(int old[],int len){
        int n[len];
        memset(n,0, sizeof(n));
        for(int i = 0;i<len;i++){
            n[i] = old[i];
        }
        return n;
    }
    void findAllRange(int arr[], int arrLen, int len) {
        for(int i = 0;i<len;i++){
            //int* c = copyArray(arr,arrLen);
            //perm(c,i,);
        }
    }
    int* vector2arr(vector<int> v){
        unsigned long vector_len = v.size();
        int newarr[vector_len];
        memset(newarr,0, sizeof(newarr));
        for(int i = 0;i<vector_len;i++){
            newarr[i] = v[i];
        }
        return newarr;
    }
    void findCombination(int arr[], int arrLen) {
        vector<vector<int> >v;
        vector<int>temp;
        temp.push_back(arr[0]);
        v.push_back(temp);
        for(int i = 1;i<arrLen;i++){
            unsigned long l = v.size();

            for(int j = 0;j<l;j++){
                vector<int> tt = v[j];
                tt.push_back(arr[i]);
                v.push_back(tt);
            }

        }

        for(int i = 0;i<v.size();i++){
            vector<int> tt = v[i];
            int *a = vector2arr(tt);
            for(int j = 0;j<tt.size();j++){
                cout << a[j] << "\t";

            }
            cout << endl;
            //perm(a,0,tt.size());
        }

    }




};


int main() {
    int arr[] = {1, 4,8};
    Solution s = Solution();
    s.findCombination(arr, 3);
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
    */\
    //s.Permutation("abc");
    return 0;
}
