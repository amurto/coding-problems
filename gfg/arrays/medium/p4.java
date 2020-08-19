// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
// Merge k Sorted Arrays

import java.util.*;
import java.io.*;



public class p4 {
    // Naive Approach
    public static ArrayList<Integer> mergeKArraysNaive(int[][] arrays, int k) {
        int[] count = new int[k];
        ArrayList<Integer> ans = new ArrayList<Integer>();
        while (ans.size() < k * k) {
            int cur = 0, min = -1;
            for (int i = 0; i < k; i++) {
                if (count[i] < k) {
                    if (min == -1) {
                        min = arrays[i][count[i]];
                        cur = i;
                    } else {
                        if (arrays[i][count[i]] < min) {
                            min = arrays[i][count[i]];
                            cur = i;
                        }
                    }
                }
            }
            ans.add(min);
            count[cur]++;
        }
        return ans;
    }

    public static class SortValues implements Comparator<List<Integer>> {
        public int compare(List<Integer> a1, List<Integer> a2) {
            if (a1.get(0) > a2.get(0))
                return 1;
            return -1;
        }
    }

    // Optimized Approach with Priority Queue
    public static ArrayList<Integer> mergeKArrays(int[][] arrays, int k) {
        PriorityQueue<List<Integer>> pq = new PriorityQueue<List<Integer>>(new SortValues());
        ArrayList<Integer> ans = new ArrayList<Integer>();
        for (int i=0; i<k; i++) {
            pq.add(Arrays.asList(arrays[i][0], i, 0));
        }
        while (!pq.isEmpty()) {
            List<Integer> a = pq.poll();
            int i=a.get(1);
            int c=a.get(2);
            ans.add(a.get(0));
            if (c<k-1) {
                pq.add(Arrays.asList(arrays[i][++c], i, c));
            }
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int arrays[][] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        int k = 3;
        ArrayList<Integer> ans = mergeKArrays(arrays, k);
        System.out.println(ans);
    }
}