//
// Created by robos on 2020/10/31.
//

#ifndef TEST_2_QUEUES_HPP
#define TEST_2_QUEUES_HPP
#include "iostream"

class SeqQueue {
public:
  explicit SeqQueue(int length); // 初始化一个顺序队列
  SeqQueue(int length, bool temp);
  int getLength_() const{
    return length_;
  }
  int judgeEmpty() const{
    if(length_)return false;
    else return true;
  }
  void insert(int item);

  void deleteQueue();

  int locate(int item);

  int getElem(int pos);

  void show();



  void menu();

private:
  int *items_;
  int length_ = 0;
  int nums = 0;
  int max_length_;
};

SeqQueue::SeqQueue(int length) {
  length_ = length;
  items_ = new int [length_];
  for(int i = 0; i < length_; i++){
    std::cout<<" 请输入第 "<<i + 1<<" 个元素 "<<std::endl;
    std::cin>>items_[i];
  }
}
SeqQueue::SeqQueue(int length, bool temp) {
  length_ = length;
  items_ = new int [length_];
}

void SeqQueue::insert(int item) {
  int pos = length_ + 1;
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

void SeqQueue::deleteQueue() {
  int pos = 1;
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

int SeqQueue::locate(int item) {
  if(length_ == 0)std::cerr<<" 顺序表为空，无法进行此操作"<<std::endl;
  for(int i = 0; i < length_; i++){
    if(items_[i] == item)return i;
  }
  return -1;
}

int SeqQueue::getElem(int pos) {
  if(pos > length_ - 1)std::cerr<< " 输入位置不合法" <<std::endl;
  return items_[pos - 1];
}

void SeqQueue::show(){
  for(int i = 0; i < length_; i++){
    std::cout<<items_[i]<<" ";
  }
  std::cout<<std::endl;
}


void SeqQueue::menu() {
  std::cout<<"请设定最大队列:"<<std::endl;
  std::cin>>max_length_;
  int status = -1;
  while(status != 4){
    std::cout<<"欢迎使用**银行自助服务系统，请输入编号决定要使用的业务："<<std::endl;
    std::cout<<"1. 取号;"<<std::endl;
    std::cout<<"2. 办理;"<<std::endl;
    std::cout<<"3. 查看;"<<std::endl;
    std::cout<<"4. 下班;"<<std::endl;
    std::cin>>status;
    switch (status) {
    case 1:
      if(length_ >= max_length_)std::cerr<<"已达到最大队列，无法取号"<<std::endl;
      else{
        insert(++nums);
        std::cout<<"取号成功，当前编号："<<nums<<", 目前排在第"<<length_<<"位"<<std::endl;
      }
      break;
    case 2:
      if (length_ <= 0)std::cout<<"队列为空，无法办理"<<std::endl;
      else{
        deleteQueue();
        std::cout<<"办理成功，还有"<<length_<<"位待办理"<<std::endl;
      }
      break;
    case 3:
      std::cout<<"目前还有"<<length_<<"位待办理, 编号分别为："<<std::endl;
      show();
      break;
    case 4:
      std::cout<<"下班成功， 今日剩余编号为："<<std::endl;
      show();
      std::cout<<"今日共办理"<<nums - length_<<"单业务"<<std::endl;
      break;
    default:
      std::cout<<"错误输入，当前无操作"<<std::endl;
      break;
    }
  }
}





class Cell{
public:
  int element_{};
  Cell* next_ = nullptr;
};

class LinkQueue {
public:
  LinkQueue()= default;;
  explicit LinkQueue(int x);
  void deQueue_();
  void enQueue_(int x);
  void show_();

private:
  int max_size_ = 0;
  Cell* front_ = nullptr;
  Cell* rear_ = nullptr;
};
LinkQueue::LinkQueue(int x) {
  this->front_ = new Cell;
  rear_ = front_;
  this->front_->element_ = x;
  this->front_->next_ = nullptr;
  max_size_ = 1;
}

void LinkQueue::enQueue_(int x) {
  this->rear_->next_ = new Cell;
  this->rear_ = this->rear_->next_;
  this->rear_->element_ = x;
  this->rear_->next_ = nullptr;
  max_size_++;
  std::cout << "add the element \'" << x << "\' to the end" << std::endl;
}

void LinkQueue::deQueue_() {
  if (!max_size_) std::cerr << "The queue is empty" << std::endl;
  else{
    Cell* tmp;
    tmp = this->front_;
    this->front_ = tmp->next_;
    delete tmp;
    max_size_--;
    std::cout << "delete the first element" << std::endl;
    if(this->front_->next_ == nullptr){
      this->front_ = this->rear_;
    }
  }
}

void LinkQueue::show_() {
  std::cout << "Size:" << max_size_ << std::endl;
  std::cout << "elements:" << std::endl;
  Cell* tmp = this->front_;
  while(tmp != nullptr){
    std::cout << tmp->element_ << " ";
    tmp = tmp->next_;
  }
  std::cout << std::endl;
  std::cout << "end" << std::endl<<std::endl;
}
#endif // TEST_2_QUEUES_HPP
