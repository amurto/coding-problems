import java.util.Scanner;

public class hsp {
    public static void main(String[] args) {
        java.util.Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int b, c;
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        in.close();
        for (int i = 0; i < n; i++) {
            if (a[i] % 3 == 0 || a[i] % 7 == 0) {
                System.out.println("YES");
            } else {
                c = 0;
                b = a[i] / 7;
                while (b > 0) {
                    if ((a[i] - b * 7) % 3 == 0) {
                        c++;
                        break;
                    }
                    b--;
                }
                b = a[i] / 3;
                while (b > 0) {
                    if ((a[i] - b * 3) % 7 == 0) {
                        c++;
                        break;
                    }
                    b--;
                }
                if (c > 0)
                    System.out.println("YES");
                else
                    System.out.println("NO");
            }
        }
    }
}