// https://codeforces.com/contest/1175/problem/E
// Minimal Segment Cover

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

const int LGN = 20;

int combine(int x, int y)
{
    // use your combiner here
    return min(x, y);
}

struct sparse_table
{
    vector<vector<int>> sp;
    sparse_table(int n)
    {
        sp.resize(n, vector<int>(LGN));
    }
    sparse_table() = default;

    void build(vector<int> &arr, int n)
    {
        // sparse table initialization with input array
        for (int i = 0; i < n; i++)
            sp[i][0] = arr[i];
        // works for min, max, gcd
        // updates not supported
        for (int k = 1; k < LGN; k++)
            for (int i = 0; i < n; i++)
                sp[i][k] = combine(sp[i][k - 1], sp[sp[i][k - 1]][k - 1]);
    }

    int k_ancestor(int u, int k)
    {
        int tmp = k;
        for (int i = LGN - 1; i >= 0; i--)
        {
            if ((1 << i) <= k)
            {
                u = sp[u][i];
                k -= (1 << i);
            }
        }
        return u;
    }
};

void solve()
{
    int n, m, mx = 0;
    cin >> n >> m;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        mx = max(mx, arr[i].second);
    }
    mx++;
    sort(arr.begin(), arr.end());
    auto cmp = [&](int &i1, int &i2)
    {
        return arr[i1].second > arr[i2].second;
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    multiset<int> ms;
    vector<int> last(mx);
    for (int i = 0, cur = 0; i < mx; i++)
    {
        while (cur < n && arr[cur].first == i)
        {
            pq.push(cur);
            ms.insert(i);
            cur++;
        }
        last[i] = i;
        if (!ms.empty())
            last[i] = *ms.begin();
        while (!pq.empty() && arr[pq.top()].second == i)
        {
            ms.erase(ms.lower_bound(arr[pq.top()].first));
            pq.pop();
        }
    }
    sparse_table st(mx);
    st.build(last, mx);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        int low = 1, high = n, res = n + 1;
        if (y < mx)
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                int ans = st.k_ancestor(y, mid);
                if (ans <= x)
                {
                    res = min(res, mid);
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
        res > n ? cout << "-1\n" : cout << res << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}