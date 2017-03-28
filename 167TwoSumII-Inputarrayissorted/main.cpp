#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> m;
        vector<int> ret;
        for(int i = 0;i<numbers.size();i++){
            m[numbers[i]] = 1;
        }
        for(int i = 0; i<numbers.size();i++){
            int a = numbers[i];
            int b = target - numbers[i];
            if(m[b] ==  1){
                int k;
                for(k = i+1;k<numbers.size();k++){
                    if(numbers[k] == b){
                        break;
                    }
                }
                //ret.push_back()
                int index1 = i + 1;
                int index2 = k + 1;
                int maxindex = index1 > index2 ? index1 : index2;
                int minindex = index1 < index2 ? index1 : index2;
                ret.push_back(minindex);
                ret.push_back(maxindex);
                break;
            }
        }
        return ret;
    }
};

void tranverseVector(vector<int> v){
    for(int i = 0;i<v.size();i++){
        cout << v[i] << endl;
    }
}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    Solution s = Solution();
    int numbers[]={-1,0};
    int target=-1;
    vector<int> v = vector<int>(numbers,numbers+ sizeof(numbers)/ sizeof(int));
    tranverseVector(s.twoSum(v,target));
    return 0;
}