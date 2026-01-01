import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());

        int count = 1;
        int start = 1;
        int end = 1;
        int sum = 1;

        while(start != N) {

            if(sum == N) {
                end++;
                sum += end;
                count++;
            }
            else if(sum < N) {
                end++;
                sum += end;
            }
            else if(sum > N) {
                sum -= start;
                start++;
            }
        }

        System.out.println(count);
    }
}