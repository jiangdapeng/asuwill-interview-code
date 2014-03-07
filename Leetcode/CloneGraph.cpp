#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

struct Node{
  vector<Node*> adj;
};

// bfs clone graph

Node* clone_graph(Node* g) {
  if(g == NULL) return NULL;
  queue<Node*> que;
  map<Node*, Node*> cloned;
  Node* ng = new Node(); // new graph node
  cloned[g] = ng;
  que.push(ng);

  while(!que.empty()){
    Node* cur = que.front();
    que.pop();
    int n = cur->adj.size();
    for(int i=0; i<n; ++i){
      Node* adj = cur->adj[i];
      if (cloned.find(adj) == cloned.end()) {
        // adj is not copied
        Node* copyadj = new Node();
        cloned[adj] = copyadj;
        cloned[cur]->adj.push_back(copyadj);
        que.push(copyadj);
      }
      else {
        cloned[cur]->adj.push_back(cloned[adj]);
      }
    }
  }
  return ng;
}
