// https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space/0
// Rotate a 2D array without using extra space

import java.util.*;
import java.io.*;

public class p3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[][] a = new int[n][n];
            String[] arr = br.readLine().split(" ");
            for (int i = 0; i < n*n; i++) 
                a[i/3][i%3] = Integer.parseInt(arr[i]);
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++) {
                    System.out.print(a[i][j] + " ");
                }
                System.out.println();
            }
        }
    }
}