#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector<int> mir(9, -1);

void add(int &curH, int &curM, int h, int m)
{
    curM++;
    if (curM == m)
    {
        curM = 0;
        curH++;
        if (curH == h)
            curH = 0;
    }
}

bool valid(int curH, int curM, int h, int m)
{
    vector<int> st;
    st.pb(curH / 10);
    st.pb(curH % 10);
    st.pb(curM / 10);
    st.pb(curM % 10);
    reverse(st.begin(), st.end());
    for (int i = 0; i < st.size(); i++)
    {
        st[i] = mir[st[i]];
        if (st[i] == -1)
            return false;
    }
    int nH = st[0] * 10 + st[1], nM = st[2] * 10 + st[3];
    return nH < h && nM < m;
}

void solve()
{
    int h, m, curH = 0, curM = 0;
    string tm;
    cin >> h >> m >> tm;
    curH = (tm[0] - '0') * 10 + (tm[1] - '0');
    curM = (tm[3] - '0') * 10 + (tm[4] - '0');
    while (!valid(curH, curM, h, m))
        add(curH, curM, h, m);
    cout << curH / 10 << curH % 10 << ":" << curM / 10 << curM % 10 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mir[0] = 0;
    mir[1] = 1;
    mir[2] = 5;
    mir[5] = 2;
    mir[8] = 8;
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}