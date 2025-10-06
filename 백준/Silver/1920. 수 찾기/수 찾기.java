// N 개의 정수가 주어져 있을 떄, 이 안에 x라는 정수 존재?
// 2초니까 2억번
// 1 <= N <= 100,000
// 1 <= M <= 100,000

// 5
// 4 1 5 2 3
// 5
// 1 3 7 9 5

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int[] array;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        array = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 0; i < N; i++) {
            array[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(array);
        
        int M = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());

        for(int i = 0; i < M; i++) {
            int a = Integer.parseInt(st.nextToken());

            if(exists(a)) {
                System.out.println("1");
            }
            else {
                System.out.println("0");
            }
        }

    }

    static boolean exists(int x){
        int left = 0;
        int right = array.length - 1;

        while(left <= right) {
            int mid = (left + right) / 2;
            if(array[mid] == x) {
                return true;
            }
            if(array[mid] < x) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return false;
    }
}
