#include <stdio.h>
#include <math.h> 
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret(n);
        for(int i = 1;i <= n;i++){
            string tmp = "";
            if(i%3 == 0){
                tmp += "Fizz";
            }
            if(i%5 == 0){
                tmp += "Buzz";
            }

            if(tmp.empty()){
                char buffer[32];
                sprintf(buffer, "%d", i);
                tmp = string(buffer);
            }
            ret[(i-1)] = tmp;

        }
        return ret;
    }

};