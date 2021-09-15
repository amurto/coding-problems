// https://codeforces.com/contest/1153/problem/E
// Serval and Snake

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

int query(int x1, int y1, int x2, int y2)
{
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    int ans;
    cin >> ans;
    if (ans == -1)
        exit(0);
    return ans & 1;
}

void solve()
{
    int n;
    cin >> n;
    array<int, 2> rows{-1, -1}, cols{-1, -1};
    for (int i = 1; i < n; i++)
    {
        int ans = query(1, 1, i, n);
        if (ans)
        {
            if (rows[0] == -1)
                rows[0] = i;
            rows[1] = i + 1;
        }
    }
    for (int j = 1; j < n; j++)
    {
        int ans = query(1, 1, n, j);
        if (ans)
        {
            if (cols[0] == -1)
                cols[0] = j;
            cols[1] = j + 1;
        }
    }
    if (rows[0] == -1)
    {
        int low = 1, high = n;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (query(1, 1, mid, cols[1] - 1))
                high = mid;
            else
                low = mid + 1;
        }
        rows[0] = rows[1] = low;
    }
    else if (cols[0] == -1)
    {
        int low = 1, high = n;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (query(1, 1, rows[1] - 1, mid))
                high = mid;
            else
                low = mid + 1;
        }
        cols[0] = cols[1] = low;
    }
    if (!query(rows[0], cols[0], rows[0], cols[0]))
        swap(cols[0], cols[1]);
    cout << "! " << rows[0] << " " << cols[0] << " " << rows[1] << " " << cols[1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}