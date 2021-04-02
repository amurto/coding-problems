// https://codeforces.com/contest/56/problem/E
// Domino Principle

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> piii;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<piii> arr(n);
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second.first;
        arr[i].second.second = i;
    }
    sort(arr.begin(), arr.end());
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && (arr[i].first + arr[i].second.first - 1) >= arr[st.top()].first)
            st.pop();
        res[arr[i].second.second] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }
    for (int r : res)
        cout << r << " ";
    return 0;
}