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

void solve()
{
    int n, res1 = 0, res2 = 0;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    for (int i = 0; i < n; i++)
        res1 += A[i] == B[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && A[i] == B[j])
                res2++;
    cout << res1 << "\n";
    cout << res2 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}