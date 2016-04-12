'__author__'=='deepak Singh Mehta(learning to code :) ) '
 
'''
    Theory :- Connected components
    Hard work beats Talent when Talent doesn't work hard. :)
 
'''
graph, vis , ans = list() , list(), list()
n,m = int(), int()

def dfs(u):
    global graph,vis
    vis[u]= True
    for v in range(len(graph[u])):
        if vis[graph[u][v]]:
            continue
        dfs(graph[u][v])
        
if __name__=='__main__':
    n,m = map(int,input().split())
    graph = [[] for i in range(n+1)]
    for _ in range(m):
        x,y = map(int,input().split())
        graph[x].append(y)
        graph[y].append(x)
    vis = [False for i in range(n+1)]
    ans = 0
    for i in range(1,n+1):
        if not vis[i]: 
            ans += 1
            dfs(i)
    print(ans)
