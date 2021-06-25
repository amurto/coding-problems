// https://codeforces.com/contest/1333/problem/D
// Challenges in school №41

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, k;
    string str;
    cin >> n >> k >> str;
    int cnt = count(str.begin(), str.end(), 'L');
    if (cnt == 0 || cnt == n)
    {
        cout << "-1\n";
        return;
    }
    vector<int> pos(cnt);
    for (int i = 0, j = 0; i < n; i++)
        if (str[i] == 'L')
            pos[j++] = i;
    int id = 0;
    while (id < cnt && (pos[id] == 0 || str[pos[id] - 1] == 'L'))
        id++;
    int rem = 0;
    for (int i = 0; i < cnt; i++)
        rem += pos[i] - i;
    if (id == cnt || rem < k)
    {
        cout << "-1\n";
        return;
    }
    vector<vector<int>> ops(k);
    for (int e = 1; e <= k; e++)
    {
        int idx = e - 1, keep = k - e;
        int mx = rem - keep;
        vector<int> tmp;
        for (int i = id; mx > 0 && i < cnt; i++)
        {
            if (str[pos[i] - 1] == 'R')
            {
                tmp.pb(i);
                mx--;
            }
        }
        for (int t : tmp)
        {
            ops[idx].pb(pos[t]);
            rem--;
            swap(str[pos[t] - 1], str[pos[t]]);
            pos[t]--;
        }
        while (id < cnt && (pos[id] == 0 || str[pos[id] - 1] == 'L'))
            id++;
    }
    if (rem > 0)
    {
        cout << "-1\n";
        return;
    }
    for (vector<int> v : ops)
    {
        cout << v.size() << " ";
        for (int u : v)
            cout << u << " ";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}