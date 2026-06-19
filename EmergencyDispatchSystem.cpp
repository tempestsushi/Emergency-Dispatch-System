#include "EmergencyDispatchSystem.h"
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
// FOR EXPLANATION OF THIS CLASS PLEASE REFER TO HEADER FILE AND FOR ALGO SCROLL DOWN 

EmergencyDispatchSystem::EmergencyDispatchSystem(Graph* graph) 
    : cityGraph(graph) {}

void EmergencyDispatchSystem::initializeDijkstra(int startNode, 
    map<int, int>& distances, map<int, int>& parents, map<int, bool>& visited) {
    
    // Initialize all distances to infinity and visited to false
    for (int i = 0; i < cityGraph->getNumLocations(); i++) {
        distances[i] = INF;
        visited[i] = false;
        parents[i] = -1;
    }
    
    // Distance to start node is 0
    distances[startNode] = 0;
}

void EmergencyDispatchSystem::relaxEdge(int currentNode, const Edge& edge,
    map<int, int>& distances, map<int, int>& parents,
    priority_queue<DijkstraNode, vector<DijkstraNode>, 
    greater<DijkstraNode>>& pq) {
    
    int neighbor = edge.destination;
    int weight = edge.weight;
    
    // If we found a shorter path to neighbor
    if (distances[currentNode] + weight < distances[neighbor]) {
        distances[neighbor] = distances[currentNode] + weight;
        parents[neighbor] = currentNode;
        pq.push(DijkstraNode(neighbor, distances[neighbor]));
    }
}

map<int, int> EmergencyDispatchSystem::dijkstra(int startNode, 
    map<int, int>& parents) {
    
    map<int, int> distances;
    map<int, bool> visited;
    priority_queue<DijkstraNode, vector<DijkstraNode>, 
                   greater<DijkstraNode>> pq;
    
    // Initialize data structures
    initializeDijkstra(startNode, distances, parents, visited);
    
    // Push start node to priority queue
    pq.push(DijkstraNode(startNode, 0));
    
    // Main Dijkstra loop
    while (!pq.empty()) {
        DijkstraNode current = pq.top();
        pq.pop();
        
        int currentNode = current.id;
        
        // Skip if already visited
        if (visited[currentNode]) {
            continue;
        }
        
        visited[currentNode] = true;
        
        // Get adjacency list for current node
        const map<int, vector<Edge>>& adjList = cityGraph->getAdjList();
        
        if (adjList.find(currentNode) != adjList.end()) {
            // Relax all edges from current node
            for (const Edge& edge : adjList.at(currentNode)) {
                if (!visited[edge.destination]) {
                    relaxEdge(currentNode, edge, distances, parents, pq);
                }
            }
        }
    }
    
    return distances;
}

vector<int> EmergencyDispatchSystem::reconstructPath(int start, int end, 
    map<int, int>& parents) {
    
    vector<int> path;
    
    // If no path exists
    if (parents[end] == -1 && start != end) {
        return path;
    }
    
    // Reconstruct path from end to start using parent pointers
    int current = end;
    while (current != -1) {
        path.push_back(current);
        if (current == start) {
            break;
        }
        current = parents[current];
    }
    
    // Reverse to get path from start to end
    reverse(path.begin(), path.end());
    
    return path;
}

PathResult EmergencyDispatchSystem::findNearestHospital(int emergencyLocationId) {
    map<int, int> parents;
    
    // Run Dijkstra from emergency location
    map<int, int> distances = dijkstra(emergencyLocationId, parents);
    
    // Get all hospital IDs
    vector<int> hospitals = cityGraph->getHospitalIds();
    
    if (hospitals.empty()) {
        cout << "ERROR: No hospitals found in the city!" << endl;
        return PathResult();
    }
    
    // Find nearest hospital
    int nearestHospitalId = -1;
    int minDistance = INF;
    
    for (int hospitalId : hospitals) {
        if (distances[hospitalId] < minDistance) {
            minDistance = distances[hospitalId];
            nearestHospitalId = hospitalId;
        }
    }
    
    // Reconstruct path to nearest hospital
    vector<int> path = reconstructPath(emergencyLocationId, nearestHospitalId, 
                                       parents);
    
    return PathResult(nearestHospitalId, minDistance, path);
}

void EmergencyDispatchSystem::displayPathResult(const PathResult& result, 
    int emergencyId) {
    
    cout << "\n******** EMERGENCY DISPATCH RESULT ********" << endl;
    
    const Location* emergencyLoc = cityGraph->getLocation(emergencyId);
    if (emergencyLoc) {
        cout << "Emergency Location: " << emergencyLoc->getName() 
             << " (ID:" << emergencyId << ")" << endl;
    }
    
    if (result.hospitalId == -1 || result.totalDistance == INF) {
        cout << "ERROR: No reachable hospital found!" << endl;
        return;
    }
    
    const Location* hospitalLoc = cityGraph->getLocation(result.hospitalId);
    if (hospitalLoc) {
        cout << "Nearest Hospital: " << hospitalLoc->getName() 
             << " (ID:" << result.hospitalId << ")" << endl;
    }
    
    cout << "Total Distance: " << result.totalDistance << " km" << endl;
    
    cout << "\nShortest Route:" << endl;
    for (size_t i = 0; i < result.path.size(); i++) {
        const Location* loc = cityGraph->getLocation(result.path[i]);
        if (loc) {
            cout << "  " << (i + 1) << ". " << loc->getName() 
                 << " (ID:" << result.path[i] << ")";
            if (i < result.path.size() - 1) {
                cout << " ->";
            }
            cout << endl;
        }
    }
    
    cout << "\n******************************************\n" << endl;
}

void EmergencyDispatchSystem::displayAllDistances(int emergencyId, 
    const map<int, int>& distances) {
    
    cout << "\nDistances from Emergency Location to All Locations:" << endl;
    cout << "---------------------------------------------------" << endl;
    
    for (const auto& pair : distances) {
        const Location* loc = cityGraph->getLocation(pair.first);
        if (loc && pair.first != emergencyId) {
            cout << "To " << loc->getName() << " (ID:" << pair.first << "): ";
            if (pair.second == INF) {
                cout << "UNREACHABLE";
            } else {
                cout << pair.second << " km";
            }
            cout << endl;
        }
    }
    cout << endl;
}

void EmergencyDispatchSystem::dispatch(int emergencyLocationId) {
    cout << "EMERGENCY DISPATCH ACTIVATED" << endl;
    
    // Find nearest hospital
    PathResult result = findNearestHospital(emergencyLocationId);
    
    // Display result
    displayPathResult(result, emergencyLocationId);
}

