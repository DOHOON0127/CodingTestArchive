// 블루레이에는 총 N개의 레슨이 들어감
// 블루레이는 연속적으로 녹화해야 함
// M개의 블루레이에 모든 동영상 녹화할 예정
// 블루레이의 크기는 최소, M개의 블루레이는 모두 같은 크기로

// 레슨의 수 N(1 <= N <= 100,000)과 블루레이의 수 M(1<=M<=N)
// 강토의 기타 레슨의 길이가 레슨 순서대로 분 단위로 주어짐
// 각 레슨의 길이는 10,000분을 넘지 않음


// 9 3 (N, M)
// 1 2 3 4 5 6 7 8 9

// 17(블루레이의 크기(녹화할 수 있는 길이) 중 최소값)

// 블루에이의 크기가 모두 같고 녹화 순서가 바뀌지 않아야 함이라는 문제 조건이 이진 탐색 알고리즘을 선택하게 만드는 실마리


import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st =  new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken()); // 9
        int M = Integer.parseInt(st.nextToken()); // 3

        StringTokenizer st1 =  new StringTokenizer(br.readLine());

        int[] A = new int[N];
        int start = 0;
        int end = 0;

        for(int i = 0; i < N; i++){
            A[i] = Integer.parseInt(st1.nextToken());
            if(start < A[i]){
                start = A[i];
            }
            end = end + A[i]; // 45
        }

        while(start <= end){
            int middle = (start + end) / 2; // 27
            int sum = 0;
            int count = 0;

            for(int i = 0; i < N; i++) {
                if (sum + A[i] > middle) {
                    count++;
                    sum = 0;
                }
                sum =sum + A[i];
            }

            if(sum != 0){
                count++;
            }

            if(count > M){
                start = middle + 1;
            }
            else{
                end = middle - 1;
            }
        }
        System.out.println(start);
    }
}


