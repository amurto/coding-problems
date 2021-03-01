#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int req(vector<int> &nums, int sum, int target)
{
    int cnt = 0;
    if (target < sum)
        for (int i = nums.size() - 1; target < sum && i >= 0; cnt++, i--)
            sum -= (nums[i] - 1);
    else if (target > sum)
        for (int i = 0; target > sum && i < nums.size(); cnt++, i++)
            sum += (6 - nums[i]);
    return cnt;
}

int op(vector<int> &nums1, vector<int> &nums2, int target, int sum1, int sum2)
{
    int cnt1 = req(nums1, sum1, target), cnt2 = req(nums2, sum2, target);
    return cnt1 + cnt2;
}

int minOperations(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size(), sum1 = 0, sum2 = 0, res = 1e6;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    for (int num : nums1)
        sum1 += num;
    for (int num : nums2)
        sum2 += num;
    if (n > m * 6 || m > n * 6)
        return -1;
    int l = max(n, m), r = min(n, m) * 6;
    while (r - l > 2)
    {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int f1 = op(nums1, nums2, m1, sum1, sum2), f2 = op(nums1, nums2, m2, sum1, sum2);
        res = min({res, f1, f2});
        if (f1 < f2)
            r = m2;
        else
            l = m1;
    }
    for (int i = l; i <= r; i++)
        res = min(res, op(nums1, nums2, i, sum1, sum2));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; i++)
        cin >> nums1[i];
    for (int i = 0; i < m; i++)
        cin >> nums2[i];
    cout << minOperations(nums1, nums2) << "\n";
    return 0;
}