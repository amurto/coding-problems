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
    queue<int> seq;
    multiset<int> ms;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            seq.push(x);
        }
        else if (t == 2)
        {
            if (ms.empty())
            {
                cout << seq.front() << "\n";
                seq.pop();
            }
            else
            {
                cout << *ms.begin() << "\n";
                ms.erase(ms.begin());
            }
        }
        else
        {
            while (!seq.empty())
            {
                ms.insert(seq.front());
                seq.pop();
            }
        }
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