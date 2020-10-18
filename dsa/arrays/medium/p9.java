// https://practice.geeksforgeeks.org/problems/sum-of-bit-differences/0
// Sum of bit differences

import java.util.*;
import java.io.*;

public class p9 {
    public static int count1s(int v) {
        int c=0;
        while (v>0) {
            c+=v%2;
            v/=2;
        }
        return c;
    }

    // Naive Approach O(n^2)
    public static int Naive(int[] a, int n) {
        int sum=0;
        for (int i=0;i<n;i++) 
            for (int j=i+1; j<n;j++) 
                sum+=count1s(a[i]^a[j]);
        return sum*2;
    }

    // Optimized Approach O(n)
    public static int Optimized(int[] a, int n) {
        int sum=0;
        for (int i=0;i<32;i++) {
            int c=0;
            for (int j=0; j<n;j++) 
                if ((a[j] & (1<<i)) == 0)
                    c++;
            sum+=c*(n-c);
        }
        return sum*2;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] a = new int[n];
            String[] line = br.readLine().split(" ");
            for (int i=0; i<n; i++) 
                a[i] = Integer.parseInt(line[i]);

            System.out.println(Naive(a, n));
            System.out.println(Optimized(a, n));
        }
    }
}