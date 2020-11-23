#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define MAX 1000

//通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
//1.添加联系人信息
//2.删除指定联系人信息
//3.查找指定联系人信息
//4.修改指定联系人信息
//5.显示所有联系人信息
//6.清空所有联系人
//0.退出
//（以名字排序所有联系人）

//创建联系人结构体
typedef struct preson {
	char name[1024];
	//让用户输入姓名的拼音，用来进行排序
	char namecmp[1024];
	char sex[1024];
	int age;
	char tel[1024];
	char address[1024];
}preson;
//创建通讯录结构体
typedef struct addressBook {
	preson pre[MAX];
	//记录通讯录中当前有效联系人
	int size;
}addressBook;
//初始化通讯录结构体
void initpre(addressBook* addressbook) {
	addressbook->size = 0;
}

//1.添加联系人信息；姓名、性别、年龄、电话、住址
void addpre(addressBook* addressbook) {
	system("cls");
	if (addressbook->size > MAX) {
		printf("通讯录已满！");
		return;
	}
	//printf("1\n");
	printf("添加联系人：\n");
	printf("姓名：");
	scanf("%s", &addressbook->pre[addressbook->size].name);
	printf("姓名的拼音：");
	scanf("%s", &addressbook->pre[addressbook->size].namecmp);
	printf("性别：");
	scanf("%s", &addressbook->pre[addressbook->size].sex);
	printf("年龄：");
	scanf("%d", &addressbook->pre[addressbook->size].age);
	printf("电话：");
	scanf("%s", &addressbook->pre[addressbook->size].tel);
	printf("住址：");
	scanf("%s", &addressbook->pre[addressbook->size].address);
	addressbook->size++;
	for (int i = addressbook->size - 1; i > 0; i--) {
		if (strcmp(addressbook->pre[i - 1].namecmp, addressbook->pre[i].namecmp) > 0) {
			preson p;
			p = addressbook->pre[i];
			addressbook->pre[i] = addressbook->pre[i - 1];
			addressbook->pre[i - 1] = p;
		}
	}
	printf("添加联系人成功！\n");
	Sleep(1000);
}
//2.删除指定联系人信息
void delpre(addressBook* addressbook) {
	//printf("2\n");
	//由于会出现同名同姓的人，因此让用户先输入想要删除的人的姓名
	//将叫这个姓名的全部联系人打印出来，然后让用户选择前面的序号进行删除
	int flag[MAX] = { -1 };
	int j = 0;
	while (1) {
		system("cls");
		printf("请输入要删除联系人的姓名：");
		char name[1024] = { 0 };
		scanf("%s", name);
		for (int i = 0; i < addressbook->size; i++) {
			if (strcmp(addressbook->pre[i].name, name) == 0) {
				printf("[%d]\t\t%s\t\t%s\t\t%d\t\t%s\t\t%s\n", i,
					addressbook->pre[i].name,
					addressbook->pre[i].sex,
					addressbook->pre[i].age,
					addressbook->pre[i].tel,
					addressbook->pre[i].address);
				flag[j] = i;
				j++;
			}
		}
		if (flag[0] == -1) {
			printf("未找到要删除的人！\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	while (1) {
		printf("请输入要删除联系人的序号：");
		int num = 0;
		scanf("%d", &num);
		for (int i = 0; i < j; i++) {
			if (flag[i] == num) {
				//数组整体前移，覆盖掉要删除的人
				for (int k = i; k < addressbook->size; k++) {
					addressbook->pre[k] = addressbook->pre[k + 1];
				}
				addressbook->size--;
				printf("删除联系人成功！\n");
				Sleep(1000);
				return;
			}
		}
		printf("输入的序号有误！\n");

	}
}
//3.查找指定联系人信息
void findpre(addressBook* addressbook) {
	//printf("3\n");
	system("cls");
	int j = 0;
	while (1) {
		printf("请输入要查找联系人的姓名：");
		char name[1024] = { 0 };
		scanf("%s", name);
		for (int i = 0; i < addressbook->size; i++) {
			if (strcmp(addressbook->pre[i].name, name) == 0) {
				printf("[%d]\t\t%s\t\t%s\t\t%d\t\t%s\t\t%s\n", i,
					addressbook->pre[i].name,
					addressbook->pre[i].sex,
					addressbook->pre[i].age,
					addressbook->pre[i].tel,
					addressbook->pre[i].address);
				j++;
			}
		}
		if (j == 0) {
			printf("未找到要查找的人！");
			while (1) {
				Sleep(1000);
				system("cls");
				printf("是否重新查找？\n1--是\t2-否\n");
				int choose = 0;
				scanf("%d", &choose);
				if (choose == 1) {
					break;
				}
				else if (choose == 2) {
					return;
				}
				else {
					printf("输入有误！\n");
					Sleep(1000);
				}
			}
		}
		else {
			printf("按'E'键返回主页\n");
			while (1) {
				char choose = 'c';
				scanf("%c", &choose);
				if (choose == 'E') {
					return;
				}
			}
		}
	}
}
//4.修改指定联系人信息
void amendpre(addressBook* addressbook) {
	//printf("4\n");
	//由于会出现同名同姓的人，因此让用户先输入想要修改的人的姓名
	//将叫这个姓名的全部联系人打印出来，然后让用户选择前面的序号进行修改
	int flag[MAX] = { -1 };
	int j = 0;
	while (1) {
		system("cls");
		printf("请输入要修改联系人的姓名：");
		char name[1024] = { 0 };
		scanf("%s", name);
		for (int i = 0; i < addressbook->size; i++) {
			if (strcmp(addressbook->pre[i].name, name) == 0) {
				printf("[%d]\t\t%s\t\t%s\t\t%d\t\t%s\t\t%s\n", i,
					addressbook->pre[i].name,
					addressbook->pre[i].sex,
					addressbook->pre[i].age,
					addressbook->pre[i].tel,
					addressbook->pre[i].address);
				flag[j] = i;
				j++;
			}
		}
		if (flag[0] == -1) {
			printf("未找到要修改的人！\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	while (1) {
		printf("请输入要修改联系人的序号：");
		int num = 0;
		scanf("%d", &num);
		for (int i = 0; i < j; i++) {
			if (flag[i] == num) {
				//让用户输入修改信息
				printf("修改后姓名：");
				scanf("%s", &addressbook->pre[flag[i]].name);
				printf("修改后姓名的拼音：");
				scanf("%s", &addressbook->pre[flag[i]].namecmp);
				printf("修改后性别：");
				scanf("%s", &addressbook->pre[flag[i]].sex);
				printf("修改后年龄：");
				scanf("%d", &addressbook->pre[flag[i]].age);
				printf("修改后电话：");
				scanf("%s", &addressbook->pre[flag[i]].tel);
				printf("修改后住址：");
				scanf("%s", &addressbook->pre[flag[i]].address);
				int k = i;
				for (int i = flag[k]; i > 0&&i<addressbook->size-1; ) {
					if (strcmp(addressbook->pre[i - 1].namecmp, addressbook->pre[i].namecmp) > 0) {
						preson p;
						p = addressbook->pre[i];
						addressbook->pre[i] = addressbook->pre[i - 1];
						addressbook->pre[i - 1] = p;
						i--;
					}
					else if(strcmp(addressbook->pre[i].namecmp, addressbook->pre[i+1].namecmp) > 0){
						preson p;
						p = addressbook->pre[i];
						addressbook->pre[i] = addressbook->pre[i + 1];
						addressbook->pre[i + 1] = p;
						i++;
					}
					else {
						break;
					}
				}
				printf("修改联系人成功！\n");
				Sleep(1000);
				return;
			}
		}
		printf("输入的序号有误！\n");
	}
}
//5.显示所有联系人信息
void showpre(addressBook* addressbook) {
	//printf("5\n");
	system("cls");
	printf("当前同通讯录共有 %d 个联系人\n", addressbook->size);
	printf("序号\t\t姓名\t\t性别\t\t年龄\t\t电话\t\t住址\n");
	for (int i = 0; i < addressbook->size; i++) {
		printf("[%d]\t\t%s\t\t%s\t\t%d\t\t%s\t\t%s\n", i,
			addressbook->pre[i].name,
			addressbook->pre[i].sex ,
			addressbook->pre[i].age,
			addressbook->pre[i].tel,
			addressbook->pre[i].address);
	}
	printf("按'E'键返回主页\n");
	while (1) {
		char choose = 'c';
		scanf("%c", &choose);
		if (choose == 'E') {
			return;
		}
	}
}
//6.清空所有联系人
void emptypre(addressBook* addressbook) {
	//printf("6\n");
	system("cls");
	printf("您真的要删除所有联系人？\n1--返回\t2--确定\n");
	while (1) {
		printf("请选择：");
		int choose = 0;
		scanf("%d", &choose);
		if (choose == 1) {
			return;
		}
		else if (choose == 2) {
			addressbook->size = 0;
			printf("删除成功！");
			Sleep(1000);
			return;
		}
		else {
			printf("输入有误！\n");
		}
	}
}
//0.退出

//打印菜单
int menu() {
	printf("---------------------------\n");
	printf("1.添加联系人\n");
	printf("2.删除指定联系人信息\n");
	printf("3.查找指定联系人信息\n");
	printf("4.修改指定联系人信息\n");
	printf("5.显示所有联系人信息\n");
	printf("6.清空所有联系人\n");
	printf("0.退出\n");
	printf("---------------------------\n");
	printf("请输入你的选择：");
	int choose = 0;
	scanf("%d", &choose);
	return choose;
}
addressBook addressbook;
addressBook* p = &addressbook;
typedef void(*Address)(addressBook*);
int main() {
	//创建一个转移表，省去繁琐的if else结构
	Address address[] = {
		NULL,
		addpre,
		delpre,
		findpre,
		amendpre,
		showpre,
		emptypre
	};
	initpre(p);
	while (1) {
		system("cls");
		int choose = menu();
		if (choose > 6 || choose < 0) {
			printf("输入有误!\n");
			Sleep(1000);
			continue;
		}
		else if (choose == 0) {
			return 0;
		}
		else {
			address[choose](p);
		}
	}
	return 0;
}

//反思与总结：

//为了避免名字重复，让用户输入名字后，还要再输入序号，这不够完善，如果没有重名那不就让用户输入的工序复杂了
//其实每个模块函数结束后，应该让用户选择是返回主菜单还是直接退出程序，只有一小部分做了这一点，还有些没加这一步
//在修改联系人信息这一模块中，用户必须将选定修改的联系人的所有信息全部修改一遍，没能实现用户选择哪个信息就修改哪个信息
//在本程序中，对联系人进行按名字排序是让用户输入名字对应的拼音然后实现的，没有调用第三方函数库来实现这一功能，不够好

//但是通讯录的基本功能已经实现，上面所说的问题后续会进行修改的
