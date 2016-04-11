/*
    Author :- Deepak Singh Mehta
    Problem:- http://acm.timus.ru/problem.aspx?space=1&num=1837
    Theory :- simple BFS

    People are unbelievably hard working at times,
    motivate yourself to be one. :)

*/



#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

map<string, int> id;
vector<int> graph[301];
int dist[301];
bool vis[301];
void bfs(){

    fill(dist,dist+301,-1);
    memset(vis,false,sizeof(vis));
    queue<int> que;
    if(id.find("Isenbaev") != id.end()){
        int s=id["Isenbaev"];
        dist[s]=0;
        que.push(s);
        vis[s]=true;
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(int v=0;v<graph[u].size();++v){
                if(!vis[graph[u][v]]){
                    dist[graph[u][v]]=dist[u]+1;
                    vis[graph[u][v]]=true;
                    que.push(graph[u][v]);
                }

            }
        }

    }
}

int main(){
    int N;

    cin >> N;

    int V = 0;
    string s1,s2,s3;

    for(int i = 0;i < N;++i){
        cin >> s1 >> s2 >> s3;

        if(id.find(s1) == id.end()) id[s1] = V++;
        if(id.find(s2) == id.end()) id[s2] = V++;
        if(id.find(s3) == id.end()) id[s3] = V++;

        int a = id[s1],b = id[s2],c = id[s3];

        graph[a].push_back(b); graph[a].push_back(c);
        graph[b].push_back(a); graph[b].push_back(c);
        graph[c].push_back(a); graph[c].push_back(b);
    }

    bfs();

    for(map<string, int>::iterator it = id.begin();it != id.end();++it){
        cout << it->first << " ";

        if(dist[it->second] == -1) cout << "undefined" << endl;
        else cout << dist[it->second] << endl;
    }

    return 0;
}
