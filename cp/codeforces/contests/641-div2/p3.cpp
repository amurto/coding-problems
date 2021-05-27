#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;

// O(n)
vector<int> lp(N + 1), pr;
void linear_sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

ll solve()
{
    int n;
    ll res = 1;
    cin >> n;
    vector<int> arr(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        while (arr[i] > 1)
        {
            int d = lp[arr[i]], id = d;
            while (arr[i] % d == 0)
            {
                mp[id]++;
                arr[i] /= d;
                id *= d;
            }
        }
    }
    for (auto x : mp)
        if (x.second >= n - 1)
            res *= 1ll * lp[x.first];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    cout << solve() << "\n";
    return 0;
}