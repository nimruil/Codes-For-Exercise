// C implementation
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define VERTEXCOUNT 12

const int Graph[VERTEXCOUNT][VERTEXCOUNT] = {
    {0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}};
int VisitedVertices[12] = {0};

int DepthFirstSearch(int);
int FindConnectedComponents();

int main() {
  FindConnectedComponents(Graph);
  return 0;
}

int FindConnectedComponents(int matrix[VERTEXCOUNT][VERTEXCOUNT]) {
  int componentCount = 0, i, j;
  for (i = 0; i < VERTEXCOUNT; i++) {
    if (VisitedVertices[i] == 0) {
      DepthFirstSearch(i);
      componentCount++;
    }
  }
  printf("Component Count = %d\n", componentCount);
  return 0;
}

int DepthFirstSearch(int currentVertex) {
  int i;
  VisitedVertices[currentVertex] = 1;
  printf("Marked node = %d\n", currentVertex + 1);
  for (i = 0; i < VERTEXCOUNT; i++) {
    if (Graph[currentVertex][i] == 1 && VisitedVertices[i] == 0)
      DepthFirstSearch(i);
  }
  return 0;
}
