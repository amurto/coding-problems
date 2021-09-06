// Finding LCM of all elements of array using prime factorisation
// LCM(arr[0], arr[1], arr[2],......, arr[n-1])
// LCM can be very big

// Example
// arr = {2, 3, 4};
// 2 -> 2
// 3 -> 3
// 4 -> 2 x 2

// LCM = 12
// 12 -> 2 x 2 x 3 -> 2^2 x 3^1

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

// Binary Exponentiation O(logn)
// n^m mod p
// p is large prime number
int power(int n, int m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

void factor(unordered_map<int, int> &PRIME, int num)
{
    unordered_map<int, int> F;
    for (int i = 2; i * i <= num; i++)
    {
        while (num % i == 0)
        {
            num /= i;
            F[i]++;
        }
    }
    if (num > 1)
        F[num]++;
    for (auto f : F)
        PRIME[f.first] = max(PRIME[f.first], f.second);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // lcm = product of (prime factor ^ maximum times it divides any arr[i])
    unordered_map<int, int> PRIME;
    for (int num : arr)
        factor(PRIME, num);

    int lcm = 1;
    for (auto p : PRIME)
        lcm = mul(lcm, power(p.first, p.second, MOD));
    return 0;
}