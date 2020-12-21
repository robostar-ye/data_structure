//
// Created by robos on 2020/10/31.
//

#ifndef TEST_2_STACKS_HPP
#define TEST_2_STACKS_HPP
#include "iostream"

struct Node {
public:
  char data = 0;
  Node *down = nullptr;
};

class LinkStack {
public:
  LinkStack(); // 单链表初始化
  ~LinkStack();
  void createLinkStack(int size);
  int getLength_();
  bool judgeEmpty();
  void insertList(char data);
  void deleteList();
  void show();
  char getHead() { return top_->data; };

private:
  Node *top_;
  int size_{};
};

LinkStack::LinkStack() {
  top_ = new Node;
  size_ = 0;
}

LinkStack::~LinkStack() {
  Node *temp_1 = top_, *temp_2;
  while (temp_1 != nullptr) {
    temp_2 = temp_1->down;
    delete temp_1;
    temp_1 = temp_2;
  }
}

void LinkStack::createLinkStack(int size) {
  if (size < 0) {
    std::cerr << "输入尺寸非法" << std::endl;
  }

  Node *temp_1 = nullptr, *temp_2 = nullptr;
  this->size_ = size;
  // temp_2 = this->top_;
  for (int i = 0; i < size; i++) {
    temp_1 = new Node;
    temp_1->down = nullptr;
    std::cout << "请输入第" << i + 1 << "个节点的值" << std::endl;
    std::cin >> temp_1->data;
    temp_1->down = temp_2;
    temp_2 = temp_1;
  }
  top_ = temp_1;
  std::cout << "创建完成" << std::endl;
}

int LinkStack::getLength_() { return size_; }

bool LinkStack::judgeEmpty() {
  if (size_)
    return false;
  else
    return true;
}

void LinkStack::insertList(char data) {
  Node *temp_1;
  temp_1 = new Node;
  temp_1->data = data;
  temp_1->down = top_;
  top_ = temp_1;
  size_++;
  std::cout << "插入" << data << "成功" << std::endl;
}

void LinkStack::deleteList() {
  if (size_ < 1)
    std::cerr << "栈已空，无法继续删除" << std::endl;
  else {
    Node *temp_1;
    temp_1 = top_->down;
    delete top_;
    top_ = temp_1;
    std::cout << "删除成功" << std::endl;
  }
}

void LinkStack::show() {
  Node *temp = top_;
  while (temp != nullptr) {
    std::cout << temp->data;
    temp = temp->down;
  }
  // std::cout<<temp->down<<std::endl;
  std::cout << std::endl;
}

LinkStack scaleChange(int nums, int scale) {
  LinkStack nums_target;
  int temp;
  while (nums != 0) {
    temp = nums % scale;
    switch (temp) {
    case 10:
      nums_target.insertList('A');
      break;
    case 11:
      nums_target.insertList('B');
      break;
    case 12:
      nums_target.insertList('C');
      break;
    case 13:
      nums_target.insertList('D');
      break;
    case 14:
      nums_target.insertList('E');
      break;
    case 15:
      nums_target.insertList('F');
      break;
    default:
      // std::cout<<char(temp + 48)<<std::endl;
      nums_target.insertList(char(temp + 48));
      break;
    }
    nums /= scale;
  }

  return nums_target;
}

void secondChange(int second) {
  LinkStack time;

  time.insertList('S');
  int temp = second % 60;
  second /= 60;
  // time.insert(0 + 48);
  // std::cout<<char(temp%10 + 48)<<std::endl;
  do {
    char temp_char = char((temp % 10) + 48);
    time.insertList(temp_char);
    temp /= 10;
  } while (temp != 0);

  time.insertList(' ');
  time.insertList('M');
  temp = second % 60;
  second /= 60;
  do {
    char temp_char = char((temp % 10) + 48);
    time.insertList(temp_char);
    temp /= 10;
  } while (temp != 0);

  time.insertList(' ');
  time.insertList('H');
  temp = second % 60;
  second /= 60;
  do {
    char temp_char = char((temp % 10) + 48);
    time.insertList(temp_char);
    temp /= 10;
  } while (temp != 0);

  time.insertList(' ');
  time.insertList('D');
  temp = second;
  do {
    char temp_char = char((temp % 10) + 48);
    time.insertList(temp_char);
    temp /= 10;
  } while (temp != 0);

  std::cout << "转换后的时间为：" << std::endl;
  time.show();
}

#endif // TEST_2_STACKS_HPP
