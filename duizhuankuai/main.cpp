#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int n,sum=0;
    cin >> n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    //cout << sum <<endl;
    int dp[sum];
    memset(dp,0,sizeof(dp));
    for(int i = 0;i<n;i++){
        for(int j=sum/2;j>=arr[i];j--){
            dp[j] = max(dp[j],dp[j-arr[i]]+arr[i]);
        }
    }
    //cout << dp[sum/2] << endl;
    //cout << sum << endl;

    int ret = max(dp[sum/2],sum-dp[sum/2]);
    cout << sum << endl;
    cout << ret << endl;
    cout << sum-ret << endl;
    if(dp[sum/2]*2 == sum){
        cout << dp[sum/2] << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}