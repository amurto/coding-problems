Number of sequences with natural numbers such that their cumulative sum is n is 2^(t-1)

```cpp
vector<int> dp(n + 1);
dp[0] = 1;
for (int i = 1; i <= n; i++)
{
    dp[i] += pre;
    pre += dp[i];
}
```
