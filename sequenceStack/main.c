#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//类型别名
typedef int dataType_t;
///////////////////////////////////////////////////////////////////////////////////////////////////
//构造顺序栈记录参数(顺序栈的栈底地址 顺序栈的容量 顺序栈的栈顶元素的下标)
typedef struct sequenceStack {
    dataType_t *Bottom;       //顺序栈的栈底地址
    unsigned int size;      //顺序栈的容量
    int Top;               //顺序栈的栈顶元素的下标
} sqStack_t;
///////////////////////////////////////////////////////////////////////////////////////////////////
//1 创建顺序栈并对顺序栈进行初始化
sqStack_t *sqStack_Create(unsigned int size)
{
    //1.1 利用calloc为顺序栈的管理结构体申请堆内存
    sqStack_t *manager = (sqStack_t*)calloc(1,sizeof (manager));

    if(NULL == manager)
    {
        perror("calloc memory for manager is failed");
        exit(-1);       //程序终止
    }

    //1.2 为所有元素申请堆内存 calloc,并完成错误处理
    manager->Bottom = (dataType_t*)calloc(size,sizeof(dataType_t));

    if(NULL == manager->Bottom)
    {
        perror("calloc memory for element is failed");
        free(manager);  //释放内存
        exit(-1);       //程序终止
    }

    //1.3 对管理顺序栈的结构体进行初始化（元素容量 最后元素下标）
    manager->size = size; //对顺序栈的容量进行初始化
    manager->Top = -1;   //由于顺序栈为空，则最后元素下标初值为-1

    return manager;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//判断顺序栈是否以满
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
//2 顺序栈   入栈
bool sqStack_Push (sqStack_t *manager,dataType_t data)
{
    //2.1 判断顺序栈是否以满
    if(sqStack_IsFull(manager))
    {
        printf("sequenceStack is Full!\n");
        return false;
    }

    //2.2 若顺序栈有空闲空间，则把新元素添加到顺序栈尾部
/*    manager->Bottom++;
    *(manager->Bottom + manager->Top) = data;   */
    manager->Bottom[++manager->Top] = data;
    return true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//判断顺序栈是否为空
bool sqStack_IsEmpty(sqStack_t *manager)
{
    return (manager->Top == -1) ? true : false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//4 顺序栈  出栈
dataType_t sqStack_Pop (sqStack_t *manager)
{
    dataType_t temp=-1;     //记录需要出栈的值

    //4.1 判断顺序栈是否为空
    if(sqStack_IsEmpty(manager))
    {
        printf("SequenceStack is Empty!\n");
        return -1;
    }

    //4.2 由于删掉一个元素，则顺序栈有效元素下标减一 后--（先赋值后--）
    temp = manager->Bottom[manager->Top--];
    return temp;

    //return manager->Bottom[manager->Top--];
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//5 遍历顺序栈中的元素
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

    //1 创建顺序栈
    sqStack_t *manager = sqStack_Create(10);

    //2 向顺序栈  入栈
    sqStack_Push (manager,5);
    sqStack_Push (manager,2);
    sqStack_Push (manager,1);
    sqStack_Push (manager,4);
    sqStack_Push (manager,6);
    sqStack_Push (manager,8);

    //3 遍历顺序栈
    sqStack_print (manager);     //5 2 1 4 6
    printf("\n");

    //6 出栈
    dataType_t temp1,temp2,temp3,temp4;
    
    temp1 = sqStack_Pop (manager);
    printf(" 出栈：%d ",temp1);

    temp2 = sqStack_Pop (manager);
    printf(" 出栈：%d ",temp2);

    temp3 = sqStack_Pop (manager);
    printf(" 出栈：%d ",temp3);

    temp4 = sqStack_Pop (manager);
    printf(" 出栈：%d\n",temp4);

    //7 遍历顺序栈
    sqStack_print (manager);     //8 8 4 8 2 4
    printf("\n");

    return 0;
}
