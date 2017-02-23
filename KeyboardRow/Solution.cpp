#include<vector>
#include<stdio.h>
#include <cstring>
using namespace std;
#define ROW1 keyboard[0];
#define ROW2 keyboard[1];
#define ROW3 keyboard[2];
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
    	vector<string> ret;


    	int keyboard[3][122] = {{0},{0},{0}};
    	keyboard[0]['q'] = keyboard[0]['w'] = keyboard[0]['e'] = keyboard[0]['r'] = keyboard[0]['t'] = keyboard[0]['y'] = keyboard[0]['u'] = keyboard[0]['i'] = keyboard[0]['o'] = keyboard[0]['p'] = 1;
    	keyboard[0]['Q'] = keyboard[0]['W'] = keyboard[0]['E'] = keyboard[0]['R'] = keyboard[0]['T'] = keyboard[0]['Y'] = keyboard[0]['U'] = keyboard[0]['I'] = keyboard[0]['O'] = keyboard[0]['P'] = 1;
		keyboard[1]['a'] = keyboard[1]['s'] = keyboard[1]['d'] = keyboard[1]['f'] = keyboard[1]['g'] = keyboard[1]['h'] = keyboard[1]['j'] = keyboard[1]['k'] = keyboard[1]['l'] = 1;
		keyboard[1]['A'] = keyboard[1]['S'] = keyboard[1]['D'] = keyboard[1]['F'] = keyboard[1]['G'] = keyboard[1]['H'] = keyboard[1]['J'] = keyboard[1]['K'] = keyboard[1]['L'] = 1;
		keyboard[2]['z'] = keyboard[2]['x'] = keyboard[2]['c'] = keyboard[2]['v'] = keyboard[2]['b'] = keyboard[2]['n'] = keyboard[2]['m'] = 1;
		keyboard[2]['Z'] = keyboard[2]['X'] = keyboard[2]['C'] = keyboard[2]['V'] = keyboard[2]['B'] = keyboard[2]['N'] = keyboard[2]['M'] = 1;
		

		for(vector<string>::const_iterator it = words.begin(); it < words.end(); ++it){
			int flag[3] = {1,1,1};
			string tmp = (*it);
			for(int i = 0 ;i < 3; i++){
				for(int j = 0; j < tmp.length(); j++){
					if(keyboard[i][tmp[j]] == 0){
						flag[i] = 0;
						break;
					}
				}
			}
			if((flag[0] + flag[1] + flag[2]) == 1){	
					ret.push_back((*it));
			}
		}
        return ret;
    }

    bool check(string tmp){
    	int keyboard[3][122] = {{0},{0},{0}};
    	keyboard[0]['q'] = keyboard[0]['w'] = keyboard[0]['e'] = keyboard[0]['r'] = keyboard[0]['t'] = keyboard[0]['y'] = keyboard[0]['u'] = keyboard[0]['i'] = keyboard[0]['o'] = keyboard[0]['p'] = 1;
    	keyboard[0]['Q'] = keyboard[0]['W'] = keyboard[0]['E'] = keyboard[0]['R'] = keyboard[0]['T'] = keyboard[0]['Y'] = keyboard[0]['U'] = keyboard[0]['I'] = keyboard[0]['O'] = keyboard[0]['P'] = 1;
		keyboard[1]['a'] = keyboard[1]['s'] = keyboard[1]['d'] = keyboard[1]['f'] = keyboard[1]['g'] = keyboard[1]['h'] = keyboard[1]['j'] = keyboard[1]['k'] = keyboard[1]['l'] = 1;
		keyboard[1]['A'] = keyboard[1]['S'] = keyboard[1]['D'] = keyboard[1]['F'] = keyboard[1]['G'] = keyboard[1]['H'] = keyboard[1]['J'] = keyboard[1]['K'] = keyboard[1]['L'] = 1;
		keyboard[2]['z'] = keyboard[2]['x'] = keyboard[2]['c'] = keyboard[2]['v'] = keyboard[2]['b'] = keyboard[2]['n'] = keyboard[2]['m'] = 1;
		keyboard[2]['Z'] = keyboard[2]['X'] = keyboard[2]['C'] = keyboard[2]['V'] = keyboard[2]['B'] = keyboard[2]['N'] = keyboard[2]['M'] = 1;
		int flag[3] = {1,1,1};
		for(int i = 0 ;i < 3; i++){
			for(int j = 0; j < tmp.length(); j++){
				// printf("row:%d char:%c %d",(i+1),tmp[j],keyboard[i][tmp[j]]);
				if(keyboard[i][tmp[j]] == 0){
					flag[i] = 0;
					break;
				}
			}
			// printf("\n");
		}
		// printf("%d\t%d\t%d\n", flag[0] , flag[1] , flag[2]);
		return flag[0] + flag[1] + flag[2];
    }

};