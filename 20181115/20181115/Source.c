#include <stdio.h>

typedef struct
{
	int year;
	int month;
	int day;
} _birth;

typedef struct
{
	char name[10];
	_birth birth;
	char sex[10];
	char phonenum[20];
} _info;

_info ** inputStruct(int size);
void printStruct(int size, _info ** info);
void swap(_info * a, _info * b);
void sort_by_name(int size, _info ** info);
void sort_by_birth(int size, _info ** info);

int main()
{
	int structNum;
	_info ** info;

	printf("�Է��� ������ ������ �Է��Ͻÿ�(by 20185784): ");
	scanf_s("%d", &structNum);

	info = inputStruct(structNum);

	printf("\n- �Է¼� -\n");
	printStruct(structNum, info);

	sort_by_name(structNum, info);

	printf("\n- �̸���(��������) -\n");
	printStruct(structNum, info);

	sort_by_birth(structNum, info);

	printf("\n- ���ϼ�(�ø�����) -\n");
	printStruct(structNum, info);

	system("pause");
}

_info ** inputStruct(int size)
{
	_info ** info = { (_info *)malloc(sizeof(_info)) };
	printf("\n�̸� / ������� / ���� / ��ȭ��ȣ ������ �Է����ּ���. (��� �׸��� ����� ���е˴ϴ�.)\n\n");
	printf("- ���� �Է�1:   ��ȣ�� 2000 1 29 ���� 01033291990\n");
	printf("- ���� �Է�2:   ȫ�浿 1999 8 15 ���� 01077778888\n\n");
	for (int i = 0; i < size; i++)
	{
		(*(info + i)) = (_info *)malloc(sizeof(_info));
		printf("������ �Է�%d: ", i + 1);
		scanf_s("%s", (*(info + i))->name, 10);
		scanf_s("%d", &(*(info + i))->birth.year);
		scanf_s("%d", &(*(info + i))->birth.month);
		scanf_s("%d", &(*(info + i))->birth.day);
		scanf_s("%s", (*(info + i))->sex, 10);
		scanf_s("%s", (*(info + i))->phonenum, 20);
	}

	return info;
}
void printStruct(int size, _info ** info)
{
	puts("");
	printf("%s\t%s\t%s\t%s\n", "[�̸�]", "[�������]", "[����]", "[��ȭ��ȣ]");
	puts("");

	for (int i = 0; i < size; i++)
	{
		printf("%s\t%d��%d��%d��\t%s\t%s\n",
			(*(info + i))->name, (*(info + i))->birth.year, (*(info + i))->birth.month,
			(*(info + i))->birth.day, (*(info + i))->sex,
			(*(info + i))->phonenum);
	}
}

void swap(_info * a, _info * b)
{
	_info temp = *b;
	*b = *a;
	*a = temp;
}

void sort_by_name(int size, _info ** info)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = i; j > 0 && strcmp((*(info + (j - 1)))->name, (*(info + j))->name) > 0; j--)
		{
			swap((*(info + (j - 1))), (*(info + j)));
		}
	}
}

void sort_by_birth(int size, _info ** info)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = i; j > 0 && (*(info + (j - 1)))->birth.year >= (*(info + j))->birth.year; j--)
		{
			if ((*(info + (j - 1)))->birth.year == (*(info + j))->birth.year)
			{
				if ((*(info + (j - 1)))->birth.month == (*(info + j))->birth.month)
				{
					if ((*(info + (j - 1)))->birth.day > (*(info + j))->birth.day)
					{
						swap((*(info + (j - 1))), (*(info + j)));
					}
				}
				else if ((*(info + (j - 1)))->birth.month > (*(info + j))->birth.month)
					swap((*(info + (j - 1))), (*(info + j)));
			}
			else
				swap((*(info + (j - 1))), (*(info + j)));
		}
	}
}