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

const int LGN = 18;

ll combine(ll x, ll y)
{
    // use your combiner here
    return max(x, y);
}

struct sparse_table
{
    vector<vector<ll>> sp;
    vector<int> hp;
    sparse_table(int n)
    {
        sp.resize(n, vector<ll>(LGN));
        hp.resize(n);
        // highest power of 2 less than i
        hp[0] = hp[1] = 0;
        for (int i = 2; i < n; i++)
            hp[i] = hp[i / 2] + 1;
    }
    sparse_table() = default;

    void build(vector<ll> &arr, int n)
    {
        // sparse table initialization with input array
        for (int i = 0; i < n; i++)
            sp[i][0] = arr[i];
        // works for min, max, gcd
        // updates not supported
        for (int k = 1; k < LGN; k++)
            for (int i = 0; i < n; i++)
                sp[i][k] = combine(sp[i][k - 1], sp[min(n - 1, i + (1 << (k - 1)))][k - 1]);
    }

    ll query(int l, int r)
    {
        int dis = r - l + 1;
        return combine(sp[l][hp[dis]], sp[r - (1 << hp[dis]) + 1][hp[dis]]);
    }
};

vector<int> next_greater(vector<ll> &arr, int n)
{
    // next >
    vector<int> seq(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
        if (!st.empty())
            seq[i] = st.top();
        st.push(i);
    }
    return seq;
}

ll calc(vector<ll> &arr, int n)
{
    ll res = 0;
    vector<ll> pre(n), suf(n);
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + arr[i];
    suf[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = suf[i + 1] + arr[i];
    sparse_table preT(n), sufT(n), rmq(n);
    preT.build(pre, n);
    sufT.build(suf, n);
    rmq.build(arr, n);
    vector<int> ng = next_greater(arr, n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
            st.pop();
        if (!st.empty())
        {
            int mx = st.top();
            // [mx,i]
            ll sum = pre[i] - pre[mx] - arr[i];
            if (ng[i] - i > 1)
                sum += max(0ll, preT.query(i + 1, ng[i] - 1) - pre[i]);
            if (mx > 0)
            {
                int low = 0, high = mx - 1, id = mx;
                while (low <= high)
                {
                    int mid = low + (high - low) / 2;
                    if (rmq.query(mid, mx - 1) <= arr[i])
                    {
                        id = min(id, mid);
                        high = mid - 1;
                    }
                    else
                        low = mid + 1;
                }
                if (id < mx)
                    sum += max(0ll, sufT.query(id, mx - 1) - suf[mx]);
            }
            res = max(res, sum);
        }
        st.push(i);
    }
    return res;
}

ll solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll res = 0;
    for (int j = 0; j < 2; j++)
    {
        res = max(res, calc(arr, n));
        reverse(arr.begin(), arr.end());
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