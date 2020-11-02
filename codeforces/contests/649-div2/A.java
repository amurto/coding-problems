import java.util.*;
import java.io.*;

public class A {
    public static int XXXXX(String[] line, String[] s) {
        ArrayList<Integer> isDivByK = new ArrayList<Integer>();

        int n = Integer.parseInt(line[0]);
        int k = Integer.parseInt(line[1]);

        int sum = 0;
        for (String num: s) {
            int temp = Integer.parseInt(num);
            sum+=temp;
            if (sum%k == 0) 
                isDivByK.add(1);
            else
                isDivByK.add(0);
        }
        int p = 0;
        while (p<n && isDivByK.get(p) != 0) p++;
        if (p==n) return -1;
        int q=n-1;
        while (q>0 && isDivByK.get(q) != 0) q--;
        return Math.max(n-p-1, q+1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t>0) {
            String[] line = br.readLine().split(" ");
            String[] s = br.readLine().split(" ");
            System.out.println(XXXXX(line, s));
            t--;
        }
    }
}