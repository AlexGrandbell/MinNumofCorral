//有n头牛（1<=n<=50,000)要挤奶。给定每头牛挤奶的时间区间[A,B](1<=A<=B<=1,000,000，A,B为整数)。牛需要呆在畜栏里才能挤奶。一个畜栏同一时间只能容纳一头牛。问至少需要多少个畜栏，才能完成全部挤奶工作，以及每头牛都放哪个畜栏里？注意：在同一个畜栏的两头牛，它们挤奶时间区间不能在端点重合。
//
//输入格式:
//第1行：一个正整数N；
//第2..N+1行：第i+1行的两个整数给出第i头奶牛的挤奶时间。
//
//输出格式：
//需要畜栏的最小数
//
//输入样例：
//5
//1 10
//2 4
//3 6
//5 8
//4 7
//
//输出样例：
//4

#include <iostream>
#include <vector>
using namespace std;

//int main() {
//    int n,max = 0;
//    cin >> n;
//    int a[n], b[n];
//    int res = 0;
//    for (int i = 0; i < n; i++) {
//        cin >> a[i] >> b[i];
//        if (b[i] > max) {
//            max = b[i];
//        }
//    }
//    vector<int> v(max + 1, 0);
//    for (int i = 0; i < n; i++) {
//        for (int j = a[i]; j <= b[i]; j++) {
//            v[j]++;
//        }
//    }
//    for (int i = 0; i < v.size(); i++) {
//        if (v[i] > res) {
//            res = v[i];
//        }
//    }
//    cout << res << endl;
//    return 0;
//}

int main(){
    int n;
    cin>>n;
    vector<int> res;
    vector<int> start,end;
    for (int i = 0; i < n; ++i) {
        int temp1,temp2;
        cin>>temp1>>temp2;
        start.push_back(temp1);
        end.push_back(temp2);
    }
    for (int i = 0; i < n; ++i) {
        bool isAvaliable = false;
        for (int& num: res) {
            if (num<start[i]){
                num = end[i];
                isAvaliable = true;
                break;
            }
        }
        if (!isAvaliable){
            res.push_back(end[i]);
        }
    }
    cout<<res.size()<<endl;
}
