// Created by robostar-ye
// 2020/10/15/ 16:03:24

#include <iostream>

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

int main() {
  LinkQueue tmp_1;
  tmp_1 = LinkQueue(1);
  tmp_1.show_();
  tmp_1.enQueue_(2);
  tmp_1.show_();
  tmp_1.deQueue_();
  tmp_1.show_();

  return 0;
}
