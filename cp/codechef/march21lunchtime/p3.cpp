#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector<int> pos(vector<int> &arr, int n)
{
    vector<int> res(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
            st.pop();
        if (!st.empty() && arr[st.top()] == arr[i])
        {
            res[i] = res[st.top()] + 1;
            st.pop();
        }
        st.push(i);
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> r1 = pos(arr, n);
    reverse(arr.begin(), arr.end());
    vector<int> r2 = pos(arr, n);
    reverse(r2.begin(), r2.end());
    for (int i = 0; i < n; i++)
        cout << r1[i] + r2[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}