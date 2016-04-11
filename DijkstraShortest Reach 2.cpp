
/*
    Author :- Deepak Singh Mehta
    Problem:- https://www.hackerrank.com/challenges/dijkstrashortreach
    Theory :- Dijkstra Algorithm

    Hard work succeeded because talent was  not working hard. :)

*/

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
#include<utility>
#include<limits.h>

#define v2d(a,n,m) vector< vector<int> > a(n,vector<int>(m,0))
#define v1d(a,n) vector<int> a(n,0)
#define ve(a) vector<int> a
#define v2e(a) vector< vector<int> > a
#define frl(i,n,m) for(int i=n;i<m;i++)
#define frl1(i,n,m) for(int i=n;i<=m;i++)

using namespace std;
typedef pair<int,int> pi;
int t,n,m,x,y,r,s;
int d[3000];
bool mark[3000];


void dijkstra(vector<pi> node[])
{
    fill(d,d+n,INT_MAX);
    fill(mark,mark+n,false);
    d[s]=0;
    int u;
    priority_queue < pi,vector < pi >,greater< pi > > pq;
    pq.push({d[s],s});
    while(!pq.empty())
    {
        u=pq.top().second;
        pq.pop();
        if(mark[u])
            continue;
        mark[u]=true;
        for(int i=0;i<node[u].size();i++)
        {
            if(d[node[u][i].second]>d[u]+node[u][i].first)
                {
                    d[node[u][i].second]=d[u]+node[u][i].first;
                    pq.push({d[node[u][i].second],node[u][i].second});
                }

        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);

    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<pi> node[n];
        frl(i,0,m)
        {
            cin>>x>>y>>r;
            node[x-1].push_back({r,y-1});
            node[y-1].push_back({r,x-1});
        }
        cin>>s;
        s--;
        dijkstra( node);
        frl(i,0,n)
        {
            if(i!=s)
            {
                if(d[i]==INT_MAX)
                    cout<<"-1 ";
                else
                    cout<<d[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
