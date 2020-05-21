import java.util.Scanner;

public class awtgh {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int d = in.nextInt();
        int a[] = new int[n];
        in.nextLine();
        String line = in.nextLine();
        String s[] = line.split("");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(s[i]);
        }
        in.close();
        int j = d, p = 0, jumps = 0, temp = 0;
        while (p < n - 1) {
            j = d;
            temp = p;
            while (j > 0) {
                if (p + j < n && a[p + j] == 1) {
                    p = p + j;
                    jumps++;
                    break;
                }
                j--;
            }
            if (p == temp)
                break;
        }
        if (p == n - 1)
            System.out.println(jumps);
        else
            System.out.println(-1);
    }
}