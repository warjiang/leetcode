#include <iostream>
#include <vector>

using namespace std;
#define N 200000
#define M 50
static int total = 0;
static int hit = 0;

class Solution {
private:

public:

    int coins1(int arr[], int len, int aim) {
        if (arr == NULL || len == 0 || aim < 0) {
            return 0;
        }
        return process1(arr, len, 0, aim);
    }

    int process1(int arr[], int len, int index, int aim) {
        int res = 0;
        if (index == len) {
            res = aim == 0 ? 1 : 0;
        } else {
            for (int i = 0; arr[index] * i <= aim; i++) {
                res += process1(arr, len, index + 1, aim - arr[index] * i);
            }
        }
        return res;
    }

    int coins2(int *arr, int len, int aim) {
        total = 0;
        hit = 0;
        if (arr == NULL || len == 0 || aim < 0) {
            return 0;
        }
        //vector<vector<int> > map(arr.size()+1, vector<int>(aim+1,0));
        //int map[N][N];
        int **map = new int *[N];
        for (int i = 0; i < N; ++i)
            map[i] = new int[N];
        return process2(arr, len, 0, aim, map);
    }

    int process2(int *arr, int len, int index, int aim, int **map) {
        int res = 0;
        if (index == len) {
            res = aim == 0 ? 1 : 0;
        } else {
            // 尝试从map中取值
            // 为0表示对应的过程并没有被搜索过
            // 非0表示对应的过程搜索结果（-1表示搜索结果为0）
            int mapValue = 0;
            for (int i = 0; arr[index] * i <= aim; i++) {
                mapValue = map[index + 1][aim - arr[index] * i];
                if (mapValue != 0) {
                    res += mapValue == -1 ? 0 : mapValue;
                    hit++;
                } else {
                    res += process2(arr, len, index + 1, aim - arr[index] * i, map);
                }
                total++;
            }
        };
        map[index][aim] = res == 0 ? -1 : res;
        return res;
    }

    int process3(int *arr, int len, int aim) {
        int **dp = new int *[len];
        for (int i = 0; i < len; i++) {
            dp[i] = new int[aim + 1];
        }
        // 初始化

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < aim + 1; j++) {
                dp[i][j] = 0;
            }
        }
        // 初始化第一行
         for(int i = 0; i<aim+1;i++){
            if(i%arr[0] == 0){
                dp[0][i]  = 1;
            }
         }
        // 初始化第一列
        for(int j = 0; j<len;j++){
            dp[j][0] = 1;
        }
        for (int i = 1; i < len; i++) {
            for (int j = 1; j < aim + 1; j++) {
                //int temp = j;
                //for (int k = 0; arr[i] * k <= j; k++) {
                //    dp[i][j] += dp[i - 1][j-arr[i] * k];
                //}
                //if(j-arr[i] >= 0)
                //    dp[i][j] = dp[i - 1][j] + dp[i][j-arr[i]];
                //else
                //    dp[i][j] = dp[i - 1][j] + 0;
                dp[i][j] = dp[i - 1][j] + ((j-arr[i] >= 0) ? dp[i][j-arr[i]] : 0);
            }
        }

        /*for(int i = 0;i<len;i++){
            for(int j = 0;j<aim+1;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;

        }*/

        return dp[len - 1][aim];
    }

    // m苹果的个数、n盘子的个数
    // 暴力破解
    int getNum1(int m,int n){
        int res = 0;
        if(n<=1){
            return 1;
        }
        for(int i = 0; i< m/2;i++){
            res += getNum1(m-i,n-1);
        }
        return res;
    }

    // 由暴力破解可以导出记忆化搜索方法
    int getNum2(int m,int n){
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
        return getNumProcess2(m,n,map);
    }
    int getNumProcess2(int m,int n,int **map){
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
                res += getNumProcess2(m-i,n-1,map);
            }
        }
        map[m][n] = res;
        return res;
    }
    //从记忆化搜索以及暴力破解可以看出，可以推导出动态规划
    int getNum4(int m,int n){
        //申请二维数组
        int **dp = new int*[M];
        for(int i = 0; i< M;i++){
            dp[i] = new int[M];
        }
        for(int i = 0;i<M;i++){
            for(int j = 0;j<M;j++){
                dp[i][j] = 0;
            }
        }
        //初始化

        for(int i = 0;i<M;i++){
            dp[0][i] = 1;
        }
        for(int i = 0; i<M;i++){
            dp[i][0] = 0;
        }
        for(int i = 1;i<M;i++){
            for(int j = 1;j<M;j++){
                for(int k = 0;k<M;k++){
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        return dp[m][n];

    }
};

int main() {
    /*
    int arr[] = {5, 10, 25, 1};
    vector<int> v = vector<int>(arr, arr + sizeof(arr) / sizeof(int));
    Solution s = Solution();
    //cout << s.process3(arr, 4, 10) << endl;
    time_t start, stop;

    start = time(NULL);
    cout <<s.coins1(arr,4,10)<<endl;
    stop = time(NULL);
    printf("Use Time:%ld\n",(stop-start));


    start = time(NULL);
    cout << s.coins2(arr,4, 10) << endl;
    stop = time(NULL);
    printf("Use Time:%ld\n",(stop-start));
    cout << (float)hit / total << endl;


    start = time(NULL);
    cout << s.coins2(arr,4, 100000) << endl;
    stop = time(NULL);
    printf("Use Time:%ld\n",(stop-start));


    start = time(NULL);
    cout << s.process3(arr,4, 100000) << endl;
    stop = time(NULL);
    printf("Use Time:%ld\n",(stop-start));
    */
    int m = 1,n =1;
    Solution s = Solution();
    cout << s.getNum2(m,n) << endl;
    return 0;
}