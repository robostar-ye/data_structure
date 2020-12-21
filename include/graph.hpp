//
// Created by robos on 2020/12/5.
//

#ifndef TEST_2_GRAPH_HPP
#define TEST_2_GRAPH_HPP

#include <iostream>
#include <utility>
#include <vector>

//! �ڽӾ����ʾ
class Mgraph {
public:
  Mgraph() = default;
  ; //! Ĭ�Ϲ��캯��
  void createGraph_(std::vector<std::vector<int>> arcs, std::vector<int> data,
                    int vexs);
  void displayGraph_();
  int getFirst_(int k);
  int getNext_(int k, int t);
  void DFS(int k, std::vector<int> visited);
  void prim_(int v);
  void Dijstra_(int v, int dis[]);

private:
  std::vector<std::vector<int>> arcs_; //!�ڽӾ���
  std::vector<int> data_;              //!������Ϣ
  int vexs_ = 0;                       //!�������
};

void Mgraph::createGraph_(std::vector<std::vector<int>> arcs,
                          std::vector<int> data, int vexs) {
  vexs_ = vexs;
  arcs_ = std::move(arcs);
  data_ = std::move(data);
}
void Ppath(int pre[], int i, int v)
{
  int k;
  k=pre[i];
  if(k==v)
    return;
  Ppath(pre,k,v);
  printf("%d, ",k+1);
}
void Mgraph::displayGraph_() {
  std::cout << "����:" << std::endl;
  for (int i = 0; i < vexs_; i++)
    std::cout << data_[i] << " " << std::endl;
  std::cout << "�ڽӾ���:" << std::endl;
  for (int i = 0; i < vexs_; i++) {
    std::cout << data_[i];
    for (int j = 0; j < vexs_; j++)
      std::cout << arcs_[i][j];
  }
}

int Mgraph::getFirst_(int k) {
  if (k < 0 || k > vexs_) {
    std::cerr << "����k������Χ" << std::endl;
    return -1;
  }
  for (int i = 0; i < vexs_; i++) {
    if (arcs_[k][i])
      return i;
  }

  return -1;
}

int Mgraph::getNext_(int k, int t) {
  if (k < 0 || k > vexs_ || t < 0 || t > vexs_) {
    std::cerr << "����k��t������Χ" << std::endl;
    return 0;
  }
  for (int i = t + 1; i < vexs_; i++) {
    if (arcs_[k][i])
      return i;
  }

  return -1;
}

void Mgraph::DFS(int k, std::vector<int> visited) {
  //!��ʶ����
  visited.clear();
  int u; //! k�ڽӵ�
  std::cout << data_[k];
  visited[k] = 1;
  u = getFirst_(k);
  while (u != -1) {
    if (visited[u] == 0)
      DFS(u, visited);
    u = getNext_(k, u);
  }
}

void Mgraph::prim_(int v) {
  int low_cost[100];
  int uset[100];
  int min_edge, min_weight, k;
  for (int i = 0; i < vexs_; i++) {
    low_cost[i] = (arcs_[v][i]);
    uset[i] = (1);
  }
  uset[v] = (0);
  std::cout << "��ʼ��" << data_[v] << std::endl;
  for (int i = 1; i < vexs_; i++) {
    min_weight = 100;
    for (int j = 0; j < vexs_; j++) {
      // if(j == 0)min_weight = low_cost[0];
      if (uset[j] && low_cost[j] < min_weight) {
        min_weight = low_cost[j];
        min_edge = j;
      }
    }

    for (int j = 0; j < vexs_; j++) {
      if (arcs_[j][min_edge] == min_weight)
        k = j;
    }
    std::cout << "�ߣ�(" << data_[k] << ',' << data_[min_edge]
              << ")��Ȩֵ:" << min_weight << std::endl;
    uset[min_edge] = 0;
    v = min_edge;

    for (int j = 0; j < vexs_; j++) {
      if (uset[j] && arcs_[v][j] < low_cost[j])
        low_cost[j] = arcs_[v][j];
    }
  }
}

