// https://codeforces.com/contest/479/problem/C
// Exams

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());
    int cur = p[0].second;
    for (int i = 1; i < n; i++)
        if (p[i].second >= cur)
            cur = p[i].second;
        else
            cur = p[i].first;
    cout << cur << "\n";
    return 0;
}