//快速排序
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 定义顺序表结构
typedef struct {
    int data[MAX_SIZE];
    int length;
} SeqList;

// 快速排序的分区函数
int partition(SeqList *list, int low, int high) {
    int pivot = list->data[high]; // 选择最后一个元素作为枢轴
    int i = low - 1; // i 是小于枢轴的元素的索引

    for (int j = low; j < high; j++) {
        if (list->data[j] < pivot) {
            i++;
            // 交换 list->data[i] 和 list->data[j]
            int temp = list->data[i];
            list->data[i] = list->data[j];
            list->data[j] = temp;
        }
    }
    // 交换 list->data[i+1] 和 list->data[high] (枢轴)
    int temp = list->data[i + 1];
    list->data[i + 1] = list->data[high];
    list->data[high] = temp;

    return i + 1;
}

// 快速排序
void quickSort(SeqList *list, int low, int high) {
    if (low < high) {
        int pi = partition(list, low, high);
        quickSort(list, low, pi - 1);  // 递归排序左子数组
        quickSort(list, pi + 1, high); // 递归排序右子数组
    }
}

// 插入元素 X 到顺序表中
void insert(SeqList *list, int x) {
    int i;
    // 查找插入位置
    for (i = 0; i < list->length; i++) {
        if (list->data[i] > x) {
            break;
        }
    }
    // 如果 i == list->length，说明 X 比所有元素都大，插入到末尾
    if (i == list->length) {
        list->data[list->length] = x;
    } else {
        // 将 i 及其之后的元素向后移动一位
        for (int j = list->length; j > i; j--) {
            list->data[j] = list->data[j - 1];
        }
        // 插入 X
        list->data[i] = x;
    }
    // 更新顺序表长度
    list->length++;
}

// 打印顺序表
void printList(SeqList *list) {
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    SeqList list;
    list.length = 0;

    // 从用户输入初始化顺序表
    int n;
    printf("请输入顺序表的长度: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("输入的长度超过最大限制 %d，程序退出。\n", MAX_SIZE);
        return 1;
    }

    printf("请输入 %d 个整数: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list.data[i]);
    }
    list.length = n;

    // 对顺序表进行排序
    quickSort(&list, 0, list.length - 1);

    // 打印排序后的顺序表
    printf("排序后的顺序表: ");
    printList(&list);

    // 从用户输入要插入的元素
    int x;
    printf("请输入要插入的元素: ");
    scanf("%d", &x);

    // 插入元素
    insert(&list, x);

    // 打印插入后的顺序表
    printf("插入 %d 后的顺序表: ", x);
    printList(&list);

    return 0;
}
