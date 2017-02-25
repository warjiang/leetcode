#include <iostream>
#include <vector>
// #include <math.h>
// #include <stdio.h>
#include "Solution.cpp"
using namespace std;

void tranverseVector(vector<int> v){
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << (*it) << endl;
	}
}


int main(){
	int findNumsArr[] = {2,4}; 
	vector<int> findNums(findNumsArr, findNumsArr + sizeof(findNumsArr)/sizeof(int));


	int numsArr[] = {1,2,3,4}; 
	vector<int> nums(numsArr, numsArr + sizeof(numsArr)/sizeof(int));
	//tranverseVector(nums);
	Solution* s = new Solution;
	vector<int> v = s->nextGreaterElement(findNums, nums);
	tranverseVector(v);
	return 0;
}