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
    int n, q;
    cin >> n >> q;
    vector<int> rows(n + 1), cols(n + 1);
    set<int> emp_rows, emp_cols;
    for (int i = 1; i <= n + 1; i++)
    {
        emp_rows.insert(i);
        emp_cols.insert(i);
    }
    for (int i = 0; i < q; i++)
    {
        int t, x, y;
        cin >> t;
        if (t == 1)
        {
            cin >> x >> y;
            rows[x]++;
            cols[y]++;
            if (rows[x] == 1)
                emp_rows.erase(x);
            if (cols[y] == 1)
                emp_cols.erase(y);
        }
        else if (t == 2)
        {
            cin >> x >> y;
            rows[x]--;
            cols[y]--;
            if (rows[x] == 0)
                emp_rows.insert(x);
            if (cols[y] == 0)
                emp_cols.insert(y);
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            bool ans = false, all_rows = false, all_cols = false;
            if (*emp_rows.lower_bound(x1) > x2)
                all_rows = true;
            if (*emp_cols.lower_bound(y1) > y2)
                all_cols = true;
            if (all_rows || all_cols)
                ans = true;
            ans ? cout << "Yes\n" : cout << "No\n";
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