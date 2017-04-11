// write your code here cpp
#include <iostream>
using namespace std;
#define M 50
class Solution {
public:
    //从记忆化搜索以及暴力破解可以看出，可以推导出动态规划
    int getNum(int m,int n){
        int **map = new int*[m+1];
        //int **map = new int*[N];
        //这里似乎有bug，如果采用int **map = new int*[m+1];和map[i] = new int[n+1];
        //2D数组不会被初始化为0，需要手动初始化。
        //但是如果直接使用int **map = new int*[N];和map[i] = new int[N];的话，2D数组会自动被初始化为0
        for(int i = 0; i < m+1 ;i++){
            //map[i] = new int[N];
            map[i] = new int[n+1];
        }
        for(int i = 0;i<m+1;i++){
            for(int j = 0;j<n+1;j++){
                map[i][j] = 0;
            }
        }
        return getNumProcess(m,n,map);

    }
    int getNumProcess(int m,int n,int **map){
        int res = 0;
        if(n<=1){
            return 1;
        }
        for(int i = 0; i< m/2;i++){
            //res += getNum1(m-i,n-1);
            int mapValue = map[m-i][n-1];
            if(mapValue != 0){
                res += mapValue;
            }else{
                res += getNumProcess(m-i,n-1,map);
            }
        }
        map[m][n] = res;
        return res;
    }
};

int main(){
    int a,b;
    cin >> a >> b;
    Solution s = Solution();
    cout << s.getNum(a,b) << endl;
    return 0;
}