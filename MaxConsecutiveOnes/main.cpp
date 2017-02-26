#include <iostream>
#include <vector>
#include "Solution.cpp"
using namespace std;

void tranverseVector(vector<int> v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	}
}

int main(){
	Solution* s = new Solution;
	int arr[] = {1,1,0,1,1,1};
	vector<int> v(arr, arr+sizeof(arr)/sizeof(int));
	int n = s->findMaxConsecutiveOnes(v);
	cout << n << endl;
	//tranverseVector(v);
	return 0;
}