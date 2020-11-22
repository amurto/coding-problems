// https://codeforces.com/contest/546/problem/C
// Soldier and Cards

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, k1, k2, c;
    deque<int> p1, p2;  
    cin >> n >> k1;
    for (int i = 0; i < k1; i++)
    {
        cin >> c;
        p1.push_front(c);
    }
    cin >> k2;
    for (int i = 0; i < k2; i++)
    {
        cin >> c;
        p2.push_front(c);
    }
    int f = 0;
    while (!p1.empty() && !p2.empty())
    {
        int c1 = p1.back(), c2 = p2.back();
        p1.pop_back();
        p2.pop_back();
        if (c1 > c2)
        {
            p1.push_front(c2);
            p1.push_front(c1);
        }
        else
        {
            p2.push_front(c1);
            p2.push_front(c2);
        }
        f++;
        if (f >= n*n*n) {
            cout << "-1\n";
            return;
        }
    }
    cout << f << " " << (p1.empty() ? 2 : 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

/*
4
3 2 3 1
1 4
*/