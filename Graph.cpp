#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <string>
#include <sstream> // Для istringstream

using namespace std;

void bfs(int start, const vector<vector<int>>& adj) {
    set<int> visited;
    queue<int> q;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << endl;

        for (int neighbor : adj[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

void dfs(int start, const vector<vector<int>>& adj) {
    set<int> visited;
    stack<int> s;

    s.push(start);
    while (!s.empty()) {
        int vertex = s.top();
        s.pop();

        if (visited.find(vertex) == visited.end()) {
            cout << vertex << endl;
            visited.insert(vertex);
        }

        for (auto it = adj[vertex].rbegin(); it != adj[vertex].rend(); ++it) {
            if (visited.find(*it) == visited.end()) {
                s.push(*it);
            }
        }
    }
}

int main() {
    string graph_type, search_type;
    int start_vertex;

    // Ввод данных
    cin >> graph_type >> start_vertex >> search_type;
    cin.ignore();  // Игнорируем оставшийся символ новой строки после счёта

    vector<vector<int>> adj(100); // до 100 вершин
    set<pair<int, int>> edges;

    string line;
    // Считываем рёбра, пока строка не пустая
    while (getline(cin, line) && !line.empty()) {
        istringstream iss(line);
        int u, v;
        if (iss >> u >> v) {  // Проверяем успешность считывания
            edges.emplace(u, v);
            if (graph_type == "u") {
                edges.emplace(v, u); // Добавляем обратное ребро для неориентированного графа
            }
        }
        else {
            cerr << "Error reading edge: " << line << endl;
        }
    }

    // Создание списка смежности
    for (const auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
    }
    for (auto& neighbors : adj) {
        sort(neighbors.begin(), neighbors.end());
    }

    // Выполняем обход
    if (search_type == "b") {
        bfs(start_vertex, adj);
    }
    else if (search_type == "d") {
        dfs(start_vertex, adj);
    }

    return 0;
}
