# Emergency Dispatch System

## Overview
The Emergency Dispatch System is a C++ application that simulates routing an emergency to the nearest hospital using graph algorithms. A city is modeled as a weighted graph where locations are nodes and roads are edges with distances.

The system uses Dijkstra’s Algorithm to determine the shortest path from an emergency location to the nearest hospital.

---

## Features
- Graph-based city representation  
- Shortest path calculation using Dijkstra’s Algorithm  
- Automatic nearest hospital detection  
- Path reconstruction from source to destination  
- Support for predefined and custom city maps  
- Modular and object-oriented design  

---
```
## Project Structure
emergency-dispatch-system/
│
├── Location.h
├── Location.cpp
├── Graph.h
├── Graph.cpp
├── EmergencyDispatchSystem.h
├── EmergencyDispatchSystem.cpp
├── main.cpp
└── README.md
```

---

## Requirements
- C++ compiler with C++11 support (GCC or Clang)  
- Standard libraries: iostream, vector, map, queue, string, algorithm  

---

## Compilation

### Using g++
g++ -o emergency_dispatch main.cpp Location.cpp Graph.cpp EmergencyDispatchSystem.cpp -std=c++11


### Using clang++
clang++ -o emergency_dispatch main.cpp Location.cpp Graph.cpp EmergencyDispatchSystem.cpp -std=c++11


---

## Usage
Run the executable:
./emergency_dispatch


### Menu Options
1. Predefined city map  
2. Custom city map  
3. Exit  

After selecting a map, enter the emergency location ID. The system will display:
- Nearest hospital  
- Total distance  
- Shortest route  

---

## Algorithm
The system uses Dijkstra’s Algorithm with a priority queue (min-heap).

- Time Complexity: O((V + E) log V)  
- Space Complexity: O(V)  

---

## Example
**Input:**
- Emergency location: 0  

**Output:**
- Nearest hospital  
- Total distance  
- Path from source to hospital  

---

## Future Improvements
- A* pathfinding  
- Real-time traffic weights  
- One-way road support  
- Map visualization  
- File-based map storage  

---

## Authors
- Umer Hafeez  
- Bazyl Sheikh  

---

## License
This project is licensed under the MIT License.
