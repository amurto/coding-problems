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
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2)
        return true;
    int n = s1.length();
    vector<int> ids;
    for (int i = 0; i < n; i++)
        if (s1[i] != s2[i])
            ids.pb(i);
    if (ids.size() == 1)
        return false;
    if (ids[0] + 1 == ids[1])
        swap(s1[ids[0]], s1[ids[1]]);
    return s1 == s2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}