// https://codeforces.com/contest/389/problem/C
// Fox and Box Accumulation

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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int v : arr)
    {
        if (pq.empty())
            pq.push(1);
        else
        {
            int tp = pq.top();
            if (tp <= v)
            {
                pq.pop();
                pq.push(tp + 1);
            }
            else
                pq.push(1);
        }
    }
    cout << pq.size() << "\n";
    return 0;
}