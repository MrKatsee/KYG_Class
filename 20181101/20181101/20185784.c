#include <stdio.h>
#include <string.h>

typedef struct
{
	int year;
	int month;
	int day;
} birth;

struct _info
{
	char name[20];
	birth my_birth;
	int sex;
	char address[30];
	char phonenumber[20];
};

typedef struct _info info;
info information[10];

void sort_by_name(int);
void sort_by_birth(int);

char * SexToString(int);

int main()
{
	int num;
	int struct_num = 0;

	printf("개인 명세서 정리 by 20185784 김호성\n");

	while (1)
	{
		if (struct_num > 10)
			break;

		puts("");
		printf("입력을 멈추시려면 0, 입력을 계속하시려면 1을 입력해주세요.\n(개인 명세서는 최대 10개까지 입력 가능합니다): ");
		scanf_s("%d", &num);

		if (num == 0)
			break;

		puts("");

		printf("이름을 입력해주세요: ");
		scanf_s("%s", information[struct_num].name, 20);

		printf("생년월일을 입력해주세요. \n");
		printf("year: ");
		scanf_s("%d", &information[struct_num].my_birth.year);
		printf("month: ");
		scanf_s("%d", &information[struct_num].my_birth.month);
		printf("day: ");
		scanf_s("%d", &information[struct_num].my_birth.day);

		printf("성별을 입력해주세요(남/여): ");
		char sex_temp[10];
		scanf_s("%s", sex_temp, 10);
		if (strcmp(sex_temp, "남") != 0 && strcmp(sex_temp, "여") != 0)
		{
			printf("올바른 값을 입력해주세요.\n");
			information[struct_num].sex = 2;
		}
		else
		{
			information[struct_num].sex = (strcmp(sex_temp, "남") == 0) ? 0 : 1;
		}

		printf("주소를 입력해주세요: ");
		while (getchar() != '\n');	//버퍼 지우기
		gets_s(information[struct_num].address, 30);

		printf("전화번호를 입력해주세요: ");
		scanf_s("%s", information[struct_num].phonenumber, 20);

		struct_num++;
	}

	puts("");
	printf("- 입력순 -\n");
	puts("");
	printf("%s\t%s\t%-10s\t%-40s\t%s\n", "[이름]", "[생년월일]", "[성별]", "[주소]", "[전화번호]");
	puts("");

	for (int i = 0; i < struct_num; i++)
	{
		printf("%s\t%d년 %d월 %d일\t%-10s\t%-40s\t%s\n",
			information[i].name, information[i].my_birth.year, information[i].my_birth.month,
			information[i].my_birth.day, SexToString(information[i].sex),
			information[i].address, information[i].phonenumber);
	}

	sort_by_name(struct_num);	//이름 내림차순으로 구조체 배열을 정리

	puts("");
	printf("- 이름순(내림차순) -\n");
	puts("");
	printf("%s\t%s\t%-10s\t%-40s\t%s\n", "[이름]", "[생년월일]", "[성별]", "[주소]", "[전화번호]");
	puts("");

	for (int i = 0; i < struct_num; i++)
	{
		printf("%s\t%d년 %d월 %d일\t%-10s\t%-40s\t%s\n",
			information[i].name, information[i].my_birth.year, information[i].my_birth.month,
			information[i].my_birth.day, SexToString(information[i].sex),
			information[i].address, information[i].phonenumber);
	}
	
	sort_by_birth(struct_num);	//생년월일 올림차순으로 구조체 배열을 정리

	puts("");
	printf("- 생년월일순(올림차순) -\n");
	puts("");
	printf("%s\t%s\t%-10s\t%-40s\t%s\n", "[이름]", "[생년월일]", "[성별]", "[주소]", "[전화번호]");
	puts("");

	for (int i = 0; i < struct_num; i++)
	{
		printf("%s\t%d년 %d월 %d일\t%-10s\t%-40s\t%s\n",
			information[i].name, information[i].my_birth.year, information[i].my_birth.month,
			information[i].my_birth.day, SexToString(information[i].sex),
			information[i].address, information[i].phonenumber);
	}
	
	system("pause");
}

//Insertion Sort (이름 내림차순)
void sort_by_name(int n)
{
	info temp;

	for (int i = 0; i < n; i++)
	{
		temp = information[i];	//분류할 구조체를 temp에 저장

		for (int j = i - 1; j >= 0; j--)	//구조체 배열의 뒤에서부터 조건에 부합하는가를 판단한다.
		{
			if (strcmp(information[j].name, temp.name) < 0)	//temp보다 낮은 이름을 가진 구조체를 만났을 경우,
			{
				for (int k = i - 1; k > j; k--)
				{
					//해당 구조체보다 배열상 뒤에 있는 모든 (이미 한 번)분류된 구조체를 뒤로 한 칸씩 민다.
					information[k + 1] = information[k];
				}

				information[j + 1] = temp;	//빈 구조체 배열 자리에 temp를 저장한다.

				break;
			}
			else if (strcmp(information[j].name, temp.name) >= 0 && j == 0)
				//만약 배열의 가장 앞까지 판단했음에도 조건에 부합하는 경우가 없다면,
			{
				for (int k = i - 1; k >= j; k--)
				{
					information[k + 1] = information[k];	//모든 (이미 한 번)분류된 구조체를 뒤로 한 칸씩 민다.
				}

				information[j] = temp;	//빈 구조체 배열 자리(0번째)에 temp를 저장한다.
			}
		}
	}
}

//Insertion Sort (생년월일 올림차순)
//위와 방법이 같으나 생년이 같은 경우 생월을, 생월이 같을 경우 생일의 높낮이로 구조체 배열을 정리한다!
void sort_by_birth(int n)
{
	info temp;

	for (int i = 0; i < n; i++)
	{
		temp = information[i];

		for (int j = i - 1; j >= 0; j--)
		{
			if (information[j].my_birth.year < temp.my_birth.year)
			{
				for (int k = i - 1; k > j; k--)
				{
					information[k + 1] = information[k];
				}

				information[j + 1] = temp;
				
				break;
			}
			else if (information[j].my_birth.year > temp.my_birth.year && j == 0)
			{
				for (int k = i - 1; k >= j; k--)
				{
					information[k + 1] = information[k];
				}

				information[j] = temp;
			}
			else if (information[j].my_birth.year == temp.my_birth.year)
			{
				if (information[j].my_birth.month < temp.my_birth.month)
				{
					for (int k = i - 1; k > j; k--)
					{
						information[k + 1] = information[k];
					}

					information[j + 1] = temp;

					break;
				}
				else if (information[j].my_birth.month > temp.my_birth.month && j == 0)
				{
					for (int k = i - 1; k >= j; k--)
					{
						information[k + 1] = information[k];
					}

					information[j] = temp;
				}
				else if (information[j].my_birth.month == temp.my_birth.month)
				{
					if (information[j].my_birth.day < temp.my_birth.day)
					{
						for (int k = i - 1; k > j; k--)
						{
							information[k + 1] = information[k];
						}

						information[j + 1] = temp;
					}
					else if (information[j].my_birth.day >= temp.my_birth.day && j == 0)
					{
						for (int k = i - 1; k >= j; k--)
						{
							information[k + 1] = information[k];
						}

						information[j] = temp;
					}
				}
			}
		}

	}
}

//정수로 저장된 성별을 문자열로 바꿔준다.
char * SexToString(int sex_int)
{
	char * sex_str;

	switch (sex_int)
	{
	default:
		sex_str = "알수없음";
		break;
	case 0:
		sex_str = "남";
		break;
	case 1:
		sex_str = "여";
		break;
	}

	return sex_str;
}