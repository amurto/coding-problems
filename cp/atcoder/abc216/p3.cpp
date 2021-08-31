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
    ll n;
    cin >> n;
    string ans = "";
    while (n > 0)
    {
        if (n & 1)
        {
            ans.pb('A');
            n--;
        }
        else
        {
            ans.pb('B');
            n /= 2;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}