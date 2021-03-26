// https://codeforces.com/contest/1506/problem/G
// Maximize the Remaining String

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    string str, res = "";
    cin >> str;
    int n = str.length();
    vector<deque<int>> ids(26);
    for (int i = 0; i < n; i++)
        ids[str[i] - 'a'].push_back(i);
    vector<int> vis(26, false);
    for (int i = 0; i < 26; i++)
        if (ids[i].empty())
            vis[i] = true;
    while (count(vis.begin(), vis.end(), true) < 26)
    {
        int cur = 0;
        for (int j = 25; j >= 0; j--)
        {
            if (vis[j])
                continue;
            bool f = true;
            for (int k = j - 1; f && k >= 0; k--)
            {
                if (vis[k])
                    continue;
                if (ids[j].front() > ids[k].back())
                    f = false;
            }
            if (f)
            {
                cur = j;
                break;
            }
        }
        vis[cur] = true;
        res.pb(char(cur + 'a'));
        for (int j = 25; j >= 0; j--)
        {
            if (vis[j])
                continue;
            while (ids[j].front() < ids[cur].front())
                ids[j].pop_front();
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}