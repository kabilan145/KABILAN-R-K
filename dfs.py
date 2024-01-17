def dfs(graph,start,visited):
    if start not in visited:
        print(start,end="")
        visited.add(start)
        for neighbor in graph[start]:
            dfs(graph,neighbor,visited)
if __name__=="__main__":
    graph={
           "A": ["B", "C"],
        "B": ["A", "D", "E"],
        "C": ["A", "F"],
        "D": ["B"],
        "E": ["B", "F"],
        "F": ["C", "E"],
    }
    visited=set()
    print("dfs is in traverse:")
    dfs(graph,'A',visited)            

