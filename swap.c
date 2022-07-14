#include<stdio.h>
#include<pthread.h>


void *swap(void *arr)
{
	int *array = (int *)arr;
	array[0] = array[0] ^ array[1];
	array[1] = array[0] ^ array[1];
	array[0] = array[0] ^ array[1];
}
int main()
{
	int arr[2];
	printf("Enter first number: ");
	scanf("%d", &arr[0]);
	printf("Enter second number: ");
	scanf("%d", &arr[1]);
	pthread_t thread;
	pthread_create(&thread, NULL, swap, (void *)arr);
	pthread_join(thread, NULL);
	printf("After swapping: first = %d, second = %d\n", arr[0], arr[1]);

	return 0;
}
