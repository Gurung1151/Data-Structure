# Team-Project
It is a team project for the Data Structure and Algorithm. In this project, we have shown the Prim's Algorithm and Bubble sort using C++ and SDL for simple graphics and animation.

## Prim's Algorithm
Prim's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected weighted graph. A minimum spanning tree is a tree that spans all the vertices of the graph with the minimum total weight.
Here's how Prim's algorithm works:

1. Initialize an empty set MST to store the edges of the minimum spanning tree.
2. Choose an arbitrary vertex v from the graph and add it to the MST set.
3. While the MST set does not contain all the vertices:
    a. Find the minimum-weight edge (u, v) such that u is in the MST set and v is not.
    b. Add the edge (u, v) to the MST set.
    c. Add vertex v to the MST set.
4.Return the MST set, which represents the minimum spanning tree of the graph.

## Bubble sort
Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The process is repeated until the list is sorted.

Here's how the bubble sort algorithm works:

1. Start with an unsorted list of elements.
2. Compare the first element with the second element. If the first element is greater than the second element, swap them.
3. Move to the next pair of adjacent elements and perform the same comparison and swap if necessary.
4. Continue this process, comparing and swapping adjacent elements, until you reach the end of the list.
5. Once you reach the end of the list, the largest element will be in its correct position at the end.
6. Repeat steps 2-5 for the remaining unsorted elements (excluding the last element, which is already in its correct position).
7. Continue this process, reducing the number of unsorted elements by one each time, until the entire list is sorted.

