// Count Occurences of Anagrams 
// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams/0

import java.util.*;
import java.io.*;

public class p4 {
    final static int MAX_CHAR = 256;

    public static Boolean IsAnagram(int[] count) {
        for (int v: count)
            if (v != 0)
                return false;
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String text = br.readLine();
            String word = br.readLine();
            int m = text.length();
            int n = word.length();


            int[] count = new int[MAX_CHAR];
            for (int i=0; i<n; i++)
                count[word.charAt(i)]++;
            for (int i=0; i<n; i++) 
                count[text.charAt(i)]--;
            
            int ans=0;
            if (IsAnagram(count))
                ans++;
            
            for (int i=n; i<m; i++) {
                count[text.charAt(i)]--;
                count[text.charAt(i-n)]++;
                if (IsAnagram(count))
                    ans++;
            }
            
            System.out.println(ans);
                
        }
    }
}