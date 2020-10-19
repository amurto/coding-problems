// Radix Sort

#include <bits/stdc++.h>
using namespace std;

void countsort(vector<int> &nums, int place)
{
    int n = nums.size(), val, par;
    vector<int> ans(n);

    // Map of 19 since range is -9 to 9
    // -9, -8, -7, -6, ..... , 6, 7, 8, 9
    vector<int> MAP(19);
    for (int i = 0; i < n; i++)
    {
        // Store the sign
        // Get the digit in place and multiply it with the sign
        // add 9 to map it to the correct index
        // -9 + 9 -> 0
        // 9 + 9 -> 18
        par = nums[i] < 0 ? -1 : 1;
        val = (((nums[i] * par) / place) % 10) * par + 9;
        MAP[val]++;
    }

    // Store prefix sum of how many times each digit occurs from -9...MAP[0] to 9...MAP[18]
    for (int i = 1; i < 19; i++)
        MAP[i] += MAP[i - 1];

    // Create the new array from the frequency map
    for (int i = n - 1; i >= 0; i--)
    {
        par = nums[i] < 0 ? -1 : 1;
        val = (((nums[i] * par) / place) % 10) * par + 9;
        ans[MAP[val] - 1] = nums[i];
        MAP[val]--;
    }
    for (int i = 0; i < nums.size(); i++)
        nums[i] = ans[i];
}

void radixsort(vector<int> &nums)
{
    int MAX = INT_MIN;
    for (int val : nums)
        MAX = max(MAX, abs(val));
    
    // Place iterates from 1 to the largest place possible
    // if MAX is a 4 digit number
    // ddd_
    // dd_d
    // d_dd
    // _ddd
    // Array will be sorted for each place
    // Complexity is O(k*n) where k is the number of digits in the absolutely largest element
    for (int place = 1; MAX / place > 0; place *= 10)
        countsort(nums, place);
}

vector<int> sortArray(vector<int> &nums)
{
    radixsort(nums);
    return nums;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> ans = sortArray(nums);
    for (int v : ans)
        cout << v << " ";
    return 0;
}