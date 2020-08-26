// https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1
// Smallest range in K lists

import java.util.*;
import java.io.*;

public class p22 {
    public static int l = 1, r = -1;

    public static void compute(int[][] arr, int[] check) {
        int min = Integer.MAX_VALUE, max = -1;
        for (int i = 0; i < check.length; i++) {
            if (check[i] == -1)
                return;
            else {
                min = Math.min(min, arr[i][check[i]]);
                max = Math.max(max, arr[i][check[i]]);
            }
        }
        if (r - l < 0 || max - min < r - l) {
            l = min;
            r = max;
        }
    }

    public static int[] findSmallestRange(int[][] arr, int n, int k) {
        PriorityQueue<List<Integer>> q = new PriorityQueue<>(
                (o1, o2) -> arr[o1.get(0)][o1.get(1)] - arr[o2.get(0)][o2.get(1)]);
        for (int i = 0; i < k; i++)
            q.add(Arrays.asList(i, 0));
        int[] check = new int[k];
        Arrays.fill(check, -1);
        l = 1; r = -1;
        while (!q.isEmpty()) {
            int x = q.peek().get(0);
            int y = q.peek().get(1);
            q.poll();
            check[x] = y;
            if (y < n - 1)
                q.add(Arrays.asList(x, y + 1));
            compute(arr, check);
        }
        int[] res = { l, r };
        return res;
    }

    public static void main(String[] args) throws IOException {
        int n = 3, k = 5;
        int arr[][] = { { 1, 3, 5 }, { 7, 8, 9 }, { 2, 4, 6 }, { 2, 3, 8 }, { 5, 7, 11 }

        };
        System.out.println(Arrays.toString(findSmallestRange(arr, n, k)));
    }
}