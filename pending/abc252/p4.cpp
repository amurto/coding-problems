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

ll nc2(int n)
{
    return (n * 1ll * (n - 1)) / 2;
}

ll solve()
{
    int n;
    ll res = 0, prev_nc2 = 0;
    cin >> n;
    vector<int> arr(n), st;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n;)
    {
        int r = i;
        while (r < n && arr[i] == arr[r])
            r++;
        st.pb(r - i);
        i = r;
    }
    sort(st.begin(), st.end());
    int cnt = 0;
    for (int j = 0; j < (int)st.size(); j++)
    {
        res += (nc2(cnt) - prev_nc2) * st[j];
        prev_nc2 += nc2(st[j]);
        cnt += st[j];
    }
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