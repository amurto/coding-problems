// Print all Encodings
/*
    1 -> a
    2 -> b
    3 -> c
    ..
    25 -> y
    26 -> z
*/

#include <bits/stdc++.h>
using namespace std;

bool valid(int num1, int num2)
{
    if (num1 == 0 || num1 * 10 + num2 > 26)
        return false;
    return true;
}

void encodings(string soFar, vector<int> &nums, int cur)
{
    if (cur == nums.size())
        cout << soFar << "\n";
    else
    {
        if (nums[cur] > 0)
            encodings(soFar + (char)('a' + nums[cur] - 1), nums, cur + 1);
        if (cur + 1 < nums.size() && valid(nums[cur], nums[cur + 1]))
            encodings(soFar + (char)('a' + (nums[cur] * 10 + nums[cur + 1]) - 1), nums, cur + 2);
    }
}

int main()
{
    string str;
    cin >> str;
    vector<int> nums(str.length());
    for (int i = 0; i < str.length(); i++)
        nums[i] = str[i] - '0';
    encodings("", nums, 0);
    return 0;
}