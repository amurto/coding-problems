// https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1
// Smallest range in K lists

import java.util.*;
import java.io.*;

public class p22 {
    public static Boolean isDone(int[] check) {
        for (int i = 0; i < check.length; i++)
            if (check[i] == -1)
                return false;
        return true;
    }

    public static int[] findSmallestRange(int[][] arr, int n, int k) {
        PriorityQueue<List<Integer>> q = new PriorityQueue<>(
                (o1, o2) -> arr[o1.get(0)][o1.get(1)] - arr[o2.get(0)][o2.get(1)]);
        for (int i = 0; i < k; i++)
            q.add(Arrays.asList(i, 0));
        int[] check = new int[k];
        Arrays.fill(check, -1);
        while (!isDone(check) && !q.isEmpty()) {
            int x = q.peek().get(0);
            int y = q.peek().get(1);
            q.poll();
            check[x] = y;
            if (y < n - 1)
                q.add(Arrays.asList(x, y + 1));
        }
        int min = arr[0][check[0]], max = -1;
        for (int i = 0; i < k; i++) {
            min = Math.min(min, arr[i][check[i]]);
            max = Math.max(max, arr[i][check[i]]);
        }
        int[] res = { min, max };
        return res;
    }

    public static void main(String[] args) throws IOException {
        int n = 4, k = 3;
        int arr[][] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
        System.out.println(Arrays.toString(findSmallestRange(arr, n, k)));
    }
}