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

void display(int n)
{
    if (n == 1)
    {
        cout << 1 << " ";
        return;
    }
    display(n - 1);
    cout << n << " ";
    display(n - 1);
}

void solve()
{
    int n;
    cin >> n;
    display(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}