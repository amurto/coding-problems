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

const int K = 26;
string solve()
{
    string str;
    cin >> str;
    int n = str.length();
    string res = str;
    vector<int> cnt(K);
    vector<queue<int>> ids(K);
    for (int i = 0; i < n; i++)
    {
        cnt[str[i] - 'a']++;
        ids[str[i] - 'a'].push(i);
    }
    auto cmp = [&](int &i1, int &i2)
    {
        return cnt[i1] < cnt[i2];
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for (int i=0; i<K; i++)
        if (cnt[i]>0)
            pq.push(i);
    while ((int)pq.size() > 1)
    {
        // d(res);
        int h = pq.top();
        pq.pop();
        int l = pq.top();
        pq.pop();
                // d(char('a'+h),char('a'+l));
        while (!ids[l].empty())
        {
            swap(res[ids[l].front()], res[ids[h].front()]);
            ids[l].pop();
            ids[h].pop();
        }
        cnt[h]-=cnt[l];
        cnt[l]=0;
        if (cnt[h] > 0)
            pq.push(h);
    }
    if (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        char ch = char('a' + cur);
        for (int i = 0; !ids[cur].empty() && i < n; i++)
        {
            if (str[i] != ch && res[i] != ch)
            {
                swap(res[i], res[ids[cur].front()]);
                ids[cur].pop();
            }
        }
        if (!ids[cur].empty())
            return "IMPOSSIBLE";
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
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}