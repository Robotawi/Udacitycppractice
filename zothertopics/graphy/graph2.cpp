//
// Created by zozo on 2/5/20.
//

#include <utility>
#include <boost/graph/adjacency_list.hpp>
#include <iostream>

int main(){
    boost::adjacency_list<> g;

    boost::add_vertex(g);
    boost::add_vertex(g);
    boost::add_vertex(g);
    boost::add_vertex(g);

    //returns a pair of iterators to the start and the end
    std::pair<boost::adjacency_list<>::vertex_iterator, boost::adjacency_list<>::vertex_iterator> vs1 = boost::vertices(g);

    std::pair<boost::adjacency_list<>::vertex_iterator, boost::adjacency_list<>::vertex_iterator> vs2 = boost::vertices(g);

    std::copy(vs2.first, vs2.second,std::ostream_iterator<boost::adjacency_list<>::vertex_descriptor> {std::cout, "\n"});


}