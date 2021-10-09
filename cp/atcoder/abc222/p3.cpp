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

// G
// C
// P
// 0 -> a beats b
// 1 -> draw
// 2 -> a loses to b
int game[3][3] = {
    {1, 0, 2},
    {2, 1, 0},
    {0, 2, 1}};

void solve()
{
    int n, m;
    cin >> n >> m;
    map<char, int> mp;
    mp['G'] = 0;
    mp['C'] = 1;
    mp['P'] = 2;
    vector<string> arr(2 * n);
    vector<int> w(2 * n), ids(2 * n);
    iota(ids.begin(), ids.end(), 0);
    for (int i = 0; i < 2 * n; i++)
        cin >> arr[i];
    auto cmp = [&](int &i1, int &i2)
    {
        if (w[i1] == w[i2])
            return i1 < i2;
        return w[i1] > w[i2];
    };
    for (int j = 0; j < m; j++)
    {
        for (int i = 1; i < 2 * n; i += 2)
        {
            int tmp = game[mp[arr[ids[i - 1]][j]]][mp[arr[ids[i]][j]]];
            if (tmp == 0)
                w[ids[i - 1]]++;
            else if (tmp == 2)
                w[ids[i]]++;
        }
        sort(ids.begin(), ids.end(), cmp);
    }
    for (int id : ids)
        cout << id + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}