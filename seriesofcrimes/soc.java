import java.util.Scanner;

public class soc {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int a[][] = new int[n][m];
        in.nextLine();
        for (int i = 0; i < n; i++) {
            String line = in.nextLine();
            String[] strs = line.split("");
            for (int j = 0; j < m; j++) {
                if (strs[j].equals("."))
                    a[i][j] = 0;
                else
                    a[i][j] = 1;
            }
        }
        // for (int i=0;i<n;i++) {
        // for (int j=0;j<m;j++) {
        // System.out.print(a[i][j]);
        // }
        // System.out.println("");
        // }
        outerloop: for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    System.out.println(i + "" + j);
                    break outerloop;
                }
            }
        }
        in.close();
    }
}