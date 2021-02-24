#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int ninf = -1e8;

int solve()
{
    int n, m, res = ninf;
    string str1, str2;
    cin >> n >> m >> str1 >> str2;
    vector<deque<int>> q1(26), q2(26);
    for (int i = 0; i < n; i++)
    {
        q1[str1[i] - 'a'].push_back(i + 1);
        q2[str1[i] - 'a'].push_back(i + 1);
    }
    vector<int> mn(m), mx(m);

    mn[0] = q1[str2[0] - 'a'].front();
    q1[str2[0] - 'a'].pop_front();
    for (int i = 1; i < m; i++)
    {
        while (q1[str2[i] - 'a'].front() < mn[i - 1])
            q1[str2[i] - 'a'].pop_front();
        mn[i] = q1[str2[i] - 'a'].front();
        q1[str2[i] - 'a'].pop_front();
    }

    mx[m - 1] = q2[str2[m - 1] - 'a'].back();
    q2[str2[m - 1] - 'a'].pop_back();
    for (int i = m - 2; i >= 0; i--)
    {
        while (q2[str2[i] - 'a'].back() > mx[i + 1])
            q2[str2[i] - 'a'].pop_back();
        mx[i] = q2[str2[i] - 'a'].back();
        q2[str2[i] - 'a'].pop_back();
    }
    for (int i = 0; i < m - 1; i++)
        res = max(res, mx[i + 1] - mn[i]);
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