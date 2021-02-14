#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool possible(vector<int> &nums, int target, int k)
{
    for (int i = 0; k >= 0 && i < nums.size(); i++)
        k -= (nums[i] - 1) / target;
    return k >= 0;
}

int minimumSize(vector<int> &nums, int maxOperations)
{
    int n = nums.size(), mx = nums[0];
    for (int num : nums)
        mx = max(mx, num);
    int l = 1, r = mx, res = mx;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (possible(nums, mid, maxOperations))
        {
            res = min(res, mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, maxOperations;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cin >> maxOperations;
    cout << minimumSize(nums, maxOperations) << "\n";
    return 0;
}