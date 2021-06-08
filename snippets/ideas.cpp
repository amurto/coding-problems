// Div2 C
// Given array of n integers and q queries (n <= 1e5, a_i <= 1e3, q <= 1e5)
// Query with two integers l and r (1 <= l < r <= n)
// Find number with maximum multiples in range [1, l-1] and [r+1, n]
// Basically delete a[l..r] and find most frequent divisor from the array

// Solution : Since a_i <= 1000, maximum primes are 168
// Make prefix array of pre[N][168] and count number of multiples for each prime in every prefix
// For every query, for each prime, frequency is pre[n][prime] - pre[r][prime] + pre[l-1][prime] 
// Print any prime with maximum frequency