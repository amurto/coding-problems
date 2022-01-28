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

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n), L(n + 1, n), R(n + 1), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        L[arr[i]] = min(L[arr[i]], i);
        R[arr[i]] = i;
    }
    vector<pii> seq;
    for (int i = 1; i <= n; i++)
        if (L[i] < R[i])
            seq.pb({L[i], R[i]});
    int sz = (int)seq.size();
    sort(seq.begin(), seq.end());
    int cur = 0;
    for (int i = 0; cur < sz;)
    {
        int itr = i, l = seq[cur].first, r = seq[cur].second;
        while (itr < sz && seq[itr].first <= r)
            itr++;
        int nxt = cur;
        for (int j = i; j < itr; j++)
            if (seq[j].second > seq[nxt].second)
                nxt = j;
        if (cur == nxt)
            cur = itr;
        else
            cur = nxt;
        if (cur < sz)
            r = min(r, seq[cur].first);
        for (int j = l + 1; j < r; j++)
            c[j] = 1;
        i = itr;
    }
    for (int i = 0; i < n; i++)
        res += c[i];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}