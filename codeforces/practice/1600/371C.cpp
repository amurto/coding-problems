// https://codeforces.com/contest/371/problem/C
// Hamburgers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool gz(vector<int> &n, vector<int> &st)
{
    for (int v : st)
        if (n[v] > 0)
            return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    vector<int> r(3), n(3), p(3);
    ll rub;
    cin >> n[0] >> n[1] >> n[2] >> p[0] >> p[1] >> p[2] >> rub;
    for (char ch : str)
    {
        if (ch == 'B')
            r[0]++;
        else if (ch == 'S')
            r[1]++;
        else
            r[2]++;
    }
    set<pair<int, int>> cnt;
    for (int i = 0; i < 3; i++)
    {
        if (r[i] == 0)
            continue;
        cnt.insert({n[i] / r[i], i});
        n[i] %= r[i];
    }
    while (rub > 0 && cnt.begin()->first != cnt.rbegin()->first)
    {
        int h = cnt.begin()->first, pos = cnt.begin()->second;
        cnt.erase(cnt.begin());

        int req = r[pos], tmp = h;

        if (req <= n[pos])
        {
            n[pos] -= req;
            h++;
        }
        else
        {
            req -= n[pos];
            if (req * p[pos] <= rub)
            {
                h++;
                rub -= req * p[pos];
                n[pos] = 0;
            }
        }
        cnt.insert({h, pos});
        if (h == tmp)
            break;
    }
    ll res = cnt.begin()->first;
    vector<int> st;
    for (auto it = cnt.begin(); it != cnt.end(); it++)
        st.pb(it->second);

    while (rub > 0 && gz(n, st))
    {
        ll tmp = rub;
        bool nham = true;
        for (int i = 0; i < st.size(); i++)
        {
            if (n[st[i]] < r[st[i]])
            {
                int neg = (r[st[i]] - n[st[i]]) * p[st[i]];
                if (neg <= rub)
                    rub -= neg;
                else
                {
                    rub = tmp;
                    nham = false;
                    break;
                }
            }
            n[st[i]] -= min(n[st[i]], r[st[i]]);
        }
        if (!nham)
            break;
        res++;
    }
    res += rub / (p[0] * r[0] + p[1] * r[1] + p[2] * r[2]);
    cout << res << "\n";
    return 0;
}