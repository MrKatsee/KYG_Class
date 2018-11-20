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

	printf("입력할 명세서의 개수를 입력하시오(by 20185784): ");
	scanf_s("%d", &structNum);

	info = inputStruct(structNum);

	printf("\n- 입력순 -\n");
	printStruct(structNum, info);

	sort_by_name(structNum, info);

	printf("\n- 이름순(내림차순) -\n");
	printStruct(structNum, info);

	sort_by_birth(structNum, info);

	printf("\n- 생일순(올림차순) -\n");
	printStruct(structNum, info);

	system("pause");
}

_info ** inputStruct(int size)
{
	_info ** info = { (_info *)malloc(sizeof(_info)) };
	printf("\n이름 / 생년월일 / 성별 / 전화번호 순으로 입력해주세요. (모든 항목은 띄어쓰기로 구분됩니다.)\n\n");
	printf("- 예시 입력1:   김호성 2000 1 29 남자 01033291990\n");
	printf("- 예시 입력2:   홍길동 1999 8 15 여자 01077778888\n\n");
	for (int i = 0; i < size; i++)
	{
		(*(info + i)) = (_info *)malloc(sizeof(_info));
		printf("개별명세 입력%d: ", i + 1);
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
	printf("%s\t%s\t%s\t%s\n", "[이름]", "[생년월일]", "[성별]", "[전화번호]");
	puts("");

	for (int i = 0; i < size; i++)
	{
		printf("%s\t%d년%d월%d일\t%s\t%s\n",
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