// https://www.hackerrank.com/challenges/sherlock-and-probability/problem
// Sherlock and Probability

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        ll n, k;
        cin >> n >> k;
        vector<char> str(n + 1);
        str[0] = '0';
        for (int i = 1; i <= n; i++)
            cin >> str[i];
        vector<ll> one(n + 1);
        ll num = 0, deno = 0;
        for (ll i = 1; i <= n; i++)
        {
            one[i] += one[i - 1];
            if (str[i] == '1')
            {
                num++;
                if (i - k - 1 >= 0)
                    num += (one[i] - one[i - k - 1]) * 2;
                else
                    num += one[i] * 2;
                one[i]++;
            }
            deno += (i - 1) * 2 + 1;
        }
        ll g = __gcd(num, deno);
        num /= g;
        deno /= g;
        cout << num << "/" << deno << "\n";
    }
    return 0;
}