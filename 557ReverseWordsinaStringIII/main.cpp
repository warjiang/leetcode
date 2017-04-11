#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;


vector<string> splitString(string str,string split){
    vector<string> ret;
    string::size_type lastpos,pos;
    lastpos = 0;
    pos = str.find(split);
    while (pos!=string::npos){
        string temp = str.substr(lastpos,pos-1);
        ret.push_back(temp);
        lastpos = pos+1;
        pos = str.find(split,pos+1);
    }
    string temp = str.substr(lastpos);
    ret.push_back(temp);
    return ret;
}


class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        char c[s.size()+1];
        int c_index = 0;
        for(int i = 0;i<s.length();i++){
            //st.push(s[i]);
            if(s[i] == ' '){
                // 出栈
                while(!st.empty()){
                    c[c_index] = st.top();
                    st.pop();
                    c_index++;
                }
                c[c_index] = ' ';
                c_index++;
            }else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            c[c_index] = st.top();
            st.pop();
            c_index++;
        }
        c[c_index] = '\0';
        //cout << c_index <<"x"<<s.length()<<endl;
        string ret = c;
        cout << ret.length() <<endl;
        return ret;

    }
};



int main() {
    //std::cout << "Hello, World!" << std::endl;
    Solution s = Solution();
    cout <<s.reverseWords("Let's take LeetCode contest")<<endl;
    return 0;
}