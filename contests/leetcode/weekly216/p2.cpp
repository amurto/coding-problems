#include <bits/stdc++.h>
using namespace std;

string getSmallestString(int n, int k)
{
    vector<int> nums(n, 1);
    k -= n;
    int cur = n - 1;
    while (k > 0)
    {
        int add = k;
        if (add > 25)
            add = 25;
        k -= add;
        nums[cur] += add;
        cur--;
    }
    string res = "";
    for (int num : nums)
        res.push_back(char(num - 1 + 'a'));
    return res;
}

int main()
{
    int n = 5, k = 73;
    cout << getSmallestString(n, k) << "\n";
    return 0;
}