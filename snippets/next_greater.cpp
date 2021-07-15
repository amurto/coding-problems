#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector<int> prev_greater(vector<int> &arr, int n)
{
    // prev >=
    vector<int> seq(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        if (!st.empty())
            seq[i] = st.top();
        st.push(i);
    }
    return seq;
}

vector<int> prev_smaller(vector<int> &arr, int n)
{
    // prev <=
    vector<int> seq(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        if (!st.empty())
            seq[i] = st.top();
        st.push(i);
    }
    return seq;
}

vector<int> next_greater(vector<int> &arr, int n)
{
    // next >=
    vector<int> seq(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        if (!st.empty())
            seq[i] = st.top();
        st.push(i);
    }
    return seq;
}

vector<int> next_smaller(vector<int> &arr, int n)
{
    // next <=
    vector<int> seq(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        if (!st.empty())
            seq[i] = st.top();
        st.push(i);
    }
    return seq;
}

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
    return 0;
}