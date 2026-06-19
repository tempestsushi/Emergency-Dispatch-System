# Emergency Dispatch System

A console-based C++ emergency dispatch simulator that finds the nearest hospital from an emergency location using Dijkstra's shortest path algorithm.

The city is represented as a weighted graph. Locations are graph nodes, roads are weighted edges, and hospitals are marked locations inside the graph. When the user enters an emergency location ID, the system calculates the shortest distance to every hospital and displays the nearest reachable hospital with the route to get there.

## Features

- Predefined city map with 18 locations
- Multiple hospital locations
- Weighted road connections using an adjacency list
- Dijkstra's algorithm with a priority queue
- Nearest-hospital detection
- Shortest-route reconstruction
- Optional display of distances from the emergency location to all other locations
- Modular object-oriented C++ design

## Tech Used

- C++
- Standard Template Library containers:
  - `map`
  - `vector`
  - `priority_queue`
- Graph data structure using an adjacency list
- Dijkstra's shortest path algorithm

No JavaScript framework or frontend library is used in this repository. This project is currently a C++ console application.

## Project Structure

```text
Emergency-Dispatch-System/
├── EmergencyDispatchSystem.cpp
├── EmergencyDispatchSystem.h
├── Graph.cpp
├── Graph.h
├── Location.cpp
├── Location.h
├── main.cpp
├── LICENSE
└── README.md
```

## How It Works

1. The program loads a predefined city map.
2. Each city location is stored as a `Location`.
3. Roads between locations are stored in the `Graph` adjacency list.
4. The user enters the ID of the emergency location.
5. `EmergencyDispatchSystem` runs Dijkstra's algorithm from that location.
6. The system compares the shortest distances to all hospitals.
7. The nearest hospital and shortest route are displayed in the console.

## Requirements

- A C++ compiler with C++11 support or newer
- Windows, macOS, or Linux terminal

Recommended compilers:

- `g++`
- `clang++`
- Microsoft Visual C++ compiler

## Build

Using `g++`:

```bash
g++ main.cpp Location.cpp Graph.cpp EmergencyDispatchSystem.cpp -o emergency_dispatch -std=c++11
```

Using `clang++`:

```bash
clang++ main.cpp Location.cpp Graph.cpp EmergencyDispatchSystem.cpp -o emergency_dispatch -std=c++11
```

On Windows, the generated executable may be named:

```bash
emergency_dispatch.exe
```

## Run

Linux/macOS:

```bash
./emergency_dispatch
```

Windows PowerShell:

```powershell
.\emergency_dispatch.exe
```

## Menu

```text
1. Use Pre-defined City Map
2. Exit
```

After selecting the predefined map, enter a location ID when prompted. The program prints:

- Emergency location
- Nearest hospital
- Total distance
- Shortest route
- Optional distances to all locations

## Core Classes

### `Location`

Stores a place in the city map.

- Location ID
- Location name
- Hospital status

### `Graph`

Stores the city map.

- Locations
- Road connections
- Edge weights
- Hospital lookup

### `EmergencyDispatchSystem`

Handles the dispatch logic.

- Runs Dijkstra's algorithm
- Finds the nearest hospital
- Reconstructs the shortest path
- Displays dispatch results

## Algorithm

The system uses Dijkstra's algorithm to calculate the shortest known distance from the emergency location to every other location in the city graph.

Complexity:

- Time: `O((V + E) log V)`
- Space: `O(V + E)`

Where:

- `V` is the number of locations
- `E` is the number of road connections

## Example Flow

```text
1. Use Pre-defined City Map
Enter the ID of the emergency location: 0
```

The system then displays the closest hospital, total route distance, and the ordered path from the emergency location to the hospital.

## Future Improvements

- Add custom city map input
- Save and load maps from files
- Add one-way road support
- Add traffic-aware road weights
- Add A* pathfinding for comparison
- Build a visual map interface

## Authors

- Umer Hafeez
- Bazyl Sheikh

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
