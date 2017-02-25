#include <stdio.h>
#include <math.h> 
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ret;
        for(int i = 0; i < findNums.size(); i++){
            int temp = findNums[i];
            int j = 0;
            for(;(temp != nums[j]) && (j < nums.size()); j++);
            for(;(nums[j] <= temp) && (j < nums.size()); j++);
            if(j >= nums.size()){
                ret.push_back(-1);
            }else{
                ret.push_back(nums[j]);
            }
        }
        return ret;
    }

};