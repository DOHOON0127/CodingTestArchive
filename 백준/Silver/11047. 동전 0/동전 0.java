// 동전의 종류 : N
// 동전을 적절히 사용해 그 합을 K로 만듦

// 첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)
//
// 둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다.
// (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

//첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.

//10 4200
//        1
//        5
//        10
//        50
//        100
//        500
//        1000
//        5000
//        10000
//        50000
// 6

//10 4790
//        1
//        5
//        10
//        50
//        100
//        500
//        1000
//        5000
//        10000
//        50000
// 12

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken()); // 10
        int K = Integer.parseInt(st.nextToken()); // 4200

        int[] A = new int[N];
        int max = 0;
        int count = 0;

        for(int i = 0; i < N; i++)
        {
            A[i] = Integer.parseInt(br.readLine());
            if(max < A[i]){
                max = A[i];
            }
        }

        for(int i = 0; i < N; i++){
            max = A[N-1-i];

            if((K / max) == 0){

            }
            else {
                if((K % max) == 0){
                    count = count + (K / max);
                    break;
                }
                count = count + (K / max);

                K = K - (max * (K / max));
            }
        }


        // -> K / 최댓값 = t 이
        // 0이면
        // 그 전 최댓값으로 이동함
        // 0이 아니면
        // K = K - t x 최댓값으로 K를 수정하고
        // 그전 최댓값으로 이동
        // 이때부터는 계속 진행
        // K = K - t x 최댓값 이게 0이 나오는 순간 종료

        System.out.println(count);

    }
}