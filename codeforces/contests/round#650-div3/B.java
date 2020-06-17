import java.util.*;
import java.lang.*;
import java.io.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t > 0) {
            int n = Integer.parseInt(br.readLine());
            int evn, evnc = 0, oddc = 0, problem = 0;
            if (n % 2 > 0)
                evn = n / 2 + 1;
            else
                evn = n / 2;
            int odd = n / 2;
            String[] line = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                int temp = Integer.parseInt(line[i]);
                if (temp % 2 == 0)
                    evnc++;
                else
                    oddc++;
                if (i % 2 != temp % 2)
                    problem++;
            }

            if (evn != evnc || odd != oddc)
                System.out.println(-1);
            else {
                if (problem % 2 > 0)
                    System.out.println(-1);
                else
                    System.out.println(problem / 2);
            }
            t--;
        }
    }

}
