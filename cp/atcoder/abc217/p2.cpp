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
    string s[4] = {"ABC", "ARC", "AGC", "AHC"};
    vector<string> arr(3);
    vector<bool> vis(4);
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < 4; j++)
            if (arr[i] == s[j])
                vis[j] = true;
    }
    for (int i = 0; i < 4; i++)
        if (!vis[i])
            return s[i];
    return s[4];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}