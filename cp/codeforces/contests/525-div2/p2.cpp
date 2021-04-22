#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > 0)
            pq.push(arr[i]);
    }
    int sub = 0;
    while (k > 0)
    {
        if (pq.empty())
            cout << "0\n";
        else
        {
            int e = pq.top() - sub;
            cout << e << "\n";
            sub += e;
            pq.pop();
            while (!pq.empty() && pq.top() <= sub)
                pq.pop();
        }
        k--;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}