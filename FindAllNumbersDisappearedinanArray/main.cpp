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
	int a[] = {4,3,2,7,8,2,3,1};
	vector<int> v (a, a + sizeof(a)/sizeof(int));
	//cout << v[8] << endl;
	Solution* s = new Solution;
	vector<int> ret = s->findDisappearedNumbers(v);
	tranverseVector(ret);
	return 0;
}