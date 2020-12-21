//
// Created by robos on 2020/11/30.
//
//#include<cstdio>
//#include<cstdlib>

#include <iostream>


#define MAXVALUE 1000
typedef int DataType;
#define MAXBIT 100
typedef struct {
  char code[MAXBIT];//哈夫曼编码值
  int start;          //编码起始位置
}HufCode;
typedef struct node {
  DataType data;//数据域
  float weight;//权值域
  int parent;//双亲域
  int left; //左孩子域
  int right;//右孩子域
}HufNode;

void HuffmanTree(float weight[],char ch[],int n, HufNode hf[]){//! 创建哈弗曼树
  int i,j,node1,node2;
  float mw1,mw2;
  for(i=0;i<2*n-1;i++){//初始化
    if(i<n){
      hf[i].weight=weight[i];
      hf[i].data=ch[i];
    }
    else
      hf[i].weight=0;
    hf[i].parent=-1;
    hf[i].left=-1;
    hf[i].right=-1;
  }
  for(i=n;i<2*n-1;i++){
    mw1=mw2=MAXVALUE;
    node1=node2=-1;
    for(j=0;j<=i-1;j++){//在双亲域为-1的结点中寻找两个权值最小的结点
      if(hf[j].parent==-1){
        if(hf[j].weight<mw1){
          mw2=mw1;
          node2=node1;
          mw1=hf[j].weight;
          node1=j;
        }
        else if(hf[j].weight<mw2){
          mw2=hf[j].weight;
          node2=j;
        }
      }
    }
    //开始构造新的二叉树
    hf[i].weight=hf[node1].weight+hf[node2].weight;
    hf[node1].parent=i;
    hf[node2].parent=i;
    hf[i].left=node1;
    hf[i].right=node2;
  }
}

void HuffmanCode(HufNode hf[],HufCode hfc[],int n){//! 获取哈弗曼编码， n编码个数
  int i,parent,left;
  HufCode hc;
  for(i=0;i<n;i++){
    hc.start=n;
    left=i;
    parent=hf[i].parent;
    while(parent!=-1){//有双亲结点，说明没有到达根结点
      if(hf[parent].left==left)
        hc.code[hc.start--]='0';//是左孩子
      else
        hc.code[hc.start--]='1';//是右孩子
      left=parent;
      parent=hf[parent].parent;   //向根进发
    }
    hc.start++;
    hfc[i]=hc;  // 获取一个编码
  }
}


int main()
{
  int i, j, n = 8;
  char ch[] = "!@#$%^&*";
  float weight[] = {0.07, 0.19, 0.02, 0.06, 0.32, 0.03, 0.21, 0.1};
  //为哈夫曼树开辟内存空间
  auto *HufTree = (HufNode *)malloc(sizeof(HufCode)*(2 * n + 1));
  //为哈夫曼编码开辟内存空间
  auto *HufCodes = (HufCode *)malloc(sizeof(HufCode)*n);
  HuffmanTree(weight, ch, n, HufTree);//创建
  std::cout<<"\n********************哈夫曼树存储数据*******************\n";
  std::cout<<"数据： 序号    权值    双亲   左孩子   右孩子\n";
  for (i = 0; i <=n - 1; i++) {//前n个结点
    printf("%c\t%d\t%f\t%d\t%d\t%d\n", HufTree[i].data,i,HufTree[i].weight,HufTree[i].parent,HufTree[i].left,HufTree[i].right);
  }
  for (i = n; i < 2 * n - 1; i++) {//后n-1个结点
    printf("\t%d\t%f\t%d\t%d\t%d\n", i, HufTree[i].weight, HufTree[i].parent, HufTree[i].left, HufTree[i].right);
  }
  HuffmanCode(HufTree, HufCodes, n);	//编码
  std::cout<<"********************哈夫曼编码编码********************"<<std::endl;
  for (i = 0; i < n;i++)
  {
    printf("%c(%f):\t", ch[i], HufTree[i].weight);
    for (j = HufCodes[i].start; j <= n; j++)
      printf("%c", HufCodes[i].code[j]);
    printf("\n");
  }
  return 0;
}