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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < k; i++)
    {
        vector<int> tmp;
        for (int j = i; j < n; j += k)
            tmp.pb(arr[j]);
        sort(tmp.begin(), tmp.end());
        for (int j = i, t = 0; j < n; j += k, t++)
            arr[j] = tmp[t];
    }
    return is_sorted(arr.begin(), arr.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}