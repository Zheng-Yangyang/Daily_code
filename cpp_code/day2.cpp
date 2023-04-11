/*
 * @Author: yangyang zheng ‘1332616027@qq.com’
 * @Date: 2023-04-11 19:08:12
 * @LastEditors: yangyang zheng ‘1332616027@qq.com’
 * @LastEditTime: 2023-04-11 19:41:53
 * @FilePath: \cpp_code\day2.cpp
 * @Description: 今天学习trie树
 */
/*
存储字符串，并且快速查找字符串是否存在
*/

#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

const int N = 1e6 + 10;
int son[N][26], cnt[N], idx;
//这里面son数组的第一维就是字符串映射到数字，不同字符串不会相同
//idx是用来给字符串编号的，按照顺序来，比如abc可能为2，bcd可能为5
char str[N];
void insert(const string &s)
{
    int p = 0;
    for(int i = 0; i < s.size(); i ++)
    {
        int c = s[i] - 'a';
        if(!son[p][c])  son[p][c] = ++idx;//当前如果不存在这个字符
        p = son[p][c];
    }
    cnt[p] ++;
}

int query(const string&s)
{
    int p = 0;
    for(int i = 0; i < s.size(); i ++)
    {
        int c = s[i] - 'a';
        if(!son[p][c])  return 0;
        p = son[p][c];
    }
    return cnt[p];
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        char op[2];
        scanf("%s%s", op, str);
        if (*op == 'I') insert(str);
        else printf("%d\n", query(str));
    }

    return 0;
}
