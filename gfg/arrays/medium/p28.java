// https://practice.geeksforgeeks.org/problems/magnet-array-problem/0
// Magnet Array Problem

import java.util.*;
import java.io.*;

public class p28 {
    public static double binarySearch(double low, double high, double[] a, int n) {
        double v = 0.0000000000001;
        double m = (low + high) / 2.0;
        double force = 0.0;
        for (int i = 0; i < n; i++) 
            force = force + 1.0 / (m - a[i]);  
        if (Math.abs(force) < v) 
            return m;
        if (force > 0)
            return binarySearch(m, high, a, n);
        else
            return binarySearch(low, m, a, n);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            double[] a = new double[n];
            for (int i = 0; i < n; i++)
                a[i] = Double.parseDouble(line[i]);
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < n - 1; i++) 
                sb.append(String.format("%.2f", binarySearch(a[i], a[i + 1], a, n)) + " ");
            System.out.println(sb);
        }
    }
}