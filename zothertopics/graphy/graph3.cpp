//
// Created by zozo on 2/5/20.
//

#include <boost/graph/adjacency_list.hpp>
#include <iostream>
typedef boost::adjacency_list<>::edge_iterator edge_iterator;
typedef boost::adjacency_list<>::edge_descriptor edge_descriptor;


int main (){
    boost::adjacency_list<> g;

    boost::adjacency_list<>::vertex_descriptor v1 = boost::add_vertex(g);
    boost::adjacency_list<>::vertex_descriptor v2 = boost::add_vertex(g);
    boost::adjacency_list<>::vertex_descriptor v3 = boost::add_vertex(g);
    boost::adjacency_list<>::vertex_descriptor v4 = boost::add_vertex(g);
    boost::adjacency_list<>::vertex_descriptor v5 = boost::add_vertex(g);
    boost::adjacency_list<>::vertex_descriptor v6 = boost::add_vertex(g);
    boost::adjacency_list<>::vertex_descriptor v7 = boost::add_vertex(g);
    boost::adjacency_list<>::vertex_descriptor v8 = boost::add_vertex(g);

    std::pair<boost::adjacency_list<>::edge_descriptor, bool> p1 = boost::add_edge(v1, v2, g);
    std::pair<boost::adjacency_list<>::edge_descriptor, bool> p2 = boost::add_edge(v1, v3, g);
    std::pair<boost::adjacency_list<>::edge_descriptor, bool> p3 = boost::add_edge(v2, v5, g);
    std::pair<boost::adjacency_list<>::edge_descriptor, bool> p4 = boost::add_edge(v2, v4, g);
    std::pair<boost::adjacency_list<>::edge_descriptor, bool> p5 = boost::add_edge(v3, v2, g);
    std::pair<boost::adjacency_list<>::edge_descriptor, bool> p6 = boost::add_edge(v5, v6, g);
    std::cout << p1.second << std::endl;

    std::pair<edge_iterator, edge_iterator> edges = boost::edges(g);
    std::copy(edges.first, edges.second, std::ostream_iterator<boost::adjacency_list<>::edge_descriptor>(std::cout, "\n"));
}