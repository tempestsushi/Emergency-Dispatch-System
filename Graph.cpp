#include "Graph.h"
#include <iostream>
using namespace std;

// FOR EXPLANATION OF THIS CLASS PLEASE REFER TO HEADER FILE AND FOR ALGO SCROLL DOWN 

Graph::Graph() : numLocations(0) {}

Graph::Graph(int numLocations) : numLocations(numLocations) {}

void Graph::addLocation(int id, string name, bool isHospital) {
    Location loc(id, name, isHospital);
    locations[id] = loc;
}

void Graph::addEdge(int src, int dest, int weight) {
    adjList[src].push_back(Edge(dest, weight));
}

void Graph::addBidirectionalEdge(int loc1, int loc2, int weight) {
    addEdge(loc1, loc2, weight);
    addEdge(loc2, loc1, weight);
}

const Location* Graph::getLocation(int id) const {
    auto it = locations.find(id);
    if (it != locations.end()) {
        return &it->second;
    }
    return nullptr;
}


int Graph::getNumLocations() const {
    return numLocations;
}

const map<int, vector<Edge>>& Graph::getAdjList() const {
    return adjList;
}

vector<int> Graph::getHospitalIds() const {
    vector<int> hospitals;
    for (const auto& pair : locations) {
        if (pair.second.getIsHospital()) {
            hospitals.push_back(pair.first);
        }
    }
    return hospitals;
}

void Graph::displayGraph() const {
    cout << "CITY MAP" << endl;
    cout << "Total Locations: " << numLocations << endl << endl;
    
    cout << "Locations:" << endl;
    for (const auto& pair : locations) {
        pair.second.display();
    }
    cout << endl << endl;

    cout << "Road Connections:" << endl;
    for (const auto& pair : adjList) {
        const Location* loc = getLocation(pair.first);
        if (loc) {
            cout << loc->getName() << " (ID:" << pair.first << ") connects to:" << endl;
            for (const Edge& edge : pair.second) {
                const Location* destLoc = getLocation(edge.destination); 
                if (destLoc) {
                    cout << "  -> " << destLoc->getName() 
                         << " (ID:" << edge.destination << "), Distance: " 
                         << edge.weight << " km" << endl;
                }
            }
        }
    }
    cout << endl << endl << endl;
}

/*
 Graph Class Functions 


 Add a location
   void Graph::addLocation(int id, string name, bool isHospital)
    Create a node (Location) and stores it in the internal map.
   - Steps:
       Create a new Location object using the provided id, name, and isHospital status
       Insert this new object into the locations map, using the id as the key and the Location object as the value

Add a directed edge
   void Graph::addEdge(int src, int dest, int weight)
   - Creates a directed connection (one-way road) between two nodes
   - Steps:
       1. Create an Edge object using the dest (destination ID) and weight (distance).
       2. Access the adjList (adjacency list map) using the src (source ID) as the key.
       3. Push the new Edge object to the back of the vector associated with that source key.

Add a bidirectional edge
   void Graph::addBidirectionalEdge(int loc1, int loc2, int weight)
   - Creates a two-way connection by adding two directed edges
   - Steps:
       1. Call addEdge with source loc1 and destination loc2.
       2. Call addEdge with source loc2 and destination loc1 using the same weight

Get a location by ID
   const Location* Graph::getLocation(int id) const
   - Retrieves a pointer to a Location object based on its ID.
   - Steps:
       1. Search the locations map for the key id.
       2. If found, return the address of the Location object (value of the map entry).
       3. If not found, return nullptr.

 Get number of locations
   int Graph::getNumLocations() const
   - Returns the current number of locations.
   - Steps:
       1. Return the current value of the numLocations variable.

Get adjacency list
   const map<int, vector<Edge>>& Graph::getAdjList() const
   - Returns a constant reference to the entire adjacency list.
   - Steps:
       Return the adjList structure map containing all connections

Get hospital IDs
   vector<int> Graph::getHospitalIds() const
   - Filters the locations to find which ones are hospitals
   - Steps:
       1. Create an empty integer vector named hospitals
       2. Iterate through every entry in the locations map
       3. For each entry, check if the Location object's getIsHospital() method returns true
       4. If true, append the location's ID (map key) to the hospitals vector
       5. Return the hospitals vector

 Display the graph
    void Graph::displayGraph() const
    - Visualizes the entire graph structure in the console.
    - Steps:
        1. Print the "CITY MAP" header and the total number of locations.
        2. Print Node Details:
            - Iterate through the locations map.
            - For each location, call its internal display() function to print its details.
        3. Print Edge Details (Roads):
            - Iterate through the adjList map.
            - For each source node:
                * Retrieve and print the source location's name using getLocation.
                * Iterate through the vector of Edges associated with this source.
                * For each edge, retrieve the destination location's name using the edge's destination ID.
                * Print the destination name, ID, and the weight (distance) of the edge.
*/
