#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> arr[10000];
int dis[501];
void dist(int s)
{
    priority_queue<pair<int, int>> pq;
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        pair<int, int> cc;
        cc = pq.top();
        pq.pop();
        int v = cc.second;
        int cost = cc.first;
        for (auto p : arr[v])
        {
            int x = p.first;
            int y = p.second;
            if (dis[y] > dis[v] + cost)
            {

                pq.push({-dis[y], y});
            }
        }
    }
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            dis[i] = -1;
        }
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;

            arr[a].push_back({c, b});
            arr[b].push_back({c, a});
        }
        int t;
        cin >> t;
        dist(t);
        for (int i = 0; i < n; i++)
        {
            cout << dis[i] << endl;
        }
    }
}