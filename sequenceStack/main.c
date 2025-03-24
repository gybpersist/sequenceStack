#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//���ͱ���
typedef int dataType_t;
///////////////////////////////////////////////////////////////////////////////////////////////////
//����˳��ջ��¼����(˳��ջ��ջ�׵�ַ ˳��ջ������ ˳��ջ��ջ��Ԫ�ص��±�)
typedef struct sequenceStack {
    dataType_t *Bottom;       //˳��ջ��ջ�׵�ַ
    unsigned int size;      //˳��ջ������
    int Top;               //˳��ջ��ջ��Ԫ�ص��±�
} sqStack_t;
///////////////////////////////////////////////////////////////////////////////////////////////////
//1 ����˳��ջ����˳��ջ���г�ʼ��
sqStack_t *sqStack_Create(unsigned int size)
{
    //1.1 ����callocΪ˳��ջ�Ĺ���ṹ��������ڴ�
    sqStack_t *manager = (sqStack_t*)calloc(1,sizeof (manager));

    if(NULL == manager)
    {
        perror("calloc memory for manager is failed");
        exit(-1);       //������ֹ
    }

    //1.2 Ϊ����Ԫ��������ڴ� calloc,����ɴ�����
    manager->Bottom = (dataType_t*)calloc(size,sizeof(dataType_t));

    if(NULL == manager->Bottom)
    {
        perror("calloc memory for element is failed");
        free(manager);  //�ͷ��ڴ�
        exit(-1);       //������ֹ
    }

    //1.3 �Թ���˳��ջ�Ľṹ����г�ʼ����Ԫ������ ���Ԫ���±꣩
    manager->size = size; //��˳��ջ���������г�ʼ��
    manager->Top = -1;   //����˳��ջΪ�գ������Ԫ���±��ֵΪ-1

    return manager;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//�ж�˳��ջ�Ƿ�����
bool sqStack_IsFull(sqStack_t *manager)
{
    return (manager->Top+1 == manager->size) ? true : false;
//        if(manager->Top+1 == manager->size)
//    {
//        return ture;
//    }
//    return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//2 ˳��ջ   ��ջ
bool sqStack_Push (sqStack_t *manager,dataType_t data)
{
    //2.1 �ж�˳��ջ�Ƿ�����
    if(sqStack_IsFull(manager))
    {
        printf("sequenceStack is Full!\n");
        return false;
    }

    //2.2 ��˳��ջ�п��пռ䣬�����Ԫ����ӵ�˳��ջβ��
/*    manager->Bottom++;
    *(manager->Bottom + manager->Top) = data;   */
    manager->Bottom[++manager->Top] = data;
    return true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//�ж�˳��ջ�Ƿ�Ϊ��
bool sqStack_IsEmpty(sqStack_t *manager)
{
    return (manager->Top == -1) ? true : false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//4 ˳��ջ  ��ջ
dataType_t sqStack_Pop (sqStack_t *manager)
{
    dataType_t temp=-1;     //��¼��Ҫ��ջ��ֵ

    //4.1 �ж�˳��ջ�Ƿ�Ϊ��
    if(sqStack_IsEmpty(manager))
    {
        printf("SequenceStack is Empty!\n");
        return -1;
    }

    //4.2 ����ɾ��һ��Ԫ�أ���˳��ջ��ЧԪ���±��һ ��--���ȸ�ֵ��--��
    temp = manager->Bottom[manager->Top--];
    return temp;

    //return manager->Bottom[manager->Top--];
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//5 ����˳��ջ�е�Ԫ��
void sqStack_print (sqStack_t *manager)
{
    for(int i=0;i<=manager->Top;i++)
    {
        printf("Element[%d]=%d\n",i,manager->Bottom[i]);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{

    //1 ����˳��ջ
    sqStack_t *manager = sqStack_Create(10);

    //2 ��˳��ջ  ��ջ
    sqStack_Push (manager,5);
    sqStack_Push (manager,2);
    sqStack_Push (manager,1);
    sqStack_Push (manager,4);
    sqStack_Push (manager,6);
    sqStack_Push (manager,8);

    //3 ����˳��ջ
    sqStack_print (manager);     //5 2 1 4 6
    printf("\n");

    //6 ��ջ
    dataType_t temp1,temp2,temp3,temp4;
    
    temp1 = sqStack_Pop (manager);
    printf(" ��ջ��%d ",temp1);

    temp2 = sqStack_Pop (manager);
    printf(" ��ջ��%d ",temp2);

    temp3 = sqStack_Pop (manager);
    printf(" ��ջ��%d ",temp3);

    temp4 = sqStack_Pop (manager);
    printf(" ��ջ��%d\n",temp4);

    //7 ����˳��ջ
    sqStack_print (manager);     //8 8 4 8 2 4
    printf("\n");

    return 0;
}
