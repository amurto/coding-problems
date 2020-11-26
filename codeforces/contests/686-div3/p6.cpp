#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), pre(n), suf(n), Lmin(n), Rmin(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre[i] = max(pre[i - 1], arr[i]);
    suf[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = max(suf[i + 1], arr[i]);

    stack<int> st;

    // [Lmin[i] ... Rmin[i]] is range for which arr[i] is minimum
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] <= arr[st.top()])
            st.pop();
        if (st.empty())
            Lmin[i] = 0;
        else
            Lmin[i] = st.top() + 1;
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] <= arr[st.top()])
            st.pop();
        if (st.empty())
            Rmin[i] = n - 1;
        else
            Rmin[i] = st.top() - 1;
        st.push(i);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int L = -1, R = -1;
        // binary search for left and right boundaries

        int low = Lmin[i] - 1, high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (pre[mid] == arr[i])
            {
                L = mid;
                low = mid + 1;
            }
            else if (pre[mid] > arr[i])
                high = mid - 1;
            else
                low = mid + 1;
        }
        low = i + 1, high = Rmin[i] + 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (suf[mid] == arr[i])
            {
                R = mid;
                high = mid - 1;
            }
            else if (suf[mid] > arr[i])
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (L == -1 || R == -1)
            continue;
        cout << "YES\n";
        cout << L + 1 << " " << R - L - 1 << " " << n - R << "\n";
        return;
    }
    cout << "NO\n";
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