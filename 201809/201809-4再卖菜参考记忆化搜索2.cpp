#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
const int MAXN = 400;
int a[MAXN], ans[MAXN], n;
bool flag,vis[MAXN][MAXN][MAXN];
 
void DFS(int step) {
    if (vis[step][ans[step - 1]][ans[step - 2]])
        return;
    if (step == n) {
        //注意最后一步需要同时满足两个条件
        if ((ans[n - 1] + ans[n - 2]) / 2 == a[n - 1])
            flag = true;
        return;
    }
    //讨论余数为0或者为1或者为2的三种情况
    for (int i = 0; i < 3; i++) {
        ans[step] = 3 * a[step - 1] - ans[step - 1] - ans[step - 2] + i;
        if (1 <= ans[step]) {
            vis[step][ans[step - 1]][ans[step - 2]] = true;
            DFS(step + 1);
            if (flag)
                return;
        }
    };
}
 
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    if (n == 2) {
        printf("%d %d\n", 1, 2 * a[0] - 1);
        return 0;
    }
    int temp = 2 * a[0];
    for (int i = 1; i <= temp; i++) {
        //讨论余数为0或者为1的两种情况
        if (i != temp) {
            ans[0] = i;
            ans[1] = temp - i;
            DFS(2);
            if (flag)
                break;
        }
        ans[0] = i;
        ans[1] = temp - i + 1;
        DFS(2);
        if (flag)
            break;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    putchar('\n');
    return 0;
}

