def bfs(graph, start):
    visited = set()
    queue = []
    visited.add(start)
    queue.append(start)
    while queue:
        node = queue.pop(0)
        print(node, end=' ')
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
# Example usage:
if __name__ == "__main__":
    graph = {0: [1, 2],1: [2],2: [0, 3],3: [3]}
    print("Breadth-First Traversal (starting from vertex 2):")
    bfs(graph, 2)