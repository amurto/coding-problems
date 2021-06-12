// https://codeforces.com/contest/1419/problem/E
// Decryption

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector<int> get_primes(int x)
{
    vector<int> primes;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            primes.pb(i);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        primes.pb(x);
    return primes;
}

vector<int> get_divs(int x)
{
    vector<int> divs;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            divs.pb(i);
            if (i != x / i)
                divs.pb(x / i);
        }
    }
    divs.pb(x);
    return divs;
}

void display(vector<int> &divs)
{
    for (int d : divs)
        cout << d << " ";
    cout << "\n";
}

void solve()
{
    int n;
    cin >> n;
    vector<int> primes = get_primes(n), divs = get_divs(n);
    int sz = primes.size();
    if (sz == 1)
    {
        display(divs);
        cout << "0\n";
        return;
    }
    map<int, int> lp;
    vector<stack<int>> st(sz);
    int last = primes[0] * primes.back();
    for (int i = 0; i < sz; i++)
    {
        for (int d : divs)
        {
            if (d != last && primes[i] != d && lp[d] == 0 && d % primes[i] == 0)
            {
                lp[d] = primes[i];
                st[i].push(d);
            }
        }
    }
    if (sz == 2 && divs.size() == 3)
    {
        display(divs);
        cout << "1\n";
        return;
    }
    vector<int> res;
    primes.pb(primes[0]);
    for (int i = 0; i < sz; i++)
    {
        res.pb(primes[i]);
        int c = primes[i] * primes[i + 1];
        vector<int> ed;
        while (!st[i].empty())
        {
            if (st[i].top() % c == 0)
                ed.pb(st[i].top());
            else
                res.pb(st[i].top());
            st[i].pop();
        }
        for (int e : ed)
            res.pb(e);
    }
    res.pb(last);
    display(res);
    cout << "0\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}