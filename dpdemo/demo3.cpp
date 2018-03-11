/*
public class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] paths = new int[m][n];
        paths[0][0] = grid[0][0];
        for(int i = 1;i<m;i++){
            paths[i][0] = grid[i][0]+paths[i-1][0];
        }
        for(int j = 1;j<n;j++){
            paths[0][j] = grid[0][j]+paths[0][j-1];
        }

        for(int i=1;i<m;i++){
            for(int j = 1;j<n;j++){
                paths[i][j]=Math.max(paths[i-1][j],paths[i][j-1])+grid[i][j];
            }
        }
        return paths[m-1][n-1];
    }
}
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int col,row;
    cin >> row >> col;
    int grid[row][col],dp[row][col];
    for(int i =0;i<row;i++){
        for(int j = 0;j<col;j++){
            cin >> grid[i][j];
        }
    }
    memset(dp,0, sizeof(dp));
    dp[0][0] = grid[0][0];
    for(int i = 1;i<row;i++){
        dp[i][0] = grid[i][0]+dp[i-1][0];
    }
    for(int j = 1;j<col;j++){
        dp[0][j] = grid[0][j]+dp[0][j-1];
    }
    for(int i=1;i<row;i++){
        for(int j = 1;j<col;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i][j];
        }
    }
    cout << dp[row-1][col-1] << endl;
}