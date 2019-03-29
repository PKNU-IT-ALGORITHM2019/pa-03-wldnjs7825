#include<stdio.h>
#include<stdlib.h>
#include<time.h>
double BubbleSort(int a[], int n);
double SelectionSort(int a[], int n);
double InsertionSort(int a[], int n);
double MergeSort(int a[], int p, int r);
void Merge(int a[], int first, int m, int last);
double QuickSort(int a[], int first, int last);
int Partition(int a[], int first, int last);
double QuickSort_m(int a[], int first, int last);
int Partition_m(int a[], int first, int last);
double QuickSort_r(int a[], int first, int last);
int Partition_r(int a[], int first, int last);

void Reset_1000();
void Reset_10000();
void Reset_100000();
void swap(int a[], int i, int max);

double sum = 0;
int tmp;
int temp[100000]; //merge함수를 위한 추가배열
double playtime[7][6]; //0.bubble 1.selection 2.insertion 3.merge 4.quick 5.quick_m 6.quick_r
clock_t start, stop;
int rev_1000[1000];//거꾸로 정렬
int rev_10000[10000];
int rev_100000[100000];
int rand_1000[1000];//랜덤 정렬
int rand_10000[10000];
int rand_100000[100000];


int main() {	
	srand(time(NULL));
		
	Reset_1000();   playtime[0][0] = BubbleSort(rev_1000,   1000);
	for (int i = 0; i < 10; i++) {
		Reset_1000(); sum += BubbleSort(rand_1000, 1000);
	}playtime[0][1] = sum / 10; sum = 0;
	Reset_10000();  playtime[0][2] = BubbleSort(rev_10000,  10000);
	for (int i = 0; i < 10; i++) {
		Reset_10000();	sum += BubbleSort(rand_10000, 10000);
	}playtime[0][3] = sum / 10; sum = 0;
	//Reset_100000(); playtime[0][4] = BubbleSort(rev_100000, 100000);
	//Reset_100000(); playtime[0][5] = BubbleSort(rand_100000,100000);
	

	Reset_1000();   playtime[1][0] = SelectionSort(rev_1000, 1000);
	for (int i = 0; i < 10; i++) {
		Reset_1000(); sum += SelectionSort(rand_1000, 1000);
	}playtime[1][1] = sum / 10; sum = 0;
	Reset_10000();  playtime[1][2] = SelectionSort(rev_10000, 10000);
	for (int i = 0; i < 10; i++) {
		Reset_10000(); sum += SelectionSort(rand_10000, 10000);
	}playtime[1][3] = sum / 10; sum = 0;
	//Reset_100000(); playtime[1][4] = SelectionSort(rev_100000, 100000);
	//Reset_100000(); playtime[1][5] = SelectionSort(rand_100000,100000);


	Reset_1000();   playtime[2][0] = InsertionSort(rev_1000, 1000);
	for (int i = 0; i < 10; i++) {
		Reset_1000(); sum += InsertionSort(rand_1000, 1000);
	}playtime[2][1] = sum / 10; sum = 0;
	Reset_10000();  playtime[2][2] = InsertionSort(rev_10000, 10000);
	for (int i = 0; i < 10; i++) {
		Reset_10000(); sum += InsertionSort(rand_10000, 10000);
	}playtime[2][3] = sum / 10; sum = 0;
	//Reset_100000(); playtime[2][4] = InsertionSort(rev_100000, 100000);
	//Reset_100000(); playtime[2][5] = InsertionSort(rand_100000,100000);


	Reset_1000();   playtime[3][0] = MergeSort(rev_1000,    0, 999);
	for (int i = 0; i < 10; i++) {
		Reset_1000(); sum += MergeSort(rand_1000, 0, 999);
	}playtime[3][1] = sum / 10; sum = 0;
	Reset_10000();  playtime[3][2] = MergeSort(rev_10000,   0, 9999);
	for (int i = 0; i < 10; i++) {
		Reset_10000(); sum += MergeSort(rand_10000, 0, 9999);
	}playtime[3][3] = sum / 10; sum = 0;
	Reset_100000(); playtime[3][4] = MergeSort(rev_100000, 0, 99999);
	for (int i = 0; i < 10; i++) {
		Reset_100000(); sum += MergeSort(rand_100000, 0, 99999);
	}playtime[3][5] = sum / 10; sum = 0;

	
	Reset_1000();  	playtime[4][0] = QuickSort(rev_1000, 0, 999);
	for (int i = 0; i < 10; i++) {
		Reset_1000(); sum += QuickSort(rand_1000, 0, 999);
	}playtime[4][1] = sum / 10; sum = 0;
	//Reset_10000();  playtime[4][2] = QuickSort(rev_10000, 0, 9999);
	for (int i = 0; i < 10; i++) {
		Reset_10000(); sum += QuickSort(rand_10000, 0, 9999);
	}playtime[4][3] = sum / 10; sum = 0;
	//Reset_100000(); playtime[4][4] = QuickSort(rev_100000, 0, 99999);
	for (int i = 0; i < 10; i++) {
		Reset_100000(); sum += QuickSort(rand_100000, 0, 99999);
	}playtime[4][5] = sum / 10; sum = 0;


	Reset_1000();   playtime[5][0] = QuickSort_m(rev_1000, 0, 999);
	for (int i = 0; i < 10; i++) {
		Reset_1000(); sum += QuickSort_m(rand_1000, 0, 999);
	}playtime[5][1] = sum / 10; sum = 0;
    //Reset_10000();  playtime[5][2] = QuickSort_m(rev_10000, 0, 9999);
	for (int i = 0; i < 10; i++) {
		Reset_10000(); sum += QuickSort_m(rand_10000, 0, 9999);
	}playtime[5][3] = sum / 10; sum = 0;
    //Reset_100000(); playtime[5][4] = QuickSort_m(rev_100000, 0, 99999);
	for (int i = 0; i < 10; i++) {
		Reset_100000(); sum += QuickSort_m(rand_100000, 0, 99999);
	}playtime[5][5] = sum / 10; sum = 0;

	Reset_1000();   playtime[6][0] = QuickSort_r(rev_1000, 0, 999);
	for (int i = 0; i < 10; i++) {
		Reset_1000(); sum += QuickSort_r(rand_1000, 0, 999);
	}playtime[6][1] = sum / 10; sum = 0;
	//Reset_10000();  playtime[6][2] = QuickSort_r(rev_10000, 0, 9999);
	for (int i = 0; i < 10; i++) {
		Reset_10000(); sum += QuickSort_r(rand_10000, 0, 9999);
	}playtime[6][3] = sum / 10; sum = 0;
    //Reset_100000(); playtime[6][4] = QuickSort_r(rev_100000, 0, 99999);
	for (int i = 0; i < 10; i++) {
		Reset_100000(); sum += QuickSort_r(rand_100000, 0, 99999);
	}playtime[6][5] = sum / 10; sum = 0;
	
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("\t\tReverse1000\tRandom1000\tReverse10000\tRandom10000\tReverse100000\tRandom100000\n");
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("Bubble\t\t");
	for(int i = 0;i < 6; i++)
		printf(" %f\t", playtime[0][i]); printf("\n");
	printf("Selection\t");
	for (int i = 0; i<6; i++)
		printf(" %f\t", playtime[1][i]); printf("\n");
	printf("Insertion\t");
	for (int i = 0; i<6; i++)
		printf(" %f\t", playtime[2][i]); printf("\n");
	printf("Merge\t\t");
	for (int i = 0; i<6; i++)
		printf(" %f\t", playtime[3][i]); printf("\n");
	printf("Quick1\t\t");
	for (int i = 0; i<6; i++)
		printf(" %f\t", playtime[4][i]); printf("\n");
	printf("Quick2\t\t");
	for (int i = 0; i<6; i++)
		printf(" %f\t", playtime[5][i]); printf("\n");
	printf("Quick3\t\t");
	for (int i = 0; i<6; i++)
		printf(" %f\t", playtime[6][i]); printf("\n");
	
	return 0;
}

