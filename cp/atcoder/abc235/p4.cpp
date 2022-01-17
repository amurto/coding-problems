#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e6 + 5, inf = 1e7;

int rotateNum(int cur)
{
    int last = cur % 10;
    cur /= 10;
    string str = to_string(cur);
    int len = (int)str.length();
    while (len > 0)
    {
        last *= 10;
        len--;
    }
    return last + cur;
}

int solve()
{
    int a, n;
    cin >> a >> n;
    queue<int> q;
    vector<bool> vis(N);
    vector<int> dis(N, inf);
    q.push(1);
    vis[1] = true;
    dis[1] = 0;
    while (!q.empty())
    {
        int sz = (int)q.size();
        while (sz > 0)
        {
            int cur = q.front();
            q.pop();
            if (cur * 1ll * a < N && !vis[cur * a])
            {
                vis[cur * a] = true;
                dis[cur * a] = dis[cur] + 1;
                q.push(cur * a);
            }
            if (cur >= 10 && cur % 10 > 0)
            {
                int num = rotateNum(cur);
                if (num < N && !vis[num])
                {
                    vis[num] = true;
                    dis[num] = dis[cur] + 1;
                    q.push(num);
                }
            }
            sz--;
        }
    }
    return dis[n] >= inf ? -1 : dis[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}