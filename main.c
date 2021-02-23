#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "list-college.h"
#include "list-stu.h"
#include "file-college.h"
#include "file-stu.h"
#include "hello.h"
struct Nodecollege *listcollege;
struct Node *list;
char number[20], nam[20];
int s;
char c[4];
int mark_1, mark_2, mark_3, mark_4;
int main()
{
	list = createList();
	listcollege = createListcollege();
	readFilecollege(listcollege, "C_Code.txt");
	readFile(list, "Stu_Info.txt");
	while (1)
	{
		Hello();
		system("pause");
		system("cls");
	}
	return 0;
}