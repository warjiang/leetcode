#include <iostream>
#include <vector>

using namespace std;
class Solution{
public:
    //构造组合数
    vector<vector<int> > getAllCombination(int arr[],int len){
        vector<vector<int> >ret;
        vector<int>a;
        a.push_back(arr[0]);
        ret.push_back(a);
        for(int i = 1;i<len;i++){
            unsigned long l = ret.size();
            for(int j = 0;j<l;j++){
                vector<int> temp = ret[j];
                temp.push_back(arr[i]);
                ret.push_back(temp);
            }
            vector<int>b;
            b.push_back(arr[i]);
            ret.push_back(b);
        }
        return ret;
    }
    vector<vector<int> >p;
    //生成全序列
    void getPermutation(int arr[], int start, int len){
        if(start == len-1){
            //显示、保存全序列
            vector<int> temp;
            for(int i = 0;i<len;i++){
                temp.push_back(arr[i]);
            }
            p.push_back(temp);
        }
        for(int i = start;i<len;i++){
            swap(arr[start],arr[i]);
            getPermutation(arr,start+1,len);
            swap(arr[start],arr[i]);
        }
    }

    vector<vector<int> > getAllPermutation(int arr[], int len){
        vector<vector<int> > ret;
        vector<vector<int> > combinations = getAllCombination(arr,len);
        for(int i = 0;i<combinations.size();i++){
            int tempArr[combinations[i].size()];
            for(int j= 0;j<combinations[i].size();j++){
                tempArr[j] = combinations[i][j];
            }
            p.clear();
            getPermutation(tempArr,0,combinations[i].size());
            //ret.insert(ret.end(),p.begin(),p.end());
            for(int j = 0;j<p.size();j++){
                ret.push_back(p[j]);
            }
        }
        return ret;
    }
};

int main(){
    int arr[] = {1,4,8};

    Solution s = Solution();
    vector<vector<int> > r = s.getAllPermutation(arr,3);
    for(int i = 0;i<r.size();i++){
        for(int j= 0;j<r[i].size();j++){
            cout << r[i][j] <<  "\t";
        }
        cout << endl;
    }

    return 0;
}