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
	cout << s->detectCapitalUse("mL") << endl;
	
	//tranverseVector(v);
	return 0;
}