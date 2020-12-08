// https://codeforces.com/contest/230/problem/B
// T-primes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e6 + 1;
bool P[N];
vector<int> p;

// O(nlognlogn)
void sieve()
{
    memset(P, true, sizeof(P));
    P[0] = P[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (!P[i])
            continue;
        for (int j = 2; i * j < N; j++)
            P[i * j] = false;
    }
    for (int i = 2; i < N; i++)
        if (P[i])
            p.pb(i);
}

bool bs(ll val)
{
    int L = 0, R = p.size() - 1;
    while (L <= R)
    {
        int mid = L + (R - L) / 2;
        ll sq = p[mid] * 1ll * p[mid];
        if (sq == val)
            return true;
        else if (sq < val)
            L = mid + 1;
        else
            R = mid - 1;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int n;
    cin >> n;
    vector<ll> arr(n);
    vector<bool> res(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        res[i] = bs(arr[i]);
    for (bool r : res)
        r ? cout << "YES\n" : cout << "NO\n";
    return 0;
}