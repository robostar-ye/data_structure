//
// Created by robos on 2020/12/5.
//
#include "../include/graph.hpp"

int main(){
  Mgraph exp_4_8;
  std::vector<int> data{1, 2, 3, 4, 5, 6};
  std::vector<std::vector<int>> arcs{
      {100, 8, 100, 100, 100, 100},
      {100, 100, 100, 100, 100, 13},
      {100, 7, 100, 100, 100, 100},
      {100, 18, 12, INT_MAX, 100, 100},
      {8, 100, 100, 6, 100, 100},
      {100, 100, 100, 19, 12, 100}
  };
  exp_4_8.createGraph_(arcs, data, 6);
  int dis[100];
  exp_4_8.Dijstra_(3, dis);

  return 0;
}