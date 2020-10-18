// https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1
// Partition array to K subsets

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool dfs(vector<int> &nums, vector<bool> &vis, vector<int> &ss, int cur, int rs) {
    if (cur == nums.size()) {
        for (int i=0; i<ss.size(); i++) {
            if (ss[i] != rs) return false;
            if (!vis[i]) return false;
        }
        return true;
    }
    for (int i=0; i<ss.size(); i++) {
        if (ss[i] + nums[cur] <= rs) {
            bool isempty = !vis[i];
            if (isempty) vis[i] = true;
            ss[i] += nums[cur];
            if (dfs(nums, vis, ss, cur+1, rs)) return true;
            ss[i] -= nums[cur];
            if (isempty) {
                vis[i] = false;
                break;
            }
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k)
{
    int n = nums.size();
    if (k==1)
        return true;
    if (k>n)
        return false;
    int sum=0;
    for (int i=0; i<n; i++) 
        sum+=nums[i];
    if (sum%k > 0)
        return false;
    int reqSum = sum/k;

    // Very important operation
    // Sort the array in non-descending order so greater elements are placed first
    // Massively reduces the running time 
    sort(nums.begin(), nums.end(), greater<int>());

    vector<int> ss(k, 0);
    vector<bool> vis(k, false);
    return dfs(nums, vis, ss, 0, reqSum);
}

int main() {
    int t;
    cin>>t;
    while (t-->0) {
        int n, k;
        cin>>n>>k;
        vector<int> nums(n);
        for (int i=0; i<n; i++) 
            cin>>nums[i];
        cout<<canPartitionKSubsets(nums, k)<<"\n";
    }
    return 0;
}