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
    int n, a, b;
    cin >> n >> a >> b;
    char cur = '.';
    for (int r = 0; r < n; r++)
    {
        char col = cur;
        for (int i = 0; i < a; i++)
        {
            cur = col;
            for (int c = 0; c < n; c++)
            {
                for (int j = 0; j < b; j++)
                    cout << cur;
                if (cur == '.')
                    cur = '#';
                else
                    cur = '.';
            }
            cout << "\n";
        }
        if (col == '.')
            cur = '#';
        else
            cur = '.';
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