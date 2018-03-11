#include <iostream>
#include <vector>
#include <set>

using namespace std;
int num = 0;

/*
void mergecount(vector<int> &a, vector<int> b, int low, int high, int mid) {
    int m = mid, n = high, p = high;
    while (m >= low && n >= mid + 1) {
        if (a[m] < a[n])
            b[p--] = a[n--];
        else {
            b[p--] = a[m--];
            num += (n - mid);
        }
    }
    while (m >= low)
        b[p--] = a[m--];
    while (n >= mid + 1)
        b[p--] = a[n--];

    for (int i = low; i <= high; i++)
        a[i] = b[i];
}
*/
/*
void merge(vector<int> &a, vector<int> b, int low, int high) {
    if (low + 1 < high) {
        int mid = (low + high) / 2;
        merge(b, a, low, mid);
        merge(b, a, mid + 1, high);
        //mergecount(a, b, low, high, mid);
        int m = mid, n = high, p = high;
        while (m >= low && n >= mid + 1) {
            if (b[m] < b[n])
                a[p--] = b[n--];
            else {
                a[p--] = b[m--];
                num += (n - mid);
            }
        }
        while (m >= low)
            a[p--] = b[m--];
        while (n >= mid + 1)
            a[p--] = b[n--];
    } else if (low + 1 == high) {
        if (a[high] <= a[low]){
            int t = a[low];
            a[low] = a[high];
            a[high] = t;
            num++;
        }
    }
}

int InversePairs(vector<int> data) {
    int len = data.size();
    if (data.size() <= 1)
        return 1000000007;
    vector<int> vec(len);
    for (int i = 0; i < len; ++i) {
        vec[i] = data[i];
    }
    merge(data, vec, 0, len - 1);
    return num % 1000000007;
}


int main() {
    int array[] = {364, 637, 341, 406, 747, 995, 234, 971, 571, 219, 993, 407, 416, 366, 315, 301, 601, 650, 418, 355,
                   460, 505, 360, 965, 516, 648, 727, 667, 465, 849, 455, 181, 486, 149, 588, 233, 144, 174, 557, 67,
                   746, 550, 474, 162, 268, 142, 463, 221, 882, 576, 604, 739, 288, 569, 256, 936, 275, 401, 497, 82,
                   935, 983, 583, 523, 697, 478, 147, 795, 380, 973, 958, 115, 773, 870, 259, 655, 446, 863, 735, 784,
                   3, 671, 433, 630, 425, 930, 64, 266, 235, 187, 284, 665, 874, 80, 45, 848, 38, 811, 267, 575};
    vector<int> data = vector<int>(array, array + sizeof(array) / sizeof(int));
    cout << InversePairs(data) << endl;

    srand((unsigned) time(NULL));
    int a = 1, b = 100000;
    set<int> s;
    while (s.size() < 10000) {
        int t = (rand() % (b - a + 1)) + a;
        s.insert(t);
    }
    vector<int> data;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        data.push_back(*it);
    }
    data.push_back(0);

    clock_t start, end;
    start = clock();
    //cout << InversePairs(data) << endl;
    for (int i = 0; i < 2*10^5; ++i) {
        //cout << "<<<<<<<<<<" << i << ">>>>>>>>>" << endl;
    }
    end = clock();
    double dur = (double) (end - start);
    printf("Use Time:%f\n", (dur / CLOCKS_PER_SEC));

    return 0;
}
*/

set<string> s;

void perm(string &str, int left, int right) {
    if (left >= right) {
        s.insert(str);
        return;
    }

    for (int i = left; i <= right; i++) {
        swap(str[i], str[left]);
        perm(str, left + 1, right);
        swap(str[i], str[left]);
    }
}

vector<string> Permutation(string str) {
    vector<string> res;
    if (str.empty())
        return res;
    int len = str.size();
    perm(str, 0, len - 1);
    res.assign(s.begin(),s.end());
    return res;
}

bool hasPathCore(char* matrix, int row, int col, char* str, int index, int i, int j, int* visited) {
    if (index == strlen(str))
        return true;
    if (i >= row || j >= col || i < 0 || j < 0 || visited[i*col+j] == 1)
        return false;

    if (matrix[i*col+j] != str[index])
        return false;
    else
    {
        visited[i*col+j] = 1;
        int a[] = {-1, 0, 1, 0};
        int b[] = {0, 1, 0, -1};
        bool flag = false;
        index++;
        for (int k = 0; k < 4; k++)
            flag = flag || hasPathCore(matrix, row, col, str, index, i + a[k], j + b[k], visited);
        if (flag == false)
            visited[i*col+j] = 0;
        return flag;
    }

}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
    if (matrix == NULL || rows*cols == 0 || str == NULL)
        return false;
    int* visited = new int[rows*cols];
    memset(visited, 0, rows*cols*sizeof(int));
    int index = 0;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
        {
            if (hasPathCore(matrix, rows, cols, str, index, i, j, visited))
                return true;
        }
    return false;

}

bool judge(int threshold, int i, int j) {
    int sum = 0;
    while (i != 0) {
        sum += i % 10;
        i /= 10;
    }
    while (j != 0) {
        sum += j % 10;
        j /= 10;
    }
    if (sum > threshold)
        return false;
    else
        return true;
}

int movingCountCore(int threshold, int row, int col, int i, int j, int* visited) {
    // 递归终止条件
    if (i<0 || j<0 || i>=row || j>=col || !judge(threshold,i,j) || visited[i*col+j]==1)
        return 0;
    // 调用载体
    int a[]={-1,0,1,0};
    int b[]={0,1,0,-1};
    int sum = 1;
    visited[i*col+j]=1;
    for (int k=0;k<4;k++)
        sum+=movingCountCore(threshold,row,col,i+a[k],j+b[k],visited);
    return sum;
}

int movingCount(int threshold, int rows, int cols)
{
    int res = 0;
    int* visited = new int[rows*cols];
    memset(visited,0,rows*cols*sizeof(int));
    res = movingCountCore(threshold,rows,cols,0,0,visited);
    return res;
}

bool matchcore(char* str, char* pattern) {
    if (*str == '\0' && *pattern == '\0')
        return true;
    if (*str != '\0' && *pattern == '\0')
        return false;

    if (*(pattern + 1) == '*') {

        if(*str == *pattern || (*pattern == '.' && *str != '\0'))
            return matchcore(str, pattern + 2) || matchcore(str +1, pattern);
        else
            return matchcore(str, pattern + 2);

        //return matchcore(str, pattern + 2) || matchcore(str +1, pattern) || matchcore(str +1, pattern+2);
    }
    else if (*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchcore(str + 1, pattern + 1);
    else
        return false;
}

bool match(char* str, char* pattern)
{
    if (str == NULL || pattern == NULL)
        return false;
    return matchcore(str, pattern);
}

int main(){
    /*
    string str = "a";
    vector<string> res = Permutation(str);
     */
    /*
    char* m1="ABCESFCSADEE";
    char* s1="ABCCED";
    cout<<hasPath(m1,3,4,s1)<<endl;//true

    char* m2="ABCESFCSADEE";
    char* s2="SEE";
     cout<<hasPath(m2,3,4,s2)<<endl;//true

    char* m3="AAAAAAAAAAAA";
    char* s3="AAAAAAAAAAAA";
    cout<<hasPath(m3,3,4,s3)<<endl;//true

    cout<<movingCount(5,10,10)<<endl;
    */
    cout<<match("aaa","aa*a.a")<<endl;
    return 0;
}
