// https://codeforces.com/contest/84/problem/C
// Biathlon

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class point
{
public:
    int x, y, idx;
    point(){};
    point(int x, int y, int idx) : x(x), y(y), idx(idx){};
    bool operator<(const point &j) const
    {
        return x < j.x;
    }
};

int dis(int x1, int y1, int x2, int y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, y;
    cin >> n;
    vector<point> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
        p[i].idx = i;
    }
    sort(p.begin(), p.end());
    vector<int> marks(n, -1);
    unordered_set<int> hit;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        int l = 0, r = n - 1;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            if (p[mid].x > x)
                r = mid;
            else
                l = mid;
        }
        if (dis(x, y, p[l].x, 0) <= (p[l].y * p[l].y) && marks[p[l].idx] == -1)
        {
            marks[p[l].idx] = i;
            hit.insert(p[l].idx);
        }
        if (dis(x, y, p[r].x, 0) <= (p[r].y * p[r].y) && marks[p[r].idx] == -1)
        {

            marks[p[r].idx] = i;
            hit.insert(p[r].idx);
        }
    }
    cout << hit.size() << "\n";
    for (int mark : marks)
        cout << mark << " ";
    return 0;
}