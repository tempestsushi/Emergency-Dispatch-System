#ifndef GRAPH_H
#define GRAPH_H

#include "Location.h"
#include <vector>
#include <map>
using namespace std;

/*
    GRAPH CLASS SUMMARY:
    

    PURPOSE OF THE GRAPH CLASS:
    This class represents a city map as a weighted graph
    The idea is that Each location is a node, and each road is an edge with a weight 
    (usually representing distance in kilometers)

    A FEW IMPORTANT COMPONENTS:
    
    - numLocations:
          Stores how many total locations the graph should have
          (It is used for display or validation)

    - locations:
          A map which basically stores each Location object
          Key   = location ID
          Value = Location object

    - adjList:
          Adjacency list to store graph edges
          Key   = source location ID
          Value = vector of edge objects representing all roads 
                  going out of that location

    - Edge struct:
          Represents a road from one location to another
          destination = an ID of the connected location
          weight      = distance between the two locations

    FUNCTIONS:
    Constructors:
        - Graph():
            Creates an empty graph.

        - Graph(numLocations):
            Creates a graph that expects a certain number of locations.

    Location Management:
        - addLocation(id, name, isHospital):
            Adds a new location to the graph

    Edge Management:
        - addEdge(src, dest, weight):
            Creates a one way connection from src to dest

        - addBidirectionalEdge(loc1, loc2, weight):
            Creates a two way road between loc1 and loc2

    Retrieval:
        - getLocation(id):
            It returns a pointer to the location with that ID
            Useful for accessing data of nodes

        - getNumLocations():
            Returns the total number of locations in the graph

        - getAdjList():
            Returns a reference to the adjacency list

        - getHospitalIds():
            Returns a list of all location IDs that are hospitals

    Display:
        - displayGraph():
            Prints the full city map:
                All locations
                All roads and distances
*/

const int INF = 999999999; // Large number to represent infinity

struct Edge {
    int destination;
    int weight;
    
    Edge(int dest, int w) : destination(dest), weight(w) {}
};

class Graph {
private:
    int numLocations;
    map<int, Location> locations;
    map<int, vector<Edge>> adjList;
    
public:
    Graph();
    Graph(int numLocations);
    
    void addLocation(int id, string name, bool isHospital = false);
    void addEdge(int src, int dest, int weight);
    void addBidirectionalEdge(int loc1, int loc2, int weight);
    
    const Location* getLocation(int id) const;
    int getNumLocations() const;
    const map<int, vector<Edge>>& getAdjList() const;
    vector<int> getHospitalIds() const;
    
    void displayGraph() const;
};

#endif