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

int solve()
{
    int n, l, res = 0;
    cin >> n >> l;
    vector<int> arr(n), bits(l);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < l; j++)
            if ((arr[i] >> j) & 1)
                bits[j]++;
    }
    for (int j = 0; j < l; j++)
        if (bits[j] > n / 2)
            res |= (1 << j);
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