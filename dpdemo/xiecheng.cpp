#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <unordered_map>
#include <cstring>
#define  N 10000
using namespace std;

bool Comp(const int &a, const int &b)
{
    return a > b ;
}
/*请完成下面这个函数，实现题目要求的功能*/
/*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */
/******************************开始写代码******************************/
string CaseServerBalance(string caseList, string serQueList) {
    vector<int> casev;
    string::size_type lastpos,pos;
    pos = caseList.find(",");
    lastpos = 0;

    while( pos != string::npos){
        string temp = caseList.substr(lastpos,pos-lastpos);
        casev.push_back(atoi(temp.c_str()));
        lastpos = pos+1;
        pos = caseList.find(",",pos+1);
    }
    string temp = caseList.substr(lastpos);
    casev.push_back(atoi(temp.c_str()));

    unordered_map<string,int> server;
    //hash_map<const char*, int> CharHash;
    pos = serQueList.find(",");
    lastpos = 0;
    int taskNum = 0;
    int serverNum = 0;
    int arr[N];
    vector<int> d;
    memset(arr,-1, sizeof(arr));
    while( pos != string::npos){
        string t = serQueList.substr(lastpos,pos-lastpos);
        string::size_type i =  t.find(":");
        string name = t.substr(3,i-3);
        string num = t.substr(i+1,t.length()-i-2);
        int name_t = atoi(name.c_str());
        int num_t = atoi(num.c_str());
        server[name] = num_t;
        d.push_back(num_t);
        arr[name_t] = num_t;
        taskNum += num_t;
        serverNum++;
        lastpos = pos+1;
        pos = serQueList.find(",",pos+1);
    }
    string t = serQueList.substr(lastpos);
    string::size_type i =  t.find(":");
    string name = t.substr(3,i-3);
    int name_t = atoi(name.c_str());
    string num = t.substr(i+1,t.length()-i-2);
    int num_t = atoi(num.c_str());
    server[name] = num_t;
    arr[name_t] = num_t;
    d.push_back(num_t);
    taskNum += num_t;
    serverNum++;
    int taskAve = taskNum/serverNum;

    sort(d.begin(),d.end());
    sort(casev.begin(),casev.end(),less<int>());
    /*
    for(int i = 0;i<casev.size();i++){
        cout << casev[i] << "\t";
    }
    cout << endl;
     */
    int current = 0;

    for(int i = 0;i<casev.size();i++){
        //cout << d[i]<<endl;
        //find d[i]
        //cout << d[i] <<endl;
        unordered_map<string,int>::iterator it;
        for(it = server.begin();it!=server.end()&&it->second != d[i];it++);
        //分配
        cout << "IP" <<it->first<<endl;
        if(it->second < taskAve && current < casev.size()){
            cout << "prpare assign" <<endl;
            int len = taskAve - it->second;
            for(int j = current;j<len;j++){
                cout << "["<<casev[j]<<",IP"<< it->first <<"]" ;
            }
            current = current+len+1;
            server[it->first] = taskAve;
        }
        //cout << it->first << endl;
        cout << endl<<"====="<<endl;

     }




    //sort(server.begin(),server.end());






    return  "";
}
/******************************结束写代码******************************/


int main() {
    string res;

    string _caseList;
    getline(cin, _caseList);
    string _serQueList;
    getline(cin, _serQueList);

    res = CaseServerBalance(_caseList, _serQueList);
    cout << res << endl;

    return 0;

}