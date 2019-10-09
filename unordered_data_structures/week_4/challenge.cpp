
#include <iostream>
#include <string>

// Note: You must not change the definition of DisjointSets here.
class DisjointSets {
public:
  int s[256];
  int distance[256];

  DisjointSets() {
    for (int i = 0; i < 256; i++) s[i] = distance[i] = -1;
  }

  int find(int i) { return s[i] < 0 ? i : find(s[i]); }
  
  void dsunion(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
      s[root_i] = root_j;
    }
  }
  
  void bfs(int i, int n, int m, int edges[][2]);
};


/* Below are two conditions that need to be programmed
 * to allow this procedure to perform a breadth first
 * traversal and mark the edge distance of the graph's
 * vertices from vertex i.
 */

void DisjointSets::bfs(int i, int n, int m, int edges[][2]) {
  
  distance[i] = 0;

  // no need to iterate more than m times
  // but loop terminates when no new
  // vertices added to the frontier.

  
  for (int d = 1; d < m; d++) {
    
    // f is the index of the first
    // vertex added to the frontier
    int f = -1;

    // rooti is the name of the set
    // holding all of the vertices
    // that have already been assigned
    // distances
    
    int rooti = find(i);

    // loop through all of the edges
    // (this could be much more efficient
    // if an adjacency list was used
    // instead of a simple edge list)
    
    for (int j = 0; j < m; j++) {

      // root0 and root1 are the names of
      // the sets that the edge's two
      // vertices belong to

      int root0 = find(edges[j][0]);
      int root1 = find(edges[j][1]);
      
      // [If one endpoint belongs to the same set as rooti, and the other endpoint does not,] then the "not" end needs to be marked in the f set, so that it can be merged at the end of the round. The part in bold and brackets above is the only part you need to implement yourself. This can be done using only boolean logic and the results of finding the root of a given node.
      

      std::cout << "rooti is: " << rooti << std::endl;
      std::cout << "findi is: " << find(i) << std::endl;
      std::cout << "s[rooti] is: " << s[rooti] << std::endl;
      // std::cout << "frooti is: " << find(rooti) << std::endl;
      // std::cout << "root0 is: " << root0 << std::endl;
      // std::cout << "find0 is: " << find(root0) << std::endl;
      // std::cout << "root1 is: " << root1 << std::endl;
      // std::cout << "find1 is: " << find(root1) << std::endl;

        // std::cout << "Distance root 0 is " << distance[root0] << std::endl;
        // std::cout << "root1 is " << root1 << std::endl;
      if ( find(root0) == find(rooti) and find(root1) != find(rooti) ) {
        
        // std::cout << "root 0 is " << root0 << std::endl;
        // std::cout << "Distance root 0 is " << distance[root0] << std::endl;
        // std::cout << "root 1 is " << root1 << std::endl;
        // std::cout << "Distance root 1 is " << distance[root1] << std::endl;
        // std::cout << "Distance d is " << distance[d] << std::endl;

        // add the [1] vertex of the edge
        // to the frontier, either by
        // setting f to that vertex if it
        // is the first frontier vertex
        // found so far, or by unioning
        // it with the f vertex that was
        // already found.
        
        // If any edge has one and only one vertex in the already-processed set (the same set as the start vertex i) then we add its other vertex to the current frontier set.
        
        if (f == -1)
          f = edges[j][1];
        else
          dsunion(f,edges[j][1]);

        // set the distance of this frontier
        // vertex to d

        distance[edges[j][1]] = d;
        
      } else if ( find(root0) != find(rooti) and find(root1) == find(rooti) ) {
        // 
        // std::cout << "root0 is " << root0 << std::endl;
        // std::cout << "Distance root 0 is " << distance[root0] << std::endl;
        // std::cout << "root1 is " << root1 << std::endl;
        // std::cout << "Distance root 1 is " << distance[root1] << std::endl;
        if (f == -1)
          f = edges[j][0];
        else
          dsunion(f,edges[j][0]);
        distance[edges[j][0]] = d;
      }
    }
    // When do we not anything else to the frontier?
    
    // if no vertices added to the frontier
    // then we have run out of vertices and
    // are done, otherwise union the frontier
    // set with the set of vertices that have
    // already been processed.
    
    if (f == -1)
      break;
    else
      dsunion(f,i);
  }
}

int main() {

  int edges[8][2] = {{0,1},{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,3}};  

  DisjointSets d;

  d.bfs(3,8,8,edges);

  for (int i = 0; i < 8; i++)
    std::cout << "Distance to vertex " << i
              << " is " << d.distance[i] << std::endl;
// Should print
// Distance to vertex 0 is 3
// Distance to vertex 1 is 2
// Distance to vertex 2 is 1
// Distance to vertex 3 is 0
// Distance to vertex 4 is 1
// Distance to vertex 5 is 2
// Distance to vertex 6 is 2
// Distance to vertex 7 is 1


  return 0;
}
