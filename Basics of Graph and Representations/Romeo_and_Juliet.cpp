#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool vis[N];
int dis[N];
vector<int> v[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : v[par])
        {
            if (!vis[child])
            {
                vis[child] = true;
                q.push(child);
                dis[child] = dis[par] + 1;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src, ds, k;
    cin >> src >> ds >> k;

    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    bfs(src);
    if (dis[ds] != -1 && dis[ds] <= k * 2)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}