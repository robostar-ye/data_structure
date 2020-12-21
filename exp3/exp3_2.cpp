//
// Created by robos on 2020/11/30.
//
#include <iostream>

//! 效率最高
char judgeProductivenessMax(int score){
  if(score >=80 && score <= 89) {
    std::cout<<"深度：2"<<std::endl;
    return 'B';
  }
  else {
    if (score >= 70 && score <= 79){
      std::cout<<"深度：3"<<std::endl;
      return 'C';
    }
    else {
      if (score >= 90){
        std::cout<<"深度：4"<<std::endl;
        return 'A';
      }
      else{
        if(score <= 59) {
          std::cout<<"深度：5"<<std::endl;
          return 'E';
        }
        else{
          std::cout<<"深度：5"<<std::endl;
          return 'D';
        }
      }
    }
  }
}

//!层数最小
char judgeHeightMin(int score){
  if(score <= 79){
    if(score <=  69){
      if(score <= 59){
        std::cout<<"深度：4"<<std::endl;
        return 'E';
      }
      else {
        std::cout<<"深度：4"<<std::endl;
        return 'D';
      }
    }
    else {
      std::cout<<"深度：3"<<std::endl;
      return 'C';
    }
  }else{
    if(score <= 89){
      std::cout<<"深度：3"<<std::endl;
      return 'B';
    }
    else {
      std::cout<<"深度：3"<<std::endl;
      return 'A';
    }
  }
}

int main(){
  std::cout<<"请输入分数（0-100）："<<std::endl;
  int  score = -1;
  std::cin>>score;
  std::cout<<"效率最大结果："<<std::endl<<judgeProductivenessMax(score)<<std::endl;
  std::cout<<"深度最小结果："<<std::endl<<judgeHeightMin(score)<<std::endl;

  return 0;
}