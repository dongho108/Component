//
//  main.cpp
//  11724)연결요소의 개수
//
//  Created by dongho on 2020/01/08.
//  Copyright © 2020 dongho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Component{
    int v;
    vector<int> ver[99];
    bool *visit = new bool[99];
    
public:
    Component(int n){
        v = n;
        //visit falae로 초기화
        for(int i=1; i<v+1; i++){
            visit[i] = false;
        }
    }
    void addEdge(int e){
        //정점에 엣지 추가 (그래프 구성)
        int x, y;
        for(int i=0; i<e; i++){
            cin >> x >> y;
            ver[x].push_back(y);
            ver[y].push_back(x);
        }
    }
    void DFS(int x){
        //각 정점마다 DFS탐색 시작
        
        //시스템스택을 이용하는 방법 : dfs는 먼저 시작정점에서 그 정점에 연결된 엣지가 있으면 그 정점에 대해 다시 dfs실행 만약 연결된 정점이 없으면 그
        if(visit[x]) return;
        visit[x] = true;
        for(int i=0; i<ver[x].size(); i++){
            int y = ver[x][i];
            DFS(y);
        }
    }
    int CheckComponent(){
        int Cnum=0; //연결요소 개수
        for(int i=1; i<v+1; i++){
            if(visit[i] == false){
                DFS(i);
                Cnum++;
            }
        }
        return Cnum;
    }
};

int main() {
    int v;
    int e;
    cin >> v >> e;
    
    Component c(v);
    c.addEdge(e);
    int result = c.CheckComponent();
    cout << result;
}
