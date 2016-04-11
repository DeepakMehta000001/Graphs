'__author__'=='deepak Singh Mehta(learning graphs)) '
#problem :- https://www.hackerrank.com/challenges/journey-to-the-moon
#theory:- Set-Disjoint

if __name__=='__main__':
  n, m = map(int, input().split())
  lis_of_sets = []
  for i in range(m):
      a,b = map(int, input().split())
      indices = []
      new_set = set()
      set_len = len(lis_of_sets)
      s = 0
      while s < set_len:
          if a in lis_of_sets[s] or b in lis_of_sets[s]:
              indices.append(s)
              new_set = new_set.union(lis_of_sets[s])
              del lis_of_sets[s]
              set_len -= 1
          else:
              s += 1

      new_set = new_set.union([a, b])
      lis_of_sets.append(new_set)

  ans = n*(n-1)//2
  for i in lis_of_sets:
      ans -= len(i)*(len(i)-1)//2
  print(ans)
