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
    int n;
    cin >> n;
    vector<int> arr(n), seq;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
        if (arr[i] != 0 && arr[i] != 1)
            seq.pb(arr[i]);
    }
    if (n == 1)
        return 1;
    int sz = seq.size();
    if (seq.empty())
        return 1;
    if (seq[0] == -1)
    {
        if (mp[-1] != sz)
            return 0;
        if (mp[-1] == 1)
            return 1;
        return (mp[1] > 0) ? 1 : 0;
    }
    return (sz == 1) ? 1 : 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}