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

bool is_prime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

void solve()
{
    int n, sum = 0, id = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (!is_prime(sum))
    {
        cout << n << "\n";
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++)
        if (((sum - arr[i]) % 2) == 0)
            id = i + 1;
    cout << n - 1 << "\n";
    for (int i = 1; i <= n; i++)
        if (i != id)
            cout << i << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}