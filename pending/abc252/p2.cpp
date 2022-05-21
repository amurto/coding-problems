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

bool solve()
{
    int n, k, mx = 0;
    cin >> n >> k;
    vector<int> A(n), B(k);
    vector<bool> greatest(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        mx = max(mx, A[i]);
    }
    for (int i = 0; i < k; i++)
        cin >> B[i];
    for (int i = 0; i < n; i++)
        if (A[i] == mx)
            greatest[i] = true;
    for (int b : B)
        if (greatest[b - 1])
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}