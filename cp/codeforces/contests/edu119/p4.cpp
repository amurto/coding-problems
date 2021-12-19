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

const ll inf = 1e18;
int solve()
{
    int n;
    ll res = inf;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int one = 0; one <= 1; one++)
    {
        for (int two = 0; two <= 4; two++)
        {
            set<int> st;
            for (int i = 0; i <= one; i++)
                for (int j = 0; j <= two; j++)
                    st.insert(i + 2 * j);
            bool pos = true;
            ll three = 0;
            for (int i = 0; pos && i < n; i++)
            {
                ll x = arr[i], cnt = inf;
                for (int y : st)
                    if (x >= y && (x - y) % 3 == 0)
                        cnt = min(cnt, (x - y) / 3);
                if (cnt >= inf)
                    pos = false;
                else
                    three = max(three, cnt);
            }
            if (pos)
                res = min(res, three + one + two);
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