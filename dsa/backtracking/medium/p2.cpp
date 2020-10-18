// https://leetcode.com/problems/permutations/
// Permutations

#include<bits/stdc++.h>
using namespace std;

void PP(vector<int> &nums, vector<vector<int>> &ans, int cur) {
    if (cur==nums.size()-1) 
        ans.push_back(nums);
    else {
        for (int i=cur; i<nums.size(); i++) {
            swap(nums[cur], nums[i]);
            PP(nums, ans, cur+1);
            swap(nums[i], nums[cur]);
        }
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    PP(nums, ans, 0);
    return ans;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permute(nums);
    return 0;
}