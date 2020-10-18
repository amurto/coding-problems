// Product array puzzle
// https://practice.geeksforgeeks.org/problems/product-array-puzzle/0
// Without Division Operator

import java.util.*;
import java.io.*;

public class p8 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line  = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i=0;i<n;i++) 
                a[i] = Integer.parseInt(line[i]);
            int left = 1, right = 1;
            int[][] mul = new int[n][2];
            for (int i=0;i<n;i++) {
                left = left*a[i];
                right = right*a[n-i-1];
                mul[i][0] = left;
                mul[n-i-1][1] = right;
            }
            for (int i=0; i<n;i++) {
                if (i==0)
                    System.out.print(mul[i+1][1] + " ");
                else if (i==n-1)
                    System.out.print(mul[i-1][0] + " ");
                else
                    System.out.print((mul[i-1][0]*mul[i+1][1]) + " ");
            }
            System.out.println();
        }
    }
}