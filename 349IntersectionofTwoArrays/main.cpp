#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //sort(nums1.begin(),nums1.end(),less<int>());
        //sort(nums2.begin(),nums2.end(),less<int>());
        unordered_map<int,int>m1,m2;
        vector<int> v;
        for(int i = 0;i<nums1.size();i++){
            m1[nums1[i]] = 1;
        }
        for(int i = 0;i<nums2.size();i++){
            m2[nums2[i]] = 1;
        }
        for(unordered_map<int,int>::iterator it = m1.begin();it!=m1.end();it++){
            //cout << it->first << " " <<it->second << endl;
            int num = it->first;
            if(m2[num]==1){
                v.push_back(num);
            }
        }
        return v;
    }
};
void tranverseVector(vector<int> v){
    for(int i = 0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    int nums1Arr[] = {1, 2, 2, 1};
    int nums2Arr[] = {2, 2};
    vector<int> nums1 = vector<int>(nums1Arr,nums1Arr+ sizeof(nums1Arr)/ sizeof(int));
    vector<int> nums2 = vector<int>(nums2Arr,nums2Arr+ sizeof(nums2Arr)/ sizeof(int));
    Solution s = Solution();
    tranverseVector(s.intersection(nums1,nums2));
    return 0;
}