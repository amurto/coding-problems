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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    set<int> st1, st2;
    for (int i = 0; i < k - 1; i++)
        st1.insert(arr[i]);
    for (int i = k - 1; i < n; i++)
    {
        st2.insert(arr[i]);
        while ((int)st1.size() < k && !st2.empty())
        {
            st1.insert(*st2.rbegin());
            st2.erase(--st2.end());
        }
        while ((int)st1.size() == k && !st2.empty() && *st1.begin() < *st2.rbegin())
        {
            st1.erase(st1.begin());
            st1.insert(*st2.rbegin());
            st2.erase(--st2.end());
        }
        cout << *st1.begin() << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}