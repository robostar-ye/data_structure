//
// Created by robos on 2020/10/29.
//

#ifndef TEST_2_TREES_HPP
#define TEST_2_TREES_HPP

#include "iostream"
#include <vector>
#include "lists.hpp"

struct BinaryTreeNode{
  char data_ = '\0';
  float weight_ = 0;   //哈夫曼编码用权值
  int nums = 0;
  BinaryTreeNode *parent_ = nullptr;
  BinaryTreeNode *left_ = nullptr;
  BinaryTreeNode *right_ = nullptr;
};


class BinaryTree{
public:
  explicit BinaryTree();
  BinaryTreeNode *build_prefix(BinaryTreeNode * temp);
  void exp3_3();
  void exp3_4();
  void exp3_1();
  BinaryTreeNode *build_by_pre_and_infix(const char *pre, const char *infix,int size);
  BinaryTreeNode *CreatHF();
  void showNode(BinaryTreeNode *temp);
  void showPreOder(BinaryTreeNode *temp);
  void showInOder(BinaryTreeNode *temp);
  void showPostOrder(BinaryTreeNode *temp);
  int depth(BinaryTreeNode *temp, int num = 0)//num=0；
  {
    if(temp != nullptr)
    {
      num++;
      if(depth(temp->left_,num)>depth(temp->right_,num))
        return depth(temp->left_,num);
      else
        return depth(temp->right_,num);
    }
    else
      return num;
  }
private:
  BinaryTreeNode *root_;
  int node_nums_=0;
  int leaf_node_nums_ = 0;
};

BinaryTree::BinaryTree() {
  root_ = new BinaryTreeNode;
  //root_->data_ = root;
  root_->left_ = nullptr;
  root_->right_ = nullptr;
}

BinaryTreeNode *BinaryTree::build_by_pre_and_infix(const char *pre, const char *infix, int size) {
  if(size == 0)return nullptr;

  BinaryTreeNode *temp_node_1;
  if(root_->left_ == nullptr && root_->right_ == nullptr) temp_node_1 = root_;
  else temp_node_1 = new BinaryTreeNode;
  std::cout<<pre[0]<<std::endl;
  temp_node_1->data_ = pre[0];
  int temp_int_1 = 0;
  while(temp_node_1->data_ != infix[temp_int_1]){
    temp_int_1++;
  }
  temp_node_1->left_ = build_by_pre_and_infix(pre + 1, infix, temp_int_1);
  temp_node_1->right_ = build_by_pre_and_infix(pre + temp_int_1 + 1, infix + temp_int_1 + 1, size - 1 - temp_int_1);

  return temp_node_1;
}

struct code{
  float weight = 0;
  char data = NULL;
};

BinaryTreeNode *BinaryTree::CreatHF() {
  LinkList elements;// 采用链表存取原始数据
  std::vector<code> code_S;
  int temp_size_1;
  std::cout<<"请输入编码个数："<<std::endl;
  std::cin>>temp_size_1;
  float temp_weight; char temp_data;
  for(int i = 0; i < temp_size_1; i++){
    std::cout<<"请输入第"<<i + 1<<"个data"<<std::endl;
    std::cin>>temp_data;
    std::cout<<"请输入第"<<i + 1<<"个weight"<<std::endl;
    std::cin>>temp_weight;
    code temp;
    temp.weight = temp_weight;
    temp.data = temp_data;
    code_S.emplace_back(temp);
  }
  std::cout<<"请依次输入编码权值："<<std::endl;
  elements.createLinkStack(temp_size_1);
  Node *head = elements.getHead_();
  Node *temp = head;
  int temp_oder = 0;

  for(int i = 0; i < temp_size_1; i++){
    Node *temp_min_1, *temp_min_2;
    int temp_1, temp_2;
    BinaryTreeNode *temp_left = new BinaryTreeNode;
    BinaryTreeNode *temp_right = new BinaryTreeNode;
    BinaryTreeNode *temp_parent = new BinaryTreeNode;
    temp_parent->right_ = temp_right;
    temp_parent->left_ = temp_left;
    temp_left->nums = temp_oder;
    temp_oder++;
    temp_right->nums = temp_oder;
    temp_oder++;
    for(int j = 0; j < temp_size_1 - i; j++){
      if(j == 0){
        temp_min_1 = head;
        temp_min_2 = head;
        temp_1 = 0;
        temp_2 = 0;
      }else if(temp->data <= temp_min_1->data){
        temp_min_1 = temp;
        temp_1 = j;
      }
      else if(temp->data <= temp_min_2->data && temp->data >= temp_min_1->data){
        temp_min_2 = temp;
        temp_2 = j;
      }
      temp = temp->down;
    }
    elements.deleteList(temp_1+1);
    elements.deleteList(temp_2+1);
    temp_left->data_ = temp_min_1->elements;
    temp_left->weight_ = temp_min_1->data;
    temp_right->data_ = temp_min_2->elements;
    temp_right->weight_ = temp_min_2->data;
    temp_parent->weight_ = temp_left->weight_ + temp_right->weight_;
    elements.insertList(1,  temp_parent->weight_);
  }

  return nullptr; }

