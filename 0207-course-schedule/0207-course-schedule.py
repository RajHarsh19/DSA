from typing import List
from collections import deque, defaultdict

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        graph = defaultdict(list)
        indegree = [0] * numCourses
        
        for course, prereq in prerequisites:
            graph[prereq].append(course)
            indegree[course] += 1
        
        
        queue = deque([i for i in range(numCourses) if indegree[i] == 0])
        finished_courses = 0
        
       
        while queue:
            current = queue.popleft()
            finished_courses += 1
            for neighbor in graph[current]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)
        
       
        return finished_courses == numCourses
