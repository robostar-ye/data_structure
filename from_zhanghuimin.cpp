#include<iostream>

using namespace std;
typedef struct polyNode {
    float coef;//系数
    int exp;//指数
    polyNode *next;//指向下一个的指针

} LNode, *LinkList;

//输入多项式的指数，系数
void CreateList1(LinkStack L, int n) {
  LinkStack p, q;
    //q = (LinkStack)malloc(sizeof(LNode));
    //! q = new LNode;
    cout << "请输入" << n << "个多项式" << endl;
    //逆位序输入n个元素的值
    //L = (LinkStack)malloc(sizeof(LNode));//生成头节点
    //L = new LNode;
    L->down = NULL;//先建立一个带头节点的单链表
    q = L;
    for (int i = n; i > 0; --i) {
        //p = (LinkStack)malloc(sizeof(LNode));
        p = new LNode;
        cout << "请输入系数" << endl;
        cin >> p->coef;
        //!cout<<p->coef<<endl;
        cout << "请输入指数" << endl;
        cin >> p->exp;
        //!cout<<p->exp<<endl;
        //p->down = L->down;
        q->down = p;
        q = p;
    }
    q->down = NULL;
};

void MergeList1(LinkStack La, LinkStack Lb, LinkStack Lc) {
  LinkStack pa = new LNode;
  LinkStack pb = new LNode;
  LinkStack pc = new LNode;
    pa = La->down;
    pb = Lb->down;
    pc = La;
    Lc = pc;
    while ((pa != NULL) && (pb != NULL)) {
        if (pb->exp > pa->exp) {
            pc->down = pa;
            pc = pa;
            pa = pa->down;
        } else {
            if (pa->exp == pb->exp) {
                pb->coef = pb->coef + pa->coef;
                pc->down = pb;
                pc = pb;
                pb = pb->down;
            }
        }
    }

    pc->down = pa ? pa : pb;
    free(Lb);
};

void showList(LinkStack L) {
  LinkStack p1;//!=new LNode;
    if (L->down != NULL) {
        p1 = L->down;
        while (p1->down != NULL) {
            cout << p1->coef << "*x^" << p1->exp << "+";
            p1 = p1->down;
            cout << p1->exp << endl;
        }
    }else{
        std::cerr<<"wrong! no L->down"<<std::endl;
    }

};

int main() {
    //输入多项式的指数，系数，创建La,Lb,Lc
    /*LinkStack la = (LinkStack)malloc(sizeof(LNode));
    LinkStack lb = (LinkStack)malloc(sizeof(LNode));
    LinkStack lc = (LinkStack)malloc(sizeof(LNode));*/
    //小实验
    LinkStack a = new LNode;
    a->coef = 2.3;
    a->exp = 3;
    cout << a->coef << "*x^" << a->exp << endl;

    //正式程序
    LinkStack la = new LNode;
    LinkStack lb = new LNode;
    LinkStack lc = new LNode;
    cout << "new la" << endl;
    CreateList1(la, 3);
    showList(la);

    cout << "new lb" << endl;
    CreateList1(lb, 2);
    showList(lb);
    MergeList1(la, lb, lc);
    lc->down = NULL;
    showList(lc);
}