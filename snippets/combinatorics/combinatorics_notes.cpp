// Combinatorics Notes for reference

// nCr -> number of ways of choosing r objects from n objects
// nCr = nC(n-r)
// number of cyclic permutations with n objects = (n-1)!

/*
Stars and Bars Theorem
Number of ways to put n identical objects into k labeled boxes = (n+k-1)Cn

https://cp-algorithms.com/combinatorics/stars_and_bars.html

Proof: 
objects -> n stars 
boxes -> k-1 bars 
*||*|||***|
Its equivalent to number of permutations containing n stars and k-1 bars
(n+k-1)! / (n! * (k-1)!)
*/


/*
Number of ways to put n identical objects into k labeled boxes such that none of the boxes is empty = (n-1)C(k-1)

Proof:
First we fill k boxes with n objects each. Now, we have n-k objects and k boxes.
Using Stars and bars, number of ways
= ((n-k)+k-1)C(n-k)
= (n-1)C(n-k)   
= (n-1)C(k-1)  (nCr = nC(n-r))
*/


/*
Sum of nCr where r is varying
nCr + (n-1)Cr + (n-2)Cr + (n-3)Cr + .... + rCr = (n+1)C(r+1)

Proof : 

https://www.toppr.com/ask/en-es/question/prove-that-ncr-n-1cr-n-2cr-rcr/

Suppose n distinct balls are arranged in a line and you are asked to select r balls. You can select r balls in nCr ways.
Another way to look at it is -> In how many ways can you select r balls such that i_th ball is the rightmost selected ball? This is (i-1)C(r-1). Now you can find all combinations by trying all possibilities for rightmost ball. 
You’ll get 0C(r-1) + 1C(r-1) + … + nC(r-1).
Since both expressions calculate same thing you have
0C(r-1) + 1C(r-1) + … + nC(r-1)=(n+1)Cr
*/

/*

Problem : https://atcoder.jp/contests/abc226/tasks/abc226_f
Comment : https://codeforces.com/blog/entry/96714?#comment-857164

Number of ways to partition n numbers into fixed size subsets 

> sum of all sizes = n
> partitions should be distinct (Ex. [[1,2],[3,4]] = [[3,4],[1,2]])

This is equivalent to determining such sequence a1,a2,…,an such that:

Each element ai is an integer between 0 and m;
For each j=1,…,m, there are exactly kj elements such that ai=j.
So this means that element i belongs a cyclic permutation group ai, or does not belong to any cyclic permutation if ai=0.

How many such sequences are there? Consider a sequence B = ((N−∑kj copies of 0), (k1 copies of 1), (k2 copies of 2), …, (km copies of m)). This is an n-element sequence, and each permutation of B correspond to the aforementioned (ai) one-to-one. Therefore, the number can be found as:

N! / (∏ (1 to j) kj!)

However, in the first chapter we distinguished the group with the same length. So we have to divide by an additional duplicate-remover.

To do this, let's convert the sequence k1,…,km into the sequence of occurrences: F1 elements of k1,…,km are equal to K1, F2 elements are equal to K2, and so on. Using this notation, the last expression can be re-written as follows:

Ka -> size of group 
Fa -> number of groups with size Ka

N! / (∏Fa,Ka) ((Ka!)^Fa) * (Fa!)

*/