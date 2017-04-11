#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin>>n) {
        double arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        double dp[n][n+1];
        memset(dp,0,sizeof(dp));
        dp[0][1]=arr[0];
        dp[0][0]=1-arr[0];
        for (int j=1;j<n;j++) {
            dp[j][0]=dp[j-1][0]*(1-arr[j]);
        }

        for (int i=1;i<n;i++)
            for (int j=0;j<=i+1;j++)
                dp[i][j]=dp[i-1][j]*(1-arr[i])+dp[i-1][j-1]*arr[i];

        double sum=0;
        for (int i=int(0.6*n+1);i<=n;i++)
            sum+=dp[n-1][i];

        cout<<sum<<endl;

    }

    return 0;
}