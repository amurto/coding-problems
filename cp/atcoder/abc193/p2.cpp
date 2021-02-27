#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, inf = 1e9 + 5;
    cin >> n;
    vector<int> A(n), P(n), X(n);
    for (int i = 0; i < n; i++)
        cin >> A[i] >> P[i] >> X[i];
    int res = inf;
    for (int i = 0; i < n; i++)
    {
        X[i] -= A[i];
        if (X[i] > 0)
            res = min(res, P[i]);
    }
    return res >= inf ? -1 : res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}