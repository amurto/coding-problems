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

const double eps = 1e-9; // set the error limit here
const int inf = 1e7;
bool nearlyEqual(double num1, double num2)
{
    return abs(num1 - num2) < eps;
}

int findSide(
    double ax, double ay,
    double bx, double by,
    double cx, double cy)
{
    if (nearlyEqual(bx - ax, 0))
    { // vertical line
        if (cx < bx)
        {
            return by > ay ? 1 : -1;
        }
        if (cx > bx)
        {
            return by > ay ? -1 : 1;
        }
        return 0;
    }
    if (nearlyEqual(by - ay, 0))
    { // horizontal line
        if (cy < by)
        {
            return bx > ax ? -1 : 1;
        }
        if (cy > by)
        {
            return bx > ax ? 1 : -1;
        }
        return 0;
    }
    double slope = (by - ay) / (bx - ax);
    double yIntercept = ay - ax * slope;
    double cSolution = (slope * cx) + yIntercept;
    if (slope != 0)
    {
        if (cy > cSolution)
        {
            return bx > ax ? 1 : -1;
        }
        if (cy < cSolution)
        {
            return bx > ax ? -1 : 1;
        }
        return 0;
    }
    return 0;
}

void dfs(vector<int> &ops, vector<int> &vis, int val, int cur, int mx, int t)
{
    if (cur >= mx)
    {
        vis[val] = min(vis[val], t);
        return;
    }
    dfs(ops, vis, val, cur + 1, mx, t);
    dfs(ops, vis, val ^ ops[cur], cur + 1, mx, t + 1);
}

int solve()
{
    int n, res = inf;
    string str;
    cin >> n >> str;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    vector<int> ops;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double ax = 1.0 * x[i], ay = 1.0 * y[i], bx = 1.0 * x[j], by = 1.0 * y[j];
            int origin_dir = findSide(ax, ay, bx, by, 0, 0);
            origin_dir++;
            vector<vector<int>> pts(3);
            pts[1].pb(i);
            pts[1].pb(j);
            for (int k = 0; k < n; k++)
            {
                if (k != i && k != j)
                {
                    int v = findSide(ax, ay, bx, by, 1.0 * x[k], 1.0 * y[k]);
                    v++;
                    pts[v].pb(k);
                }
            }
            if (origin_dir != 1)
            {
                int mask = 0;
                for (int pt : pts[1])
                    mask |= (1 << pt);
                for (int pt : pts[origin_dir])
                    mask |= (1 << pt);
                ops.pb(mask);
            }
        }
    }
    sort(ops.begin(), ops.end());
    ops.resize(unique(ops.begin(), ops.end()) - ops.begin());
    int sz = (int)ops.size();
    int h = sz / 2;
    vector<int> vis1(1 << n, inf), vis2(1 << n, inf);
    dfs(ops, vis1, 0, 0, h, 0);
    dfs(ops, vis2, 0, h, sz, 0);
    int mask = 0;
    for (int i = 0; i < n; i++)
        if (str[i] == 'R')
            mask |= (1 << i);
    for (int i = 0; i < (1 << n); i++)
        res = min(res, vis1[i] + vis2[mask ^ i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}