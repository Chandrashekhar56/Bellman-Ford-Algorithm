class Graph_for_BellmanFord:

	def __init__(self, totalvertices):
		self.TotalVertices = totalvertices
		self.graph = []
		
	def add_new_Edge(self, source, destination, weight):
		self.graph.append([source,destination ,weight])
		
	def display(self, distance):
		print("Vertex Distance from Source")
		for x in range(self.TotalVertices):
			print("{0}\t\t{1}".format(x, distance[x]))
	
	def function_of_BellmanFord_Algo(self, source_vertex):

		distance = [float("Inf")] * self.TotalVertices
		distance[source_vertex] = 0

		for _ in range(self.TotalVertices - 1):
			for source, destination,weight in self.graph:
				if distance[source] != float("Inf") and distance[source] +weight < distance[destination]:
						distance[destination] = distance[source] + weight

		for source, destination, weight in self.graph:
				if distance[source] != float("Inf") and distance[source] + weight  < distance[destination]:
						print("Graph contains negative weight cycle")
						return
		self.display(distance)

g1 = Graph_for_BellmanFord(8)
g1.add_new_Edge(0, 1, -2)
g1.add_new_Edge(1, 3, -5)
g1.add_new_Edge(2, 5, 3)
g1.add_new_Edge(3, 4, -1)
g1.add_new_Edge(4, 7, -2)
g1.add_new_Edge(5, 6, 5)
g1.add_new_Edge(6, 2, -1)
g1.add_new_Edge(7, 3, 3)

g1.function_of_BellmanFord_Algo(0)

