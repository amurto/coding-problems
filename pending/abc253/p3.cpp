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

void solve()
{
    int q;
    cin >> q;
    multiset<int> ms;
    for (int i = 0; i < q; i++)
    {
        int t, x, c;
        cin >> t;
        if (t == 1)
        {
            cin >> x;
            ms.insert(x);
        }
        else if (t == 2)
        {
            cin >> x >> c;
            while (c > 0 && ms.find(x) != ms.end())
            {
                ms.erase(ms.lower_bound(x));
                c--;
            }
        }
        else
            cout << *ms.rbegin() - *ms.begin() << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}