void Reset_1000()
{
	int n = 1000;
	for (int i = 0; i < n; i++)
	{
		rev_1000[i] = n - i;
		rand_1000[i] = rand()%n+1;
	}
}

void Reset_10000()
{
	int n = 10000;
	for (int i = 0; i < n; i++)
	{
		rev_10000[i] = n - i;
		rand_10000[i] = rand() % n + 1;
	}
}
void Reset_100000()
{
	int n = 100000;
	for (int i = 0; i < n; i++)
	{
		rev_100000[i] = n - i;
		rand_100000[i] = rand() % n + 1;
	}
}


void swap(int a[], int i, int max)
{
	tmp = a[i];
	a[i] = a[max];
	a[max] = tmp;
}

double BubbleSort(int a[],int n){
	start = clock();
	for (int i = n; i > 1; i--) //n-1번 반복
	{ 
		for (int j = 0; j < i-1; j++) 
		{
			if (a[j] > a[j + 1])
				swap(a, j, j+1);
		}
	}
	stop = clock();
	return ((double)stop - start)/1000;
}

double SelectionSort(int a[], int n) {
	start = clock();
	int max = 0;
	int j = 0;
	int max_index = 0;
	for (int i = n-1; i > 0; i--)
	{
		max = i;
		for (j = 0; j <= i; j++)
		{
			if (a[j] > a[max])
				max = j;
		}
		swap(a, i, max);
	}
	stop = clock();
	return ((double)stop - start) / 1000;
}

