#ifdef amurto
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
    int n;
    cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    int p = arr[0].first, i = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (i < n)
    {
        while (i < n && arr[i].first == p)
        {
            pq.push(arr[i].second);
            i++;
        }
        if (!pq.empty())
        {
            if (pq.top() < p)
                return false;
            pq.pop();
        }
        int nxt = p + 1;
        if (i < n)
            nxt = arr[i].first;
        if (!pq.empty())
            nxt = p + 1;
        p = nxt;
    }
    while (!pq.empty())
    {
        if (pq.top() < p)
            return false;
        pq.pop();
        p++;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}