//
// Created by robos on 2020/10/29.
//

#include "../include/trees.hpp"

int main(){
  std::cout<<"请输入前序/中序的长度(int)"<<std::endl;
  int size_temp_1;
  std::cin>>size_temp_1;
  char *arr_pre = new char[size_temp_1];
  char *arr_infix = new char[size_temp_1];

  std::cout<<"请输入前序数组"<<std::endl;
  for(int i = 0; i < size_temp_1; i++){
    std::cin>>arr_pre[i];
  }

  std::cout<<"请输入中序数组"<<std::endl;
  for(int i = 0; i < size_temp_1; i++){
    std::cin>>arr_infix[i];
  }

  BinaryTree binary_tree_temp;
  binary_tree_temp.build_by_pre_and_infix(arr_pre, arr_infix, size_temp_1);
}