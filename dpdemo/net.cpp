#include <iostream>
#include <algorithm>

using namespace std;

//typedef long long LL;
const int maxn = 4194304 / 1024 * 55 + 5;
int dp[maxn], a[55];

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        //scanf("%d", &a[i]);
        cin >> a[i];
        a[i] /= 1024;
        sum += a[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        //for (int j = sum / 2; j >= a[i]; --j) {
        //    dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        //}
        for (int j = a[i]; j <=sum / 2; ++j) {
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }
    printf("%d\n", max(dp[sum / 2], sum - dp[sum / 2]) * 1024);

    return 0;
}