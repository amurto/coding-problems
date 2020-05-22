import java.util.Scanner;

public class poster {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        String s = in.next();
        in.close();
        k--;
        char input[] = s.toCharArray();
        int m = k < n - 1 - k ? -1 : 1;
        if (m == 1) {
            while (k < n - 1) {
                System.out.println("RIGHT");
                k++;
            }
            System.out.println("PRINT " + input[k]);
            k--;
            while (k >= 0) {
                System.out.println("LEFT");
                System.out.println("PRINT " + input[k]);
                k--;
            }
        } else {
            while (k > 0) {
                System.out.println("LEFT");
                k--;
            }
            System.out.println("PRINT " + input[k]);
            k++;
            while (k < n) {
                System.out.println("RIGHT");
                System.out.println("PRINT " + input[k]);
                k++;
            }
        }
    }
}