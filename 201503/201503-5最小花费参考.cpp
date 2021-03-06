/* CCF201503-5 最小花费 */
 
#include <iostream>
#include <cstring>
#include <vector>
 
using namespace std;
 
typedef unsigned long long ULL;
 
const int MAXN = 100000;
ULL price[MAXN+1];
int visited[MAXN+1];
 
struct adjacency {
    int node, edge;
    adjacency(int n, int e) { node = n; edge = e;}
};
vector<adjacency> g[MAXN+1];
 
struct node {
    int node, edge;
};
 
int N, M;
ULL ans;
bool endflag;
 
void dfs(int node, int end, ULL miniprice)
{
    ULL currprice;
    ULL cost;
 
    if(node == end) {
        cout << ans << endl;
 
        endflag = true;
 
        return;
    } else {
        visited[node] = 1;
        for(int i=0; i<(int)g[node].size() && !endflag; i++) {
            if(!visited[g[node][i].node]) {
                currprice = min(miniprice, price[node]);
 
                cost = g[node][i].edge * currprice;
 
                ans += cost;
                dfs(g[node][i].node, end, currprice);
                ans -= cost;
            }
        }
    }
}
 
int main()
{
    int u, v, e;
 
    // 输入数据
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        cin >> price[i];
    for(int i=1; i<=N-1; i++) {
        cin >> u >> v >> e;
 
        g[u].push_back(adjacency(v, e));
        g[v].push_back(adjacency(u, e));
    }
 
    // 输入起点和终点，用DFS计算最小花费，并且输出结果
    int start, end;
    for(int i=0; i<M; i++) {
        cin >> start >> end;
 
        memset(visited, 0, sizeof(visited));
        endflag = false;
        ans = 0;
        dfs(start, end, price[start]);
    }
 
    return 0;
}

