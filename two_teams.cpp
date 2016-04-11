/*
    Author :- Deepak Singh Mehta
    Problem:- http://acm.timus.ru/problem.aspx?space=1&num=1106
    Theory :- Simple BFS

    Hard work succeeded because talent was  not working hard. :)

*/

#include<bits/stdc++.h>
#define pb push_back
#define p(a) pair<int,int>
#define mp make_pair
#define NAX 101
#define MOD 1000000007
#define v(a) vector<int>
#define fastio ios::sync_with_stdio(false)
#define si(a) scanf("%d",&a)
#define ll long long
#define ff first
#define ss second
using namespace std;

vector<int> graph[NAX];
set<int> A;
bool vis[NAX]={false};
int n;
void bfs(){
    list<int> que;
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;++i){
        if(vis[i]) continue;
        vis[i]=true;
        que.pb(i);
        bool what=true;
        while(!que.empty()){
            int sz=que.size();
            while(sz--){
            int u=que.front();
            que.pop_front();
            if(what)A.insert(u);
            for(int v=0;v<graph[u].size();++v){
                if(vis[graph[u][v]]) continue;
                    vis[graph[u][v]]=true;
                    que.pb(graph[u][v]);

                }
            }
            what= !what;
            }

        }

}

int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        while(x!=0){
            graph[i].pb(x);
            cin>>x;
        }
    }
   //cout<<graph[3][0]<<" "<<graph[3][1]<<" "<<graph[3][2]<<" "<<graph[3][3]<<endl;
    bfs();
    cout<<A.size()<<endl;
    for(set<int>::iterator it=A.begin();it!=A.end();++it)
        cout<<*it<<" "; cout<<endl;

    return 0;
}
