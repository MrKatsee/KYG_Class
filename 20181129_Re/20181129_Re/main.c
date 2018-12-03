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

	printf("정수를 입력한 후, ENTER를 입력해주세요.\n(ctrl + z 후, ENTER -> 입력종료) >>\n");

	while (gets(input) != NULL)
	{
		int val = atoi(input);

		cur = createNode(val);
		head = append(head, cur);
	}

	printf("입력이 완료되었습니다.\n\n");

	printNode(head);
	printNodeNumber(head);
	printMidNum(head);
	printReverse(head);
	head = deleteNode(head);
	printNode(head);

	system("pause");
	return 0;
}