void Mgraph::Dijstra_(int v, int dis[]) {
  int i,j;
  int no;
  int min_dis;
  //int dis[6];
  int visited[6]={0};
  int pre[6];

  visited[v]=1;
  for(i=0;i<vexs_;i++)
  {
    dis[i]=arcs_[v][i];
    pre[i]=v;
  }

  for(i=0;i<vexs_;i++)
  {
    min_dis=INT_MAX;
    for(j=0;j<vexs_;j++)
    {
      if(!visited[j] && dis[j]<min_dis)
      {
        min_dis=dis[j];
        no=j;
      }
    }
    visited[no]=1;
    for(j=0;j<vexs_;j++)
    {
      if(!visited[j] && arcs_[no][j]!=INT_MAX && dis[no]+arcs_[no][j] < dis[j])
      {
        dis[j]=dis[no]+arcs_[no][j];
        pre[j]=no;
      }
    }
  }


  for(i=0;i<vexs_;i++)
  {
    if(visited[i])
    {
      printf("��%d��%d�����·������Ϊ:%d\t·��Ϊ:",v+1,i+1,dis[i]);
      printf("%d, ",v+1);
      Ppath(pre,i,v);

      printf("%d\n",i+1);
    }
    else
      printf("no path\n");
  }
}

/**
 *
 */
//! �ڽӱ��ʾ
typedef struct arc { //! �߱�ڵ�
  int adjvex_{};     //! �������
  struct arc *next = nullptr;
} ArcNode, *PArcNode;

typedef struct { //! �����ڵ�
  int data_{};
  ArcNode *head_ = nullptr;
} VexNode;

class VGragh { //! �ڽӱ�
public:
  VGragh() = default;
  ;
  void createGraph_(std::vector<std::vector<int>> arcs, std::vector<int> data,
                    int vexs);
  void displayGraph_();
  int getFirst_(int k);
  int getNext_(int k, int u);
  void BFS(int v, std::vector<int> visited);
  void prim_(int v);

private:
  std::vector<VexNode> lists_; //!�����
  int edges_ = 0, vexs_ = 0;   //!������������
};
void VGragh::createGraph_(std::vector<std::vector<int>> arcs,
                          std::vector<int> data, int vexs) {
  vexs_ = vexs;
  for (int i = 0; i < vexs; i++) {
    for (int j = vexs - 1; j >= 0; j--) {
      if (arcs[i][j]) {
        auto p = new ArcNode;
        p->adjvex_ = j;
        p->next = lists_[i].head_;
        lists_[i].head_ = p;
      }
    }
  }
}

void VGragh::displayGraph_() {
  PArcNode p_temp;
  for (int i = 0; i < vexs_; i++) {
    std::cout << "Line" << i << ":" << std::endl;
    p_temp = lists_[i].head_;
    while (p_temp != nullptr) {
      std::cout << '[' << p_temp->adjvex_ << "]   ";
      p_temp = p_temp->next;
    }
    std::cout << std::endl;
  }
}

int VGragh::getFirst_(int k) {
  if (k < 0 || k > vexs_) {
    std::cerr << "����k������Χ" << std::endl;
    return -1;
  }
  if (lists_[k].head_ == nullptr)
    return -1;
  else
    return lists_[k].head_->adjvex_;
}

int VGragh::getNext_(int k, int u) {
  PArcNode p_temp;
  if (k < 0 || k > vexs_ || u < 0 || u > vexs_) {
    std::cerr << "����k��u������Χ" << std::endl;
    return -1;
  }
  p_temp = lists_[k].head_;
  while (p_temp->next != nullptr && p_temp->adjvex_ != u)
    p_temp = p_temp->next;
  if (p_temp->next == nullptr)
    return -1;
  else
    return p_temp->next->adjvex_;
}

void VGragh::BFS(int v, std::vector<int> visited) {
  visited.clear();
  int u;
  std::vector<int> queue;  //! ѭ������
  int front = 0, rear = 0; //! ��ͷ��βָ��
  int w;                   //! v �ڽӵ�

  std::cout << lists_[v].data_;
  visited[v] = 1;
  queue[rear] = v;
  rear++;
  while (front < rear) {
    u = queue[front];
    front++;
    w = getFirst_(u);
    while (w != -1) {
      if (visited[w] == 0) {
        std::cout << lists_[w].data_;
        visited[w] = 1;
        queue[rear] = w;
        rear++;
      }
      w = getNext_(u, w);
    }
  }
}

// void VGragh::prim_(int v) {
//  std::vector<int> low_cost;
//  std::vector<int> uset;
//  int min_edge, min_weight, k;
//  for(int i = 0; i<vexs_; i++){
//    low_cost.emplace_back(arc[v][i]);
//  }
//}

#endif // TEST_2_GRAPH_HPP
