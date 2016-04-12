/*
    Author:- Deepak Singh Mehta.
    Problem link:- https://www.hackerrank.com/contests/booking-hack-a-holiday/challenges/weekend-away
    Theory:- Ad hoc
    Deciding what not to do is as important as deciding what to do.
*/
#include<bits/stdc++.h>
#define pb push_back
#define p(a) pair<int,int>
#define mp make_pair
#define NAX 100001
#define MOD 1000000007
#define v(a) vector<int>
#define fastio ios::sync_with_stdio(false)
#define si(a) scanf("%d",&a)
#define ll long long
#define ff first
#define ss second
using namespace std;

int tests,n,m;


int main(){
    int tests;
    si(tests);
    for(;tests;--tests){
        map<int,multiset<int> > cities;
        int n,m;
        si(n);si(m);
        map<int,int> graph;
        for(int i=0;i<m;++i){
            int u,v,cost;
            si(u);si(v);si(cost);
            cities[u].insert(cost);
            cities[v].insert(cost);
            graph[u]=cost;
            graph[v]=cost;

        }
        long long res= 9999999;
            for(map<int,int>::iterator mit=graph.begin();mit!=graph.end();++mit){
                int i = mit->ff;
            int small=9999999,smallest = 9999999;
            for(multiset<int>::iterator it=cities[i].begin();it!=cities[i].end();++it){
                int dist = *it;
                if(dist < smallest){
                    small = smallest;
                    smallest= dist;
                }else if(dist < small)
                    small= dist;
            }
            long long total= 0;
            total = smallest+small;
            res = min(res,total);
        }
    cout<<res<<endl;
    }
    return 0;
}

