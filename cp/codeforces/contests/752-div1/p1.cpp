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
    vector<int> arr(n + 1), rem(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        int j = i + 1;
        while (j > 0 && arr[i] % j == 0)
            j--;
        if (j == 0)
            return false;
        rem[i] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        while (arr[i] % j == 0)
            j++;
        if (j > i + 1)
            return false;
    }
    int del = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i + 1 - del <= rem[i])
            del++;
        else
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}