// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k/0
// Longest Sub-Array with Sum K

import java.util.*;
import java.io.*;

public class p18 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] params = br.readLine().split(" ");
            int n = Integer.parseInt(params[0]);
            int k = Integer.parseInt(params[1]);
            String[] line = br.readLine().split(" ");

            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = Integer.parseInt(line[i]);

            HashMap<Integer, Integer> h = new HashMap<Integer, Integer>();
            int max = 0, sum = 0;
            h.put(0, -1);
            for (int i = 0; i < n; i++) {
                sum += a[i];
                if (h.get(sum) == null)
                    h.put(sum, i);
                if (h.containsKey(sum - k)) {
                    max = Math.max(max, i - h.get(sum - k));
                }
            }
            System.out.println(max);
        }
    }
}