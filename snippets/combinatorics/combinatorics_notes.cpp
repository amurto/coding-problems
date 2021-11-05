// Combinatorics Notes for reference

// nCr -> number of ways of choosing r objects from n objects
// nCr = nC(n-r)

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