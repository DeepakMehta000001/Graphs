/*
    Author :- Deepak Singh Mehta
    Problem:- https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights
    Theory :- Floyd Warshalls algorithm.(dp)

    Hard work succeeded because talent was  not working hard. :)

*/


#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
#include<map>
using namespace std;

#define sd(a) scanf("%d",&a)
#define pd(a) prlong longf("%lld\n",(a))
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 100000000
int adj[500][500];
int main()
{
	int n,m,q,x,y,r,i,j,k;
	sd(n);
	sd(m);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			adj[i][j]=INF;
		}
		adj[i][i]=0;
	}
	for(i=0;i<m;++i)
	{
		sd(x);
		sd(y);
		sd(r);
		if(x!=y)
			adj[x][y]=r;
	}
	for(k=1;k<=n;++k)
	{
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				if(adj[i][k]!=INF&&adj[k][j]!=INF)
				{
					adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);

				}
			}
		}
	}
	sd(q);
	while(q--)
	{
		sd(x);
		sd(y);
		if(adj[x][y]==INF)
			printf("%d\n",-1);
		else
			printf("%d\n",adj[x][y]);
	}
}
