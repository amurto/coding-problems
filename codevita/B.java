import java.util.*;
import java.io.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String[] line = br.readLine().split(" ");
    
            int zeros = 0, ones = 0, twos = 0;
            for (int i=0; i<n; i++) {
                int v = Integer.parseInt(line[i]);
                if (v%3 == 0)
                    zeros++;
                else if (v%3==1)
                    ones++;
                else 
                    twos++;
            }
            if ((zeros == 0 && ones > 0 && twos > 0) || (zeros > ones+twos+1))
                System.out.println("No");
            else 
                System.out.println("Yes");
        }
    }
}