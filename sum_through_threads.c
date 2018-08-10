/*
* @Author: Siddhartha Arora
* @Date:   2018-08-09 19:43:24
* @Last Modified by:   Siddhartha Arora
* @Last Modified time: 2018-08-09 21:04:20
*/


/*Trying Multhreading in c by creating a function sum which adds numbers till a user defined limit 
  and simentaneously asking the user to input 10 numbers */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long long sum =0;

void* sum_on_thread(void* arg)
{
	long long* num_ptr = (long long*) arg;
	long long num = *num_ptr;

	for(long long i = 0; i<=num;i++)
	{
		sum = sum +i;
	}


	pthread_exit(0);
}

int main(int argc, char const *argv[])
{
	
	if(argc<2)
	{
		printf(" \nYou need to enter just one argument");
		exit(0);
	}

	//Getting the number from the user
	long long num = atoll(argv[1]);

	//Thread id that I will use 
	pthread_t tid;

	//Creating attributes
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	/*Using the Pthread_create function and passing values. We are not passing the sum function like - "sum_on_thread()"
	beacuse we just want to pass the function pointer and not execute the function*/
	pthread_create(&tid,&attr,sum_on_thread, &num);

	//Waiting till the thread does work

	printf("\nLet us take input from the user on a different thread");

	int a[10];
	//int a;
	printf("\nEnter 10 numbers ");

	for(int j = 0;j<10;j++)
	{
		scanf("%d",&a[j]);
	}

	printf("\n The numbers that you have entered are :- \n");

	for(int j = 0;j<10;j++)
	{
		printf("Number %d : %d\n",j,a[j]);
	}

	//printf(" \n The number that you entered is : %d\n",a);
	pthread_join(tid,NULL);	//NULL beacuse we are not passing ny values back


printf("\n\n The sum is : %lld \n\n",sum);


	return 0;
}