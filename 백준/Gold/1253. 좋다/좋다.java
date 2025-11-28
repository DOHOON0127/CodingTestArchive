import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] a = new int[N];

        for(int i = 0; i < N; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }

        // 1 2 3 4 5 6 7 8 9 10
        // 내가 찾는 수가 K이고
        // a[start] + a[end] > K 이면 end--
        // a[start] + a[end] < K 이면 start++
        // a[start] + a[end] == K 이면 start++, end--, count++;

        int result = 0;

        // a[]
        // 1 2 3 4 5 6 7 8 9 10

        // 0 1 3 4

        Arrays.sort(a);
        
        for(int k = 0; k < N; k++){

            long find = a[k]; // 10(k=9)
            int start = 0; // 0
            int end = N-1; // 9

            while(start < end) {

                if(a[start] + a[end] == find) {

                    if(start != k && end != k){
                        result++;
                        break;
                    }
                    else if(start == k){
                        start++;
                    }
                    else if(end == k){
                        end--;
                    }

                }
                else if(a[start] + a[end] < find) {
                    start++;
                }
                else{
                    end--;
                }
            }

        }

        System.out.println(result);

    }
}