class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        # {0: [1, 2]}
        adjMap = {}

        for prereq in prerequisites:
            if prereq[0] not in adjMap:
                adjMap[prereq[0]] = [prereq[1]]
            else:
                adjMap[prereq[0]].append(prereq[1])


        visited = set()

        def dfs(prereq):
            if prereq in visited:
                return False
            
            # not in prerequisites map, course has no prereq
            if prereq not in adjMap:
                return True
         
            visited.add(prereq)
            for req in adjMap[prereq]:
                if dfs(req) == False:
                    return False
            
            visited.remove(prereq)
            return True
        
        if len(prerequisites) == 0:
            return True
        
        for course in range(numCourses):
            if not dfs(course):
                return False

        return True

            
        