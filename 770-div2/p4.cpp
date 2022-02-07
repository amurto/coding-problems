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

int query(int i, int j, int k)
{
    cout << "? " << i << " " << j << " " << k << endl;
    int ans = -1;
    cin >> ans;
    if (ans == -1)
        exit(0);
    return ans;
}

pii calc(int i1, int i2, int i3, int i4)
{
    array<int, 4> ids{i1, i2, i3, i4};
    vector<tuple<int, int, int, int>> vals;
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            for (int k = j + 1; k < 4; k++)
                vals.pb(make_tuple(ids[i], ids[j], ids[k], query(ids[i], ids[j], ids[k])));
    sort(vals.begin(), vals.end(), [](tuple<int, int, int, int> &t1, tuple<int, int, int, int> &t2)
         { return get<3>(t1) > get<3>(t2); });
    vector<int> mn_mx;
    for (int id : ids)
    {
        int cnt = 0;
        for (int i = 0; i < 2; i++)
        {
            if (get<0>(vals[i]) == id)
                cnt++;
            if (get<1>(vals[i]) == id)
                cnt++;
            if (get<2>(vals[i]) == id)
                cnt++;
        }
        if (cnt >= 2)
            mn_mx.pb(id);
    }
    return {mn_mx[0], mn_mx[1]};
}

void solve()
{
    int n;
    cin >> n;
    pii ans = {1, 2};
    for (int i = 4; i <= n; i += 2)
        ans = calc(ans.first, ans.second, i - 1, i);
    if (n & 1)
    {
        int j = 1;
        while (j == ans.first || j == ans.second)
            j++;
        ans = calc(ans.first, ans.second, j, n);
    }
    int ans1 = ans.first, ans2 = ans.second;
    cout << "! " << ans1 << " " << ans2 << endl;
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