// https://codeforces.com/contest/371/problem/C
// Hamburgers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    vector<int> req(3), n(3), price(3);
    ll rub;
    cin >> n[0] >> n[1] >> n[2] >> price[0] >> price[1] >> price[2] >> rub;
    for (char ch : str)
    {
        if (ch == 'B')
            req[0]++;
        else if (ch == 'S')
            req[1]++;
        else
            req[2]++;
    }
    for (int i = 0; i < 3; i++)
        if (req[i] == 0)
            n[i] = 0;
    ll res = 0, low = 1, high = 1e12 + max({n[0], n[1], n[2]});
    
    // Binary Search
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        vector<ll> R = {mid * req[0], mid * req[1], mid * req[2]};
        for (int i = 0; i < 3; i++)
        {
            R[i] -= n[i];
            R[i] = max(R[i], 0LL);
        }
        if (R[0] * price[0] + R[1] * price[1] + R[2] * price[2] <= rub)
        {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << res << "\n";
    return 0;
}