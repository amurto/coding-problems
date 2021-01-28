// https://codeforces.com/contest/1047/problem/C
// Enlarge GCD
// Longest subsequence with GCD > 1

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e7;
int P[N];

// O(nlognlogn)
void sieve()
{
    memset(P, 0, sizeof(P));
    P[0] = P[1] = 1;
    for (int i = 2; i * i < N; i++)
    {
        if (P[i])
            continue;
        for (int j = 2; i * j < N; j++)
            P[i * j] = i;
    }
    P[2] = 2;
    for (int i = 3; i < N; i += 2)
        if (!P[i])
            P[i] = i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int g = 0;
    for (int v : arr)
        g = __gcd(g, v);
    unordered_map<int, int> mp;
    for (int v : arr)
    {
        v /= g;
        while (v > 1)
        {
            int cur = P[v];
            mp[cur]++;
            while (v % cur == 0)
                v /= cur;
        }
    }
    int res = 0;
    for (auto m : mp)
        res = max(res, m.second);
    res ? cout << n - res : cout << -1;
    return 0;
}
