#include "all.h"
int main() {
	list = createList();	
	listcollege = createListcollege();	
	readFilecollege(listcollege, "C_Code.txt");				
	readFile(list,"Stu_Info.txt");			//��ȡѧ����Ϣ�ļ� 
	while(1)
	{
		Hello();
		system("pause");
		system("cls");
	}
	return 0;
}

