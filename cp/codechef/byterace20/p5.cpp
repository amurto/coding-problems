#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m;
        cin >> n >> m;
        vector<ll> A(n), B(m), L(n), R(n), idx(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int i = 0; i < m; i++)
        {
            cin >> B[i];
            B[i]--;
            idx[B[i]] = 1;
        }
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && A[i] <= A[st.top()])
                st.pop();
            L[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && A[i] <= A[st.top()])
                st.pop();
            R[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            int l = lower_bound(B.begin(), B.end(), i) - lower_bound(B.begin(), B.end(), L[i]);
            int r = upper_bound(B.begin(), B.end(), R[i]) - upper_bound(B.begin(), B.end(), i);
            sum += A[i] * l * r;
            if (idx[i])
                sum += A[i] * (l + r + 1);
        }
        cout << sum << "\n";
    }
    return 0;
}