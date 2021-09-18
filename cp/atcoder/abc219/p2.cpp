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
    vector<string> arr(3);
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    string t, res = "";
    cin >> t;
    for (char ch : t)
        res += arr[ch - '1'];
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