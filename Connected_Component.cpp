#include<bits/stdc++.h>
using namespace std;
///KHONG DE QUY IN RA CAC THANH PHAN LIEN THONG
// định nghĩa đồ thị bằng danh sách kề
//vector<vector<int>> graph;

// hàm DFS để tìm các thành phần liên thông
// void DFS(int u, vector<bool>& visited) {
//     stack<int> s;
//     s.push(u);

//     while (!s.empty()) {
//         int v = s.top();
//         s.pop();
//         if (!visited[v]) {
//             visited[v] = true;
//             cout << v << " ";
//             for (int i = 0; i < graph[v].size(); ++i) {
//                 int w = graph[v][i];
//                 if (!visited[w]) {
//                     s.push(w);
//                 }
//             }
//         }
//     }
// }

// // hàm để tính toán các thành phần liên thông của đồ thị
// void findConnectedComponents(int n) {
//     vector<bool> visited(n, false);

//     for (int i = 0; i < n; ++i) {
//         if (!visited[i]) {
//             cout << "Thành phần liên thông: ";
//             DFS(i, visited);
//             cout << endl;
//         }
//     }
// }

// int main() {
//     int n, m; // n là số đỉnh, m là số cạnh

//     cout << "Nhập số đỉnh: ";
//     cin >> n;

//     cout << "Nhập số cạnh: ";
//     cin >> m;

//     // khởi tạo đồ thị vô hướng với n đỉnh và m cạnh
//     graph.resize(n);
//     for (int i = 0; i < m; ++i) {
//         int u, v;
//         cout << "Nhập cạnh thứ " << i + 1 << ": ";
//         cin >> u >> v;
//         graph[u].push_back(v);
//         graph[v].push_back(u);
//     }

//     // tính toán các thành phần liên thông của đồ thị
//     findConnectedComponents(n);

//     return 0;
// }


/////////        DE QUY ////////

void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph, vector<int>& component) {
    visited[node] = true; // Mark the node as visited
    component.push_back(node); // Add the node to the current component
    for (int neighbor : graph[node]) { // Loop over the neighbors of the current node
        if (!visited[neighbor]) { // If the neighbor is not visited yet
            dfs(neighbor, visited, graph, component); // Recursively explore the neighbor
        }
    }
}

vector<vector<int>> connected_components(vector<vector<int>>& graph) {
    int n = graph.size(); // Number of nodes in the graph
    vector<bool> visited(n, false); // Initially all nodes are unvisited
    vector<vector<int>> components; // A vector to hold all the connected components

    for (int i = 0; i < n; i++) { // Loop over all nodes
        if (!visited[i]) { // If the current node is unvisited
            vector<int> component; // Start a new component
            dfs(i, visited, graph, component); // Explore the component
            components.push_back(component); // Add the component to the vector of components
        }
    }
    return components;
}

int main() {
    int n, m;
    cin >> n >> m; // Read in the number of nodes and edges
    vector<vector<int>> graph(n); // Initialize the graph as an adjacency list
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // Read in the endpoints of the edge
        graph[u].push_back(v); // Add the edge to the graph
        graph[v].push_back(u); // Since the graph is undirected, we need to add it twice
    }
    vector<vector<int>> components = connected_components(graph); // Compute the connected components
    // cout << "Connected Components:\n";
    // for (int i = 0; i < components.size(); i++) {
    //     cout << "Component " << i + 1 << ": ";
    //     for (int j = 0; j < components[i].size(); j++) {
    //         cout << components[i][j] << " "; // Print the nodes in the current component
    //     }
    //     cout << "\n";
    // }
    cout<<components.size()<<endl;
    return 0;
}
