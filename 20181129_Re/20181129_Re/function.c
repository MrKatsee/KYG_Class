#include "myHeader.h"

LINK createNode(int val)
{
	LINK cur = (node *)malloc(sizeof(node));

	cur->value = val;
	cur->next = NULL;

	return cur;
}
LINK append(LINK head, LINK cur)
{
	LINK reader = head;

	if (reader == NULL)
	{
		return cur;
	}

	while (reader->next != NULL)
		reader = reader->next;

	reader->next = cur;

	return head;
}

void printNode(LINK head)
{
	LINK reader = head;

	printf("�Է��ڷḦ ������� ���\n>> ");

	while (reader != NULL)
	{
		printf("%d ", reader->value);
		reader = reader->next;
	}
	puts("");
}

void printNodeNumber(LINK head)
{
	LINK reader = head;
	int count = 0;

	printf("�Էµ� �ڷ��� ������ ���\n>> ");

	while (reader != NULL)
	{
		count++;
		reader = reader->next;
	}

	printf("%d", count);
	puts("");
}

void printMidNum(LINK head)
{
	LINK reader = head;
	int count = 0, temp = 0;

	printf("�Է��ڷ��� �߰���ġ�� �ִ� �ڷ��� �� ���\n>> ");

	while (reader != NULL)
	{
		count++;
		reader = reader->next;
	}

	reader = head;

	while (temp < count / 2)
	{
		temp++;
		reader = reader->next;
	}

	printf("%d ", reader->value);
	puts("");
}

void printReverse(LINK head)
{
	LINK reader = head;
	int count = 0;

	printf("�Է��ڷḦ �Է� �������� ���\n>> ");

	while (reader != NULL)
	{
		count++;
		reader = reader->next;
	}

	reader = head;

	for (int i = count; i > 0; i--)
	{
		for (int j = 1; j < i; j++)
		{
			reader = reader->next;
		}

		printf("%d ", reader->value);

		reader = head;
	}

	puts("");
}

LINK deleteNode(LINK head)
{
	LINK reader = head;
	LINK changer = NULL;

	int count = 0;

	printf("�Է��ڷῡ�� Ȧ����° �ڷḦ ��� ����\n");

	while (reader != NULL)
	{
		count++;
		reader = reader->next;
	}

	reader = head;

	for (int i = count; i > 0; i--)
	{
		for (int j = 1; j < i; j++)
			reader = reader->next;

		if (i % 2 == 1)
		{
			free(reader);

			if (i == 1)
				return changer;
		}
		else
		{
			reader->next = changer;
			changer = reader;
		}

		reader = head;
	}
}
