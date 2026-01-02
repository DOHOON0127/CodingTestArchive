import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int start = 0;
        int end = N-1;
        int count = 0;

        int[] arr = new int[N];
        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        while(start < end) {
            if(arr[start] + arr[end] == M) {
                count++;
                start++;
            }
            else if(arr[start] + arr[end] < M) {
                start++;
            }
            else {
                end--;
            }
        }

        System.out.println(count);
    }
}