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


void main() {

	int start = 0; int end = MAX_NUM - 1;
	

	printf("����Ž��_6 ã��\n");
	printf("���_ [%d] ��ġ������\n\n", seq_search(6, start, end));
}