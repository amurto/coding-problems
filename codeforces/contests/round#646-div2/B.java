import java.util.*;
import java.io.*;

public class B {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));

        int t = in.nextInt();
        while (t > 0) {
            String s = in.next();
            String tokens[] = s.split("");
            ArrayList<Integer> arr = new ArrayList<Integer>();
            for (String tok : tokens)
                arr.add(Integer.parseInt(tok));
            int len = arr.size();
            int count = 0;
            if (len == 1)
                System.out.println(0);
            else if (arr.get(0) == arr.get(len - 1)) {
                int temp = arr.get(0);
                int eq = 1, neq = 0;
                arr.remove(0);
                arr.remove(arr.size() - 1);
                for (int i = 0; i < arr.size(); i++) {
                    if (arr.get(i) == temp)
                        eq++;
                    else
                        neq++;
                }
                count = eq < neq ? eq : neq;
                System.out.println(count);
            } else {
                int zeros = 0, ones = 0;
                arr.remove(0);
                arr.remove(arr.size() - 1);
                for (int i = 0; i < arr.size(); i++) {
                    if (arr.get(i) == 0)
                        zeros++;
                    else
                        ones++;
                }
                count = zeros < ones ? zeros : ones;
                System.out.println(count);
            }
            t--;
        }

        in.close();
    }
}