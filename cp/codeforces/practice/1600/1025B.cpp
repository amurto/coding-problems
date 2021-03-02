// https://codeforces.com/contest/1025/problem/B
// Weakened Common Divisor

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool check(vector<int> &a, vector<int> &b, int n, int p)
{
    for (int i = 0; i < n; i++)
        if (a[i] % p > 0 && b[i] % p > 0)
            return false;
    return true;
}

int fac(vector<int> &a, vector<int> &b, int n)
{
    for (int j = 0; j < 2; j++)
    {
        int e = a[0];
        for (int i = 2; i * i <= e; i++)
        {
            if (e % i == 0)
            {
                if (check(a, b, n, i))
                    return i;
                while (e % i == 0)
                    e /= i;
            }
        }
        if (e > 1 && check(a, b, n, e))
            return e;
        swap(a[0], b[0]);
    }
    return -1;
}

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    return fac(a, b, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}