void BinaryTree::showNode(BinaryTreeNode *temp){
  std::cout<<"data："<<temp->data_<<"  "<<"order:"<<temp->nums<<std::endl;
}

void BinaryTree::showPreOder(BinaryTreeNode *temp) {
  if(temp != nullptr){
    showNode(temp);
    showPreOder(temp->left_);
    showPreOder(temp->right_);
  }
}

void BinaryTree::showInOder(BinaryTreeNode *temp) {
  if (temp != nullptr){
    showInOder(temp->left_);
    showNode(temp);
    showInOder(temp->right_);
  }
}

void BinaryTree::showPostOrder(BinaryTreeNode *temp) {
  if(temp != nullptr){
    showPostOrder(temp->left_);
    showPostOrder(temp->right_);
    showNode(temp);
  }
}

void BinaryTree::exp3_3() {
  root_->nums = 8;
  root_->left_ = new BinaryTreeNode;
  root_->left_->nums = 6;
  root_->left_->data_ = 'B';
  root_->right_ = new BinaryTreeNode;
  root_->right_->nums = 7;
  root_->right_->left_ = new BinaryTreeNode;
  root_->right_->left_->nums = 4;
  root_->right_->left_->data_ = 'C';
  root_->right_->right_ = new BinaryTreeNode;
  root_->right_->right_->nums = 5;
  root_->right_->right_->left_ = new BinaryTreeNode;
  root_->right_->right_->left_->nums = 2;
  root_->right_->right_->left_->data_ = 'A';
  root_->right_->right_->right_ = new BinaryTreeNode;
  root_->right_->right_->right_->nums = 3;
  root_->right_->right_->right_->left_ = new BinaryTreeNode;
  root_->right_->right_->right_->left_->nums = 1;
  root_->right_->right_->right_->left_->data_ = 'E';
  root_->right_->right_->right_->right_ = new BinaryTreeNode;
  root_->right_->right_->right_->right_->nums = 0;
  root_->right_->right_->right_->right_->data_ = 'D';

  std::cout<<"前序："<<std::endl;
  showPreOder(root_);
  std::cout<<"中序："<<std::endl;
  showInOder(root_);
  std::cout<<"后序："<<std::endl;
  showPostOrder(root_);
}

BinaryTreeNode *BinaryTree::build_prefix(BinaryTreeNode *temp) {
  if (temp != root_)
    temp = new BinaryTreeNode;
  std::cout << "请输入节点data，节点为空时请以‘#’替代：" << std::endl;
  std::cin >> temp->data_;
  if (temp->data_ != '#') {
//    std::cout << "请输入节点序号：" << std::endl;
//    std::cin >> temp->nums;
    node_nums_++;
    temp->left_=build_prefix(temp->left_);
    temp->right_=build_prefix(temp->right_);
    if(temp->left_ == nullptr && temp->right_ == nullptr){
      leaf_node_nums_++;
      //std::cout<<"当前叶子节点data："<<temp->data_<<temp->left_<<temp->right_<<std::endl;
    }
//    if(temp->left_->data_ == '#' && temp->right_->data_ == '#'){
//      leaf_node_nums_++;
  }else{
    delete temp;
    temp = nullptr;
  }
  return temp;
}
void BinaryTree::exp3_1() {
  CreatHF();
  showPreOder(root_);
}
void BinaryTree::exp3_4() {
  build_prefix(root_);
  std::cout<<"depth:"<<depth(root_, 0)<<std::endl;
  std::cout<<"node nums:"<<node_nums_<<std::endl
  <<"leaf node nums:"<<leaf_node_nums_<<std::endl;
}
#endif // TEST_2_TREES_HPP
