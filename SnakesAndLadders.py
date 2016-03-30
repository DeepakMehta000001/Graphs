'__author__'=='deepak Singh Mehta(learning brute force)) '
#Testcases on the given link.. 
#https://www.hackerrank.com/challenges/the-quickest-way-up

if __name__=='__main__':
  tests = int(input())
  for _ in range(tests):
    vis = [False for i in range(120)]
    dist = [0 for i in range(120)]
    graph = [[] for i in range(120)]
    ladder = int(input())
    for _ in range(ladder):
      x,y = map(int,input().split())
      graph[x].append(y)
      dist[x]-=1
    snakes = int(input())
    for _ in range(snakes):
      x,y = map(int,input().split())
      graph[x].append(y)
      dist[x]-=1
    #print(graph)
    for i in range(1,100):
      if len(graph[i])==0:
        for j in range(i+1,i+7):
          graph[i].append(j)
          if j>=100:
            break
    #print(graph)
    que = []
    que.append(1)
    dist[1]=0
    while len(que)!=0 and que[0]!=100:
      k = que[0]
      del que[0]
      for i in graph[k]:
        if not vis[i]:
          vis[i]=True
          que.append(i)
          dist[i]+=1+dist[k]
    print(-1 if not dist[100] else dist[100])
    
