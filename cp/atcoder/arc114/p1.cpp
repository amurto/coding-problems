#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 50;
// O(n)
vector<int> lp(N + 1), pr;
vector<ll> st;

void recur(int cur, ll x)
{
    if (cur == pr.size())
    {
        if (x > 1)
            st.pb(x);
        return;
    }
    recur(cur + 1, x);
    recur(cur + 1, x * 1ll * pr[cur]);
}

void linear_sieve()
{
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
    recur(0, 1);
    sort(st.begin(), st.end());
}

bool is_div(vector<ll> &arr, ll x)
{
    for (ll a : arr)
        if (__gcd(a, x) == 1)
            return false;
    return true;
}

ll solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (ll d : st)
        if (is_div(arr, d))
            return d;
    return st.back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    cout << solve() << "\n";
    return 0;
}