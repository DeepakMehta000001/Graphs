'__author__'=='deepak Singh Mehta(learning to code :) ) '
 
'''
    problem link:- https://www.hackerrank.com/challenges/primsmstsub
    
    Theory :- Prims Algorithm
    
    Hard work beats Talent when Talent doesn't work hard. :)
 
'''
INT_MAX = 10000000


if __name__=='__main__':
    n,m = map(int,input().split())
    vis = [False for i in range(n+1)]
    graph = [[] for i in range(n+1)]
    for _ in range(m):
        a,b,c = map(int,input().split())
        graph[a].append([b,c])
        graph[b].append([a,c])
    pq = list()
    s = int(input())
    dist = [INT_MAX for i in range(n+1)]
    dist[s]=0
    pq.append([0,s])
    while len(pq)!=0:
        v,d = pq[0][1],pq[0][0]
        del pq[0]
        vis[v]=True
        if d <= dist[v]:
            for i in range(len(graph[v])):
                w,e = graph[v][i][0], graph[v][i][1]
                if not vis[w] and dist[w]>e:
                    dist[w]=e
                    pq.append([dist[w],w])
                    pq.sort()
    sum1 = 0
    for i in range(1,n+1):
        sum1 += dist[i]
    print(sum1)
    
