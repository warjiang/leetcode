#include <iostream>
#include <string>

using namespace std;
/*
class LongestSubstring {
public:
    int findLongest(string A, int n, string B, int m) {
        // write code here
        int v[n][m];
        //memset(v, 0, n * m);
        //for(int i = 0;i<n;i++){
        //    for(int j = 0;j<m;j++){
        //        v[i][j] = 0;
        //    }
        //}

        // 初始化第一行
        size_t found = B.find(A[0]);
        for (int i = 0; i < m; i++) {
            if (found != string::npos) {
                v[0][i] = 1;
            }
        }
        // 初始化第一列
        found = A.find(B[0]);
        for (int i = 0; i < n; i++) {
            if (found != string::npos) {
                v[i][0] = 1;
            }
        }

        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(i == 0||j==0){
                    if(A[i]==B[j]){
                        v[i][j] = 1;
                    }
                }else{
                    v[i][j] = 0;
                }
            }
        }
        int max = 0;

        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                cout<<v[i][j]<< " ";
            }
            cout << endl;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (A[i] == B[j]) {
                    v[i][j] = v[i - 1][j - 1] + 1;
                    if (v[i][j] > max)
                        max = v[i][j];
                }else{
                    v[i][j] = 0;
                }
            }
        }

        cout << "========" << endl;
        for(int i = 0;i<n;i++){
            cout << A[i] << "\t";
            for(int j =0;j<m;j++){
                cout<<v[i][j]<< " ";
            }
            cout << endl;
        }

        return max;
    }
};
*/

class LongestSubstring {
public:
    int findLongest(string A, int n, string B, int m) {
        // write code here
        int v[n][m];
        memset(v,0,n*m* sizeof(int));
        for(int i = 0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(i == 0||j==0){
                    if(A[i]==B[j]){
                        v[i][j] = 1;
                    }
                }else{
                    v[i][j] = 0;
                }
            }
        }
        int max = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (A[i] == B[j]) {
                    v[i][j] = v[i - 1][j - 1] + 1;
                    if (v[i][j] > max)
                        max = v[i][j];
                }else{
                    v[i][j] = 0;
                }
            }
        }
        return max;
    }
};
int main() {
    LongestSubstring longestSubstring = LongestSubstring();
    cout << longestSubstring.findLongest("cacccca",7,"aaacca",6) << endl;
    return 0;
}
