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

	printf("���� ���� ���� by 20185784 ��ȣ��\n");

	while (1)
	{
		if (struct_num > 10)
			break;

		puts("");
		printf("�Է��� ���߽÷��� 0, �Է��� ����Ͻ÷��� 1�� �Է����ּ���.\n(���� ������ �ִ� 10������ �Է� �����մϴ�): ");
		scanf_s("%d", &num);

		if (num == 0)
			break;

		puts("");

		printf("�̸��� �Է����ּ���: ");
		scanf_s("%s", information[struct_num].name, 20);

		printf("��������� �Է����ּ���. \n");
		printf("year: ");
		scanf_s("%d", &information[struct_num].my_birth.year);
		printf("month: ");
		scanf_s("%d", &information[struct_num].my_birth.month);
		printf("day: ");
		scanf_s("%d", &information[struct_num].my_birth.day);

		printf("������ �Է����ּ���(��/��): ");
		char sex_temp[10];
		scanf_s("%s", sex_temp, 10);
		if (strcmp(sex_temp, "��") != 0 && strcmp(sex_temp, "��") != 0)
		{
			printf("�ùٸ� ���� �Է����ּ���.\n");
			information[struct_num].sex = 2;
		}
		else
		{
			information[struct_num].sex = (strcmp(sex_temp, "��") == 0) ? 0 : 1;
		}

		printf("�ּҸ� �Է����ּ���: ");
		while (getchar() != '\n');	//���� �����
		gets_s(information[struct_num].address, 30);

		printf("��ȭ��ȣ�� �Է����ּ���: ");
		scanf_s("%s", information[struct_num].phonenumber, 20);

		struct_num++;
	}

	puts("");
	printf("- �Է¼� -\n");
	puts("");
	printf("%s\t%s\t%-10s\t%-40s\t%s\n", "[�̸�]", "[�������]", "[����]", "[�ּ�]", "[��ȭ��ȣ]");
	puts("");

	for (int i = 0; i < struct_num; i++)
	{
		printf("%s\t%d�� %d�� %d��\t%-10s\t%-40s\t%s\n",
			information[i].name, information[i].my_birth.year, information[i].my_birth.month,
			information[i].my_birth.day, SexToString(information[i].sex),
			information[i].address, information[i].phonenumber);
	}

	sort_by_name(struct_num);	//�̸� ������������ ����ü �迭�� ����

	puts("");
	printf("- �̸���(��������) -\n");
	puts("");
	printf("%s\t%s\t%-10s\t%-40s\t%s\n", "[�̸�]", "[�������]", "[����]", "[�ּ�]", "[��ȭ��ȣ]");
	puts("");

	for (int i = 0; i < struct_num; i++)
	{
		printf("%s\t%d�� %d�� %d��\t%-10s\t%-40s\t%s\n",
			information[i].name, information[i].my_birth.year, information[i].my_birth.month,
			information[i].my_birth.day, SexToString(information[i].sex),
			information[i].address, information[i].phonenumber);
	}
	
	sort_by_birth(struct_num);	//������� �ø��������� ����ü �迭�� ����

	puts("");
	printf("- ������ϼ�(�ø�����) -\n");
	puts("");
	printf("%s\t%s\t%-10s\t%-40s\t%s\n", "[�̸�]", "[�������]", "[����]", "[�ּ�]", "[��ȭ��ȣ]");
	puts("");

	for (int i = 0; i < struct_num; i++)
	{
		printf("%s\t%d�� %d�� %d��\t%-10s\t%-40s\t%s\n",
			information[i].name, information[i].my_birth.year, information[i].my_birth.month,
			information[i].my_birth.day, SexToString(information[i].sex),
			information[i].address, information[i].phonenumber);
	}
	
	system("pause");
}

//Insertion Sort (�̸� ��������)
void sort_by_name(int n)
{
	info temp;

	for (int i = 0; i < n; i++)
	{
		temp = information[i];	//�з��� ����ü�� temp�� ����

		for (int j = i - 1; j >= 0; j--)	//����ü �迭�� �ڿ������� ���ǿ� �����ϴ°��� �Ǵ��Ѵ�.
		{
			if (strcmp(information[j].name, temp.name) < 0)	//temp���� ���� �̸��� ���� ����ü�� ������ ���,
			{
				for (int k = i - 1; k > j; k--)
				{
					//�ش� ����ü���� �迭�� �ڿ� �ִ� ��� (�̹� �� ��)�з��� ����ü�� �ڷ� �� ĭ�� �δ�.
					information[k + 1] = information[k];
				}

				information[j + 1] = temp;	//�� ����ü �迭 �ڸ��� temp�� �����Ѵ�.

				break;
			}
			else if (strcmp(information[j].name, temp.name) >= 0 && j == 0)
				//���� �迭�� ���� �ձ��� �Ǵ��������� ���ǿ� �����ϴ� ��찡 ���ٸ�,
			{
				for (int k = i - 1; k >= j; k--)
				{
					information[k + 1] = information[k];	//��� (�̹� �� ��)�з��� ����ü�� �ڷ� �� ĭ�� �δ�.
				}

				information[j] = temp;	//�� ����ü �迭 �ڸ�(0��°)�� temp�� �����Ѵ�.
			}
		}
	}
}

//Insertion Sort (������� �ø�����)
//���� ����� ������ ������ ���� ��� ������, ������ ���� ��� ������ �����̷� ����ü �迭�� �����Ѵ�!
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

//������ ����� ������ ���ڿ��� �ٲ��ش�.
char * SexToString(int sex_int)
{
	char * sex_str;

	switch (sex_int)
	{
	default:
		sex_str = "�˼�����";
		break;
	case 0:
		sex_str = "��";
		break;
	case 1:
		sex_str = "��";
		break;
	}

	return sex_str;
}