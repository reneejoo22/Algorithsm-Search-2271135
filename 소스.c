//�پ��� Ž�� ���

#include<stdio.h>

#define MAX_NUM 9
int list[MAX_NUM] = { 1,2,3,4,5,6,7,8,9 };

int seq_search(int key, int low, int high) {	//���� �⺻���� ����Ž��_

	int i;

	for (i = low; i < high; i++)
		if (list[i] == key)
			return i;	//Ž���� �����ϸ� ��ġ �� ����
	return -1; //Ž���� �����ϸ� -1 ����

}

int seq_search2(int key, int low, int high) {	//������ ����Ž��_ 

	int i;

	list[high + 1] = key;
	for (i = low; list[i] != key; i++)	//Ű �� ã���� ����
		;
	if (i == (high + 1)) return -1;
			return i;	//ã�� Ű���� ���Ƿ� �߰��ߴ� ���̸� ���д� -1, �ƴҽ� �����̴� i ��ȯ
	return -1; //Ž���� �����ϸ� -1 ����

}

int binary_search(int key, int low, int high) {	//��ȯȣ���� �̿��� ����Ž��

	int middle;

	if (low <= high) {
		middle = (low + high) / 2;
		if (key == list[middle])
			return middle;
		else if (key < list[middle])	//���� �κ� Ž��
			return binary_search(key, low, middle - 1);
		else	//������ �κи� Ž��
			return binary_search(key, middle + 1, high);
	}
	return -1;	//Ž�� ����
}

int binary_search2(int key, int low, int high) {	//�ݺ��� �̿��� ����Ž��_ ���� ���� �߰��� ��� ����

	int middle;

	while (low <= high) {

		middle = (low + high) / 2;
		
		if (key == list[middle])
			return middle;
		
		else if (key > list[middle])	//���� �κ� Ž��
			low = middle + 1;
		else	//������ �κи� Ž��
			high = middle - 1;
	}
	return -1;	//Ž�� ����
}

//���� ���� Ž��
#define INDEX_SIZE 256

typedef struct {

	int key;
	int index;
} itable;

itable index_list[INDEX_SIZE] = { {1,0}, {4,3}, {7,6} };

int index_search(int key, int n) {	//���� ����Ž��
	
	int i, low, high;

	if (key<list[0] || key>list[n - 1])	//���ĵ� ���� ������ ���ڸ��� �ش�ġ ������ ���ٴ� ���̴� ����
		return -1;
	for (i = 0; i < INDEX_SIZE; i++)
		if (index_list[i].key <= key && index_list[i].key > key)
			break;
		
	if (i == INDEX_SIZE) {
		low = index_list[i - 1].index;
		high = n;
	}
	else {
		low = index_list[i].index;
		high = index_list[i + 1].index;
	}

	return seq_search(key, low, high);
}

int interpol_search(int key, int n) {	//����Ž��

	int low, high, j;

	low = 0;
	high = n - 1;

	while ((list[high] >= key) && (key > list[low])) {	//ã�������� ����
		j = ((float)(key - list[low]) / (list[high] - list[low]) * (high - low) + low);
		if (key > list[j]) low = j + 1;
		else if (key < list[j])high = j - 1;
		else low = j;	//��ã�� ��� �ش� ������ �����ϰ� ���� �ٽ�
	}
	if (list[low] == key)return(low);
	else return -1;
}

void main() {

	int start = 0; int end = MAX_NUM - 1;
	

	printf("����Ž��_6 ã��\n");
	printf("���_ [%d] ��ġ������\n\n", seq_search(6, start, end));

	printf("������ ����Ž��_6 ã��\n");
	printf("���_ [%d] ��ġ������\n\n", seq_search2(6, start, end));

	printf("��ȯȣ���� �̿��� ����Ž��_6 ã��\n");
	printf("���_ [%d] ��ġ������\n\n", binary_search(6, start, end));

	printf("�ݺ��� �̿��� ����Ž��_6 ã��\n");
	printf("���_ [%d] ��ġ������\n\n", binary_search2(6, start, end));

	printf("���� ����Ž��_6 ã��\n");
	printf("���_ [%d] ��ġ������\n\n", index_search(6, MAX_NUM));

	printf("����Ž��_6 ã��\n");
	printf("���_ [%d] ��ġ������\n\n", interpol_search(6, MAX_NUM));
}
