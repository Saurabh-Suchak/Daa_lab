#include<bits/stdc++.h>
using namespace std;

// To check if there exists
// at least 1 hamiltonian cycle
bool hasCycle;

// Function to check if a vertex v
// can be added at index pos in
// the Hamiltonian Cycle
bool isSafe(int v, int graph[][6], vector<int> path, int pos)
{

	// If the vertex is adjacent to
	// the vertex of the previously
	// added vertex
	if (graph[path[pos - 1]][v] == 0)
		return false;

	// If the vertex has already
	// been included in the path
	for (int i = 0; i < pos; i++)
		if (path[i] == v)
			return false;

	// Both the above conditions are
	// not true, return true
	return true;
}

// Recursive function to find all
// hamiltonian cycles
void FindHamCycle(int graph[][6], int pos, vector<int> path, bool visited[], int N)
{
	// If all vertices are included
	// in Hamiltonian Cycle
	if (pos == N) {

		// If there is an edge
		// from the last vertex to
		// the source vertex
		if (graph[path[path.size() - 1]][path[0]] != 0) {

			// Include source vertex
			// into the path and
			// print the path
			path.push_back(0);
			for (int i = 0; i < path.size(); i++) {
				cout << path[i] << " ";
			}
			cout << endl;

			// Remove the source
			// vertex added
			path.pop_back();

			// Update the hasCycle
			// as true
			hasCycle = true;
		}
		return;
	}

	// Try different vertices
	// as the next vertex
	for (int v = 0; v < N; v++) {

		// Check if this vertex can
		// be added to Cycle
		if (isSafe(v, graph, path, pos) && !visited[v]) {

			path.push_back(v);
			visited[v] = true;

			// Recur to construct
			// rest of the path
			FindHamCycle(graph, pos + 1, path, visited, N);

			// Remove current vertex
			// from path and process
			// other vertices
			visited[v] = false;
			path.pop_back();
		}
	}
}

// Function to find all possible
// hamiltonian cycles
void hamCycle(int graph[][6], int N)
{
	// Initially value of boolean
	// flag is false
	hasCycle = false;

	// Store the resultant path
	vector<int> path;
	path.push_back(0);

	// Keeps the track of the
	// visited vertices
	bool visited[N];

	for (int i = 0; i < N; i++)
		visited[i] = false;

	visited[0] = true;

	// Function call to find all
	// hamiltonian cycles
	FindHamCycle(graph, 1, path, visited, N);

	if (!hasCycle) {

		// If no Hamiltonian Cycle
		// is possible for the
		// given graph
		cout << "No Hamiltonian Cycle" << "possible " << endl;
		return;
	}
}
	
int main()
{
	int graph[][6] = {
			{ 0, 1, 1, 0, 0, 1 },
			{ 1, 0, 1, 0, 1, 1 },
			{ 1, 1, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 1, 0 },
			{ 0, 1, 0, 1, 0, 1 },
			{ 1, 1, 0, 0, 1, 0 },
		};
	hamCycle(graph, 6);

	return 0;
}

