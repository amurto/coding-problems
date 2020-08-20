import java.util.*;
import java.io.*;

public class p13 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] params = br.readLine().split(" ");
            long n= Integer.parseInt(params[0]);
            long m= Integer.parseInt(params[1]);
            String[] line1 = br.readLine().split(" ");
            String[] line2 = br.readLine().split(" ");
            HashSet<Long> h = new HashSet<Long>();
            for (int i=0; i<m; i++)
                h.add(Long.parseLong(line2[i]));
            StringBuffer sb=new StringBuffer();
            for (String s: line1) 
                if (!h.contains(Long.parseLong(s)))
                    sb.append(s+" ");
            System.out.println(sb);
        }
    }
}