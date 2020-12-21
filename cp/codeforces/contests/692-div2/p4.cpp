#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    string str;
    cin >> str;
    int n = str.length();
    ll x, y, res = 0;
    cin >> x >> y;
    vector<int> cnt(2);
    for (char ch : str)
    {
        if (ch == '0' || ch == '?')
        {
            res += (cnt[1] * y);
            cnt[0]++;
        }
        else
        {
            res += (cnt[0] * x);
            cnt[1]++;
        }
    }

    ll az = res, cur = res;
    for (int i=0; i<str.length(); i++) {
        if (str[i] == '?') {
            
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}