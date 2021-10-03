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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (is_sorted(arr.begin(), arr.end()))
        return true;
    vector<int> seq, ids;
    for (int i = 0; i < n; i++)
    {
        if (i + x < n || i - x >= 0)
        {
            seq.pb(arr[i]);
            ids.pb(i);
        }
    }
    sort(seq.begin(), seq.end());
    for (int i = 0; i < (int)ids.size(); i++)
        arr[ids[i]] = seq[i];
    return is_sorted(arr.begin(), arr.end());
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