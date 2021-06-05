#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

class node
{
public:
    int id;
    ll x, y, sum = 0;
    node() {}
    node(int id, ll x, ll y) : id(id), x(x), y(y)
    {
        sum = x + y;
    }
};

ll solve()
{
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> y[i];
    vector<vector<node>> seq(2);
    for (int i = 0; i < n; i++)
        seq[0].pb(node(i, x[i], y[i]));
    for (int i = 0; i < n; i++)
        seq[1].pb(node(i, x[i], y[i]));

    sort(seq[0].begin(), seq[0].end(), [&](node &p1, node &p2)
         {
             if (p1.sum == p2.sum)
                 return p1.x > p2.x;
             return p1.sum > p2.sum;
         });
    sort(seq[1].begin(), seq[1].end(), [&](node &p1, node &p2)
         {
             if (p1.sum == p2.sum)
                 return p1.y > p2.y;
             return p1.sum > p2.sum;
         });
    vector<ll> itr(2), score(2);
    vector<bool> vis(n);
    for (int i = 0, p = 0; i < n; i++, p ^= 1)
    {
        while (itr[p] < n && vis[seq[p][itr[p]].id])
            itr[p]++;
        vis[seq[p][itr[p]].id] = true;
        if (p == 0)
            score[p] += seq[p][itr[p]].x;
        else
            score[p] += seq[p][itr[p]].y;
    }
    return score[0] - score[1];
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