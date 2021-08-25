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

void calc(vector<int> &vals, int a, int b)
{
    int n = a + b;
    int s1 = (n + 1) / 2, s2 = n / 2;
    for (int i = 0; i <= a; i++)
    {
        // b loses serve i times
        // a wins a-i serves
        // a loses s1-(a-i) serves
        if (i <= s2 && s1 - a + i >= 0)
            vals.pb(i + s1 - a + i);
    }
}
void solve()
{
    int a, b;
    cin >> a >> b;
    vector<int> vals;
    for (int i = 0; i < 2; i++)
    {
        calc(vals, a, b);
        swap(a, b);
    }
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    cout << vals.size() << "\n";
    for (int v : vals)
        cout << v << " ";
    cout << "\n";
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