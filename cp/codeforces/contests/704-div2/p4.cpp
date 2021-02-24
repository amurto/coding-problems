#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void display(vector<int> &x, vector<int> &y)
{
    cout << "Yes\n";
    for (int e : x)
        cout << e;
    cout << "\n";
    for (int e : y)
        cout << e;
    cout << "\n";
}

void solve()
{
    int a, b, k;
    cin >> a >> b >> k;

    int n = a + b;
    vector<int> x, y;
    for (int i = 0; i < b; i++)
    {
        x.pb(1);
        y.pb(1);
    }
    for (int i = 0; i < a; i++)
    {
        x.pb(0);
        y.pb(0);
    }
    if (a == 0 || b == 1)
    {
        if (k > 0)
        {
            cout << "No\n";
            return;
        }
        display(x, y);
        return;
    }
    if (k > a + b - 2)
    {
        cout << "No\n";
        return;
    }
    int cur = b - 1;
    while (cur < n - 1 && k > 0)
    {
        swap(y[cur], y[cur + 1]);
        cur++;
        k--;
    }
    if (k > 0)
    {
        int last = b - 2;
        while (k > 0)
        {
            swap(y[last], y[last + 1]);
            last--;
            k--;
        }
    }
    display(x, y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}