double InsertionSort(int a[], int n)
{
	start = clock();
	for (int i = 1; i < n; i++)
	{		
		tmp = a[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (tmp < a[j])
			{
				a[j + 1] = a[j];
				if (j == 0)
					a[j] = tmp;
			}
			else
			{
				a[j + 1] = tmp;
				break;
			}
		}
	}
	stop = clock();
	return ((double)stop - start) / 1000;
}

double MergeSort(int a[], int first, int last) //first = 0; last = 999;
{
	start = clock();
	int m;
	if (first < last)
	{
		m = (first + last) / 2; 
		MergeSort(a, first, m);
		MergeSort(a, m + 1, last);
		Merge(a, first, m, last);
	}
	stop = clock();
	return ((double)stop - start) /1000;
}

void Merge(int a[], int first, int m, int last) //정렬되어 있는 두 배열을 합함
{
	int i = first;
	int j = m + 1;
	int cnt = 0;

	while (i <= m && j <= last)
	{
		if (a[i] <= a[j])
			temp[cnt++] = a[i++];
		else
			temp[cnt++] = a[j++];
	}
	while (i <= m)
		temp[cnt++] = a[i++];
	while (j <= last)
		temp[cnt++] = a[j++];
	for (int k = 0; k < cnt; k++)
		a[first++] = temp[k];
}

double QuickSort(int a[], int first, int last) //마지막 값을 피봇으로 선택
{
	start = clock();
	if (first < last)
	{
		int m = Partition(a, first, last);
		QuickSort(a, first, m - 1);
		QuickSort(a, m + 1, last);
	}
	stop = clock();
	return ((double)stop - start) / 1000;
}

int Partition(int a[], int first, int last) 
{
	int pivot = a[last]; //pivot
	int i = first - 1; //pivot보다 작은 값들 중 마지막 값
	for (int j = first; j < last; j++) //j가 지금 검사 하려는 값
	{
		if (a[j] < pivot)
		{
			i++;
			swap(a, i, j);
		}
	}
	swap(a, i+1, last);

	return i+1;//pivot을 반환
}

double QuickSort_m(int a[], int first, int last)//중간값을 피봇으로 선택
{
	start = clock();
	if (first < last)
	{
		int m = Partition_m(a, first, last);
		QuickSort(a, first, m - 1);
		QuickSort(a, m + 1, last);
	}
	stop = clock();
	return ((double)stop - start) / 1000;
}

int Partition_m(int a[], int first, int last)
{
	
	int i = first - 1; //pivot보다 작은 값들 중 마지막 값
	int m = (first + last) / 2;
	if ((a[first] >= a[last] && a[first] <= a[m]) || (a[first] <= a[last] && a[first] >= a[m]))
		swap(a, first, last);
	else if ((a[m] >= a[first] && a[m] <= a[last]) || (a[m] <= a[first] && a[m] >= a[last]))
		swap(a, m, last);
	int pivot = a[last];
	
	for (int j = first; j < last; j++) //j가 지금 검사 하려는 값
	{
		if (a[j] < pivot)
		{
			i++;
			swap(a, i, j);
		}
	}
	swap(a, i + 1, last);

	return i + 1;//pivot을 반환
}

double QuickSort_r(int a[], int first, int last)//랜덤값을 피봇으로 선택
{
	start = clock();
	if (first < last)
	{
		int m = Partition_r(a, first, last);
		QuickSort(a, first, m - 1);
		QuickSort(a, m + 1, last);
	}
	stop = clock();
	return ((double)stop - start) / 1000;
}

int Partition_r(int a[], int first, int last)
{
	int r = a[rand()%(last-first+1)+first];
	int i = first - 1; //pivot보다 작은 값들 중 마지막 값
	
	swap(a, r, last);
	int pivot = a[last];

	for (int j = first; j < last; j++) //j가 지금 검사 하려는 값
	{
		if (a[j] < pivot)
		{
			i++;
			swap(a, i, j);
		}
	}
	swap(a, i + 1, last);

	return i + 1;//pivot을 반환
}