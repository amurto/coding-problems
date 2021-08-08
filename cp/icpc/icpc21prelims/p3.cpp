#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int K = 30;

ll solve()
{
    int n, x, e = 0;
    cin >> n >> x;
    if ((n & 1) && x == 0)
        return -1;
    vector<int> seq, bits(K);
    if (n & 1)
        seq.pb(1);
    for (int i = 1; i < K; i += 2)
        if ((n >> i) & 1)
            bits[i]++;
    for (int i = 2; i < K; i += 2)
        if ((n >> i) & 1)
            bits[i - 1] += 2;
    for (int i = 0; i < K; i++)
        for (int j = 0; j < bits[i]; j++)
            seq.pb(1 << i);
    int sz = seq.size(), sum = 0;
    int res = sz;
    for (int i = 1; i <= sz; i++)
    {
        sum += seq[i - 1];
        if (sum <= x)
            res = min(res, 1 + sz - i);
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