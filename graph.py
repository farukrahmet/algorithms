class Graph(object):
    _adj = {}

    def __init__(self):
        pass

    def add_adj(self, head_node, adj_node):
        if(head_node in self._adj):
            self._adj[head_node].append(adj_node)
        else:
            self._adj[head_node] = [adj_node]

    def drop_adj(self, head_node, adj_node):
        if(head_node not in self._adj):
            print("There is no node that named : %d" % (head_node))
        else:
            adj_list = self._adj[head_node]
            try:
                adj_list.pop(adj_list.index(adj_node))
                self._adj[head_node] = adj_list
            except ValueError:
                print("This node : %s not related with : %s" % (
                    adj_node, head_node))

    def show_graph(self):
        print(self._adj)

    def is_adjacent(self, head_node, adj_node, depth=0):
        # TODO
        pass

    def shortes_path(self, source_node, target_node):
        # TODO
        pass

    def is_there_loop(self):
        # TODO
        pass
