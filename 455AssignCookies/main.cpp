#include <iostream>
#include <vector>
using namespace std;

//bool less(const int & m1, const int & m2) {
//    return m1 < m2;
//}
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        sort(g.begin(),g.end(),less<int>());
        sort(s.begin(),s.end(),less<int>());
        int i = 0, j= 0;
        while (i<g.size() && j<s.size()){
            if(s[j] >= g[i]){
                i++;
                j++;
                res++;
            }else{
                j++;
            }
        }

        return  res;
    }
};
int main() {
    //std::cout << "Hello, World!" << std::endl;
    int g[] = {1,5};
    int s[] = {1,1,4};
    vector<int> vg = vector<int>(g, g+sizeof(g)/ sizeof(int));
    vector<int> vs = vector<int>(s, s+sizeof(s)/ sizeof(int));
    Solution solution = Solution();
    cout << solution.findContentChildren(vg,vs) << endl;
    return 0;
}