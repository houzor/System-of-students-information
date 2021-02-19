#include "all.h"
int main() {
	list = createList();	
	listcollege = createListcollege();	
	readFilecollege(listcollege, "C_Code.txt");				
	readFile(list,"Stu_Info.txt");			//读取学生信息文件 
	while(1)
	{
		Hello();
		system("pause");
		system("cls");
	}
	return 0;
}

