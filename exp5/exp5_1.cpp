#include <stdio.h>

#define MAX_LEN     (100)                       //  ��󳤶�

typedef int key_type;                           //  ����ؼ�������Ϊint
typedef char info_type;
typedef struct
{
    key_type key;                               //  �ؼ�����
    info_type data;                             //  ����������,����Ϊinfo_type
}rec_type;                                      //  ����Ԫ�ص�����

/*-----------------x��y����------------------*/
void swap_rec(rec_type &x, rec_type &y)         //  ��������
{
    rec_type tmp = x;
    x = y;
    y = tmp;
}

/*-----------------����˳���------------------*/
void create_list(rec_type recs[], key_type keys[], int n)
{
    int i;

    for(i = 0; i < n; i++)                      // recs[0...n-1]��������¼
        recs[i].key = keys[i];
}

/*-----------------���˳���------------------*/
void disp_list(rec_type recs[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", recs[i].key);

    printf("\n");
}

/*-----------------����������Զ�����ĳ���------------------*/
/*-----------------����˳���------------------*/
void create_list1(rec_type recs[], key_type keys[], int n)
{
    int i;

    for(i = 1; i <= n; i++)                     // recs[1...n]��������¼
    {
        recs[i].key = keys[i - 1];
    }
}

/*-----------------���˳���------------------*/
void disp_list1(rec_type recs[], int n)
{
    int i;

    for(i = 1; i <= n; i++)
    {
        printf("%d ", recs[i].key);
    }
    printf("\n");
}

/*---------------��ʾһ�˻��ֺ�Ľ��--------------*/
static void disp_partition(rec_type recs[], int s, int t)
{
    static int i = 1;                               // �ֲ���̬����������ʼ��һ��
    int j;

    printf("��%d�λ���:", i);
    for(j = 0; j < s; j++)
        printf("   ");
    for(j = s; j <= t; j++)
        printf("%3d", recs[j].key);
    printf("\n");
    i++;
}

/*---------------һ�˻���--------------*/
static int partition_recs(rec_type recs[], int s, int t)
{
    int i = s, j = t;//��ʼλ�ã� ����Ԫ�ظ���-1
    rec_type tmp = recs[i];                         //  ��recs[i]Ϊ��׼ [6, 8, 7, 9, 0, 1, 3, 2, 4, 5]

    while(i < j)                                    //  �����˽������м�ɨ��,ֱ��i=jΪֹ
    {
        while(i < j && recs[j].key >= tmp.key)
            j--;                                    //  ��������ɨ��,��һ��С��tmp.key��recs[j]
        recs[i] = recs[j];                          //  �ҵ�������recs[j],����recs[i]��
        while(i < j && recs[i].key <= tmp.key)
            i++;                                    //  ��������ɨ��,��һ������tmp.key��recs[i]
        recs[j] = recs[i];                          //  �ҵ�������recs[i],����recs[j]��
    }
    recs[i] = tmp;
    disp_partition(recs, s, t);

    return i;
}

static void quick_sort(rec_type recs[], int s, int t)
{
    int i;

    if(s < t)                                       //  ���������ٴ�������Ԫ�ص����
    {
        i = partition_recs(recs, s, t);
        quick_sort(recs, s, i - 1);                 //  ��������ݹ�����
        quick_sort(recs, i + 1, t);                 //  ��������ݹ�����
    }
}

int main(int argc, char *argv[])
{
    int n = 8;
    rec_type recs[MAX_LEN];
    key_type a[] = {10,80,45,3,65,23,98,8};

    create_list(recs, a, n);
    printf("����ǰ: ");
    disp_list(recs, n);
    quick_sort(recs, 0, n - 1);
    printf("�����: ");
    disp_list(recs, n);
    return 0;
}



