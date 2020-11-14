#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int minimumJumps(vector<int> &forbidden, int a, int b, int x)
{
    unordered_set<int> forbi(forbidden.begin(), forbidden.end());
    vector<vector<bool>> vis(2, vector<bool>(5000));
    queue<pair<int, bool>> q;
    q.push({0, false});
    vis[0][0] = 1;
    vis[1][0] = 1;
    int jumps = 0;
    while (!q.empty())
    {
        int len = q.size();
        while (len-- > 0)
        {
            pair<int ,int> cur = q.front();
            if (cur.first == x)
                return jumps;
            q.pop();
            int forward = cur.first + a;
            int backward = cur.second - b;
            if (forward < 5000 && vis[0][forward] == 0 && !forbi.count(forward))
            {
                q.push({forward, false});
                vis[0][forward] = 1;
            }
            if (!cur.second && backward >= 0 && vis[1][backward] == 0 && !forbi.count(backward))
            {
                q.push({backward, true});
                vis[1][backward] = 1;
            }
        }
        jumps++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> forbidden = {8, 3, 16, 6, 12, 20};
    int a = 15, b = 13, x = 11;
    cout << minimumJumps(forbidden, a, b, x) << "\n";
    return 0;
}