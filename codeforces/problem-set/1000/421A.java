import java.util.Scanner;

public class ph {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();
        int arr[] = new int[a+b];
        for (int i=0; i<a+b; i++) {
            arr[i] = in.nextInt();
        }
        in.close();
        for (int i=0;i<n;i++) {
            for (int j=0;j<a+b;j++) {
                if (arr[j] == i+1) {
                    if (j<a) 
                        System.out.print(1 + " ");
                    else
                        System.out.print(2 + " ");
                    break;
                }
            }
        }   
    }
}