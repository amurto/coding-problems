#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e6 + 5;
// O(n)
vector<int> lp(N + 1), pr;
int cnt[N];
void linear_sieve()
{
    memset(cnt, 0, sizeof(cnt));
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

set<int> get_factors(int x)
{
    set<int> st;
    while (x > 1)
    {
        int d = lp[x];
        st.insert(d);
        while (x % d == 0)
            x /= d;
    }
    return st;
}

int solve()
{
    int n, v, g = 0, op = 0;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        arr.pb(v);
        g = __gcd(g, v);
    }
    for (int i = 0; i < n; i++)
        arr.pb(arr[i]);
    n *= 2;
    for (int i = 0; i < n; i++)
        arr[i] /= g;
    set<int> cur;
    for (int i = 0; i < n; i++)
    {
        set<int> st = get_factors(arr[i]);
        for (int x : st)
        {
            cnt[x]++;
            op = max(op, cnt[x]);
        }
        for (int x : cur)
            if (st.find(x) == st.end())
                cnt[x] = 0;
        cur = st;
    }
    for (int x : cur)
        cnt[x] = 0;
    return op;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}