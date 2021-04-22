#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int query(int x, int y)
{
    cout << "? " << x << " " << y << "\n";
    fflush(stdout);
    int v;
    cin >> v;
    if (v == -2)
        exit(0);
    return v;
}

void solve()
{
    int a = 0, b = 0;
    int g = query(0, 0);
    for (int i = 29; i >= 0; i--)
    {
        int ta = a, tb = b;
        for (int j = i - 1; j >= 0; j--)
        {
            ta |= (1 << j);
            tb |= (1 << j);
        }
        int q = query(ta, tb);
        if (g == 1)
        {
            if (q == 1)
            {
                a |= (1 << i);
                g = query(a, b);
            }
            else
            {
                ta |= (1 << i);
                int c = query(ta, tb);
                if (c == -1)
                {
                    a |= (1 << i);
                    b |= (1 << i);
                }
                g = (q == -1) ? 1 : 0;
            }
        }
        else if (g == 0)
        {
            ta |= (1 << i);
            int c = query(ta, tb);
            if (c == -1)
            {
                a |= (1 << i);
                b |= (1 << i);
            }
            g = 0;
        }
        else
        {
            if (q == -1)
            {
                b |= (1 << i);
                g = query(a, b);
            }
            else
            {
                tb |= (1 << i);
                int c = query(ta, tb);
                if (c == 1)
                {
                    a |= (1 << i);
                    b |= (1 << i);
                }
                g = (q == 1) ? -1 : 0;
            }
        }
    }
    cout << "! " << a << " " << b << "\n";
    fflush(stdout);
}

int main()
{
    solve();
    return 0;
}