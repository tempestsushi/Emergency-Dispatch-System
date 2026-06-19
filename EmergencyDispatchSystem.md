EmergencyDispatch-System
Project Title:

Emergency Dispatch System

ID | Name

24K-2532 Bazyl Sheikh
24K-2519 Umer Hafeez Siddiqui

**Introduction**

Our project is an Emergency Dispatch System designed to locate the nearest hospital from an emergency location using Dijkstra’s Algorithm. The system represents a city map as a graph, where intersections are nodes and roads are edges with distances or travel times as weights. When an emergency call is received, the algorithm efficiently calculates the shortest path to the closest hospital, ensuring that ambulances can reach patients in the minimum possible time. This project demonstrates the real-world application of graph theory, greedy algorithms, and efficient data structures in solving time-critical problems.

**Description**

Represent the city as a weighted graph, where nodes are locations (intersections, hospitals, emergency sites) and edges are roads with distance/time weights.

Implement Dijkstra’s Algorithm to find the shortest route between the emergency site and all hospitals.

Determine which hospital is nearest based on total travel distance or time.

Display the shortest route (sequence of nodes) and total distance on the console.

Allow users to input a custom map (number of locations, connections, and weights).

(Optional) Compare performance with A* algorithm or visualize the path.

**Data Structures that will be used

Data Structure Usage Purpose**

Graph (Adjacency List) To store all locations (nodes) and roads (edges) with weights. Efficiently represent city connections. Priority Queue / Min Heap Used inside Dijkstra’s algorithm. To pick the next node with the smallest tentative distance quickly. Array / Hash Map (Distance Table) Stores shortest known distances from source to all nodes. Keeps track of minimum distances while exploring. Set / Boolean Array To mark visited nodes. Prevents re-processing of already finalized nodes. Parent Map / Array To reconstruct the shortest path from source to hospital. Helps print the actual route taken. Queue (optional) For comparison with BFS or initial graph setup. Alternative for unweighted graph testing.
