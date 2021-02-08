#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> st(2);
    int cur = 0;
    st[0].pb(0);
    st[1].pb(0);
    for (int i = 0; i < n; i++)
    {
        if (!st[cur].empty() && st[cur].back() == arr[i])
            cur ^= 1;
        st[cur].pb(arr[i]);
        cur ^= 1;
    }
    int res = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 1; j < st[i].size(); j++)
            if (st[i][j] != st[i][j - 1])
                res++;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}