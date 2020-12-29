#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

char hb(int val)
{
    int cnt = 0;
    while (val > 1)
    {
        cnt++;
        val >>= 1;
    }
    return cnt + 'a';
}
string solve()
{
    int n, k;
    cin >> n >> k;
    priority_queue<int> pq;
    for (int i = 26; i >= 0; i--)
    {
        if ((1 << i) & k)
        {
            pq.push(1 << i);
        }
    }
    if (pq.size() > n)
        return "-1";
    while (pq.size() < n)
    {
        int tp = pq.top();
        pq.pop();
        if (tp == 1)
            return "-1";
        pq.push(tp / 2);
        pq.push(tp / 2);
    }
    string str;
    while (!pq.empty())
    {
        str.pb(hb(pq.top()));
        pq.pop();
    }
    return str;
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