//
// Created by robos on 2020/10/18.
//

#ifndef TEST_2_LISTS_HPP
#define TEST_2_LISTS_HPP
//! 后面做栈与队列的实验时直接复制的此文件代码进行修改，没想到在另外两处的全局修改影响到了此处，所以这个地方可能有些错误需要继续debug
#include <iostream>

// typedef int SeqList;
// const int LISTSIZE = 100;
class SeqList {
public:
  explicit SeqList(int length); // 初始化一个顺序链表
  SeqList(int length, bool temp);
  int getLength_() const{
    return length_;
  }
  int judgeEmpty() const{
    if(length_)return false;
    else return true;
  }
  void insert(int pos, int item);

  void deleteList(int pos);

  int locate(int item);

  int getElem(int pos);

  void show();

  void delRepeat();

  void split(SeqList &A, SeqList &B);

private:
  int *items_;
  int length_;
};

SeqList::SeqList(int length) {
  length_ = length;
  items_ = new int [length_];
  for(int i = 0; i < length_; i++){
    std::cout<<" 请输入第 "<<i + 1<<" 个元素 "<<std::endl;
    std::cin>>items_[i];
  }
}
SeqList::SeqList(int length, bool temp) {
  length_ = length;
  items_ = new int [length_];
}

void SeqList::insert(int pos, int item) {
  if(pos >= length_){
    int * temp = new int[pos];
    for(int i = 0; i < length_; i++){
      temp[i] = items_[i];
    }
    delete items_;
    items_ = temp;
    items_[pos - 1] = item;
    length_ ++;
  }else if(pos < 1) std::cerr<<"插入位置不合法"<<std::endl;
  else{
    for(int i = length_ - 1; i > pos; i--){
      items_[i] = items_[i - 1];
    }
    length_ ++;
  }
}

void SeqList::deleteList(int pos) {
  if(length_ == 0){
    std::cerr<<" 顺序表为空，无法进行删除操作 "<<std::endl;
  }else if(pos  < 1 || pos > length_ + 1){
    std::cerr<< " 删除位置不合法 "<<std::endl;
  }else{
    for(int i = pos - 1; i < length_; i++){
      items_[i] = items_[i + 1];
    }
    length_--;
  }
}

int SeqList::locate(int item) {
  if(length_ == 0)std::cerr<<" 顺序表为空，无法进行此操作"<<std::endl;
  for(int i = 0; i < length_; i++){
    if(items_[i] == item)return i;
  }
  return -1;
}

int SeqList::getElem(int pos) {
  if(pos > length_ - 1)std::cerr<< " 输入位置不合法" <<std::endl;
  return items_[pos - 1];
}

void SeqList::show(){
  for(int i = 0; i < length_; i++){
    std::cout<<items_[i]<<" ";
  }
  std::cout<<std::endl;
}

void SeqList::delRepeat() {
  for(int i = 0; i < length_; i++){
    for(int j = i+1; j < length_; j++){
      if(items_[i] == items_[j]){
        deleteList(j);
        //std::cout<<j<<std::endl;
       j--;
      };
    }
  }
}

void SeqList::split(SeqList &A, SeqList &B) {
  A = SeqList(0, true);
  B = SeqList(0, true);
  int m = 1, n = 1;
  for(int i = 0; i < length_; i++){
    if(items_[i]<=0){
      A.insert(1,items_[i]);
      m++;
    }else{
      B.insert(1,items_[i]);
      n++;
    }
  }
}
// 单链表
class Node{
public:
  float data = 0;
  char elements = '\0';
  Node *down = nullptr;
};

class LinkList {
public:
  LinkList(); // 单链表初始化
  ~LinkList();
  void createLinkStack(int size);
  int getLength_();
  bool judgeEmpty();
  void insertList(int pos, int data);
  void deleteList(int pos);
  void show();
  void delRepeat();
  Node *getHead_(){return head_;}
private:
  Node *head_;
  int size_{};
};

LinkList::LinkList(){
  head_ = new Node;
  size_ = 0;
}

LinkList::~LinkList() {
  delete head_;
}

void LinkList::createLinkStack(int size){
  if(size < 0){
    std::cerr<<"输入尺寸非法"<<std::endl;
  }

  Node *temp_1 = nullptr, *temp_2= nullptr;
  this->size_ = size;
  temp_2 = this->head_;
  for(int i = 0; i < size; i++){
    temp_1 = new Node;
    temp_1->down = nullptr;
    std::cout<<"请输入第"<< i+1 <<"个节点的权值" <<std::endl;
    std::cin>>temp_1->data;
    std::cout<<"请输入第"<< i+1 <<"个节点的元素" <<std::endl;
    std::cin>>temp_1->elements;
    temp_2->down = temp_1;
    temp_2 = temp_1;
  }
  temp_2->down = nullptr;
  std::cout<<"创建完成"<<std::endl;
}

int LinkList::getLength_() {
  return size_;
}

bool LinkList::judgeEmpty() {
  if(size_)return false;
  else return true;
}

void LinkList::insertList(int pos, int data) {
  if(pos < 1 || pos > size_){
    std::cerr<<"插入位置非法"<<std::endl;
  }
  Node * temp_1, *temp_2;
  temp_1 = head_;
  int i= 0;
  while(temp_1 != nullptr && i < pos - 1){
    temp_1 = temp_1 ->down;
  }
  temp_2 = new Node;
  temp_2->data = data;
  temp_2->down = temp_1->down;
  temp_1->down = temp_2;
  size_++;
}

void LinkList::deleteList(int pos) {
  if(pos < 1 || pos > size_)std::cerr<<"删除位置非法"<<std::endl;
  else{
    Node * temp = head_;
    Node * temp_1;
    for(int i = 0; i < pos ; i++){
      temp = temp->down;
    }
    temp_1 = temp->down;
    temp->down = temp_1->down;
    delete temp_1;
  }
}

void LinkList::show() {
  Node *temp = head_;
  while (temp->down != nullptr){
    std::cout<<temp->down->data<<" ";
    temp = temp->down;
  }
  // std::cout<<temp->down<<std::endl;
  std::cout<<std::endl;
}

void LinkList::delRepeat() {
  Node *temp_1, *temp_2;
  temp_1 = head_->down;
  while (temp_1 != nullptr){
    temp_2 = temp_1;
    while (temp_2 ->down != nullptr){
      if(temp_1->data == temp_2->down->data){
        Node * temp_3 = temp_2->down;
        temp_2->down = temp_3->down;
        delete temp_3;
      }else
      temp_2 = temp_2->down;
    }
    temp_1 = temp_1->down;
  }
}
#endif // TEST_2_LISTS_HPP
