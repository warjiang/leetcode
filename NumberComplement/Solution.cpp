#include <stdio.h>
#include <math.h> 
class Solution {
public:
    // int findComplement(int num) {
    //     int e = 0;
    //     while((num >= pow(2,e))){
    //     	e++;
    //     };
    //     return (((int)pow(2,e)-1) ^ num);
    // }

    int findComplement(int num) {
        if(num <= 1){
        	return 0;
        }
        return (1 - num%2) + 2 * findComplement(num/2);
    }

};