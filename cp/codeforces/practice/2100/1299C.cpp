// https://codeforces.com/contest/1299/problem/C
// Water Balance

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class node
{
public:
    ll sum = 0, len = 0;
    node() {}
    node(ll sum, ll len) : sum(sum), len(len) {}
};

double avg(ll sum, ll len)
{
    return (1.0 * sum) / (1.0 * len);
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n + 1), pre(n + 1), nxt(n + 1);
    vector<node> con(n + 1);
    vector<double> res(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }
    stack<int> st;
    st.push(0);
    con[0] = node(0, 1);
    for (int i = 1; i <= n; i++)
    {
        double cur = 1.0 * arr[i];
        while (avg(con[st.top()].sum + pre[i] - pre[st.top()], con[st.top()].len + i - st.top()) < avg(con[st.top()].sum, con[st.top()].len))
            st.pop();
        int last = st.top() + 1;
        con[i] = node(pre[i] - pre[st.top()], i - st.top());
        nxt[last] = i;
        st.push(i);
    }
    for (int i = 1; i <= n;)
    {
        double ans = avg(con[nxt[i]].sum, con[nxt[i]].len);
        for (int j = i; j <= nxt[i]; j++)
            res[j] = ans;
        i = nxt[i] + 1;
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    solve();
    return 0;
}