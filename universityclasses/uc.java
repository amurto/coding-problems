import java.util.Scanner;

public class uc {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();
        int a[][] = new int[n][7];
        for (int i = 0; i < n; i++) {
            String line = in.nextLine();
            String strs[] = line.split("");
            for (int j = 0; j < 7; j++) {
                a[i][j] = Integer.parseInt(strs[j]);
            }
        }
        in.close();
        int rooms = 0, temp = 0;
        for (int i = 0; i < 7; i++) {
            temp = 0;
            for (int j = 0; j < n; j++) {
                if (a[j][i] == 1)
                    temp++;
            }
            if (temp > rooms)
                rooms = temp;
        }
        System.out.print(rooms);
    }
}