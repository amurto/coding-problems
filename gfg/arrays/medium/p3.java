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
            for (int i = 0; i < n * n; i++)
                a[i / n][i % n] = Integer.parseInt(arr[i]);

            for (int i = 0; i < (n + 1) / 2; i++) {
                for (int j = 0; j < n / 2; j++) {
                    int temp = a[i][j];
                    a[i][j] = a[n - 1 - j][i];
                    a[n - 1 - j][i] = a[n - 1 - i][n - 1 - j];
                    a[n - 1 - i][n - 1 - j] = a[j][n - 1 - i];
                    a[j][n - 1 - i] = temp;
                    // Rotation
                    // i j
                    // j n-1-i
                    // n-1-i n-1-j
                    // n-1-j i
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print(a[i][j] + " ");
                }
            }
            System.out.println();
        }
    }
}