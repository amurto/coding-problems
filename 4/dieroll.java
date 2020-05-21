import java.util.Scanner;

public class dieroll {
    public static int getGCD(int n1, int n2) {
        if (n2 == 0) {
            return n1;
        }
        return getGCD(n2, n1 % n2);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int y = in.nextInt();
        int w = in.nextInt();
        in.close();
        if (w > y) {
            y = w;
        }
        y = 6 - y + 1;
        int gcd = getGCD(y, 6);
        System.out.println((y/gcd) + "/" + (6/gcd));
    }
}