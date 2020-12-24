// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1080
// 10139 - Factovisors

// check if m divides n!
// factorise m
// check if all prime factors exist in range [1,n]
// for a factor, divide n by all its powers until required power is reached

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve(int n, int m)
{
    string d = " divides ", dnd = " does not divide ";
    int x = m;
    unordered_map<int, int> F;
    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            x /= i;
            F[i]++;
        }
    }
    if (x > 1)
        F[x]++;
    for (auto f : F)
    {
        int cur = f.first, req = f.second;
        while (req > 0)
        {
            if (cur > n)
                return dnd;
            req -= n / cur;
            cur *= f.first;
        }
    }
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    while (cin >> n)
    {
        cin >> m;
        if (m == 0)
        {
            cout << m << " does not divide " << n << "!" << endl;
            continue;
        }
        cout << m << solve(n, m) << n << "!\n";
    }
    return 0;
}