#include "EmergencyDispatchSystem.h"
#include <iostream>
#include <map>
using namespace std;

void displayMenu() {
    cout << "===== Emergency Dispatch System Menu =====" << endl;
    cout << "1. Use Pre-defined City Map" << endl;
    cout << "2. Exit" << endl;
    cout << "==========================================" << endl;
    cout << "Enter choice: ";
}

Graph* createPredefinedMap() {
    Graph* graph = new Graph(18);
    
    // Add locations (id, name, isHospital)
    graph->addLocation(0, "Downtown", false);
    graph->addLocation(1, "Residential Area North", false);
    graph->addLocation(2, "Residential Area South", false);
    graph->addLocation(3, "City Hospital", true);
    graph->addLocation(4, "Industrial Zone East", false);
    graph->addLocation(5, "Industrial Zone West", false);
    graph->addLocation(6, "Shopping District", false);
    graph->addLocation(7, "Medical Center", true);
    graph->addLocation(8, "University", false);
    graph->addLocation(9, "Airport", false);
    graph->addLocation(10, "Sports Complex", false);
    graph->addLocation(11, "Park District", false);
    graph->addLocation(12, "Emergency Hospital", true);
    graph->addLocation(13, "Business District", false);
    graph->addLocation(14, "Suburban Area", false);
    graph->addLocation(15, "Train Station", false);
    graph->addLocation(16, "Community Health Center", true);
    graph->addLocation(17, "Waterfront District", false);
    
    // Add bidirectional roads (location1, location2, distance)
    // Downtown connections
    graph->addBidirectionalEdge(0, 1, 4);   // Downtown <-> Residential North
    graph->addBidirectionalEdge(0, 2, 5);   // Downtown <-> Residential South
    graph->addBidirectionalEdge(0, 4, 7);   // Downtown <-> Industrial East
    graph->addBidirectionalEdge(0, 6, 3);   // Downtown <-> Shopping District
    graph->addBidirectionalEdge(0, 13, 2);  // Downtown <-> Business District
    
    // Residential North connections
    graph->addBidirectionalEdge(1, 3, 3);   // Residential North <-> City Hospital
    graph->addBidirectionalEdge(1, 8, 6);   // Residential North <-> University
    graph->addBidirectionalEdge(1, 11, 4);  // Residential North <-> Park District
    graph->addBidirectionalEdge(1, 14, 5);  // Residential North <-> Suburban Area
    
    // Residential South connections
    graph->addBidirectionalEdge(2, 7, 4);   // Residential South <-> Medical Center
    graph->addBidirectionalEdge(2, 10, 6);  // Residential South <-> Sports Complex
    graph->addBidirectionalEdge(2, 14, 3);  // Residential South <-> Suburban Area
    
    // City Hospital connections
    graph->addBidirectionalEdge(3, 7, 5);   // City Hospital <-> Medical Center
    graph->addBidirectionalEdge(3, 8, 4);   // City Hospital <-> University
    graph->addBidirectionalEdge(3, 11, 3);  // City Hospital <-> Park District
    
    // Industrial East connections
    graph->addBidirectionalEdge(4, 5, 6);   // Industrial East <-> Industrial West
    graph->addBidirectionalEdge(4, 6, 4);   // Industrial East <-> Shopping District
    graph->addBidirectionalEdge(4, 9, 9);   // Industrial East <-> Airport
    graph->addBidirectionalEdge(4, 15, 7);  // Industrial East <-> Train Station
    
    // Industrial West connections
    graph->addBidirectionalEdge(5, 9, 8);   // Industrial West <-> Airport
    graph->addBidirectionalEdge(5, 17, 5);  // Industrial West <-> Waterfront District
    
    // Shopping District connections
    graph->addBidirectionalEdge(6, 7, 4);   // Shopping District <-> Medical Center
    graph->addBidirectionalEdge(6, 13, 3);  // Shopping District <-> Business District
    graph->addBidirectionalEdge(6, 15, 5);  // Shopping District <-> Train Station
    
    // Medical Center connections
    graph->addBidirectionalEdge(7, 8, 3);   // Medical Center <-> University
    graph->addBidirectionalEdge(7, 12, 6);  // Medical Center <-> Emergency Hospital
    graph->addBidirectionalEdge(7, 16, 5);  // Medical Center <-> Community Health Center
    
    // University connections
    graph->addBidirectionalEdge(8, 9, 8);   // University <-> Airport
    graph->addBidirectionalEdge(8, 11, 4);  // University <-> Park District
    graph->addBidirectionalEdge(8, 12, 7);  // University <-> Emergency Hospital
    
    // Airport connections
    graph->addBidirectionalEdge(9, 15, 6);  // Airport <-> Train Station
    graph->addBidirectionalEdge(9, 17, 4);  // Airport <-> Waterfront District
    
    // Sports Complex connections
    graph->addBidirectionalEdge(10, 12, 5); // Sports Complex <-> Emergency Hospital
    graph->addBidirectionalEdge(10, 14, 4); // Sports Complex <-> Suburban Area
    
    // Park District connections
    graph->addBidirectionalEdge(11, 14, 6); // Park District <-> Suburban Area
    
    // Emergency Hospital connections
    graph->addBidirectionalEdge(12, 16, 4); // Emergency Hospital <-> Community Health Center
    
    // Business District connections
    graph->addBidirectionalEdge(13, 15, 3); // Business District <-> Train Station
    graph->addBidirectionalEdge(13, 17, 4); // Business District <-> Waterfront District
    
    // Suburban Area connections
    graph->addBidirectionalEdge(14, 16, 5); // Suburban Area <-> Community Health Center
    
    // Train Station connections
    graph->addBidirectionalEdge(15, 17, 5); // Train Station <-> Waterfront District
    
    return graph;
}

void runDispatchSystem(Graph* graph) {
    if (!graph) {
        cout << "Error: No valid graph!" << endl;
        return;
    }
    
    // Display the city map
    graph->displayGraph();
    
    // Create dispatch system
    EmergencyDispatchSystem dispatcher(graph);
    
    // Get emergency location from user
    int emergencyId;
    cout << "Enter the ID of the emergency location: ";
    cin >> emergencyId;
    
    if (emergencyId < 0 || emergencyId >= graph->getNumLocations()) {
        cout << "Invalid location ID!" << endl;
        return;
    }
    
    // Dispatch emergency services
    dispatcher.dispatch(emergencyId);
    
    // Optional: Show all distances
    char showAll;
    cout << "Would you like to see distances to all locations? (y/n): ";
    cin >> showAll;
    
    if (showAll == 'y' || showAll == 'Y') {
        map<int, int> parents;
        map<int, int> distances = dispatcher.dijkstra(emergencyId, parents);
        dispatcher.displayAllDistances(emergencyId, distances);
    }
}

int main() {
    cout << "**************************************************" << endl;
    cout << "   EMERGENCY DISPATCH SYSTEM - Version 1.0" << endl;
    cout << "**************************************************" << endl;
    
    Graph* graph = nullptr;
    int choice;
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "\nLoading pre-defined city map..." << endl;
                graph = createPredefinedMap();
                runDispatchSystem(graph);
                delete graph;
                graph = nullptr;
                break;
                
            case 2:
                cout << "\nExiting Emergency Dispatch System. Stay safe!" << endl;
                if (graph) delete graph;
                return 0;
                
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}