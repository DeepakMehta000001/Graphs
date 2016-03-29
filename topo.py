'__author__'=='deepak Singh Mehta(learning to code)) '
'''
    Graph#5 Topological Sorting in DAG.
    Principle is to use stack with keeps track
    all the "edged from v" nodes before v pushing
    v

    date:- 21/3/2016
    time:- 9:30am
'''
stack,graph,vis,n = [],{},[],int()


def dfs(v):
  global vis,graph,stack,n
  vis[v]=True
  for i in graph[v]:
    if not vis[i]:
      dfs(i)
  stack.append(v)


def topSort():
  global vis,graph,stack,n
  vis = [False]*n
  for i in range(n):
    if not vis[i]:
      dfs(i)
  for i in stack[::-1]:
    print(i,end=' ')
    

if __name__=='__main__':
  n,m = map(int,input().split())
  for i in range(n):
    graph[i]=[]
  for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)
  topSort()
  
