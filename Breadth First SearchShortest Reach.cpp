/*
    Author :- Deepak Singh Mehta
    Problem:- https://www.hackerrank.com/challenges/bfsshortreach
    Theory :- Simple BFS

    Hard work succeeded because talent was  not working hard. :)

*/


#include<bits/stdc++.h>
#define pb push_back
#define p(a) pair<int,int>
#define mp make_pair
#define NAX 3001
#define mod 1000000007
#define v(a) vector<int>
#define fastio ios::sync_with_stdio(false)
#define si(a) scanf("%d",&a)
#define ll long long

using namespace std;

bool vis[NAX]={false};
int dist[NAX]={INT_MAX};
vector<int> graph[NAX];
int n,m,src;

void dfs(){
    queue<int> que;
    vis[src]=true;
    dist[src]=0;
    que.push(src);
    while(!que.empty()){
        int a = que.front();
        que.pop();
            for(int i=0;i<graph[a].size();++i){
                if(!vis[graph[a][i]]){
                    dist[graph[a][i]] = max(dist[graph[a][i]],dist[a]+6);
                    vis[graph[a][i]]=true;
                    que.push(graph[a][i]);
                }
            }
    }
}


void init(){
    //memset(vis,false,sizeof(vis));
    fill(vis,vis+NAX,false);
    for(int i=0;i<NAX;++i)
        graph[i].clear();
    memset(dist,INT_MAX,sizeof(dist));
}

int main(){
    int tests;
    scanf("%d",&tests);
    for(;tests;--tests){
        init();
        scanf("%d%d",&n,&m);
        for(;m;--m){
            int x,y;scanf("%d%d",&x,&y);
            graph[x].pb(y);
            graph[y].pb(x);
        }
        scanf("%d",&src);
        dfs();
        for(int i=1;i<=n;++i){
            if(i==src)continue;
            if(dist[i]==INT_MAX) printf("-1 ");
            else
             printf("%d ",dist[i]);
        }
        printf("\n");
    }
    return 0;
}
