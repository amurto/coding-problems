#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e6 + 1, MX = 2e6 + 5;

int solve()
{
    int n, k, x, res = 1;
    cin >> n >> k;
    ll sum = 0;
    vector<int> freq(MX), pre(MX);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sum += x;
        freq[x]++;
    }
    for (int i = 1; i < MX; i++)
        pre[i] = freq[i] + pre[i - 1];
    for (int i = 2; i < N; i++)
    {
        if (pre[i - 1] > 0)
            continue;
        ll req = sum;
        for (int j = 2 * i; j < MX; j += i)
            req -= (j - i) * (pre[j - 1] - pre[j - i - 1]);
        if (req <= k)
            res = i;
    }
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