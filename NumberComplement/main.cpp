#include <iostream>
// #include <math.h>
// #include <stdio.h>
#include "Solution.cpp"
using namespace std;

int main(){
	Solution* s = new Solution;
	cout << s->findComplement(5) << endl;
	cout << s->findComplement(1) << endl;
	return 0;
}