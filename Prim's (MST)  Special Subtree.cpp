
/*
    Author :- Deepak Singh Mehta
    Problem:- https://www.hackerrank.com/challenges/primsmstsub
    Theory :- Prims algorithm

    Hard work succeeded because talent was  not working hard. :)

*/


#include <bits/stdc++.h>
using namespace std;


int main() {

    int n,m;
    int vis[3002]={0};
        cin>>n>>m;
        vector< pair<int,int> > vi[n+1];
        int a,b,c;
        for(int i=0;i<m;i++){
            cin>>a>>b>>c;
            vi[a].push_back(make_pair(c,b));
            vi[b].push_back(make_pair(c,a));
        }
        priority_queue<pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > > q;
        int s;
        cin>>s;
        int dis[n+1];
        for(int i=1;i<=n;i++)
            dis[i]=INT_MAX;
            //dis[i]=50000000;
        dis[s]=0;
        q.push(make_pair(0,s));
        while(!q.empty()){
            pair<int,int> top=q.top();
            q.pop();
            int v=top.second;
            int d=top.first;
           // dis[v]=d;
            vis[v]=1;
            //cout<<v<<endl;
            if(d<=dis[v]){
                for(int i=0;i<vi[v].size();i++){
                    int w=vi[v][i].second;
                    int e=vi[v][i].first;
                    if(dis[w]>e && vis[w]!=1){
                        dis[w]=e;
                        q.push(make_pair(dis[w],w));
                    }
               }
            }
        }
        unsigned long long sum=0;
        for(int i=1;i<=n;i++){
           // if(i!=s){
               // if(dis[i]!=50000000)
                   sum+=dis[i];
            //}
        }
        cout<<sum<<endl;

    return 0;
}
