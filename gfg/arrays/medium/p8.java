// https://practice.geeksforgeeks.org/problems/overlapping-intervals/0
// Overlapping Intervals

import java.util.*;
import java.io.*;

public class p8 {
    public static class pair {
        int first;
        int second;

        pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public String toString() {
            return first + " " + second;
        }
    }

    public static ArrayList<pair> overlappedInterval(ArrayList<pair> vec, int n) {
        Collections.sort(vec, (v1, v2) -> v1.first - v2.first);
        ArrayList<pair> stack = new ArrayList<pair>();
        for (int i=0; i<n; i++) {
            if (stack.isEmpty())
                stack.add(vec.get(i));
            else {
                pair a = stack.get(stack.size()-1);
                pair b = vec.get(i);
                if (a.second < b.first)
                    stack.add(b);
                else {
                    stack.remove(stack.size() - 1);
                    stack.add(new pair(a.first, Math.max(a.second, b.second)));
                }
            }
        }
        return stack;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            ArrayList<pair> vec = new ArrayList<pair>();
            String[] line = br.readLine().split(" ");
            for (int i = 0; i < 2*n; i+=2) {
                vec.add(new pair(Integer.parseInt(line[i]),Integer.parseInt(line[i+1])));
            }
            ArrayList<pair> ans = overlappedInterval(vec, n);
            StringBuffer sb = new StringBuffer();
            for (int i=0;i<ans.size();i++) 
                sb.append(ans.get(i)+" ");
            System.out.println(sb);
        }
    }
}