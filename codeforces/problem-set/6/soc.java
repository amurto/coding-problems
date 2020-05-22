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
        in.close();
        int p=0,q=0,count=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    count = 0;
                    for (int k=0;k<m;k++) {
                        if (a[i][k] == 1)
                            count++;
                    }
                    if (count == 1)
                        p = i+1;
                    count = 0;
                    for (int k=0;k<n;k++) {
                        if (a[k][j] == 1)
                            count++;
                    }
                    if (count == 1)
                        q = j+1;
                }
            }
        }
        System.out.println(p + " " + q);
    }
}