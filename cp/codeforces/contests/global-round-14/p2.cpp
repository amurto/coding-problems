    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    #define pb push_back

    ll sq_root(ll x)
    {
        ll l = 0, r = 2e9 + 1;
        while (l != r)
        {
            ll mid = (l + r + 1) / 2;
            if (mid * mid > x)
                r = mid - 1;
            else
                l = mid;
        }
        if (l * l == x)
            return l;
        return 0;
    }

    bool solve()
    {
        ll n;
        cin >> n;
        for (int i = 0; i < 2; i++)
        {
            if (n & 1)
                return false;
            n /= 2;
            if (sq_root(n) > 0)
                return true;
        }
        return false;
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin >> t;
        while (t-- > 0)
            solve() ? cout << "YES\n" : cout << "NO\n";
        return 0;
    }