#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums, int x)
{
    int n = nums.size(), sum=0, L=INT_MAX, R=INT_MAX;
    for (int i=0; i<n; i++) {
        sum+=nums[i];
        if (sum == x)   
            L = i+1;
    }
    sum=0;
    for (int j=n-1; j>=0; j--) {
        sum+=nums[j];
        if (sum==x)
            R = n-j;
    }
    if (sum < x)
        return -1;
    int req = sum - x, sf=0, res=min(L, R);
    unordered_map<int, int> pre;
    unordered_set<int> st;
    st.insert(0);
    pre[0] = -1;
    for (int i=0; i<n; i++) {
        sf+=nums[i];
        if (sf - req >= 0 && st.count(sf-req)) 
            res = min(res, n - (i-pre[sf-req]));
        st.insert(sf);
        pre[sf] = i;
    } 
    if (res == INT_MAX)
        return -1;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << minOperations(nums, x) << "\n";
    return 0;
}