#include <iostream>
#include <vector>
#include <string>
#include <sstream>
// #include <math.h>

#include "Solution.cpp"
using namespace std;

void tranverseVector(vector<string> v){
	for(vector<string>::iterator it = v.begin(); it != v.end(); it++){
		cout << (*it) << endl;
	}
}


int main(){
	int n = 15;
	Solution* s = new Solution;
	string a = "";
	vector<string> v = s->fizzBuzz(n);
	//vector<string> ret(n);
	//stringstream stream; 
	//string str;
	//stream << 1234;     //向stream中插入整型数1234 
	//stream >> str; 
	//cout << str << endl;
	//stream << 1234;     //向stream中插入整型数1234 
	//stream >> str; 
	//cout << str << endl;
	tranverseVector(v);
	//cout << a.empty() <<endl;
	return 0;
}