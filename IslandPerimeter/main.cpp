#include <iostream>
#include <vector>
#include "Solution.cpp"
using namespace std;

int main(){
	Solution* s = new Solution;
	/*
	int a[4][4] = { {0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}} ;
	vector<vector<int> > v(4,vector<int>(4));
	for(int i = 0;i <4;i++){
		for(int j = 0;j<4;j++){
			v[i][j] = a[i][j];
		}
	}
	*/
	int a[1][1] = { {1}} ;
	vector<vector<int> > v(4,vector<int>(4));
	for(int i = 0;i <1;i++){
		for(int j = 0;j<1;j++){
			v[i][j] = a[i][j];
		}
	}
	cout << s->islandPerimeter(v) << endl;
	return 0;
}