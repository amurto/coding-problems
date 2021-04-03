#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

void solve()
{
    int n, a;
    cin >> n;
    vector<vector<int>> vis(n, vector<int>(n));
    vector<deque<pii>> dq(2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dq[(i + j) % 2].pb({i, j});
    int m = n * n;
    while (m-- > 0)
    {
        cin >> a;
        a--;
        if (a == 0)
        {
            if (dq[1].empty())
            {
                pii tp = dq[0].front();
                dq[0].pop_front();
                cout << 3 << " " << tp.first + 1 << " " << tp.second + 1 << "\n";
                fflush(stdout);
            }
            else
            {
                pii tp = dq[1].front();
                dq[1].pop_front();
                cout << 2 << " " << tp.first + 1 << " " << tp.second + 1 << "\n";
                fflush(stdout);
            }
        }
        else if (a == 1)
        {
            if (dq[0].empty())
            {
                pii tp = dq[1].front();
                dq[1].pop_front();
                cout << 3 << " " << tp.first + 1 << " " << tp.second + 1 << "\n";
                fflush(stdout);
            }
            else
            {
                pii tp = dq[0].front();
                dq[0].pop_front();
                cout << 1 << " " << tp.first + 1 << " " << tp.second + 1 << "\n";
                fflush(stdout);
            }
        }
        else
        {
            if (dq[0].size() > dq[1].size())
            {
                pii tp = dq[0].front();
                dq[0].pop_front();
                cout << 1 << " " << tp.first + 1 << " " << tp.second + 1 << "\n";
                fflush(stdout);
            }
            else
            {
                pii tp = dq[1].front();
                dq[1].pop_front();
                cout << 2 << " " << tp.first + 1 << " " << tp.second + 1 << "\n";
                fflush(stdout);
            }
        }
        fflush(stdout);
    }
}

int main()
{
    solve();
    return 0;
}