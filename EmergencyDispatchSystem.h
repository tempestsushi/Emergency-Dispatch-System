#ifndef EMERGENCYDISPATCHSYSTEM_H
#define EMERGENCYDISPATCHSYSTEM_H

#include "Graph.h"
#include <vector>
#include <queue>
#include <map>
using namespace std;

/*
    EmergencyDispatchSystem Class
  

    EmergencyDispatchSystem(Graph* graph)
        - Constructor: Initialize the system with a city graph

    void initializeDijkstra(int startNode, map<int,int>& distances,
                            map<int,int>& parents, map<int,bool>& visited)
        - Initialize distances, parents, and visited maps for Dijkstra

    void relaxEdge(int currentNode, const Edge& edge, 
                   map<int,int>& distances, map<int,int>& parents,
                   priority_queue<DijkstraNode, vector<DijkstraNode>, greater<DijkstraNode>>& pq)
        - Relax an edge: update distance and parent if a shorter path is found

    vector<int> reconstructPath(int start, int end, map<int,int>& parents)
        - Reconstruct the shortest path from start to end using parent pointers

    map<int,int> dijkstra(int startNode, map<int,int>& parents)
        - Compute shortest distances from start node to all locations using Dijkstra’s algorithm

    PathResult findNearestHospital(int emergencyLocationId)
        - Find the closest hospital and the shortest path from the emergency location

    void displayPathResult(const PathResult& result, int emergencyId)
        - Display the route, nearest hospital, and total distance for an emergency

    void displayAllDistances(int emergencyId, const map<int,int>& distances)
        - Display distances from the emergency location to all other locations

    void dispatch(int emergencyLocationId)
        - Main function: perform emergency dispatch to nearest hospital and display results
*/


struct DijkstraNode {
    int id;
    int distance;
    
    DijkstraNode(int id, int dist) : id(id), distance(dist) {}
    bool operator>(const DijkstraNode& other) const {
        return distance > other.distance;
    }
};

struct PathResult {
    int hospitalId;
    int totalDistance;
    vector<int> path;
    
    PathResult() : hospitalId(-1), totalDistance(INF) {}
    PathResult(int hId, int dist, vector<int> p) 
        : hospitalId(hId), totalDistance(dist), path(p) {}
};

class EmergencyDispatchSystem {
private:
    Graph* cityGraph;
    
    void initializeDijkstra(int startNode, map<int, int>& distances, 
                           map<int, int>& parents, map<int, bool>& visited);
    void relaxEdge(int currentNode, const Edge& edge, 
                   map<int, int>& distances, map<int, int>& parents,
                   priority_queue<DijkstraNode, vector<DijkstraNode>, 
                   greater<DijkstraNode>>& pq);
    vector<int> reconstructPath(int start, int end, map<int, int>& parents);
    
public:
    EmergencyDispatchSystem(Graph* graph);
    
    // Core Dijkstra implementation
    map<int, int> dijkstra(int startNode, map<int, int>& parents);
    
    // Find nearest hospital and path
    PathResult findNearestHospital(int emergencyLocationId);
    
    // Display functions
    void displayPathResult(const PathResult& result, int emergencyId);
    void displayAllDistances(int emergencyId, const map<int, int>& distances);
    
    // Main dispatch function
    void dispatch(int emergencyLocationId);
};

#endif