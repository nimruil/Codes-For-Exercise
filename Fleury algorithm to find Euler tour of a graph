// C implementation

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int v1Connections[7] = {0, 1, 0, 0, 1, 1, 1};
int v2Connections[7] = {1, 0, 1, 1, 0, 0, 1};
int v3Connections[7] = {0, 1, 0, 1, 0, 0, 0};
int v4Connections[7] = {0, 1, 1, 0, 1, 0, 1};
int v5Connections[7] = {1, 0, 0, 1, 0, 1, 1};
int v6Connections[7] = {1, 0, 0, 0, 1, 0, 0};
int v7Connections[7] = {1, 1, 0, 1, 1, 0, 0};

int *AdjacencyArray(int input) {
  int *startingPointArray;

  switch (input) {
  case 1:
    startingPointArray = v1Connections;
    break;
  case 2:
    startingPointArray = v2Connections;
    break;
  case 3:
    startingPointArray = v3Connections;
    break;
  case 4:
    startingPointArray = v4Connections;
    break;
  case 5:
    startingPointArray = v5Connections;
    break;
  case 6:
    startingPointArray = v6Connections;
    break;
  case 7:
    startingPointArray = v7Connections;
    break;
  default:
    break;
  };
  return startingPointArray;
}

int DegreeOfVertex(int vertex) {
  int vertexDegree = 0, *vertexConnectionArray, i;

  vertexConnectionArray = AdjacencyArray(vertex);
  for (i = 0; i < 7; i++) {
    if (vertexConnectionArray[i] == 1)
      vertexDegree++;
  }
  return vertexDegree;
}

int DepthFirstSearch(int currentVertex, int visitedVertexArray[7]) {
  int counter = 0, i;
  visitedVertexArray[currentVertex - 1] = 1;
  counter++;
  for (i = 0; i < 7; i++) {
    // eger currentvertexten baska bir vertexe edge varsa ve bu ziyaret
    // edilmemis bir  vertex ise bu edge i toplama ekle, bir sonraki vertex e
    // bak
    if (AdjacencyArray(currentVertex)[i] != 0 && visitedVertexArray[i] != 1) {
      counter += DepthFirstSearch(i + 1, visitedVertexArray);
    }
  }
  return counter;
}
int FindLastEdge(int *array) {
  int finalVertex, i;
  for (i = 0; i < 7; i++) {
    if (*(array + i) == 1) {
      finalVertex = i + 1;
      break;
    }
  }
  return finalVertex;
}

int RemoveEdge(int currentVertex, int nextVertex) {
  AdjacencyArray(currentVertex)[nextVertex - 1] = 0;
  AdjacencyArray(nextVertex)[currentVertex - 1] = 0;
  return 0;
}

int AddEdge(int currentVertex, int nextVertex) {
  AdjacencyArray(currentVertex)[nextVertex - 1] = 1;
  AdjacencyArray(nextVertex)[currentVertex - 1] = 1;
  return 0;
}

int CheckEdgeValidity(int currentVertex, int nextVertex) {
  int counter = 0, i;
  // sonraki vertex son bagli vertex mi, eger oyleyse diger kontrolleri yapmaya
  // gerek yok
  int adjacentVertexArray[7];
  for (i = 0; i < 7; i++) {
    adjacentVertexArray[i] = AdjacencyArray(currentVertex)[i];
    if (*(adjacentVertexArray + i) != 0) {
      counter++;
    }
  }
  if (counter == 1)
    return 1;
  // current vertex den erisilebilen vertex sayisi
  int visitedVertexArray[7]; // if visited,A[i]<-1
  for (i = 0; i < 7; i++) {
    visitedVertexArray[i] = 0;
  }
  int counter1 = DepthFirstSearch(currentVertex, visitedVertexArray);
  // currentvertex-nextvertex edge ini gecici olarak cikar, sonra erisilebilen
  // vertex sayisini kontrol et
  RemoveEdge(currentVertex, nextVertex);
  for (i = 0; i < 7; i++) {
    visitedVertexArray[i] = 0;
  }
  int counter2 = DepthFirstSearch(currentVertex, visitedVertexArray);
  // currentvertex-nextvertex edge ini grafa geri ekle
  AddEdge(currentVertex, nextVertex);
  // eger counter1, counter2 den buyukse bu edge bir koprudur
  if (counter1 > counter2)
    return 0;
  else
    return 1;
}

void Fleury(int currentVertex) {
  int i, *connectionArray;
  if (DegreeOfVertex(currentVertex) == 0)
    return;
  connectionArray = AdjacencyArray(currentVertex);
  if (DegreeOfVertex(currentVertex) == 1) {
    int nextVertex = FindLastEdge(connectionArray);
    RemoveEdge(currentVertex, nextVertex);
    printf("Sonraki vertex = %d\n", nextVertex);
    Fleury(nextVertex);
  }
  for (i = 0; i < 7; i++) {
    if (connectionArray[i] != 0) {
      int a = CheckEdgeValidity(currentVertex, i + 1);
      if (a == 1)
        RemoveEdge(currentVertex, i + 1);
      printf("Sonraki vertex = %d\n", i + 1);
      Fleury(i + 1);
    }
  }
}

int main() {
  int startingPoint, i;
  int *startingPointArray = (int *)(malloc(7 * sizeof(int)));
  printf("Bu program G2 grafinda euler turunu gerceklestirmektedir.\n");
  printf("Baslangic noktasini seciniz (min. 1, max. 7): ");
  scanf("%d", &startingPoint);
  printf("Baslangic vertexi = %d\n", startingPoint);
  Fleury(startingPoint);
  printf("Euler turu tamamlandi.\n");
  free(startingPointArray);
  for (i = 1; i < 8; i++) {
    free(AdjacencyArray(i));
  }
  return 0;
}
