#include "myHeader.h"

LINK createNode(int val);
LINK append(LINK head, LINK cur);
void printNode(LINK head);
void printNodeNumber(LINK head);
void printMidNum(LINK head);
void printReverse(LINK head);
LINK deleteNode(LINK head);

int main()
{
	LINK cur;
	LINK head = NULL;

	char input[10];

	printf("������ �Է��� ��, ENTER�� �Է����ּ���.\n(ctrl + z ��, ENTER -> �Է�����) >>\n");

	while (gets(input) != NULL)
	{
		int val = atoi(input);

		cur = createNode(val);
		head = append(head, cur);
	}

	printf("�Է��� �Ϸ�Ǿ����ϴ�.\n\n");

	printNode(head);
	printNodeNumber(head);
	printMidNum(head);
	printReverse(head);
	head = deleteNode(head);
	printNode(head);

	system("pause");
	return 0;
}
