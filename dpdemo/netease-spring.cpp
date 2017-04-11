#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#define N 100000
using namespace std;
/*
class Solution {
public:
    int leastTime(int arr[], int len, int sum) {
        //int min = INT32_MAX;
        set<int>s;
        vector<vector<int> >v;
        s.insert(0);
        for(int i=0;i<len;i++){
            vector<int> m;

            set<int>added;
            for(set<int>::iterator it=s.begin();it!=s.end();it++){
                added.insert(*it + arr[i]);
            }
            for(set<int>::iterator i = added.begin();i!=added.end();i++){
                m.push_back(*i);
            }
            v.push_back(m);
            s.insert(added.begin(),added.end());
        }
        //cout << s.size() <<endl;
        int ans=sum;
        for(set<int>::iterator it=s.begin();it!=s.end();it++){
            ans=min(ans,max(*it,sum-*it));
        }
        return ans;
    }

    //暴力访问每个组合数，并求解
    //提交运行，没有出结果不对，反而爆出内存不够
    int leastTime1(int arr[],int arrLen,int sum){
        vector<int>time;
        time.push_back(arr[0]);
        for(int i = 1;i<arrLen;i++){
            int l = time.size();
            for(int j = 0;j<l;j++){
                int temp = time[j] + arr[i];
                time.push_back(temp);
            }
            time.push_back(arr[i]);
        }
        int min = INT32_MAX;
        for(int i = 0;i<time.size();i++){
            int t = sum - time[i] > time[i] ? sum - time[i] : time[i];
            if(t < min)
                min = t;
        }
        return min;
    }

    //改进1，替换vector为arr
    int leastTime2(int arr[],int arrLen,int sum){
        int time[N];
        int count = 0;
        memset(time,0,sizeof(time));
        time[count] = arr[0];
        count++;
        for(int i = 1;i<arrLen;i++){
            int l = count;
            for(int j = 0;j<l;j++){
                int temp = time[j] + arr[i];
                time[count] = temp;
                count++;
            }
            time[count] = arr[i];
            count++;
        }
        int min = INT32_MAX;
        for(int i = 0;i<count;i++){
            int t = sum - time[i] > time[i] ? sum - time[i] : time[i];
            if(t < min)
                min = t;
        }
        return min;
    }

    //转换成0-1背包问题
    // 状态变量dp[i][j]表示前i个物品去装容量为j的书包，最多能装多少
    // 状态转移方程dp[i][j] = max{dp[i-1][j],dp[i-1][j-v[i]]+v[i]}
    int leastTime3(int arr[],int arrLen,int sum){
        int dp[arrLen][sum];
        memset(dp,0, sizeof(dp));
        //dp[i][0] 为0
        //dp[0][i] 为0
        for(int i = 1;i<arrLen;i++){
            for(int j = 1;j<sum;j++){
                dp[i][j] = dp[i-1][j];
                if(j-arr[i] >= 0){
                    //dp[i][j] = dp[i-1][j] > dp[i-1][j-arr[i]]+arr[i] ? dp[i-1][j] : dp[i-1][j-arr[i]]+arr[i];
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i]]+arr[i] );
                }
            }
        }
        return max(sum-dp[arrLen-1][sum/2],dp[arrLen-1][sum/2]);
        //return  > dp[arrLen][sum/2] ? sum-dp[arrLen][sum/2]:dp[arrLen][sum/2] ;
    }

    vector<vector<int> > combination(int arr[],int arrLen){
        vector<vector<int> >ret;
        vector<int> s;
        s.push_back(arr[0]);
        ret.push_back(s);
        for(int i = 1;i<arrLen;i++){
            unsigned long l = ret.size();
            for(int j = 0;j<l;j++){
                s = ret[j];
                s.push_back(arr[i]);
                ret.push_back(s);
            }
            vector<int> temp;
            temp.push_back(arr[i]);
            ret.push_back(temp);
        }
        for(int i = 0;i<ret.size();i++){
            vector<int> a = ret[i];
            for(int j = 0;j<a.size();j++){
                cout << ret[i][j] << "\t";
            }
            cout << endl;
        }
        return ret;
    }

//#define N 100000
    //最少时间问题
    int leastCPUTime(int arr[],int len, int sum){
        int dp[N];
        memset(dp,0, sizeof(dp));
        for(int i = 0;i<len;i++){
            for(int j = sum/2; j >= arr[i];j--){
                dp[j] = max(dp[j-arr[i]]+arr[i],dp[j]);
            }
            //for(int j = 0;j<=sum/2;j++){
            //    if(j>=arr[i]){
            //        dp[j] = max(dp[j-arr[i]]+arr[i],dp[j]);
            //    }
            //}
        }
        return max(dp[sum/2],sum-dp[sum/2])*1024;
    }
};

int main(){
    int n;
    cin >> n;
    int arr[n];
    memset(arr,0, sizeof(arr));
    int sum = 0;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        arr[i] = arr[i]/1024;
        sum+= arr[i];
    }
    //for(int i = 0;i<n;i++){
    //    cout<<arr[i]<<"\t";
    //}
    //cout << endl;
    cout << sum << endl;
    Solution s = Solution();
    //int arr[] = {1,2,3};
    //s.combination(arr,3);
    //cout<<s.leastTime(arr,n,sum)<<endl;
    //cout<<s.leastTime3(arr,n,sum)<<endl;
    cout << s.leastCPUTime(arr,n,sum) << endl;

}
*/

const int maxn = 4194304 / 1024 * 55 + 5;

//int dp[maxn];
int main(){

    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for(int i = 0;i<n;i++){
        cin >> a[i];
        a[i] = a[i]/1024;
        sum += a[i];
    }
    /*
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; ++i) {
    	for(int j = sum/2; j >= a[i]; --j) {
        	dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
    	}

    }
    cout << max(dp[sum/2], sum-dp[sum/2])*1024 << endl;
     */
    int dp[n+1][sum+1];
    memset(dp,0, sizeof(dp));
    for(int k =0; k*a[0] <= sum;k++)
        dp[0][k*a[0]] = a[0];

    /*
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=sum;j++){
            if(j>=a[i])
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-a[i]]+a[i]);
        }
    }
     */
    for(int c = 0; c <= sum; c++){
        for(int i = 1;i<=n;i++){
            if(c >= a[i])
                dp[i][c] = max(dp[i-1][c],dp[i-1][c-a[i]]+a[i]);
        }
    }
    cout << "here" << endl;
    cout << dp[n][sum/2] <<endl;
    return 0;
}