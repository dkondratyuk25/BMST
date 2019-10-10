#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int lenOfBinaryNumber(char *bin)
{
	int len = 0;
	//пока мы не дошли до конца числа обозначенного символом \0 в char, прибавляем по единице в длину числа
	while (bin[len] != '\0')
		len++;
	return len;
}


int binaryCharToDecimal(char* bin)
{
	int i = 1;
	int res = 0;
	int len = lenOfBinaryNumber(bin);
	//вычисление количества разрядов в двоичном числе

	//цикл по превращению двоичного числа в десятичного
	for (int k = len - 1; k > -1; k--)
	{
		if (bin[k] == '1')
			res += i;
		i *= 2;
	}
	return res;
}


int main()
{
	int arr_len;
	printf("Please input the length of the array: ");
	scanf("%d", &arr_len);

	printf("Input binary numbers: \n");

	char **binaryArray = malloc(arr_len * 64);//массив чисел, 64 это максимальная длина строки с числом
	//цикл который читает введеннуе двоичные числа с консоли и заполняет ими массив
	for (int i = 0; i < arr_len; i++)
	{
		binaryArray[i] = malloc(64);
		scanf("%s", binaryArray[i]);
	}

	//цикл который переводит числа из двоичной системы в десятичную и выводит числа
	for (int i = 0; i < arr_len; i++)
	{
		char* bin = binaryArray[i];
		int res = binaryCharToDecimal(bin);
		printf("%d \n", res);
	}
	getch();
	return 0;
}
