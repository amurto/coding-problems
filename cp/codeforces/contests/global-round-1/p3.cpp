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
vector<int> vec, st = {1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};
bool is_pw2(int x)
{
    while (x > 1)
    {
        if (x & 1)
            return false;
        x >>= 1;
    }
    return true;
}

void solve()
{
    for (int i = 2; i <= 25; i++)
        vec.pb((1 << i) - 1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        if (is_pw2(x + 1))
        {
            int id = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
            cout << st[id] << "\n";
        }
        else
        {
            int a = x, b = 0;
            for (int bit = 0; x > 0; x >>= 1, bit++)
                if (!(x & 1))
                    b |= (1 << bit);
            cout << (a ^ b) << "\n";
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