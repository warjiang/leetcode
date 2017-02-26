#include <vector>
using namespace std;
class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ones = 0, old_max_ones = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                old_max_ones++;
            }else{
                if(old_max_ones >= max_ones){
                    max_ones = old_max_ones;
                }
                old_max_ones = 0;
            }
        }
        if(old_max_ones >= max_ones){
            max_ones = old_max_ones;
        }
        return max_ones;
    }
};