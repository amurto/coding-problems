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

const int N = 2e5 + 5;
// O(n)
vector<int> lp(N + 1), pr;
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
}

void solve()
{
    int n, k;
    cin >> n >> k;
    stack<int> st;
    vector<int> T(n + 1);
    st.push(1);
    for (int i = 0; pr[i] <= n; i++)
        if (pr[i] * 2 > n)
            st.push(pr[i]);
    int sz = (int)st.size(), v = 1;
    if (n - sz > max(k, n - k))
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    if (k > n - k)
    {
        k = n - k;
        v = 0;
    }
    while (sz > k)
    {
        st.pop();
        sz--;
    }
    while (!st.empty())
    {
        T[st.top()] = 1;
        st.pop();
    }
    for (int i = 1; i <= n; i++)
        if (T[i] == v)
            cout << i << " ";
    cout << "\n";
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
        solve();
    return 0;
}