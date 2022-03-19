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
    int n;
    cin >> n;
    int big = 0;
    ll sum1 = 0, sum2 = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum1 += i;
        sum2 += arr[i];
        if (arr[i] > n - 1)
            big++;
    }
    if (sum1 == sum2)
        return false;
    if (big == 1)
        return true;
    ll diff = sum2 - sum1;
    return diff & 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Alice\n" : cout << "Bob\n";
    return 0;
}
