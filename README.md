# RRT Visualizer
RRT (Rapidly-expanding Random Trees) is a random sampling method of path finding. To avoid the complex mathematical definition, this is how the algorithm works (at its most basic form):
1. Given: A continuous space with boundaries, a start and end point, and function for determining if a given point is an obstacle or not.
2. Randomly choose a point in the space, and scale its distance to distance *n* from the nearest previously-discovered point. If it is not valid (inside an obstacle), repeat (2).
3. If it is valid, connect it to the the nearest point (building a graph data structure). 
4. If the chosen point is within distance *n* to the end point, connect it to the end and trace back to the start node. If not, go back to (2)
5. Run graph search on the new graph.

Future Extensions:
- Two RRT trees growing from each end, with the goal of connecting the trees
- Introducing bias to the random sampling of nodes, to "nudge" the tree towards the end point
- RRT*, an optimized version of RRT that is mathematically proven to provide an optimal solution as the @ of samples tends towards infinity
  - Records distance from the start node, connects a new node to the neighbor (within a fixed radius) with the smallest distance (think of distance as a cost function)
  - Rewires the tree by re-establishing connections of its neighbors (within a fixed radius) to maintain a minimal distance/cost for each of the neighbors.
- Integrate C++ and MATLAB for inter-process communication.
- Visual, interactive creation of the obstacles, step-by-step playback with UI controls, or learning how the algorithm functions by allowing the user to select a point and see how the RRT algorithm connects it to the graph.

## Project Structure
This project is intended to be split into different parts, primarily for ease of development. 

1. Input file: describes the geometry of the space to explore, the start and end node positions, and the gemeotry of the obstacles involved.
2. C++ code: Reads in the input file, runs the RRT algorithm, and outputs an intermediate file 
3. Intermediate file: contains a) the position of the obstacles and b) the position of the nodes/edges of the RRT graph during each iteration
   -  The eventual goal is for this to be abstracted away, and for C++ to communicate directly with the MATLAB process, but the intermediate file solution is simpler for the time being.
4. MATLAB: Reads in the intermediate file, and plots the state of the RRT algorithm during each iteration, and can export as a video file.

## Development
- Developed on a Linux machine w/ `g++` & `gdb` installed
- To debug: use VSCode's Run & Debug (already created `tasks.json` and `launch.json`)
- To build: `g++ src/cpp/main.cpp -o out/main.out`
  - TODO: use Makefiles to compile multiple files
- To run: `./out/main.out`