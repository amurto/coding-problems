    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    #define pb push_back

    const int b = 32;
    ll query(vector<ll> &cnt)
    {
        ll res = 0;
        for (int i = 0; i < b; i++)
            if (cnt[i] > 0)
                res |= (1ll << i);
        return res;
    }
    void solve()
    {
        int n, q, x, v;
        cin >> n >> q;
        vector<ll> arr(n), cnt(b);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            ll x = arr[i];
            for (int j = 0; x > 0; j++, x >>= 1)
                cnt[j] += (1 & x);
        }
        cout << query(cnt) << "\n";
        while (q-- > 0)
        {
            cin >> x >> v;
            x--;
            for (int j = 0; arr[x] > 0; j++, arr[x] >>= 1)
                cnt[j] -= (1 & arr[x]);
            arr[x] = v;
            for (int j = 0; v > 0; j++, v >>= 1)
                cnt[j] += (1 & v);
            cout << query(cnt) << "\n";
        }
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