//#include <iostream>
//#include <vector>
//#include <cstring>
//using namespace std;
//
//
//#define  N 5
//bool isSameColor(char v[],char c[], int len){
//    char temp = c[0];
//    bool ret = true;
//    for(int i = 1;i<len;i++){
//        if(c[i] != temp){
//            ret = false;
//            break;
//        }
//    }
//    return ret;
//}
//
//bool isSequence(char v[],char c[],int len){
//    //int max=-1,min=INT_MAX,sum = 0;
//    for(int i = 0;i<len;i++){
//        char min =v[i];
//        int index = i;
//        for(int j = i+1;j<len;j++){
//            if(min > v[j]){
//                min = v[j];
//                index = j;
//            }
//        }
//        if(index != i){
//            char temp = v[i];
//            v[i] = v[index];
//            v[index] = temp;
//        }
//    }
//    bool ret = true;
//
//    for(int i = 0;i<len-1;i++){
//        //cout << v[i] << "\t";
//        if(v[i+1] - v[i] > 1){
//            ret = false;
//            break;
//        }
//    }
//    //cout << endl;
//    /*
//    int  sum = 0,min = INT_MAX;
//    for(int i = 0;i<len;i++){
//        if(min > v[i]){
//            min = v[i];
//        }
//        sum+=v[i];
//
//    }
//    cout << min << "\t" << sum << endl;
//    if((5*min+10) == sum){
//        return true;
//    }else{
//        return false;
//    }
//     */
//
//    //return (sum -10) % 5 == 0;
//    /*
//    double a = (sum -10)/5;
//    cout << a << endl;
//    if(a-(int)a==0){
//        return true;
//    }else{
//        return false;
//    }
//    */
//    return ret;
//}
//int num[127];
//void analyse(char v[],char c[],int len){
//    //int num[127];
//    memset(num,0, sizeof(num));
//    for(int i =0;i<len;i++){
//        num[v[i]]++;
//    }
//}
//
//int main(){
//    //int v1[N];char v2[N];
//    char v1[N],v2[N];
//    memset(v1,0, sizeof(v1));
//    memset(v2,0, sizeof(v2));
//
//
//    for(int i = 0;i<N;i++){
//        cin >> v1[i];
//        cin >> v2[i];
//    }
//    /*
//    for(int i = 0;i<N;i++){
//        cout << v1[i] << "\t" << v2[i] << endl;
//    }
//     */
//    int ret = 7;
//    if(isSameColor(v1,v2,N)){
//        //同色
//        if(isSequence(v1,v2,N)){
//            //顺子
//            cout << "sequence" <<endl;
//            ret = ret <  1 ? ret : 1;
//        }else{
//            ret = ret <  4 ? ret : 4;
//        }
//    }else{
//        if(isSequence(v1,v2,N)){
//            // 顺子不同色
//            //cout << isSequence(v1,v2,N) << endl;
//            ret = ret <  5 ? ret : 5;
//        }
//
//        analyse(v1,v2,N);
//        bool same2 = false,same3 = false,same4 = false;
//        for(int i = '2'; i <= 'Z';i++){
//            if(num[i] == 2){
//                same2 = true;
//            }
//            if(num[i] == 3){
//                same3 = true;
//            }
//            if(num[i] == 4){
//                same4 = true;
//            }
//
//        }
//        if(same4){
//            //ret = 2;
//            ret = ret <  2 ? ret : 2;
//        }else{
//            if(same3){
//                if(same2){
//                    //ret = 3;
//                    ret = ret <  3 ? ret : 3;
//                }else{
//                    //ret = 6;
//                    ret = ret <  6 ? ret : 6;
//                }
//            }
//        }
//
//    }
//    cout << ret << endl;
//    return 0;
//}

#include <iostream>
#include <cstring>
using namespace std;


#define  N 5
bool isSameColor(int v[],char c[], int len){
    char temp = c[0];
    bool ret = true;
    for(int i = 1;i<len;i++){
        if(c[i] != temp){
            ret = false;
            break;
        }
    }
    return ret;
}

bool isSequence(int v[],char c[],int len){

    //int max=-1,min=INT_MAX,sum = 0;
    for(int i = 0;i<len;i++){
        char min =v[i];
        int index = i;
        for(int j = i+1;j<len;j++){
            if(min > v[j]){
                min = v[j];
                index = j;
            }
        }
        if(index != i){
            char temp = v[i];
            v[i] = v[index];
            v[index] = temp;
        }
    }
    bool ret = true;

    for(int i = 0;i<len-1;i++){
        cout << v[i] << "\t";
        if(v[i+1] - v[i] > 1){
            ret = false;
            break;
        }
    }
    return ret;

    /*
    int sum = 0;
    for(int i = 0;i<len;i++){
        sum+=v[i];
    }
    return (sum - 10) % 5 == 0;
     */
    /*
    int  sum = 0,min = INT_MAX;
    for(int i = 0;i<len;i++){
        if(min > v[i]){
            min = v[i];
        }
        sum+=v[i];

    }
    cout << min << "\t" << sum << endl;
    if((5*min+10) == sum){
        return true;
    }else{
        return false;
    }
     */
}
int num[127];
void analyse(int v[],char c[],int len){
    //int num[127];
    memset(num,0, sizeof(num));
    for(int i =0;i<len;i++){
        num[v[i]]++;
    }
}

int main(){
    //int v1[N];char v2[N];
    int map[1000];
    map['J'] = 11;
    map['Q'] = 12;
    map['K'] = 13;
    map['A'] = 14;
    int v1[N];
    char v2[N];
    memset(v1,0, sizeof(v1));
    memset(v2,0, sizeof(v2));

    char temp;
    for(int i = 0;i<N;i++){
        //cin >> v1[i];
        cin >> temp;
        if(temp=='J' || temp == 'Q' || temp == 'K' || temp == 'A'){
            v1[i] = map[temp];
        }else{
            v1[i] = temp - '0';
        }
        cin >> v2[i];
    }
    /*
    for(int i = 0; i< N;i++){
        cout << v1[i] << "\t";
    }
    cout << endl;
    return 0;
     */
    /*
    for(int i = 0;i<N;i++){
        cout << v1[i] << "\t" << v2[i] << endl;
    }
    */
    int ret = 7;
    if(isSameColor(v1,v2,N)){
        //同色
        if(isSequence(v1,v2,N)){
            //顺子
            //cout << "sequence" <<endl;
            ret = ret <  1 ? ret : 1;
        }else{
            ret = ret <  4 ? ret : 4;
        }
    }else{
        if(isSequence(v1,v2,N)){
            // 顺子不同色
            //cout << isSequence(v1,v2,N) << endl;
            ret = ret <  5 ? ret : 5;
        }
        analyse(v1,v2,N);
        bool same2 = false,same3 = false,same4 = false;
        for(int i = 2; i <= 20;i++){

            if(num[i] == 2){
                same2 = true;
            }
            if(num[i] == 3){
                same3 = true;
            }
            if(num[i] == 4){
                same4 = true;
            }

        }
        //cout << same2 << "\t" << same3 << "\t" << same4 << endl;
        if(same4){
            //ret = 2;
            ret = ret <  2 ? ret : 2;
        }else{
            if(same3){
                if(same2){
                    //ret = 3;
                    ret = ret <  3 ? ret : 3;
                }else{
                    //ret = 6;
                    ret = ret <  6 ? ret : 6;
                }
            }
        }

    }
    cout << ret << endl;
    return 0;
}