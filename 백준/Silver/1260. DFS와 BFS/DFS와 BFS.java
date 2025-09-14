// 시간제한 2초, 2억번 안에
// 방문할 수 있는 노드 여러 개일 경우, 노드 번호 작은 것 먼저 방문
// 더 이상 방문할 수 있는 노드가 없을 때 종료
// 노드 번호는 1~n까지
// 두 노드 사이에 여러 개의 엣지가 잇을 수 잇음, 입력으로 주어지는 엣지는 양방향

// 노드 개수 n, 엣지 개수 m, 탐색 시작 노드 번호 v 입력 받기 (n<=1000, m<=10000)
// 그 다음 m개의 줄에 엣지가 연결하는 두 노드의 번호가 주어짐

//1 -> 2 3 4
//2 -> 1 4
//3 -> 1 4
//4 -> 1 2 3

//1 -> 2 3
//2 -> 1 5
//3 -> 1 4
//4 -> 3 5
//5 -> 2 4


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static boolean visited[];
    static ArrayList<Integer>[] A;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken()); // 노드
        int m = Integer.parseInt(st.nextToken()); // 엣지 수
        int v = Integer.parseInt(st.nextToken()); // 시작 노드

        A = new ArrayList[n+1];

        for(int i = 1; i <= n; i++) {
            A[i] = new ArrayList<Integer>();
        }

        for (int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            A[a].add(b);
            A[b].add(a);
        }

        for(int i = 1; i < n+1; i++) {
            Collections.sort(A[i]);
        }

        visited = new boolean[n+1];

        DFS(v);

        System.out.println();

        visited = new boolean[n+1];

        BFS(v);

    }

    public static void DFS(int now) {

        visited[now] = true;

        System.out.print(now + " ");

        for (int i : A[now]) {
            if (!visited[i]) {
                DFS(i);
            }
        }
    }

    public static void BFS(int Node){
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(Node);
        visited[Node] = true;

        while(!q.isEmpty()) {
            int now = q.poll();
            System.out.print(now + " ");
            for(int i : A[now]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.add(i);
                }
            }
        }
    }
}