/*
 * @Author: yangyang zheng ‘1332616027@qq.com’
 * @Date: 2023-04-12 22:24:38
 * @LastEditors: yangyang zheng ‘1332616027@qq.com’
 * @LastEditTime: 2023-04-12 22:33:45
 * @FilePath: \cpp_code\day3.cpp
 * @Description: 今天学习的是并查集算法
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;
int p[N];   //p[N]表示的是每个节点的父节点，并且将父节点等于本身的点定义为根节点(或者代表节点)
int find(int x)  // 返回x的祖先节点 + 路径压缩
{
    if (p[x] != x) p[x] = find(p[x]);   //将x的父亲置为x父亲的祖先节点,实现路径的压缩
    return p[x];
}


int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )  p[i] = i;   //刚开始都是一个节点一堆，所以每个节点都是根节点
    while (m -- )
    {
        string op;
        int a, b;
        cin >> op >> a >> b;
        if (op == "M") p[find(a)] = find(b);    //
        else
        {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        
    }
    return 0;
}
/*
下面这个是有统计连通块数量的代码
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int p[N], siz[N];
int n, m;
int find(int x)
{
    if(p[x] == x)   return x;
    return p[x] = find(p[x]);
}

void unionset(int x, int y)
{
    x = find(x), y = find(y);
    if(siz[x] > siz[y])   swap(x, y);
    p[x] = y;
    siz[y] += siz[x];
}


int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        siz[i] = 1;
    }

    while (m -- )
    {
        string op;
        int a, b;
        cin >> op;

        if (op == "C")
        {
            cin >> a >> b;
            a = find(a), b = find(b);
            if (a != b)
            {
                unionset(a, b);
            }
        }
        else if (op == "Q1")
        {
            cin >> a >> b;
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else
        {
            cin >> a;
            cout << siz[find(a)] << endl;
        }
    }

    return 0;
}
