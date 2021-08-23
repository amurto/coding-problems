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

string solve()
{
    int k;
    string str;
    cin >> str >> k;
    vector<string> strs;
    sort(str.begin(), str.end());
    do
    {
        strs.pb(str);
    } while (next_permutation(str.begin(), str.end()));
    strs.resize(unique(strs.begin(), strs.end()) - strs.begin());
    return strs[k - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}