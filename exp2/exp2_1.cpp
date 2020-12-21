//
// Created by robos on 2020/10/31.
//
#include "../include/stacks.hpp"

int main(){
  int nums;

  //! TEST
//  LinkStack test;
//  test.insert('1');
//  test.insert('2');
//  test.insert('3');
//  test.insert('4');
//  test.insert('A');
//  test.show();

  std::cout<<"请输入要转换的十进制数:"<<std::endl;
  std::cin>>nums;
  LinkStack target_2 = scaleChange(nums, 2);
  std::cout<<"转换后的二进制为"<<std::endl;
  target_2.show();
  LinkStack target_8 = scaleChange(nums, 8);
  std::cout<<"转换后的八进制为"<<std::endl;
  target_8.show();
  LinkStack target_16 = scaleChange(nums, 16);
  std::cout<<"转换后的十六进制为"<<std::endl;
  target_16.show();

  return 0;
}