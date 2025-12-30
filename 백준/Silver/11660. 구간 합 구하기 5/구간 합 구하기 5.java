import java.util.*;
import java.io.*;

public class Main {

    static int[][] arr;

    public static void main(String[] ars) throws IOException {

        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken()); // 4 표의 크기
        int M = Integer.parseInt(st.nextToken()); // 3 합을 구해야 하는 횟수

        arr = new int[N+1][N+1];

        for(int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int[][] arr1 = new int[N+1][N+1];

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                arr1[i][j] = arr1[i][j-1] + arr1[i-1][j] - arr1[i-1][j-1] + arr[i][j];
            }
        }

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            int result = arr1[x2][y2] - arr1[x1-1][y2] - arr1[x2][y1-1] + arr1[x1-1][y1-1];
            System.out.println(result);
        }
    }

}
