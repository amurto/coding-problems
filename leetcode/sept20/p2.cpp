#include <bits/stdc++.h>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
{
    if(nums.size()<2 || k==0)
        return false;
    set<long> s;
    int l=0;
    for(int i=0;i<nums.size();i++){
        if(abs(i-l) > k)
            s.erase(nums[l++]);
        auto it = s.lower_bound((long)nums[i] - (long)t);
        if(it != s.end() && *it <= ((long)nums[i] + (long)t))
            return true;
        s.insert(nums[i]);
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k, t, v;
        cin >> n >> k >> t;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            cin >> v;
            a.push_back(v);
        }
        cout<<containsNearbyAlmostDuplicate(a, k, t);
    }
    return 0;
}