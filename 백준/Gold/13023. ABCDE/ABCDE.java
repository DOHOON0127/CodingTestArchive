// n 명이 참가하는 캠프 ( n <= 2000 )
// 0 ~ n-1번까지 존재
// 사람의 수 n, 친구 관계의 수 m
// 2번째 줄부터 m개의 줄에 정수 a와 b가 주어짐

// DFS의 시간복잡도는 O(V+E)이므로 최대 4000 (간선 + 노드)
// 모든 노드를 진행했을때, 4000 * 2000 = 8,000,000 이므로 DFS 사용가능

//8 8
//
//0 -> 4
//1 -> 7
//2 -> 7
//3 -> 4 5 7
//4 -> 6 7 3 0
//5 -> 3
//6 -> 4
//7 -> 1 2 3 4
//
//이걸 이제 arraylist로 표현 해야 함
//가중치, 방향없는 인접리스트
//방문했던 노드는 탐색을 중지해야 하고
//depth가 5까지 내려오면 1을 출력
//
//visited 배열
//isArrived 5도착 확인
//A 그래프 데이터 저장 인접리스트
//
//for(n개수 만큼 반복){
//  A 인접 리스트의 각 ArrayList 초기화
//}
//
//for(m개수 만큼 반복){
//    A 인접 리스트의 각 ArrayList 초기화
//}
//
//for(n개수 만큼 반복){
//    각 노드마다 DFS 실행하기
//    if(isArrived) 반복 종료
//}
//
//if(isArrived) 1 else 0
//
//DFS{
// if(깊이 5 || isArrived){
//    isArrived = true;
//    종료
// }
// 방문배열에 현재 노드 기록
// 현재 노드의 연결 노드 중 방문하지 않은 노드 DFS로 실행(depth 증가)
//}


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static boolean visited[];
    static ArrayList<Integer>[] A;
    static boolean isArrived;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        isArrived = false;

        visited = new boolean[n];
        A = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            A[i] = new ArrayList<Integer>();
        }

        for(int i = 0; i < m; i++){

            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            A[a].add(b);
            A[b].add(a);

        }

        for(int i = 0; i < n; i++){
            DFS(i, 1);
            if(isArrived){
                break;
            }
        }

        if(isArrived){
            System.out.println("1");
        }
        else{
            System.out.println("0");
        }

    }

    public static void DFS(int now, int depth){
        if(depth == 5 || isArrived){
            isArrived = true;
            return;
        }
        visited[now] = true;
        for(int i : A[now]){
            if(!visited[i]){
                DFS(i, depth+1);
            }
        }
        visited[now] = false; // 백트래킹 필요 -> 함수가 끝날때 방문 표시를 지워서 다른 경로에서도 해당 노드를 사용할 수 있도록 함
    }
}