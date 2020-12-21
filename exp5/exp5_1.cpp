#include <stdio.h>

#define MAX_LEN     (100)                       //  最大长度

typedef int key_type;                           //  定义关键字类型为int
typedef char info_type;
typedef struct
{
    key_type key;                               //  关键字项
    info_type data;                             //  其他数据项,类型为info_type
}rec_type;                                      //  查找元素的类型

/*-----------------x和y交换------------------*/
void swap_rec(rec_type &x, rec_type &y)         //  引用类型
{
    rec_type tmp = x;
    x = y;
    y = tmp;
}

/*-----------------创建顺序表------------------*/
void create_list(rec_type recs[], key_type keys[], int n)
{
    int i;

    for(i = 0; i < n; i++)                      // recs[0...n-1]存放排序记录
        recs[i].key = keys[i];
}

/*-----------------输出顺序表------------------*/
void disp_list(rec_type recs[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", recs[i].key);

    printf("\n");
}

/*-----------------以下运算针对堆排序的程序------------------*/
/*-----------------创建顺序表------------------*/
void create_list1(rec_type recs[], key_type keys[], int n)
{
    int i;

    for(i = 1; i <= n; i++)                     // recs[1...n]存放排序记录
    {
        recs[i].key = keys[i - 1];
    }
}

/*-----------------输出顺序表------------------*/
void disp_list1(rec_type recs[], int n)
{
    int i;

    for(i = 1; i <= n; i++)
    {
        printf("%d ", recs[i].key);
    }
    printf("\n");
}

/*---------------显示一趟划分后的结果--------------*/
static void disp_partition(rec_type recs[], int s, int t)
{
    static int i = 1;                               // 局部静态变量仅被初始化一次
    int j;

    printf("第%d次划分:", i);
    for(j = 0; j < s; j++)
        printf("   ");
    for(j = s; j <= t; j++)
        printf("%3d", recs[j].key);
    printf("\n");
    i++;
}

/*---------------一趟划分--------------*/
static int partition_recs(rec_type recs[], int s, int t)
{
    int i = s, j = t;//起始位置， 划分元素个数-1
    rec_type tmp = recs[i];                         //  以recs[i]为基准 [6, 8, 7, 9, 0, 1, 3, 2, 4, 5]

    while(i < j)                                    //  从两端交替向中间扫描,直至i=j为止
    {
        while(i < j && recs[j].key >= tmp.key)
            j--;                                    //  从右向左扫描,找一个小于tmp.key的recs[j]
        recs[i] = recs[j];                          //  找到这样的recs[j],放入recs[i]处
        while(i < j && recs[i].key <= tmp.key)
            i++;                                    //  从左向右扫描,找一个大于tmp.key的recs[i]
        recs[j] = recs[i];                          //  找到这样的recs[i],放入recs[j]处
    }
    recs[i] = tmp;
    disp_partition(recs, s, t);

    return i;
}

static void quick_sort(rec_type recs[], int s, int t)
{
    int i;

    if(s < t)                                       //  区间内至少存在两个元素的情况
    {
        i = partition_recs(recs, s, t);
        quick_sort(recs, s, i - 1);                 //  对左区间递归排序
        quick_sort(recs, i + 1, t);                 //  对右区间递归排序
    }
}

int main(int argc, char *argv[])
{
    int n = 8;
    rec_type recs[MAX_LEN];
    key_type a[] = {10,80,45,3,65,23,98,8};

    create_list(recs, a, n);
    printf("排序前: ");
    disp_list(recs, n);
    quick_sort(recs, 0, n - 1);
    printf("排序后: ");
    disp_list(recs, n);
    return 0;
}



