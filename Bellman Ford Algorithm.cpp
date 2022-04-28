#include <bits/stdc++.h>
struct data_of_Edge {
   int source_of_edge, destination_of_edge, weight_of_edge;
};
struct Graph_of_BellmanFord {
   int Vertices, Edges;
   struct data_of_Edge* edge;
};
struct Graph_of_BellmanFord* createGraph_for_BellmanFord(int Vertices, int Edges) {
   struct Graph_of_BellmanFord* g = new Graph_of_BellmanFord;
   g->Vertices = Vertices;
   g->Edges = Edges;
   g->edge = new data_of_Edge[Edges];
   return g;
}
void function_of_BellmanFord_Algo(struct Graph_of_BellmanFord* graph, int source_of_edge) {
   int Vertices = graph->Vertices;
   int Edges = graph->Edges;
   int distance[Vertices];
   for (int x = 0; x < Vertices; x++)
      distance[x] = INT_MAX;
      distance[source_of_edge] = 0;
   for (int x = 1; x <= Vertices - 1; x++) {
      for (int y = 0; y < Edges; y++) {
         int m = graph->edge[y].source_of_edge;
         int Vertices = graph->edge[y].destination_of_edge;
         int weight_of_edge = graph->edge[y].weight_of_edge;
         if (distance[m] != INT_MAX && distance[m] + weight_of_edge < distance[Vertices])
         distance[Vertices] = distance[m] + weight_of_edge;
      }
   }
   for (int x = 0; x < Edges; x++) {
      int m = graph->edge[x].source_of_edge;
      int Vertices = graph->edge[x].destination_of_edge;
      int weight_of_edge = graph->edge[x].weight_of_edge;
      if (distance[m] != INT_MAX && distance[m] + weight_of_edge < distance[Vertices]) {
         printf("Graph contains negative weight_of_edge cycle");
         return;
      }
   }
   printf("Vertex :\t\t\t ");
   for (int x = 0; x < Vertices; ++x)
      printf("%d \t", x);
      printf("\nDistance From source_of_edge : ");
   for (int x = 0; x < Vertices; ++x)
      printf("%d \t",distance[x]);
   return;
}
int main() {
   int Vertices = 8;
   int Edges = 8;
   struct Graph_of_BellmanFord* g = createGraph_for_BellmanFord(Vertices, Edges);
   g->edge[0].source_of_edge = 0;
   g->edge[0].destination_of_edge = 1;
   g->edge[0].weight_of_edge = -2;


   g->edge[1].source_of_edge = 0;
   g->edge[1].destination_of_edge = 3;
   g->edge[1].weight_of_edge = 5;

   g->edge[2].source_of_edge = 0;
   g->edge[2].destination_of_edge = 5;
   g->edge[2].weight_of_edge = -3;

   g->edge[3].source_of_edge = 1;
   g->edge[3].destination_of_edge = 4;
   g->edge[3].weight_of_edge = 1;

   g->edge[4].source_of_edge = 3;
   g->edge[4].destination_of_edge = 7;
   g->edge[4].weight_of_edge = -2;

   g->edge[5].source_of_edge = 2;
   g->edge[5].destination_of_edge = 6;
   g->edge[5].weight_of_edge = 5;

   g->edge[6].source_of_edge = 5;
   g->edge[6].destination_of_edge = 2;
   g->edge[6].weight_of_edge = 1;

   g->edge[7].source_of_edge = 4;
   g->edge[7].destination_of_edge = 3;
   g->edge[7].weight_of_edge = -3;

   function_of_BellmanFord_Algo(g, 0);
   return 0;
}
