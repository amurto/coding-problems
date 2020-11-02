import java.util.*;
import java.io.*;

public class C {

    public static long Minimum(ArrayList<Long> arr) {
        long min = arr.get(0);
        for (int i = 0; i < arr.size(); i++)
            min = Math.min(min, arr.get(i));
        return min;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] weights = br.readLine().split(" ");
            int[] count = new int[n+1];
            for (String s : weights) 
                count[Integer.parseInt(s)]++;
            int ans =0;
            for (int i=2;i<=2*n;i++) {
                int cur = 0;
                for (int j=1;j<(i+1)/2;j++) {
                    if (i-j > n)
                        continue;
                    cur+=Math.min(count[j], count[i-j]);
                }
                if (i%2==0) 
                    cur+=count[i/2]/2;
                ans=Math.max(cur, ans);
            }
            System.out.println(ans);
        }
    }
}