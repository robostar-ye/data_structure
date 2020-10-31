//
// Created by robos on 2020/10/19.
//
#include "../include/lists.hpp"

int main(){
  SeqList temp = SeqList(17);
  temp.show();
  SeqList A = SeqList(1, true), B = SeqList(1, true);
  temp.split(A, B);
  A.show();
  B.show();

  return 0;
}