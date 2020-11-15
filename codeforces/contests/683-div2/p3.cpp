    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    #define pb push_back

    bool dfs(int cur, ll cost, ll w, vector<ll> &arr, stack<ll> &st)
    {
        if (cost >= (w + 1) / 2 && cost <= w)
            return true;
        if (cost > w || cur == arr.size())
            return false;
        st.push(cur);
        if (dfs(cur + 1, cost + arr[cur], w, arr, st))
            return true;
        st.pop();
        if (dfs(cur + 1, cost, w, arr, st))
            return true;

        return false;
    }

    void solve()
    {
        int n;
        ll w;
        cin >> n >> w;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<ll> res;
        stack<ll> st;
        bool ans = dfs(0, 0, w, arr, st);
        if (!ans)
        {
            cout << "-1\n";
            return;
        }
        while (!st.empty())
        {
            res.pb(st.top() + 1);
            st.pop();
        }
        reverse(res.begin(), res.end());
        cout << res.size() << "\n";
        for (int idx : res)
            cout << idx << " ";
        cout << "\n";
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin >> t;
        while (t-- > 0)
        {
            solve();
        }
        return 0;
    }