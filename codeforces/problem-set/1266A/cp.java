import java.util.*;
import java.io.*;

public class cp {
    public static int calculateSum(ArrayList<Integer> arr) {
        int sum = 0;
        for (int a : arr) {
            sum += a;
        }
        return sum;
    }

    public static boolean isDivBy20(ArrayList<Integer> arr) {
        int evn = 0;
        int zero = 0;
        for (int a : arr) {
            if (a % 2 == 0)
                evn++;
            if (a == 0)
                zero++;
            if (evn > 1 && zero > 0) 
                return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        int n = in.nextInt();
        while (n > 0) {
            ArrayList<Integer> arr = new ArrayList<Integer>();
            String y = in.next();
            String[] tokens = y.split("");
            for (String t : tokens)
                arr.add(Integer.parseInt(t));
            if (calculateSum(arr) % 3 == 0 && isDivBy20(arr))
                System.out.println("red");
            else
                System.out.println("cyan");
            n--;
        }
        in.close();
    }
}