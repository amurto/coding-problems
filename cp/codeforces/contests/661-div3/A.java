import java.util.*;
import java.io.*;

public class A {
    public static Boolean isValid(int a, int b) {
        int c = Math.abs(a-b);
        if (c <= 1)
            return true;
        else
            return false;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] arrELements = br.readLine().split(" ");
            ArrayList<Integer> arr = new ArrayList<Integer>();
            for (String s: arrELements) 
                arr.add(Integer.parseInt(s));
            Collections.sort(arr);
            int i=0;
            while (i<n-1 && isValid(arr.get(i), arr.get(i+1))) {
                i++;
            }
            if (i==n-1)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}