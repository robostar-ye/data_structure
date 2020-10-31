//
// Created by robos on 2020/10/31.
//
#include "../include/stacks.hpp"
bool para_judge(){
  std::cout<<"请输入要输入的字符序列长度："<<std::endl;
  int size_char;
  std::cin>>size_char;
  char *char_arr = new char[size_char];
  LinkStack char_stack;
  for(int i = 0; i < size_char; i++){
    std::cout<<"请输入第"<<i + 1<<"个字符"<<std::endl;
    std::cin>>char_arr[i];
    char_stack.insertList(char_arr[i]);
  }

  for(int i = 0; i < size_char; i++){
    if(char_stack.getHead() != char_arr[i]){
      std::cout<<"不是一个回文"<<std::endl;
      return false;
    }
    char_stack.deleteList();
  }

  std::cout<<"是一个回文"<<std::endl;

  return true;
}


int main(){
  para_judge();

  return 0;
}