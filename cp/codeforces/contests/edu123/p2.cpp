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

void display(vector<int> &arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    reverse(arr.begin(), arr.end());
    display(arr);
    for (int i = 2, j = n - 1; i <= n; i++, j--)
    {
        swap(arr[j - 1], arr[j]);
        display(arr);
    }
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