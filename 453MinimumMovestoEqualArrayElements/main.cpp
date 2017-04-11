#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end(),less<int>());
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
        }
        return sum - nums.size()*nums[0];
    }
};
int main() {
    //std::cout << "Hello, World!" << std::endl;

    int arr[] = {-1,1};
    vector<int> a = vector<int>(arr, arr+ sizeof(arr)/ sizeof(int));
    Solution s = Solution();
    cout << s.minMoves(a) << endl;
    return 0;
}