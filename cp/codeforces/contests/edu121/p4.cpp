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

const int N = 2e5 + 5, inf = 1e9 + 7;
int req[N];
void init()
{
    int j = 0;
    for (int i = 1; j < N; i *= 2)
    {
        while (j < min(i + 1, N))
        {
            req[j] = i - j;
            j++;
        }
    }
}

int solve()
{
    int n, res = inf;
    cin >> n;
    vector<int> arr(n), pre(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pre[arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
        pre[i] += pre[i - 1];
    set<int> st;
    st.insert(0);
    for (int i = n; i > 0; i--)
    {
        int cur = req[pre[i - 1]], suf = pre[n] - pre[i - 1];
        st.insert(suf);
        for (int bit = 1; bit < (1<<30); bit *= 2)
        {
            auto it = st.upper_bound(bit);
            it--;
            int val = *it;
            res = min(res, cur + bit - val + req[suf - val]);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}