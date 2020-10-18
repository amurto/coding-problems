// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
// The Celebrity Problem

import java.util.*;
import java.io.*;

public class p5 {
    public static int getId(int M[][], int n) {
        Deque<Integer> dq = new LinkedList<Integer>();
        for (int i = n - 1; i >= 0; i--)
            dq.push(i);
        while (dq.size() > 1) {
            int a = dq.pop();
            int b = dq.pop();
            if (M[a][b] == 1)
                dq.push(b);
            else
                dq.push(a);
        }
        int v = dq.pop();
        for (int i = 0; i < n; i++)
            if (i != v && (M[v][i] == 1 || M[i][v] == 0))
                return -1;
        return v;
    }

    public static void main(String[] args) throws IOException {
        int n = 2;
        int[][] M = { { 0, 1, 0 }, { 0, 0, 0 }, { 0, 1, 0 } };
        System.out.println(getId(M, n));
    }
}