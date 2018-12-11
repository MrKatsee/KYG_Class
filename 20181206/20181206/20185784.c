#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int CountFile(char * fileStr, int mode);
void SaveRev(FILE * f, char * fileStr);

enum mode
{
	LINE,
	WORD,
	CHAR
};

int main(int argc, char ** argv)
{
	FILE * f1 = NULL;
	FILE * f2 = NULL;

	char * fileName = "OSParadigmShift.rev";

	char * str;
	int i = 0;
	int count = 0;

	f1 = fopen(argv[1], "r");
	f2 = fopen(fileName, "w");

	fseek(f1, 0, SEEK_END);
	str = (char*)malloc(ftell(f1));
	fseek(f1, 0, SEEK_SET);

	while (!feof(f1))
	{
		*(str + i++) = fgetc(f1);
	}
	str[i] = '\0';

	printf("<Count Result>\n");

	count = CountFile(str, LINE);
	printf("Line Count:\t\t%d\n", count);

	count = CountFile(str, WORD);
	printf("Word Count:\t\t%d\n", count);

	count = CountFile(str, CHAR);
	printf("Character Count:\t%d(Except for Space)\n", count);

	SaveRev(f2, str);
	printf("File saved in %s\n", fileName);

	free(str);
	fclose(f1);
	fclose(f2);

	system("pause");
}

int CountFile(char * fileStr, int mode)
{
	char * delimiterLine = "\n";
	char * delimiterWord = " \n";
	int count = 0;
	char * str = (char*)malloc(sizeof(char) * (strlen(fileStr) + 1));
	strcpy(str, fileStr);
	char * token;

	switch (mode)
	{
	default:
		break;
	case 0:
		token = strtok(str, delimiterLine);
		count++;
		while (token != NULL)
		{
			token = strtok(NULL, delimiterLine);
			count++;
		}
		break;
	case 1:
		token = strtok(str, delimiterWord);
		count++;
		while (token != NULL)
		{
			count++;
			token = strtok(NULL, delimiterWord);
		}
		break;
	case 2:
		for (int i = 0; *(str + i) != 0; i++)
		{
			//공백 제외
			if (*(str + i) != 32)
				count++;
		}
		break;
	}

	free(str);

	return count;
}

void SaveRev(FILE * f, char * fileStr)
{
	char * str = (char*)malloc(sizeof(char) * (strlen(fileStr) + 1));
	strcpy(str, fileStr);

	int i = 0;
	while (*(str + i) != 0)
	{
		if (*(str + i) >= 65 && *(str + i) <= 90)
		{
			*(str + i) += 32;
		}
		else if (*(str + i) >= 97 && *(str + i) <= 122)
		{
			*(str + i) -= 32;
		}
		putc(*(str + i), f);
		i++;
	}

	free(str);
}