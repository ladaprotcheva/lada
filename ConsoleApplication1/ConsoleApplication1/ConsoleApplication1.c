#include "stdafx.h"
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <math.h>
void swap(int* a, int* b) // функція щоб поміняти місцями елементи 
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int low, int high) // функція для розділу
{
	int pov = arr[high];  // останній елемент стає pov
	int i = (low - 1);  // індекс найменшого елемента

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pov) // якщо теперешній елемент менший або рівний за елемент p
		{
			i++;    // збільшує індекс найменшого елемента 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quicksort(int a[], int p, int r) // p початковий індекс r останній індекс 
{
	if (p < r)
	{
		int q;
		q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}
void printArray(int a[], int size) // виведення відсортованої строки 
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
long m1(int a, int b) // функція для знаходження 1 мінімального числа
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
long m2(int a, int b, int c) // функція для знаходження 2 мінімального числа 
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
struct rozdil1 // структура 1-го розділу в якому для прикладу 6 робітників
{
	char pracivnik[15]; // прізвище робітника
	int pay; // заробітня платня робітника
	int age; // скільки років працює цей робітник
};
struct rozdil2 // структура 2-го розділу в якому для прикладу 4 робітника
{
	char pracivnik[15];
	int pay;
	int age;
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int c[6]; // допоміжний масив для сортування зарплат 1-го розділу 
	int d[4]; // допоміжний масив для сортування зарплат 2-го розділу
	struct rozdil1 a[6]; // позначимо 1-шу структура за а
	struct rozdil2 b[4]; // позначимо 2-гу структуру за b
	int min1, min2, min3, min4, minimal, i;
	int n1 = sizeof(c) / sizeof(c[0]);
	int n2 = sizeof(d) / sizeof(d[0]);
	min1 = 0; // задамо мінімальне значення 0 
	min2 = 0;
	min3 = 0;
	min4 = 0;
	for (i = 0; i < 6; i++) // введення даних
	{
		printf("Введіть для кожного робітника у підрозділі 1 його прізвище, заробітню платню та скільки років він працює\n ");
		scanf_s("%s %d %d", a[i].pracivnik, &a[i].pay, &a[i].age);
	}
	printf("\n"); // відступ
	printf("Дані для першого підрозділа по заробітній платні робітника: \n"); // виведення даних
	for (i = 0; i < 6; i++)
	{
		printf(" %s , його плата = %d , працює %d р.\n", a[i].pracivnik, a[i].pay, a[i].age);
	}
	printf("\n");
	for (i = 0; i < 4; i++)
	{
		printf("Введіть для кожного робітника у підрозділі 2 його прізвище, заробітню платню та скільки років він працює\n ");
		scanf_s("%s %d %d", b[i].pracivnik, &b[i].pay, &b[i].age);
	}
	printf("\n");
	printf("Дані для другого підрозділа по заробітній платні робітника: \n");
	for (i = 0; i < 4; i++)
	{
		printf(" %s , його плата = %d , працює %d р.\n", b[i].pracivnik, b[i].pay, b[i].age);
	}
	minimal = a[0].pay; // задамо значення 1 елементу структури для загального minimal щоб зрівнювати його з іншими
	for (i = 0; i < 6; i++)
	{
		min1 = m1(a[i].pay, minimal); // прирівняння і-го значення структури з загальним мінімальним, так ми знайдемо 1-ше мінімальне 
	}
	minimal = a[0].pay; // скидаємо значення до початкового
	for (i = 0; i < 6; i++)
	{
		min2 = m2(a[i].pay, minimal, min1); // прирівняння і-го значення структури з загальним мінімальним та 1 мінімальним, так ми знайдемо 2-ге мінімальне
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
	printf("Дві мінімальні заробітні платні у першому підрозділі %d %d\n", min1, min2);
	printf("Дві мінімальні заробітні платні у другому підрозділі %d %d\n", min3, min4);
	printf("Введіть ще раз почергово заробітню плату робітників 1 розділу \n");
	for (i = 0; i < 6; i++)
	{
		scanf_s("%d", &c[i]);
	}
	quicksort(c, 0, n1 - 1); // сортування
	printf("Відсортовані зарплати 1-го розділу методом швидкого сортування \n");
	printArray(c, n1);
	printf("Введіть ще раз почергово заробітню плату робітників 2 розділу \n");
	for (i = 0; i < 4; i++)
	{
		scanf_s("%d", &d[i]);
	}
	quicksort(d, 0, n2 - 1); // сортування
	printf("Відсортовані зарплати 2-го розділу методом швидкого сортування \n");
	printArray(d, n2);
	return 0;
}