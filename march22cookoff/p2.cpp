#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int B = 64;

int pop_cnt(int x, int y)
{
    return __builtin_popcount(x ^ y);
}

bool display(int i1, int i2, int i3, int i4)
{
    if (i1 == i3 || i2 == i3 || i1 == i4 || i2 == i4)
        return false;
    cout << i1 << " " << i2 << " " << i3 << " " << i4 << "\n";
    return true;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<pii>> st(31);
    if (n >= B)
    {
        for (int i = 1; i < n; i += 2)
            st[pop_cnt(arr[i - 1], arr[i])].pb({i - 1, i});
        for (int b = 0; b < 31; b++)
            if ((int)st[b].size() >= 2)
                if (display(st[b][0].first + 1, st[b][0].second + 1, st[b][1].first + 1, st[b][1].second + 1))
                    return;
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            st[pop_cnt(arr[i], arr[j])].pb({i, j});
    for (int b = 0; b < 31; b++)
        for (int i = 0; i < (int)st[b].size(); i++)
            for (int j = 0; j < i; j++)
                if (display(st[b][j].first + 1, st[b][j].second + 1, st[b][i].first + 1, st[b][i].second + 1))
                    return;
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}