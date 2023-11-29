//다양한 탐색 방법

#include<stdio.h>

#define MAX_NUM 9
int list[MAX_NUM] = { 1,2,3,4,5,6,7,8,9 };

int seq_search(int key, int low, int high) {	//가장 기본적인 순차탐색_

	int i;

	for (i = low; i < high; i++)
		if (list[i] == key)
			return i;	//탐색에 성공하면 위치 값 보냄
	return -1; //탐색에 실패하면 -1 리턴

}


void main() {

	int start = 0; int end = MAX_NUM - 1;
	

	printf("순차탐색_6 찾기\n");
	printf("결과_ [%d] 위치해있음\n\n", seq_search(6, start, end));
}