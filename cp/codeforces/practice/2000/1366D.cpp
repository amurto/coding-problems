// https://codeforces.com/contest/1366/problem/D
// Two Divisors

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e7 + 5;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    int n;
    cin >> n;
    vector<int> arr(n), d1(n, -1), d2(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int d = lp[arr[i]];
        while (arr[i] % d == 0)
            arr[i] /= d;
        if (arr[i] > 1)
        {
            d1[i] = d;
            d2[i] = arr[i];
        }
    }
    for (int d : d1)
        cout << d << " ";
    cout << "\n";
    for (int d : d2)
        cout << d << " ";
    cout << "\n";
    return 0;
}