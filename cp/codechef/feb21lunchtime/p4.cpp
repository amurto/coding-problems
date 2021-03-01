#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void op(set<int> &unq, vector<int> &arr, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] >= st.top())
        {
            unq.insert(arr[i] - st.top());
            st.pop();
        }
        st.push(arr[i]);
    }
}

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    set<int> unq;
    op(unq, arr, n);
    reverse(arr.begin(), arr.end());
    op(unq, arr, n);
    return (int)unq.size();
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