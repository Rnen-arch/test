//��������
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// ����˳���ṹ
typedef struct {
    int data[MAX_SIZE];
    int length;
} SeqList;

// ��������ķ�������
int partition(SeqList *list, int low, int high) {
    int pivot = list->data[high]; // ѡ�����һ��Ԫ����Ϊ����
    int i = low - 1; // i ��С�������Ԫ�ص�����

    for (int j = low; j < high; j++) {
        if (list->data[j] < pivot) {
            i++;
            // ���� list->data[i] �� list->data[j]
            int temp = list->data[i];
            list->data[i] = list->data[j];
            list->data[j] = temp;
        }
    }
    // ���� list->data[i+1] �� list->data[high] (����)
    int temp = list->data[i + 1];
    list->data[i + 1] = list->data[high];
    list->data[high] = temp;

    return i + 1;
}

// ��������
void quickSort(SeqList *list, int low, int high) {
    if (low < high) {
        int pi = partition(list, low, high);
        quickSort(list, low, pi - 1);  // �ݹ�������������
        quickSort(list, pi + 1, high); // �ݹ�������������
    }
}

// ����Ԫ�� X ��˳�����
void insert(SeqList *list, int x) {
    int i;
    // ���Ҳ���λ��
    for (i = 0; i < list->length; i++) {
        if (list->data[i] > x) {
            break;
        }
    }
    // ��� i == list->length��˵�� X ������Ԫ�ض��󣬲��뵽ĩβ
    if (i == list->length) {
        list->data[list->length] = x;
    } else {
        // �� i ����֮���Ԫ������ƶ�һλ
        for (int j = list->length; j > i; j--) {
            list->data[j] = list->data[j - 1];
        }
        // ���� X
        list->data[i] = x;
    }
    // ����˳�����
    list->length++;
}

// ��ӡ˳���
void printList(SeqList *list) {
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    SeqList list;
    list.length = 0;

    // ���û������ʼ��˳���
    int n;
    printf("������˳���ĳ���: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("����ĳ��ȳ���������� %d�������˳���\n", MAX_SIZE);
        return 1;
    }

    printf("������ %d ������: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list.data[i]);
    }
    list.length = n;

    // ��˳����������
    quickSort(&list, 0, list.length - 1);

    // ��ӡ������˳���
    printf("������˳���: ");
    printList(&list);

    // ���û�����Ҫ�����Ԫ��
    int x;
    printf("������Ҫ�����Ԫ��: ");
    scanf("%d", &x);

    // ����Ԫ��
    insert(&list, x);

    // ��ӡ������˳���
    printf("���� %d ���˳���: ", x);
    printList(&list);

    return 0;
}
