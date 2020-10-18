// https://practice.geeksforgeeks.org/problems/ugly-numbers/0
// Ugly Numbers

import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class p1 {
    final static int MAX = 10000;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        BigInteger[] a = new BigInteger[MAX];
        BigInteger two = BigInteger.TWO, three = BigInteger.valueOf(3), five= BigInteger.valueOf(5);
        a[0]=BigInteger.ONE;
        int pos=1, i=0,j=0,k=0;
        while (pos < MAX) {
            BigInteger[] b = new BigInteger[] {two, three, five};
            Arrays.sort(b);
            BigInteger v = b[0];
            a[pos] = v;
            pos++;
            if (v.compareTo(two)==0) {
                i++;
                two=a[i].multiply(BigInteger.valueOf(2));
            }
            if (v.compareTo(three)==0) {
                j++;
                three=a[j].multiply(BigInteger.valueOf(3));
            }
            if (v.compareTo(five)==0) {
                k++;
                five=a[k].multiply(BigInteger.valueOf(5));
            }
        }
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            System.out.println(a[n-1]);
        }
    }
}