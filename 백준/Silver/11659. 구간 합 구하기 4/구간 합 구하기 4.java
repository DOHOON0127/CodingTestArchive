import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken()); // 5
        int M = Integer.parseInt(st.nextToken()); // 3

        String s = br.readLine(); // 5 4 3 2 1
        String[] arr = s.split(" ");

        // 합 배열 만들기
        int[] sum = new int[N+1]; // 이러면 0으로 초기화

        sum[0] = 0;

        for(int i = 1; i < N+1; i++){
            sum[i] = sum[i-1] + Integer.parseInt(arr[i-1]);
        }

        // sum
        // 0 5 9 12 14 15

        // 5 4 3 2 1

        for(int i = 0; i < M; i++){
            StringTokenizer st1 = new StringTokenizer(br.readLine());

            int start = Integer.parseInt(st1.nextToken()); // 1 2 5
            int end = Integer.parseInt(st1.nextToken()); // 3 4 5

            int count = 0;

            count = sum[end] - sum[start-1];

            System.out.println(count);
        }

    }
}