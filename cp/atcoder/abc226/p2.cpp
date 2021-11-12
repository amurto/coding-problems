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

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int len, v;
        cin >> len;
        for (int j = 0; j < len; j++)
        {
            cin >> v;
            arr[i].pb(v);
        }
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n;)
    {
        int r = i;
        while (r < n && arr[i] == arr[r])
            r++;
        res++;
        i = r;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}