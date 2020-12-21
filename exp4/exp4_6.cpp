//
// Created by robos on 2020/12/5.
//
#include "../include/graph.hpp"

int main(){
  Mgraph m_graph_4_6;
  std::vector<int>data = {1, 2, 3, 4, 5, 6};
  std::vector<std::vector<int>> arcs{
      {INT_MAX, 31, INT_MAX, INT16_MAX, 21, 11},
      {31, INT_MAX, 7, 18, INT_MAX, 8},
      {INT_MAX, 7, INT_MAX, 12, INT_MAX, INT_MAX},
      {INT_MAX, 18, 12, INT_MAX, 29, 23},
      {21, INT_MAX, INT_MAX, 29, INT_MAX, 9},
      {11, 8, INT_MAX, 23, 9, INT_MAX}
  };
  m_graph_4_6.createGraph_(arcs, data, 6);
  m_graph_4_6.prim_(1);

  return 0;
}