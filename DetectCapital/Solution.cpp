#include <vector>
using namespace std;
class Solution {
public:
	bool detectCapitalUse(string word) {
		// detect first letters
		// cout <<"*"<< (word[0] <= 'Z') << endl;
		bool flag = true;
		int word_len = word.length();
		if((word[0] <= 'Z')&&(word[0] >= 'A')){
			//USA or Google
			if(word_len >= 2){
				if((word[1] <= 'Z')&&(word[1] >= 'A')){
					// USA
					//bool flag = true;
					for(int i = 2;i< word_len;i++){
						if((word[i] > 'Z')||(word[i] < 'A')){
							flag = false;
							break;
						}	
					}
					//return flag;
				}else{
					// Google
					//bool flag = true;
					for(int i = 2;i< word_len;i++){
						if((word[i] > 'z')||(word[i] < 'a')){
							flag = false;
							break;
						}	
					}
					//return flag;
				}
			}else{
				//return true;
				flag = true;
			}
		}else if((word[0] <= 'z')&&(word[0] >= 'a')){
			//leetcode
			//bool flag = true;
			for(int i = 1;i< word_len;i++){
				if((word[i] > 'z')||(word[i] < 'a')){
					flag = false;
					break;
				}	
			}

		}else{
			flag = false;
		}
        return flag;
    }
};