import java.util.*;
import java.io.*;

public class B {

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
            String[] candies = br.readLine().split(" ");
            ArrayList<Long> a = new ArrayList<Long>();
            for (String s : candies)
                a.add(Long.parseLong(s));

            String[] oranges = br.readLine().split(" ");
            ArrayList<Long> b = new ArrayList<Long>();
            for (String s : oranges)
                b.add(Long.parseLong(s));

            long minA = Minimum(a);
            long minB = Minimum(b);
            long moves = 0L;
            for (int i = 0; i < n; i++) {
                long valA = a.get(i) - minA;
                long valB = b.get(i) - minB;
                moves = moves + Math.abs(valA - valB) + Math.min(valA, valB);
            }
            System.out.println(moves);
        }
    }
}