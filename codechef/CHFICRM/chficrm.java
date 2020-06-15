    import java.util.*;
    import java.io.*;

    class chficrm {
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int t = Integer.parseInt(br.readLine());
            while (t > 0) {
                int n = Integer.parseInt(br.readLine());
                int count[] = new int[4];
                int a[] = new int[n];
                String line = br.readLine();
                String s[] = line.split(" ");
                for (int i = 0; i < n; i++)
                    a[i] = Integer.parseInt(s[i]);
                Boolean ans = true;
                for (int coin : a) {
                    if (coin == 10) {
                        if (count[1] < 1) {
                            ans = false;
                            break;
                        } else {
                            count[1]--;
                        }
                    } else if (coin == 15) {
                        if (count[2] >= 1) {
                            count[2]--;
                        } else if (count[1] >= 2) {
                            count[1] = count[1] - 2;
                        } else {
                            ans = false;
                            break;
                        }
                    }
                    count[coin / 5]++;
                    n--;
                }
                System.out.println(ans ? "YES" : "NO");
                t--;
            }
        }
    }