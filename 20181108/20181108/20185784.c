#include <stdio.h>
#define colSize 3
#define rowSize 3

void indexAddMat(int mat_1[][3], int mat_2[][3], int mat_result[][3]);
void ptrProdMat(int(*mat_1)[3], int(*mat_2)[3], int(*mat_result)[3]);

int main()
{
	int mat_1[3][3], mat_2[3][3], mat_result[3][3];

	printf("1��° ��������� �Է��մϴ�.\n");
	for (int i = 0; i < colSize * rowSize; i++)
	{
		printf("%d��° ������ �Է����ּ���: ", i);
		scanf_s("%d", mat_1[0] + i);
	}

	printf("\n2��° ��������� �Է��մϴ�.\n");
	for (int i = 0; i < colSize * rowSize; i++)
	{
		printf("%d��° ������ �Է����ּ���: ", i);
		scanf_s("%d", mat_2[0] + i);
	}

	printf("\n\n1��° �������\t\t\t2��° �������\n");
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			printf("%5d", *(*(mat_1 + i) + j));
		}

		printf("\t\t\t");

		for (int j = 0; j < colSize; j++)
		{
			printf("%5d", *(*(mat_2 + i) + j));
		}

		puts("");
	}

	puts("");

	indexAddMat(mat_1, mat_2, mat_result);

	printf("\n\nindexAddMat ��� �������\n");
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			printf("%5d", *(*(mat_result + i) + j));
		}
		puts("");
	}

	ptrProdMat(mat_1, mat_2, mat_result);

	printf("\n\nptrProdMat ��� �������\n");
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			printf("%5d", *(*(mat_result + i) + j));
		}
		puts("");
	}

	system("pause");
	return 0;
}

void indexAddMat(int mat_1[][3], int mat_2[][3], int mat_result[][3])
{
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			mat_result[i][j] = mat_1[i][j] + mat_2[i][j];
		}
	}
}

void ptrProdMat(int(*mat_1)[3], int(*mat_2)[3], int(*mat_result)[3])
{
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			*(*(mat_result + i) + j) = 0;
			for (int k = 0; k < rowSize; k++)
			{
				*(*(mat_result + i) + j) += (*(*(mat_1 + i) + k) * *(*(mat_2 + k) + j));
			}
		}
	}
}