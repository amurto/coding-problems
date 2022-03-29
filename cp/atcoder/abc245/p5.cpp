#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<pii> chocs(n), boxes(m);
    vector<int> C(m), D(m);
    for (int i = 0; i < n; i++)
        cin >> chocs[i].first;
    for (int i = 0; i < n; i++)
        cin >> chocs[i].second;
    for (int i = 0; i < m; i++)
        cin >> boxes[i].first;
    for (int i = 0; i < m; i++)
        cin >> boxes[i].second;
    sort(chocs.begin(), chocs.end());
    sort(boxes.begin(), boxes.end());
    multiset<int> ms;
    for (int i = n - 1, j = m - 1; i >= 0; i--)
    {
        while (j >= 0 && boxes[j].first >= chocs[i].first)
        {
            ms.insert(boxes[j].second);
            j--;
        }
        auto it = ms.lower_bound(chocs[i].second);
        if (it == ms.end())
            return false;
        else
            ms.erase(it);
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}