#include <stdio.h>
#define colSize 3
#define rowSize 3

void indexAddMat(int mat_1[][3], int mat_2[][3], int mat_result[][3]);
void ptrProdMat(int(*mat_1)[3], int(*mat_2)[3], int(*mat_result)[3]);

int main()
{
	int mat_1[3][3], mat_2[3][3], mat_result[3][3];

	printf("1번째 정방행렬을 입력합니다.\n");
	for (int i = 0; i < colSize * rowSize; i++)
	{
		printf("%d번째 정수를 입력해주세요: ", i);
		scanf_s("%d", mat_1[0] + i);
	}

	printf("\n2번째 정방행렬을 입력합니다.\n");
	for (int i = 0; i < colSize * rowSize; i++)
	{
		printf("%d번째 정수를 입력해주세요: ", i);
		scanf_s("%d", mat_2[0] + i);
	}

	printf("\n\n1번째 정방행렬\t\t\t2번째 정방행렬\n");
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

	printf("\n\nindexAddMat 결과 정방행렬\n");
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			printf("%5d", *(*(mat_result + i) + j));
		}
		puts("");
	}

	ptrProdMat(mat_1, mat_2, mat_result);

	printf("\n\nptrProdMat 결과 정방행렬\n");
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