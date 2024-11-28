import java.io.*;
import java.util.*;

public class Dijkstra {
    public static void main(String[] args) throws IOException { //used throw because it was easier than try catch
        // Input and output files
        String inputFile = "cop3503-dijkstra-input.txt";
        String outputFile = "cop3503-dijkstra-output-Dellinger-william.txt";



        // Read input
        BufferedReader reader = new BufferedReader(new FileReader(inputFile));
        int numVertices = Integer.parseInt(reader.readLine().trim()); 
        int sourceVertex = Integer.parseInt(reader.readLine().trim()); 
        int numEdges = Integer.parseInt(reader.readLine().trim()); 



        // Build  graph
        Map<Integer, List<Edge>> graph = new HashMap<>();
        for (int i = 1; i <= numVertices; i++) {
            graph.put(i, new ArrayList<>());
        }

        for (int i = 0; i < numEdges; i++) {
            String[] edgeData = reader.readLine().trim().split(" "); 
            int u = Integer.parseInt(edgeData[0]); 
            int v = Integer.parseInt(edgeData[1]); 
            int weight = Integer.parseInt(edgeData[2]); 
            graph.get(u).add(new Edge(v, weight)); 
            graph.get(v).add(new Edge(u, weight)); 
        }
        reader.close();




        // Dijkstra's algorithm
        int[] distances = new int[numVertices + 1];
        int[] parents = new int[numVertices + 1];
        Arrays.fill(distances, Integer.MAX_VALUE);
        Arrays.fill(parents, -1);
        distances[sourceVertex] = 0;

        PriorityQueue<Vertex> pq = new PriorityQueue<>(Comparator.comparingInt(v -> v.distance));
        pq.add(new Vertex(sourceVertex, 0));

        while (!pq.isEmpty()) {
        Vertex current = pq.poll();
        int u = current.id;

        // Traverse neighbors
        for (Edge edge : graph.get(u)) {
        int v = edge.to;
        int newDist = distances[u] + edge.weight;

        // Update shortest path
        if (newDist < distances[v]) {
        distances[v] = newDist;
        parents[v] = u;
        pq.add(new Vertex(v, newDist));
    }
    }
    }






        // Write to output
    BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
    writer.write(numVertices + "\n");
    for (int i = 1; i <= numVertices; i++) {
    writer.write(i + " " + (distances[i] == Integer.MAX_VALUE ? -1 : distances[i]) + " " + parents[i] + "\n");
    }
    writer.close();
        
    }




    //edge class
    static class Edge {
    int to, weight;

    Edge(int to, int weight) {
    this.to = to;
    this.weight = weight;
        }
    }





    // Vertex class 
    static class Vertex {
    int id, distance;

     Vertex(int id, int distance) {
    this.id = id;
    this.distance = distance;
        }
    }
}
