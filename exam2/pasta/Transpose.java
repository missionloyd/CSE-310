import java.util.*;
  
class Graph
{
    // Edit number of vertices here
    private static int vertices = 8;
    
    private static ArrayList<Integer>[] adj = new ArrayList[vertices];
   
    private static ArrayList<Integer>[] tr = new ArrayList[vertices];
  
    public static void addedge(int u, int v, boolean choice)
    {
        if(!choice)
            adj[u].add(v);
        else
            tr[u].add(v);
    }
  
    public static void printGraph()
    {
        for(int i = 0; i < vertices; i++)
        {
            System.out.print(i + "--> ");
            for(int j = tr[i].size()-1; j >= 0; j--)
                System.out.print(tr[i].get(j) + " ");
            System.out.println();
        }
    }
    
    public static void printGraphO()
    {
        for(int i = 0; i < vertices; i++)
        {
            System.out.print(i + "--> ");
            for(int j = 0; j < adj[i].size(); j++)
                System.out.print(adj[i].get(j) + " ");
            System.out.println();
        }
    }
  
    public static void getTranspose()
    {
        for(int i = 0; i < vertices; i++)
            for(int j = 0; j < adj[i].size(); j++)
                addedge(adj[i].get(j), i, true);
    }
  
    public static void main (String[] args) throws java.lang.Exception
    {
        for(int i = 0; i < vertices; i++)
        {
            adj[i] = new ArrayList<Integer>();
            tr[i] = new ArrayList<Integer>();
        }
        addedge(0, 2, false);
        addedge(1, 0, false);
        addedge(1, 3, false);
        addedge(2, 1, false);
        addedge(3, 2, false);
        addedge(4, 1, false);
        addedge(4, 6, false);
        addedge(5, 2, false);
        addedge(5, 4, false);
        addedge(5, 7, false);
        addedge(6, 7, false);
        addedge(7, 4, false);
        
        //This prints out the original graph
        printGraphO();
        System.out.println();
        
        getTranspose();
          
        // This prints out the transposed graph
        printGraph();
    }
}