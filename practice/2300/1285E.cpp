// https://codeforces.com/contest/1285/problem/E
// Delete a Segment

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

const int inf = 1e9 + 7;
struct interval
{
    int l, r, id;
    interval() {}
    interval(int idx, int left, int right)
    {
        id = idx;
        l = left;
        r = right;
    }
    bool operator<(const interval &other) const
    {
        if (l == other.l)
            return r < other.r;
        return l < other.l;
    }
};

int solve()
{
    int n, res = 0, sum = 0;
    cin >> n;
    vector<interval> arr;
    vector<int> vals(n);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        arr.pb(interval(i, l, r));
    }
    auto cmp = [](interval i1, interval i2)
    {
        return i1.r > i2.r;
    };
    priority_queue<interval, vector<interval>, decltype(cmp)> pq(cmp);
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n;)
    {
        int itr = i, last = arr[i].r;
        while (itr < n && arr[itr].l <= last)
        {
            last = max(last, arr[itr].r);
            itr++;
        }
        if (itr - i > 1)
        {
            array<int, 2> lmn{inf, inf}, rmx{-inf, -inf};
            vector<int> pts;
            for (int j = i; j < itr; j++)
            {
                pts.pb(arr[j].l);
                pts.pb(arr[j].r);
                lmn[1] = min(lmn[1], arr[j].l);
                if (lmn[0] > lmn[1])
                    swap(lmn[0], lmn[1]);
                rmx[1] = max(rmx[1], arr[j].r);
                if (rmx[0] < rmx[1])
                    swap(rmx[0], rmx[1]);
            }
            sort(pts.begin(), pts.end());
            pts.resize(unique(pts.begin(), pts.end()) - pts.begin());
            int ptr = i;
            for (int pt : pts)
            {
                while (ptr < itr && arr[ptr].l == pt)
                {
                    pq.push(arr[ptr]);
                    ptr++;
                }
                while (!pq.empty() && pq.top().r == pt)
                    pq.pop();
                if ((int)pq.size() == 1)
                {
                    interval cur = pq.top();
                    if (pt >= lmn[1] && pt < rmx[1])
                        vals[cur.id]++;
                }
            }
        }
        else
            vals[arr[i].id]--;
        i = itr;
        sum++;
    }
    for (int x : vals)
        res = max(res, sum + x);
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