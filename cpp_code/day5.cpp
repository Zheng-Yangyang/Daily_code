/*
服务器有三种运行状态:空载、单任务、多任务，每个时间片的能耗的分别为1、3、4;
每个任务由起始时间片和结束时间片定义运行时间:
如果一个时间片只有一个任务需要执行，则服务器处于单任务状态；
如果一个时间片有多个任务需要执行，则服务器处于多任务状态；
给定一个任务列表，请计算出从第一个任务开始，到所有任务结束，服务器的总能耗
例子
输入: 3
     4 8
     1 6
     2 9
输出: 3 4
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1e6 + 10;
int a[N], diff[N];
int main() {
    int n;
    cin >> n;
    int begin = 1000001;
    int last = 0;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        begin = min(begin, start);
        last = max(last, end);
        diff[start]++;
        diff[end + 1]--;
    }
    a[0] = diff[0];
    for (int i = begin; i <= last; i++)
    {
        a[i] = a[i - 1] + diff[i];
    }
    int result = 0;
    for (int i = begin; i <= last; i++)
    {
        if (a[i] == 0)   result += 1;
        else if (a[i] == 1)  result += 3;
        else
        {
            result += 4;
        }
    }
    cout << result << endl;



    return 0;
}