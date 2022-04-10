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
    vector<string> s(n), t(n);
    map<string, int> cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> t[i];
        if (s[i] == t[i])
            cnt[s[i]]++;
        else
        {
            cnt[s[i]]++;
            cnt[t[i]]++;
        }
    }
    for (int i = 0; i < n; i++)
        if (cnt[s[i]] > 1 && cnt[t[i]] > 1)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}