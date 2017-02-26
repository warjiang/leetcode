#include <vector>
using namespace std;
class Solution {
public:
	int islandPerimeter(vector<vector<int> >& grid) {
		int a = 0,b = 0,row = grid.size(), col = grid[0].size();
        for(int i = 0; i < row; i++){
        	for(int j = 0; j < col; j++){
        		// 	grid[i-1][j-1]	!grid[i-1][j]	grid[i-1][j+1]
        		// 	!grid[i][j-1]	!grid[i][j]	 	!grid[i][j+1]
        		// 	grid[i+1][j-1]	!grid[i+1][j]	grid[i+1][j+1]
        		a += grid[i][j];
        		if(i == (row-1)){
        			//first line
        			if((j < col-1) && ((grid[i][j]+grid[i][j+1]) == 2)){
        				b++;
        			}
        		}else{
        			//other line
        			if((j < col-1) && ((grid[i][j]+grid[i][j+1]) == 2)){
        				b++;
        			}
        			if((grid[i+1][j]+grid[i][j]) == 2){
        				b++;
        			}
        		}
        	}
        }
        return 4*a - 2*b;
    }
};