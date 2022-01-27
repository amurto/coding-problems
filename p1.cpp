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

void solve(int n, int k)
{
    ll sum = 0;
    int mx = n - 1;
    vector<int> mark(n / 2), arr(n / 2);
    iota(mark.begin(), mark.end(), 0);
    for (int i = 0; i < n / 2; i++)
        arr[i] = mx ^ i;
    if (n == 4 && k == 3)
    {
        cout << "-1\n";
        return;
    }
    if (k == n - 1)
    {
        swap(mark[0], arr[1]);
        swap(arr[2], arr[3]);
    }
    else if (k >= n / 2)
        swap(mark[0], arr[mx ^ k]);
    else
        swap(arr[0], arr[k]);
    for (int i = 0; i < n / 2; i++)
        cout << mark[i] << " " << arr[i] << "\n";
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
        int n, k;
        cin >> n >> k;
        solve(n, k);
    }
    return 0;
}