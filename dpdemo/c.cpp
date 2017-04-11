#include <iostream>
#include <string>

using namespace std;

class Palindrome {
public:
    void lcs(string A, int lenA, string B, int lenB, int *max, int *index) {
        int v[lenA][lenB];
        memset(v, 0, lenA * lenB * sizeof(int));
        for (int i = 0; i < lenA; i++) {
            for (int j = 0; j < lenB; j++) {
                if (i == 0 || j == 0) {
                    if (A[i] == B[j]) {
                        v[i][j] = 1;
                    }
                }
            }
        }
        //int max = 0 ,index =0;
        //max  = 0;
        //index = 0;
        *max = 0, *index = 0;
        for (int i = 1; i < lenA; i++) {
            for (int j = 1; j < lenB; j++) {
                if (A[i] == B[j]) {
                    v[i][j] = v[i - 1][j - 1] + 1;
                    if (v[i][j] > *max) {
                        *max = v[i][j];
                        *index = i - *max + 1;
                    }
                } else {
                    v[i][j] = 0;
                }
            }
        }
        //cout << "lcs is :" << max << endl;
        //cout << A.substr(index,max)<<endl;
    }

    /*
    string addToPalindrome(string A, int n) {
        // write code here
        string s = A;
        int max,index;
        reverse(s.begin(),s.end());
        lcs(A,A.length(),s,s.length(),&max,&index);
        //cout<<max<<endl;
        //cout<<index<<endl;
        if(max == 0){
            //找不到回文序列
            //return A+s.substr(1);
            return s.substr(1);
        }else{
            //cout << "ex" <<endl;
            //string temp = A.substr(0,index);
            string middle = A.substr(index,max);
            string left = A.substr(0,index);
            string right = A.substr(max);
            cout << "left :" << left << endl;
            cout << "right:" << right << endl;
            if(!left.empty()){
            }
            //cout << temp << endl;
            //string ret = A - temp;
            //reverse(temp.begin(),temp.end());
            //return A+temp;
            //return "--";
        }

    }
    */
    bool isPalindrome(string str) {
        unsigned long len = str.length();
        bool f = true;
        for (int i = 0; i < (len / 2 + 1); i++) {
            if (str[i] != str[len - i - 1]) {
                f = false;
                return f;
            }
        }
        return f;
    }

    string addToPalindrome(string A, int n) {
        string s = A;
        reverse(s.begin(), s.end());
        string ans;
        while(!s.empty()){
            ans.push_back(s.back());
            s.pop_back();
            if(isPalindrome(s)){
                break;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

};

int main() {
    Palindrome p = Palindrome();
    //cout << p.addToPalindrome("ab",2) << endl;
    cout << p.addToPalindrome("abbbbbaa", 8) << endl;
    //cout << p.isPalindrome("ab") << endl;
    return 0;
}