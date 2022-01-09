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
    ll k;
    cin >> k;
    vector<int> arr;
    string res = "";
    while (k > 0)
    {
        arr.pb(k % 2);
        k /= 2;
    }
    reverse(arr.begin(), arr.end());
    for (int v : arr)
        if (v == 0)
            res.pb('0');
        else
            res.pb('2');
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