import java.util.*;
import java.io.*;

public class p1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t>0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
            ArrayList<Long> a = new ArrayList<Long>();
            for (String s: line) 
                a.add(Long.parseLong(s));
            int total= 1;
            for (int i=1; i<n; i++)
                if (a.get(i) <= a.get(i-1))
                    total++;
                else 
                    a.set(i, a.get(i-1));
            System.out.println(total);
            t--;
        }
    }
}
