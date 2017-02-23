#include <iostream>
#include <string>
// #include <math.h>
// #include <stdio.h>
#include "Solution.cpp"
using namespace std;


void traverse_vector(vector<string>& words){
	for(vector<string>::const_iterator it = words.begin(); it < words.end(); ++it)
	{
		string tmp = (*it);
		// cout<<tmp[0]<<endl;
		// cout<<tmp.length()<<endl;
		cout << tmp << endl;
	}
		// cout<<(*it)[0]<<endl;
}


int main(){
	// Solution* s = new Solution;
	// cout << s->findComplement(5) << endl;
	// cout << s->findComplement(1) << endl;
	// vector <string> words("Hello", "Alaska", "Dad", "Peace");
	std::vector<string> words;
	words.push_back("Hello");
	words.push_back("Alaska");
	words.push_back("Dad");
	words.push_back("Peace");
	// traverse_vector(words);
	// cout << int('a') << int('A') <<endl;
	// cout << int('z') << int('Z') <<endl;
	Solution *s = new Solution;
	vector<string> ret = s->findWords(words);
	traverse_vector(ret);
	// cout << s->check("Hello") << endl;
	return 0;
}