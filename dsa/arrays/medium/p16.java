// https://practice.geeksforgeeks.org/problems/smallest-distant-window/0
// Smallest distinct window

import java.util.*;
import java.io.*;

public class p16 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            char[] s = br.readLine().trim().toCharArray();
            int[] map = new int[26];
            
            // Count number of distinct characters
            int d = 0;
            for (char v : s) {
                if (map[v - 'a'] == 0) {
                    map[v - 'a'] = 1;
                    d++;
                }
            }

            int[] window = new int[26];
            int start = 0, end = 1, min = Integer.MAX_VALUE, c=1;
            window[s[start] - 'a']++;
            while (end < s.length) {
                if (window[s[end] - 'a']==0)
                    c++;
                window[s[end] - 'a']++;
                
                // Current substring is a match
                if (c==d) {
                    while (window[s[start] - 'a'] > 1) {
                        window[s[start] - 'a']--;
                        start++;
                    }
                    min = Math.min(min, end - start + 1);
                }
                end++;
            }
            if (s.length == 1)
                System.out.println(1);
            else
                System.out.println(min);
        }
    }
}