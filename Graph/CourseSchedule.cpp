#include "header.h"
//passed all test cases

//https://leetcode.com/problems/course-schedule/
//this problem reduces down to finding a cycle in a directed graph.
//we can use concept of indegrees combined with BFS to solve this problem (Kahn's algorithm)
//https://en.wikipedia.org/wiki/Topological_sorting#Algorithms
//https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	if (prerequisites.size() == 0) return true;
	//calculate indegree of each course.
	//indegree is the number of nodes pointing to a node
	//indegree can be seen as the number of prereqs for a course
	vector<int> indegrees(numCourses, 0);
	for (int i = 0; i < prerequisites.size(); ++i) {
		int course = prerequisites[i][0];
		indegrees[course]++;
	}

	//build the graph. course -> {list of courses I can take after taking current course}
	map<int, vector<int>> adj;
	for (int i = 0; i < prerequisites.size(); ++i) {
		adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	}
	int count = 0; //number of nodes that has indegree = 0
  
	queue<int> q;
	//add all courses that have indegree == 0
  for (int i = 0; i < numCourses; i++) {
		if (indegrees[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int top = q.front();
		if (indegrees[top] == 0) {
			++count;
		}
		vector<int> nextCourses = adj[top];
		for (int i = 0; i < nextCourses.size(); ++i) {
			indegrees[nextCourses[i]]--;
			if (indegrees[nextCourses[i]] == 0) q.push(nextCourses[i]);
		}
		q.pop();
	}
	//return true if count == numCourses
	return count == numCourses;
}

void main() {
	int numCourses = 2;
	vector<vector<int>> prerequisites = {
		{0, 1}
		{1, 0}
	};
	cout << canFinish(numCourses, prerequisites) << endl;
}
