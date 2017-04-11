#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define N 10000

void f(int n) {
    int a[N];
    memset(a, 0, sizeof(a));
    //int i = 1;

    a[0] = 1;
    for (int j = 2; j <= n; j++) {
        int c = 0;
        for (int i = 0; i < N; i++) {
            int s = a[i] * j + c;
            a[i] = s % 10;
            c = s / 10;
        }
    }
    int k;
    for(k= N-1;k>=0&&a[k]==0;k--);
    for(int j=k;j>=0;j--){
        cout << a[j];
    }
    cout << endl;

}

int main() {
    //std::cout << "Hello, World!" << std::endl;
    f(1000);
    return 0;
}


/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int a;
    while (cin>>a){
        vector<int> vec(a);
        for (int i=0; i<a; i++) cin>>vec[i];
        sort(vec.begin(),vec.end());
        int sum1=0,sum2=0;
        for(int j=a-1; j>=0; j--) {
            cout<<vec[j]/1024<<" ";
            if (sum1>=sum2) sum2 += vec[j];
            else sum1+=vec[j];
        }
        cout<<endl;
        int res= sum1>=sum2 ? sum1 : sum2 ;
        cout<<res/1024<<endl;
    }
    return 0;
}*/



//#include <bits/stdc++.h>
#include <vector>

/*using namespace std;

int vis[204800];
vector<int> a;
int n;
int solve(vector<int> vec) {
    int i, j, len = 0;
    for(int i = 0; i < vec.size(); ++i)  len += (vec[i] /= 1024);
    memset(vis, 0, sizeof(vis[0]) * (len / 2 + 1));

    vis[0] = 1;
    for(i = 0; i < vec.size(); ++i) {
        for(j =  len / 2 - vec[i]; j >= 0; --j) {
            if(vis[j] && !vis[j + vec[i]]) {
                vis[j + vec[i]] = 1;
            }
        }
    }
    i = len / 2;
    cout << len <<endl;
    while(i >= 0 && !vis[i])
        --i;
    for(int k = 0;k<vec.size();k++){
        cout << vec[k] <<" ";
    }
    cout <<endl;
    for(int k = i;k>=0;k--){
        if(vis[k]){
            cout << k << "  ";
        }

    }
    cout << endl;
    return (len - i) * 1024;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    cout << solve(a) << endl;
    return 0;
}*/


//int dp[210000];
//int n,arr[51];
//void display(int arr[],int len){
//    for(int i =0;i<len;i++){
//        cout <<arr[i]<<" ";
//    }
//    cout <<endl;
//}
//int main()
//{
//    int n;
//    scanf("%d",&n);
//    int sum = 0;
//    for(int i = 0 ; i < n ; i ++){
//        scanf("%d",&arr[i]);
//        arr[i] /= 1024;
//        sum += arr[i];
//    }
//    int sum1=0;
//    for(int i = 0 ; i < n ; i ++) {
//        //sum1+=arr[i];
//        for (int j = sum / 2; j >= arr[i]; --j)
//            dp[j] = max(dp[j], dp[j - arr[i]] + arr[i]);//dp[j]表示在容量为j的情况可存放的重量
//        display(dp,sum/2+1);
//        //cout<<sum1-dp[sum1/2]<<" ";
//    }
//    //display(dp,sum/2);
//    cout<<endl;
//    cout << sum << dp[sum/2] <<endl;
//    printf("%d\n",(sum-dp[sum/2]));
//    return 0;
//}
//#include <math.h>
//class Solution {
//public:
//    vector<int> constructRectangle(int area) {
//        int max = (int) ceil(sqrt(area));
//        vector<int> ret;
//        for(int i = max;i>0;i--){
//            //double a = i;
//            if(area%i ==0 ){
//                int a = i;
//                int b = area/a;
//                int m1 = a > b ? a: b;
//                int m2 = a < b ? a: b;
//                ret.push_back(m1);
//                ret.push_back(m2);
//                return ret;
//            }
//        }
//        return ret;
//
//    }
//};
//
//void tranverseVector(vector<int> v){
//    for(int i = 0;i<v.size();i++){
//        cout << v[i] << endl;
//    }
//}
//
//int main(){
//    Solution s = Solution();
//    //cout << s.constructRectangle(4) <<endl;
//    tranverseVector(s.constructRectangle(100));
//}