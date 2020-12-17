#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll fm(ll v)
{
    ll cur = 1, res = 1;
    while (cur <= v)
    {
        cur <<= 1;
        if (cur <= 1e9 && abs(cur - v) < abs(res - v))
            res = cur;
    }
    if (cur <= 1e9 && abs(cur - v) < abs(res - v))
        res = cur;
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
    {
        int n;
        cin >> n;
        vector<ll> A(n), B(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int i = 0; i < n; i++)
            B[i] = fm(A[i]);
        for (int b : B)
            cout << b << " ";
        cout << "\n";
    }
    return 0;
}