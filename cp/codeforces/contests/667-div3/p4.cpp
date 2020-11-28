#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void createNumber(ll num, vector<ll> &a)
{
    while (num > 0)
    {
        a.pb(num % 10);
        num /= 10;
    }
}

ll computeSum(vector<ll> a)
{
    ll sum = 0;
    for (ll v : a)
        sum += v;
    return sum;
}

ll computeMinV(vector<ll> a, int n)
{
    int i = n - 1;
    while (a[i] == 9)
        i--;
    return a[i] + 1 + 9 * (n - i - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        ll num, s, minv, ans = 0;
        cin >> num >> s;
        vector<ll> a;
        createNumber(num, a);
        int n = a.size();
        ll cur_sum = computeSum(a);
        minv = computeMinV(a, n);
        if (cur_sum <= s)
            ans = 0;
        else if (s < minv)
        {
            if (n == 18)
                ans = 1000000000000000000 - num;
            else
                ans = pow((ll)10, (ll)n) - num;
        }
        else
        {
            ll i = 0;
            while (i < n - 1 && cur_sum > s)
            {
                cur_sum -= a[i];
                a[i] = 0;
                a[i + 1]++;
                cur_sum++;
                i++;
            }
            for (ll j = 0; j < n; j++)
                ans += pow((ll)10, j) * a[j];
            ans -= num;
        }
        cout << ans << endl;
    }
    return 0;
}