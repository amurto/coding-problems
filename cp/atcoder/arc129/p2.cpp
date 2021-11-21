#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<pii> arr(n);
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    set<int> st1, st2;
    for (int i = 0; i < n; i++)
    {
        st1.insert(arr[i].first);
        st2.insert(arr[i].second);
        int l = *st2.begin(), r = *st1.rbegin();
        if (l < r)
            res[i] = (r - l + 1) / 2;
    }
    for (int x : res)
        cout << x << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}