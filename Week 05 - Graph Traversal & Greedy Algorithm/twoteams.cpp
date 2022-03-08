#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N,M,v1,v2,deq,mid;
vector<vector<int>> edge;

int isBipartie(int l,int r){
    vector<vector<int>> graph;
    vector<int> visited;
    list<int> Queue;
    graph.resize(N);
    visited.resize(N);

    for(int i=l;i<r;i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    Queue.push_back(edge[l][0]);
    visited[edge[l][0]] = 1;
    while(!Queue.empty()){
        deq = Queue.front();
        Queue.pop_front();

        for(int i=0;i<graph[deq].size();i++){
            if(!visited[graph[deq][i]]){
                Queue.push_back(graph[deq][i]);
                visited[graph[deq][i]] = 3-visited[deq];
            }
            else{
                if(visited[deq] == visited[graph[deq][i]]){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int searchGraph(int start,int end){
    mid = start + (end-start)/2;
    if(mid == end || mid == start)
        return mid;
    else if(!isBipartie(0,mid)){
        printf("A (%d %d)\n",start,mid);
        return searchGraph(start,mid);
    }
    else{
        printf("B (%d %d)\n",mid,end);
        return searchGraph(mid,end);
    }
}

int main(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> v1 >> v2;
        edge.push_back({v1-1,v2-1});
    }

    // for(int i=15850;i<15850=;i++){
    //     printf("%d %d\n",i,isBipartie(0,i));
    // }

    cout << searchGraph(0,M+1);
}