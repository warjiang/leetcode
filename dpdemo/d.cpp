#include <iostream>
#include <string>

using namespace std;


class Palindrome {
public:
    int lcs(string A, int lenA, string B, int lenB) {
        int dp[lenA][lenB];
        memset(dp, 0, lenA * lenB * sizeof(int));
        for (int i = 0; i < lenA; i++) {
            for (int j = 0; j < lenB; j++) {
                if (i == 0 || j == 0) {
                    if (A[i] == B[j])
                        dp[i][j] = 1;
                }
            }
        }
        int max = 0;
        int indexi = 0;
        int index = 0;
        for (int i = 1; i < lenA; i++) {
            for (int j = 1; j < lenB; j++) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > max) {
                        max = dp[i][j];
                        index = j;
                        indexi = i;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        cout << "len is " << max << endl;
        //cout << "index is" << index << endl;
        string tempB = B.substr(index - max + 1, max);
        string tempA = A.substr(indexi - max + 1, max);
        //string tempA = A.substr(index-max+1,max);
        cout << "tempB\t" << tempB << endl;
        cout << "tempA\t" << tempA << endl;
        return max;

    }

    bool isPalindrome(string str, int len) {
        for (int i = 0; i < (len / 2) + 1; i++) {
            if (str[i] != str[len - i - 1]) {
                return false;
            }
        }
        return true;
    }

    int getLongestPalindrome(string A, int n) {
        // write code here
        //string B = A;
        //reverse(B.begin(),B.end());
        //return lcs(A,n,B,n);
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n - i; j++) {
                if (isPalindrome(A.substr(i, j), j)) {
                    if (j > max) {
                        max = j;
                    }
                }
            }
        }
        return max;
    }


    int getLongestPalindrome1(string A, int n) {
        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        // 初始化单个字符情况，均为1;
        // 初始化时候注意双字符串的情况，无论a还是aa都是回文字符串
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if(i && A[i] == A[i-1]){
                dp[i-1][i] = 1;
            }
        }

        int max = 0;

        /*
        for (int i = 0; i < n; i++) {
            for (int j = i+2; j < n; j++) {

                if(A[i] == A[j] && dp[i+1][j-1]){
                    //dp[i][j] = dp[i+1][j-1] + 2;
                    //if(i+1==j){
                    //dp[i][j] = dp[i+1][j-1] + 2;
                    //}
                    dp[i][j] = 1;
                    if(j-i+1 > max){
                        max = j-i+1;
                    }
                }
            }
        }
        */
        for(int len = 2;len < n;len++){
            for(int i = 0;i<n-len;i++){
                int j = i + len;
                if(A[i] == A[j] && dp[i+1][j-1]){
                    dp[i][j]  = 1;
                    if(j-i+1>max){
                        max = j-i+1;
                    }
                }
            }
        }

        return max;
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        //int dp[s.size()][s.size()] = {0}, left = 0, right = 0, len = 0;
        int lens = s.size();
        int dp[lens][lens];
        memset(dp,0, sizeof(dp));
        int left = 0, right = 0, len = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                if (dp[j][i] && len < i - j + 1) {
                    len = i - j + 1;
                    left = j;
                    right = i;
                }
            }
            dp[i][i] = 1;
        }
        return s.substr(left, right - left + 1);
    }

    //凑硬币
    //题目描述，用若干枚1、3、4来凑够aim,最少用多少枚硬币
    //要想知道凑够aim需要多少
    int leastCoins(int arr[],int arrLen,int aim){
        int dp[aim+1];
        memset(dp,0, sizeof(dp));
        //dp(i) = j表示凑够i元，最少需要j个硬币
        //dp的转移方程为dp(i) = min{(dp(i-value')+1)}(value'属于arr,也就是{1,3,4})
        dp[0] = 0;
        for(int i = 1;i<aim+1;i++){
            int temp = INT32_MAX;
            for(int j = 0;j<arrLen;j++){
                if(i-arr[j]>=0&&dp[(i-arr[j])]+1<temp){
                    temp = dp[(i-arr[j])]+1;
                }
            }
            dp[i] = temp;
        }
        return dp[aim];
    }
    // 最长递增子序列
    int longestIncreasingSubsequence(int arr[],int arrLen,int n){
        int dp[arrLen];
        memset(dp,0, sizeof(dp));
        dp[0] = 1;
        for(int i = 1;i<arrLen;i++){
            int max = 1;
            for(int j =0;j<i;j++){
                if(arr[i]>arr[j] && max < dp[j]+1)
                    max = dp[j]+1;
            }
            dp[i] = max;
        }
        return dp[n];
    }

};
int main() {
    Palindrome p = Palindrome();
    Solution s = Solution();
    // cout<<p.getLongestPalindrome("acbdcbbbdbdaaccbcacdacdccababcddabddaaaaaaabdbabcdddaacabacbacbbdabdacddbbadaacbbdcbccacacdabcabacacbbbdcccacdcdcdcbcbabdcdacdddbbabcaccddddddabdacaabccdcabcbcbabacaaaccaccaddabbdadcdacdcdbaadbcabdcdcaaacbcadccbbddbaddcaddcaadcbbcbbdcbdadcddabdddcdbddbbdabaaddcaadd",265)<<endl;
    // cout<<p.getLongestPalindrome("adbcbdf",6) <<endl;
    // cout<<p.getLongestPalindrome("baabccc",7)<<endl;
    // cout<<p.getLongestPalindrome("abc1234321ab",12)<<endl;
     cout<<p.getLongestPalindrome1("abc1234321ab",12)<<endl;//7
    // cout << p.getLongestPalindrome1("baabccc", 7) << endl;//4
    // cout << s.longestPalindrome("baabccc") << endl;
    // string d = "abcd";
    // cout<<d.substr(0,1)<<endl;
    // cout<<d.substr(0,2)<<endl;
    // cout<<d.substr(0,3)<<endl;
    // cout<<d.substr(0,4)<<endl;

    // least coins
    //int arr[] = {1,3,5};
    //for(int i = 0;i<=11;i++){
    //    cout << s.leastCoins(arr,3,i) << endl;
    //}

    //longest increasing subsequence
    //int arr[] = {5,3,4,8,6,7};
    //for(int i = 0;i<6;i++){
    //    cout << s.longestIncreasingSubsequence(arr,6,i)<<endl;
    //}

    return 0;
}