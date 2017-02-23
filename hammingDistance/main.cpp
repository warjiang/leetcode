#include <iostream>
#include "Solution.cpp"
using namespace std;

int main(){
	Solution* s = new Solution;
	int x = 1, y = 4;

	cout << s->hammingDistance(x,y) << endl;
	cout << (0&-1) << endl;
	return 0;
}