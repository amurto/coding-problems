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
    int n, msb = -1;
    cin >> n;
    for (int bit = 20; msb == -1 && bit >= 0; bit--)
        if (((n - 1) >> bit) & 1)
            msb = bit;
    vector<int> arr, arr1, arr2;
    for (int i = 0; i < n; i++)
    {
        if ((i >> msb) & 1)
            arr1.pb(i);
        else
            arr2.pb(i);
    }
    for (int i = 0; i < (int)arr1.size(); i++)
        if (arr1[i] == (1 << msb))
            swap(arr1[0], arr1[i]);
    reverse(arr1.begin(), arr1.end());
    for (int i = 0; i < (int)arr2.size(); i++)
        if (arr2[i] == 0)
            swap(arr2[0], arr2[i]);
    for (int x : arr1)
        arr.pb(x);
    for (int x : arr2)
        arr.pb(x);
    for (int x : arr)
        cout << x << " ";
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