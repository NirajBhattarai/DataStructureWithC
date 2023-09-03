# 10. Graphs (5 hrs)

## Introduction
- Introduction to the basic concept of graphs.
- Importance and applications of graphs in computer science.

## Graphs as an ADT
- Definition of Abstract Data Type (ADT) for graphs.
- Representation of graphs using ADT.

## Transitive Closure
- Concept of transitive closure in graph theory.
- Methods and algorithms for finding transitive closure.

## Warshall's Algorithm
- Introduction to Warshall's algorithm.
- Steps and implementation of Warshall's algorithm for transitive closure.

## Types of Graph
- Different classifications of graphs (e.g., directed, undirected, weighted, unweighted).
- Properties and characteristics of different types of graphs.

## Graph Traversal and Spanning Forests
- Techniques for traversing a graph (e.g., Depth-First Search, Breadth-First Search).
- Concept and applications of spanning forests.

## Kruskal's and Round-Robin Algorithms
- Introduction to Kruskal's algorithm for Minimum Spanning Trees.
- Steps and implementation of Kruskal's algorithm.
- Overview of Round-Robin algorithm and its applications.

## Shortest-path Algorithm
- Concept of shortest path in a graph.
- Algorithms to find the shortest path (Bellman-Ford, Floyd-Warshall).

## Greedy Algorithm
- Principles behind greedy algorithms.
- Applications of greedy algorithms in graph problems.

## Dijkstra's Algorithm
- Introduction to Dijkstra's shortest path algorithm.
- Steps and implementation of Dijkstra's algorithm.




## Introduction

### What is a Graph?
A graph is a collection of nodes (often called vertices) and edges that connect pairs of nodes. Graphs are a fundamental concept in computer science and mathematics, allowing for the representation of networks, relationships, and structures. 

### Why Study Graphs?
Graphs provide a universal model to represent and analyze complex systems, ranging from computer networks, social networks, molecular structures, transportation systems, to even language semantics. Understanding graphs and their properties helps in designing efficient algorithms for real-world problems.

### History of Graphs
The concept of graphs was first introduced in the 18th century by the famous mathematician Leonhard Euler. He solved the Königsberg bridge problem, leading to the inception of graph theory. The field has since grown and evolved, playing a pivotal role in various disciplines.

### Basic Terminology
- **Vertex (Plural: Vertices):** A point in the graph.
- **Edge:** A line connecting two vertices, signifying a relationship.
- **Adjacent:** Two vertices are adjacent if there's an edge connecting them.
- **Degree:** The number of edges connected to a vertex.
- **Path:** A sequence of vertices where each adjacent pair is connected by an edge.
- **Cycle:** A path that starts and ends at the same vertex.

### Graphs vs Trees
While both graphs and trees consist of vertices and edges, trees are a subset of graphs. Trees do not contain cycles and are connected, meaning there's exactly one path between every pair of vertices. In contrast, graphs can have cycles and might not always be connected.

### Applications of Graphs
- **Social Networks:** Representing people as vertices and relationships as edges.
- **Web Crawling:** Representing web pages as vertices and hyperlinks as edges.
- **Transportation Networks:** Representing cities as vertices and routes as edges.
- **Molecular Biology:** Representing molecules as vertices and bonds as edges.

Understanding the foundational principles of graphs sets the stage for diving deeper into various algorithms, types, and advanced applications that offer solutions to real-world problems.

# Graphs as an ADT

## What is an Abstract Data Type (ADT)?
An Abstract Data Type (ADT) is a specification of data types based on a set of operations that can be performed on the data, abstracting away the details of its implementation.

## Graph ADT
The Graph ADT provides an abstract view of a graph structure, focusing on the operations rather than its specific implementation. Here are the primary operations associated with the Graph ADT:

### 1. **addVertex(v)**
   - **Purpose:** Add a vertex `v` to the graph.
   - **Description:** Adds a new vertex to the graph.

### 2. **addEdge(v1, v2)**
   - **Purpose:** Add an edge between vertices `v1` and `v2`.
   - **Description:** Depending on the type of the graph (directed/undirected), it either adds an edge between `v1` and `v2` or a directed edge from `v1` to `v2`.

### 3. **removeVertex(v)**
   - **Purpose:** Remove vertex `v` from the graph.
   - **Description:** Removes the vertex and all associated edges.

### 4. **removeEdge(v1, v2)**
   - **Purpose:** Remove the edge between vertices `v1` and `v2`.
   - **Description:** Deletes the edge connecting `v1` and `v2`.

### 5. **getVertices()**
   - **Purpose:** Retrieve all vertices in the graph.
   - **Description:** Returns a collection of all vertices.

### 6. **getEdges()**
   - **Purpose:** Retrieve all edges in the graph.
   - **Description:** Returns a collection of all edges.

### 7. **isAdjacent(v1, v2)**
   - **Purpose:** Check if `v1` and `v2` are adjacent.
   - **Description:** Returns `true` if an edge exists between `v1` and `v2`; otherwise, `false`.

### 8. **getNeighbors(v)**
   - **Purpose:** Fetch all vertices adjacent to vertex `v`.
   - **Description:** Returns a collection of vertices connected to `v`.

## Representation of Graphs using ADT
The ADT defines the operations, but the graph can be represented in multiple ways:

### 1. **Adjacency Matrix:** 
A 2D array where the element at `matrix[i][j]` indicates the presence (or weight) of an edge between vertex `i` and vertex `j`.

### 2. **Adjacency List:** 
Each vertex has a list of its neighbors. This method is particularly efficient for sparse graphs.


# Transitive Closure

## Introduction

In graph theory, the concept of transitive closure deals with determining if a path exists between two vertices in a directed graph. If there's a path from vertex `u` to vertex `v`, then vertex `v` is transitively reachable from vertex `u`.

## Definition

For a directed graph, the transitive closure is a matrix `TC` where `TC[i][j]` is `1` (or `true`) if there's a path from vertex `i` to vertex `j`, otherwise `0` (or `false`).

## Importance

Understanding transitive closure helps in:

1. Determining the reachability of vertices in a graph.
2. Optimizing certain algorithms, especially those related to path-finding or connectivity problems.
3. Representing the flow of information or resources within networks.1