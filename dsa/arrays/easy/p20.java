// Wave Array
// https://practice.geeksforgeeks.org/problems/wave-array/0

import java.util.*;
import java.io.*;

public class p20 {
    public static void swap(int arr[], int x, int y) {
        int tmp = arr[x];
        arr[x] = arr[y];
        arr[y] = tmp;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] a = new int[n];
            String[] arr = br.readLine().split(" ");
            for (int i = 0; i < n; i++)
                a[i] = Integer.parseInt(arr[i]);
            for (int i = 0; i < n - 1; i += 2) {
                swap(a, i, i + 1);
            }
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < n; i++) {
                sb.append(a[i] + " ");
            }
            System.out.println(sb);
        }
    }
}