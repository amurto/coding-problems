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

const int N = 1e6 + 5;
bool P[N + 1];
// O(n)
vector<int> lp(N + 1), pr;
void linear_sieve()
{
    for (int i = 0; i <= N; i++)
        P[i] = false;
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
    for (int x : pr)
        P[x] = true;
}

ll bf(vector<int> &arr, int n, int e)
{
    ll res = 0;
    for (int i = 0; i < e; i++)
    {
        vector<int> seq;
        for (int j = i; j < n; j += e)
            seq.pb(arr[j]);
        int sz = (int)seq.size();
        for (int j = 0; j < sz; j++)
            if (seq[j] > 1 && !P[seq[j]])
                seq[j] = 0;
        for (int j = 0; j < sz; j++)
        {
            int prod = seq[j];
            for (int k = j + 1; k < sz; k++)
            {
                if (prod == 0)
                    break;
                if (seq[k] == 0)
                    break;
                if (prod > 1 && seq[k] != 1)
                    break;
                prod *= seq[k];
                if (P[prod])
                    res++;
            }
        }
    }
    return res;
}

ll solve()
{
    int n, e;
    ll res = 0;
    cin >> n >> e;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < e; i++)
    {
        vector<int> seq;
        for (int j = i; j < n; j += e)
            seq.pb(arr[j]);
        int sz = (int)seq.size();
        int p1 = sz, p2 = sz;
        for (int j = sz - 1; j >= 0; j--)
        {
            if (seq[j] == 1)
            {
                if (p2 > p1)
                    res += 1ll * (p2 - p1);
            }
            else if (!P[seq[j]])
            {
                p1 = j;
                p2 = j;
            }
            else
            {
                res += 1ll * (p1 - j - 1);
                p2 = p1;
                p1 = j;
            }
        }
    }
    // cout << bf(arr, n, e) << "\n";
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}