/*
 * @Author: yangyang zheng ‘1332616027@qq.com’
 * @Date: 2023-04-13 18:42:03
 * @LastEditors: yangyang zheng ‘1332616027@qq.com’
 * @LastEditTime: 2023-04-13 19:15:03
 * @FilePath: \cpp_code\day4.cpp
 * @Description: 今天写点图论题目和数学题目
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 105;
int g[N][N];
int d[N][N];
int n, m;
struct node
{
    int x, y;
};
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1 ,0, -1};

int bfs(int x, int y)
{
    queue<node> q;
    q.push({x, y});
    memset(d, -1, sizeof d);
    d[0][0] = 0;
    while(q.size())
    {
        auto u = q.front();
        q.pop();
        for(int i = 0; i < 4; i ++)
        {
            int a = u.x + dx[i], b = u.y + dy[i];
            if(a >= 0 && a < n && b >= 0 && b < m && g[a][b] == 0 && d[a][b] == -1)
            {
                d[a][b] = d[u.x][u.y] + 1;
                q.push({a, b});
            }
        }
    }
    return d[n - 1][m - 1];
}

int main()
{
    
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
            cin >> g[i][j];
    }
    cout << bfs(0, 0) << endl;
}

/*
下面是一道快速幂的题目

*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;


LL qmi(int a, int b, int p)
{
    LL res = 1 % p;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * (LL)a % p;
        b >>= 1;
    }
    return res;
}


int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        int a, b, p;
        scanf("%d%d%d", &a, &b, &p);
        printf("%lld\n", qmi(a, b, p));
    }

    return 0;
}
