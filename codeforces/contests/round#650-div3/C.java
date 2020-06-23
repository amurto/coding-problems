import java.util.*;
import java.lang.*;
import java.io.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t>0) {
            String[] line = br.readLine().split(" ");
            int n = Integer.parseInt(line[0]);
            int k = Integer.parseInt(line[1]);
            String[] string = br.readLine().split("");
            ArrayList<Integer> res = new ArrayList<Integer>();
            for (int i=0; i<n; i++)
                res.add(Integer.parseInt(string[i]));
            res.add(1);
            int c = 0, tables = 0;
            Boolean beg = false;
            Boolean end = false;
            for (int i=0; i<=n; i++) {
                if (res.get(i) == 0) {
                    if (i==0) beg = true;
                    if (i==n-1) end = true;
                    c++;
                }
                else {
                    if (c>0) {
                        int m = c%(k+1);
                        int tb = c/(k+1);
                        if (beg && end) {
                            tables = tables+ tb;
                            if (m>0) 
                                tables++;
                        } else if (beg || end) 
                            tables = tables+ tb;
                        else {
                            if (m < k)  
                                tb--;
                            tables+=tb;
                        }
                    }
                    c=0;
                    beg = false;
                    end = false;
                }
            }
            System.out.println(tables);
            t--; 
        }
    }
}
