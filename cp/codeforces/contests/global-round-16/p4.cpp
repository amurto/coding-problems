#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

pii get_cell(int px, int n, int m)
{
    int r = px / m, c = px % m;
    return {r, c};
}

bool is_last_col(int px, int n, int m)
{
    return ((px % m) == (m - 1));
}

bool is_first_col(int px, int n, int m)
{
    return (px % m) == 0;
}

int solve()
{
    int n, m, res = 0;
    cin >> n >> m;
    int k = n * m;
    vector<int> arr(k), ids(k), pos(k), seat(k);
    iota(ids.begin(), ids.end(), 0);
    for (int i = 0; i < k; i++)
        cin >> arr[i];
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return arr[i1] < arr[i2]; });
    for (int i = 0; i < k;)
    {
        int r = i;
        vector<int> idx;
        while (r < k && arr[ids[i]] == arr[ids[r]])
        {
            idx.pb(ids[r]);
            r++;
        }
        sort(idx.begin(), idx.end());
        queue<int> q;
        int cur = i;
        for (int j = cur; j < r; j++)
        {
            if (is_last_col(j, n, m) || j + 1 == r)
            {
                q.push(j);
                for (int t = j - 1; t >= i && !is_last_col(t, n, m); t--)
                    q.push(t);
            }
        }
        for (int id : idx)
        {
            pos[id] = q.front();
            q.pop();
        }
        i = r;
    }
    for (int i = 0; i < k; i++)
    {
        pii px = get_cell(pos[i], n, m);
        for (int j = px.first * m; j < pos[i]; j++)
            res += seat[j];
        seat[pos[i]] = 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}