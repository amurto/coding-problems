// Minimum number to make median X
// https://practice.geeksforgeeks.org/problems/minimum-number-to-make-median-x/0

import java.util.*;
import java.io.*;

public class p8 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            int[] a = new int[n];
            for (int i=0; i<n; i++)
                a[i]= Integer.parseInt(line[i]);
        }
    }
}