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

void op(int x)
{
    cout << "! " << x << endl;
}

void solve()
{
    int n;
    cin >> n;
    auto query = [&](int l, int r)
    {
        cout << "? " << l << " " << r << endl;
        int ans;
        cin >> ans;
        if (ans == -1)
            exit(0);
        return ans;
    };
    if (query(1, n) != 1)
    {
        op(-1);
        return;
    }
    int low = 1, high = n;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int a = query(1, mid), b = query(mid + 1, n);
        if (a > b)
            high = mid;
        else
            low = mid + 1;
    }
    op(low);
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