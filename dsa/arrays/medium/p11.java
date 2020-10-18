// https://practice.geeksforgeeks.org/problems/stock-span-problem/0
// Stock span problem

import java.util.*;
import java.io.*;

public class p11 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] a = new int[n];
            String[] line = br.readLine().split(" ");
            for (int i=0; i<n; i++) 
                a[i] = Integer.parseInt(line[i]);

            int[] ans = new int[n];
            Deque<Integer> stack = new LinkedList<Integer>();
            for (int i=0; i<n;i++) {
                if (stack.isEmpty()) {
                    ans[i] = 1;
                    stack.push(i);
                } else {
                    while (!stack.isEmpty() && a[stack.peek()] <= a[i]) 
                        stack.pop();
                    if (stack.isEmpty())
                        ans[i] = i+1;
                    else
                        ans[i]=i-stack.peek();
                    stack.push(i);
                }   
            }
            StringBuffer sb = new StringBuffer();
            for (int v: ans)
                sb.append(v + " ");
            System.out.println(sb);
        }
    }
}