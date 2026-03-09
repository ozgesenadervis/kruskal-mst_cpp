# kruskal-mst_cpp
Minimum Spanning Tree implementation using Kruskal's Algorithm in C++

# Project Description
This project implements Kruskal’s Algorithm to generate a Minimum Spanning Tree (MST) for a weighted graph.
The goal is to determine the minimum-cost network (fiber optic cable laying) that connects all nodes without forming cycles.

The system models a communication network where nodes represent network points and edges represent possible connections with associated costs. The algorithm selects the least expensive edges while ensuring that all nodes remain connected. 

# Concepts and Data Structures Used
Graph Data Structure
Disjoint Set Union (Union-Find)
Path Compression
Union by Rank
Greedy Algorithm

The Disjoint Set Union structure is used to keep track of connected components and prevent cycle formation while building the MST. 

# Algorithm Steps
1. All edges are sorted in ascending order based on cost.
2. Each vertex is initially placed in its own set.
3. Edges are processed one by one.
4. If an edge connects two different sets, it is added to the MST.
5. The sets are merged using Union-Find.
6. The process continues until V − 1 edges are selected. 

# Programming Language
C++

# Author
Özge Sena Derviş
Computer Engineering Student
