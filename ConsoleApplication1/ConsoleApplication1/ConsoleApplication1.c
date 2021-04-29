#include "stdafx.h"
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <math.h>
void swap(int* a, int* b) // ������� ��� ������� ������ �������� 
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int low, int high) // ������� ��� ������
{
	int pov = arr[high];  // ������� ������� ��� pov
	int i = (low - 1);  // ������ ���������� ��������

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pov) // ���� ��������� ������� ������ ��� ����� �� ������� p
		{
			i++;    // ������ ������ ���������� �������� 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quicksort(int a[], int p, int r) // p ���������� ������ r ������� ������ 
{
	if (p < r)
	{
		int q;
		q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}
void printArray(int a[], int size) // ��������� ����������� ������ 
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
long m1(int a, int b) // ������� ��� ����������� 1 ���������� �����
{
	if (a < b)
		b = a;
	else
		if (a = b)
			b = a;
		else
			b = b;
	return b;
}
long m2(int a, int b, int c) // ������� ��� ����������� 2 ���������� ����� 
{
	if (a < b && a > c)
		b = a;
	else
		if (a = b && a > c)
			b = a;
		else
			b = b;
	return b;
}
struct rozdil1 // ��������� 1-�� ������ � ����� ��� �������� 6 ��������
{
	char pracivnik[15]; // ������� ��������
	int pay; // �������� ������ ��������
	int age; // ������ ���� ������ ��� �������
};
struct rozdil2 // ��������� 2-�� ������ � ����� ��� �������� 4 ��������
{
	char pracivnik[15];
	int pay;
	int age;
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int c[6]; // ��������� ����� ��� ���������� ������� 1-�� ������ 
	int d[4]; // ��������� ����� ��� ���������� ������� 2-�� ������
	struct rozdil1 a[6]; // ��������� 1-�� ��������� �� �
	struct rozdil2 b[4]; // ��������� 2-�� ��������� �� b
	int min1, min2, min3, min4, minimal, i;
	int n1 = sizeof(c) / sizeof(c[0]);
	int n2 = sizeof(d) / sizeof(d[0]);
	min1 = 0; // ������ �������� �������� 0 
	min2 = 0;
	min3 = 0;
	min4 = 0;
	for (i = 0; i < 6; i++) // �������� �����
	{
		printf("������ ��� ������� �������� � ������� 1 ���� �������, �������� ������ �� ������ ���� �� ������\n ");
		scanf_s("%s %d %d", a[i].pracivnik, &a[i].pay, &a[i].age);
	}
	printf("\n"); // ������
	printf("��� ��� ������� �������� �� �������� ����� ��������: \n"); // ��������� �����
	for (i = 0; i < 6; i++)
	{
		printf(" %s , ���� ����� = %d , ������ %d �.\n", a[i].pracivnik, a[i].pay, a[i].age);
	}
	printf("\n");
	for (i = 0; i < 4; i++)
	{
		printf("������ ��� ������� �������� � ������� 2 ���� �������, �������� ������ �� ������ ���� �� ������\n ");
		scanf_s("%s %d %d", b[i].pracivnik, &b[i].pay, &b[i].age);
	}
	printf("\n");
	printf("��� ��� ������� �������� �� �������� ����� ��������: \n");
	for (i = 0; i < 4; i++)
	{
		printf(" %s , ���� ����� = %d , ������ %d �.\n", b[i].pracivnik, b[i].pay, b[i].age);
	}
	minimal = a[0].pay; // ������ �������� 1 �������� ��������� ��� ���������� minimal ��� ��������� ���� � ������
	for (i = 0; i < 6; i++)
	{
		min1 = m1(a[i].pay, minimal); // ���������� �-�� �������� ��������� � ��������� ���������, ��� �� �������� 1-�� �������� 
	}
	minimal = a[0].pay; // ������� �������� �� �����������
	for (i = 0; i < 6; i++)
	{
		min2 = m2(a[i].pay, minimal, min1); // ���������� �-�� �������� ��������� � ��������� ��������� �� 1 ���������, ��� �� �������� 2-�� ��������
	}
	minimal = b[0].pay;
	for (i = 0; i < 4; i++)
	{
		min3 = m1(b[i].pay, minimal);
	}
	minimal = b[0].pay;
	for (i = 0; i < 4; i++)
	{
		min4 = m2(b[i].pay, minimal, min3);
	}
	printf("\n");
	printf("�� ������� ������� ����� � ������� ������� %d %d\n", min1, min2);
	printf("�� ������� ������� ����� � ������� ������� %d %d\n", min3, min4);
	printf("������ �� ��� ��������� �������� ����� �������� 1 ������ \n");
	for (i = 0; i < 6; i++)
	{
		scanf_s("%d", &c[i]);
	}
	quicksort(c, 0, n1 - 1); // ����������
	printf("³��������� �������� 1-�� ������ ������� �������� ���������� \n");
	printArray(c, n1);
	printf("������ �� ��� ��������� �������� ����� �������� 2 ������ \n");
	for (i = 0; i < 4; i++)
	{
		scanf_s("%d", &d[i]);
	}
	quicksort(d, 0, n2 - 1); // ����������
	printf("³��������� �������� 2-�� ������ ������� �������� ���������� \n");
	printArray(d, n2);
	return 0;
}