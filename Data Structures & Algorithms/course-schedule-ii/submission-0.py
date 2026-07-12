class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adjmap = {i:[] for i in range(numCourses)}

        # idea dfs cycle check -> keep track of visited set and stack
        # when we hit a course with zero prerequisites we want to
        # remove from set and pop from stack then add to returning array



        # map prereq to its corresponding courses
        for prereq in prerequisites:
            if prereq[0] in adjmap:
                adjmap[prereq[0]].append(prereq[1])
            else:
                adjmap[prereq[0]] = [prereq[1]]
        

        cycle = set()
        visit = set()
        output = []

        def dfs(course):
            if course in cycle:
                return False
            
            if course in visit:
                return True
            
            cycle.add(course)
            visit.add(course)

            for crs in adjmap[course]:
                if not dfs(crs):
                    return False
            
            cycle.remove(course)
            visit.add(course)
            output.append(course)
            return True

        for course in adjmap:
            if not dfs(course):
                return []
        
        return output
            

