
#include<iostream>
#include<string>
const int MAX = 20;
using namespace std;


struct ArcNode {			        //弧结点
  int adjvex = -1;		        //所指顶点位置
  ArcNode *nextarc = nullptr;		//下一条狐指针
  size_t info = 0;			//弧信息
};


struct VNode {				        //顶点
  string data = "0";
  ArcNode *firstarc = nullptr;		//第一条依附该顶点的弧的指针
};


struct Graph {				        //图结构
  VNode vertices[MAX];	                //全部顶点
  int vexnum, arcnum;		        //顶点数和弧数
  Graph(int m, int n) :vexnum(m), arcnum(n) {};
  Graph() :vexnum(0), arcnum(0) {};
};


int main() {
  int vnum, anum, tempanum = 0;
  cout << "输入顶点数：";
  cin >> vnum;
  cout << "输入弧数：";
  cin >> anum;
  cout << "\n\n";
  Graph G(vnum, anum);
  for (int i = 0; i < vnum; i++) {
    cout << "输入结点" << i << "的信息：";
    cin >> G.vertices[i].data;
    if (tempanum < anum)
      cout << "输入依靠此结点的弧的信息（输入-1以停止）：\n";
    else
      cout << "已输入所有弧的信息！\n";
    bool first = true;
    ArcNode *p, *temp;
    for (int j = 0; tempanum < anum; j++) {
      int pointto;
      cout << "输入弧" << tempanum << "所指向的顶点位置：";
      cout << tempanum <<endl;
      cin >> pointto;
      if (pointto == -1)
        break;
      else {
        tempanum++;
        if (first) {
          first = false;
          G.vertices[i].firstarc = new ArcNode;
          G.vertices[i].firstarc->adjvex = pointto;
          p = G.vertices[i].firstarc;
        } else {
          temp = new ArcNode;
          temp->adjvex = pointto;
          p->nextarc = temp;
          p = temp;
        }
      }
    }
    cout << endl;
  }

  for (int i = 0; i != vnum; i++) {
    int temp = 1;
    cout << "顶点" << i << ": |" << G.vertices[i].data << "|";
    if (G.vertices[i].firstarc) {
      cout << " -> " << G.vertices[i].firstarc->adjvex;
      auto pt = G.vertices[i].firstarc->nextarc;
      while (pt) {
        temp++;
        cout << " -> " << pt->adjvex;
        pt = pt->nextarc;
      }
      cout << "-> ^";
    } else {
      temp = 0;
      cout << " -> ^";
    }
    std::cout<<" 入度: "<< temp <<std::endl;
    cout << endl;
  }
  return 0;
}