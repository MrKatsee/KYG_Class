#pragma once
#include <stdio.h>
#include <string.h>

typedef struct node {
	int value;
	struct node * next;
} node;

typedef node * LINK;
