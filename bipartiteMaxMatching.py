'__author__'=='deepak Singh Mehta(learning Bipartite Maximum Matching... :))'

graph,M,N = list(),6,6

#recursive dfs returns true if there's a matching for vextex u is possible
def bpm(u,seen,match): 
    global graph,N,M
    for v in range(N):
        if graph[u][v] and not seen[v]: #if applicant u is interested in job and is not visited
            seen[v] = True #mark as visited
            #If job 'v' is not assigned to an applicant OR
            #previously assigned applicant for job v (which is match[v]) 
            #has an alternate job available. 
            #Since v is marked as visited in the above line, match[v] 
            #in the following recursive call will not get job 'v' again
            if match[v]<0 or bpm(match[v],seen,match):
                match[v]=u
                return True
    return False       
        
#Returns maximum number of matching from M to N
def maxBPM():
    global graph,M,N
    # An array to keep track of the applicants assigned to
    # jobs. The value of matchR[i] is the applicant number
    # assigned to job i, the value -1 indicates nobody is
    # assigned.
    match = [-1 for i in range(N)] #Initially all jobs are available
    result = 0 #Count of jobs assigned to applicants
    for u in range(M):
        seen = [False for i in range(N)]#Mark all jobs as not seen for next applicant.
        if bpm(u,seen,match): # Find if the applicant 'u' can get a job
            result += 1
    return result

if __name__=='__main__':
    graph = [[0,1,1,0,0,0],
             [1,0,0,1,0,0],
             [0,0,1,0,0,0],
             [0,0,1,1,0,0],
             [0,0,0,0,0,0],
             [0,0,0,0,0,1]
             ]
    print("Maximum number of applicants that can get job is",maxBPM())
