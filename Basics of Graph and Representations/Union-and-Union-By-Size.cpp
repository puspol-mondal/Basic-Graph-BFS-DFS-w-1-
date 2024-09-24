#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int pra[N];
int dsu_size[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        pra[i] = -1;
        dsu_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if (pra[node] == -1)
    {
        return node;
    }
    int leader = dsu_find(pra[node]);
    pra[node] = leader;
    return leader;
}
void dsu_union(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    pra[leaderB] = leaderA;
}
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (dsu_size[leaderA] > dsu_size[leaderB])
    {
        pra[leaderB] = leaderA;
        dsu_size[leaderA] += dsu_size[leaderB];
    }
    else
    {
        pra[leaderA] = leaderB;
        dsu_size[leaderB] += dsu_size[leaderA];
    }
}
int main()
{
    dsu_initialize(7);
    dsu_union_by_size(1, 2);
    dsu_union_by_size(2, 3);
    dsu_union_by_size(4, 5);
    dsu_union_by_size(5, 6);
    cout << dsu_find(1) << endl;
    cout << dsu_find(4) << endl;

    return 0;
}