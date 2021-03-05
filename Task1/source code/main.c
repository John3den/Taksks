#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 256

void ReadMatrix(int arr[N][N], int height, int width) {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			scanf("%i", &arr[i][j]);
}

void DisplayMatrix(int arr[N][N], int height, int width) {
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == height - 1 && j == width - 1)
				printf("%i", arr[i][j]);
			else
				printf("%i ", arr[i][j]);
		}
		printf("\n");
	}
}

int FindMinInRow(int arr[N][N], int height, int width, int row) {
	int min = arr[row][0];
	for (int j = 1; j < width; j++)
	{
		if (min > arr[row][j])
		{
			min = arr[row][j];
		}
	}
	return min;
}

int IsMaxInColumn(int arr[N][N], int height, int width, int column, int number) {
	for (int i = 0; i < height; i++)
	{
		if (arr[i][column] > number) return 0;
	}
	return 1;
}

int AverageInColumn(int arr[N][N], int height, int width, int column) {
	int sum = 0;
	for (int i = 0; i < height; i++)
		sum += arr[i][column];
	return sum / height;
}
int main() {
	int arr[N][N];
	int sp[N][2];
	int height, width;
	int numberOfSaddlePoints = 0;
	scanf("%i", &width);
	scanf("%i", &height);
	ReadMatrix(arr, height, width);
	for (int i = 0; i < height; i++)
	{
		for (int k = 0; k < width; k++)
		{
			if (arr[i][k] == FindMinInRow(arr, height, width, i))
			{
				if (IsMaxInColumn(arr, height, width, k, arr[i][k]))
				{
					sp[numberOfSaddlePoints][0] = i;
					sp[numberOfSaddlePoints][1] = k;
					numberOfSaddlePoints++;
				}
			}
		}
	}
	for (int i = 0; i < numberOfSaddlePoints; i++)
		arr[sp[i][0]][sp[i][1]] = AverageInColumn(arr, height, width, sp[i][1]);
	printf("%i\n", numberOfSaddlePoints);
	DisplayMatrix(arr, height, width);
}