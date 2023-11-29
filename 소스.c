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

int seq_search2(int key, int low, int high) {	//개선된 순차탐색_ 

	int i;

	list[high + 1] = key;
	for (i = low; list[i] != key; i++)	//키 값 찾으면 종료
		;
	if (i == (high + 1)) return -1;
			return i;	//찾은 키값이 임의로 추가했던 값이면 실패니 -1, 아닐시 성공이니 i 반환
	return -1; //탐색에 실패하면 -1 리턴

}

int binary_search(int key, int low, int high) {	//순환호출을 이용한 이진탐색

	int middle;

	if (low <= high) {
		middle = (low + high) / 2;
		if (key == list[middle])
			return middle;
		else if (key < list[middle])	//왼쪽 부분 탐색
			return binary_search(key, low, middle - 1);
		else	//오른쪽 부분만 탐색
			return binary_search(key, middle + 1, high);
	}
	return -1;	//탐색 실패
}

int binary_search2(int key, int low, int high) {	//반복을 이용한 이진탐색_ 구간 값과 중간값 계속 갱신

	int middle;

	while (low <= high) {

		middle = (low + high) / 2;
		
		if (key == list[middle])
			return middle;
		
		else if (key > list[middle])	//왼쪽 부분 탐색
			low = middle + 1;
		else	//오른쪽 부분만 탐색
			high = middle - 1;
	}
	return -1;	//탐색 실패
}

//색인 순차 탐색
#define INDEX_SIZE 256

typedef struct {

	int key;
	int index;
} itable;

itable index_list[INDEX_SIZE] = { {1,0}, {4,3}, {7,6} };

int index_search(int key, int n) {	//색인 순차탐색
	
	int i, low, high;

	if (key<list[0] || key>list[n - 1])	//정렬된 값의 각각의 끝자리에 해당치 않으면 없다는 뜻이니 실패
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

int interpol_search(int key, int n) {	//보간탐색

	int low, high, j;

	low = 0;
	high = n - 1;

	while ((list[high] >= key) && (key > list[low])) {	//찾을때까지 연산
		j = ((float)(key - list[low]) / (list[high] - list[low]) * (high - low) + low);
		if (key > list[j]) low = j + 1;
		else if (key < list[j])high = j - 1;
		else low = j;	//못찾을 경우 해당 값으로 저장하고 연산 다시
	}
	if (list[low] == key)return(low);
	else return -1;
}

void main() {

	int start = 0; int end = MAX_NUM - 1;
	

	printf("순차탐색_6 찾기\n");
	printf("결과_ [%d] 위치해있음\n\n", seq_search(6, start, end));

	printf("개선된 순차탐색_6 찾기\n");
	printf("결과_ [%d] 위치해있음\n\n", seq_search2(6, start, end));

	printf("순환호출을 이용한 이진탐색_6 찾기\n");
	printf("결과_ [%d] 위치해있음\n\n", binary_search(6, start, end));

	printf("반복을 이용한 이진탐색_6 찾기\n");
	printf("결과_ [%d] 위치해있음\n\n", binary_search2(6, start, end));

	printf("색인 순차탐색_6 찾기\n");
	printf("결과_ [%d] 위치해있음\n\n", index_search(6, MAX_NUM));

	printf("보간탐색_6 찾기\n");
	printf("결과_ [%d] 위치해있음\n\n", interpol_search(6, MAX_NUM));
}
