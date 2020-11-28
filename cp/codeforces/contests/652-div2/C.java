import java.util.*;
import java.io.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t>0) {
            String[] line = br.readLine().split(" ");
            int n = Integer.parseInt(line[0]);
            int k = Integer.parseInt(line[1]);
            String[] string = br.readLine().split(" ");
            ArrayList<Long> a = new ArrayList<Long>();
            for (String s: string) 
                a.add(Long.parseLong(s));
            String[] w = br.readLine().split(" ");
            ArrayList<Integer> friends = new ArrayList<Integer>();
            for (String s: w) 
                friends.add(Integer.parseInt(s));
            Collections.sort(a, Collections.reverseOrder());
            Collections.sort(friends);
            long sum = 0L;
            int l=0, r=n-1;
            for (int i=0;i<k; i++) {
                long max = a.get(l);
                if (friends.get(i) > 1)
                    max+=a.get(r);
                else
                    max*=2;
                l++;
                r = r-(friends.get(i)-1);
                sum+=max;
            }
            System.out.println(sum);
            t--;
        }
    }
}
