//
// Created by robos on 2020/10/19.
//
#include "../include/lists.hpp"

int main(){
  LinkList L = LinkList();
  L.createLinkStack(12);
  L.show();
  L.delRepeat();
  L.show();
  return 0;
}