#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define MAX 1000

//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ�������������Ա����䡢�绰��סַ
//1.�����ϵ����Ϣ
//2.ɾ��ָ����ϵ����Ϣ
//3.����ָ����ϵ����Ϣ
//4.�޸�ָ����ϵ����Ϣ
//5.��ʾ������ϵ����Ϣ
//6.���������ϵ��
//0.�˳�
//������������������ϵ�ˣ�

//������ϵ�˽ṹ��
typedef struct preson {
	char name[1024];
	//���û�����������ƴ����������������
	char namecmp[1024];
	char sex[1024];
	int age;
	char tel[1024];
	char address[1024];
}preson;
//����ͨѶ¼�ṹ��
typedef struct addressBook {
	preson pre[MAX];
	//��¼ͨѶ¼�е�ǰ��Ч��ϵ��
	int size;
}addressBook;
//��ʼ��ͨѶ¼�ṹ��
void initpre(addressBook* addressbook) {
	addressbook->size = 0;
}

//1.�����ϵ����Ϣ���������Ա����䡢�绰��סַ
void addpre(addressBook* addressbook) {
	system("cls");
	if (addressbook->size > MAX) {
		printf("ͨѶ¼������");
		return;
	}
	//printf("1\n");
	printf("�����ϵ�ˣ�\n");
	printf("������");
	scanf("%s", &addressbook->pre[addressbook->size].name);
	printf("������ƴ����");
	scanf("%s", &addressbook->pre[addressbook->size].namecmp);
	printf("�Ա�");
	scanf("%s", &addressbook->pre[addressbook->size].sex);
	printf("���䣺");
	scanf("%d", &addressbook->pre[addressbook->size].age);
	printf("�绰��");
	scanf("%s", &addressbook->pre[addressbook->size].tel);
	printf("סַ��");
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
	printf("�����ϵ�˳ɹ���\n");
	Sleep(1000);
}
//2.ɾ��ָ����ϵ����Ϣ
void delpre(addressBook* addressbook) {
	//printf("2\n");
	//���ڻ����ͬ��ͬ�յ��ˣ�������û���������Ҫɾ�����˵�����
	//�������������ȫ����ϵ�˴�ӡ������Ȼ�����û�ѡ��ǰ�����Ž���ɾ��
	int flag[MAX] = { -1 };
	int j = 0;
	while (1) {
		system("cls");
		printf("������Ҫɾ����ϵ�˵�������");
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
			printf("δ�ҵ�Ҫɾ�����ˣ�\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	while (1) {
		printf("������Ҫɾ����ϵ�˵���ţ�");
		int num = 0;
		scanf("%d", &num);
		for (int i = 0; i < j; i++) {
			if (flag[i] == num) {
				//��������ǰ�ƣ����ǵ�Ҫɾ������
				for (int k = i; k < addressbook->size; k++) {
					addressbook->pre[k] = addressbook->pre[k + 1];
				}
				addressbook->size--;
				printf("ɾ����ϵ�˳ɹ���\n");
				Sleep(1000);
				return;
			}
		}
		printf("������������\n");

	}
}
//3.����ָ����ϵ����Ϣ
void findpre(addressBook* addressbook) {
	//printf("3\n");
	system("cls");
	int j = 0;
	while (1) {
		printf("������Ҫ������ϵ�˵�������");
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
			printf("δ�ҵ�Ҫ���ҵ��ˣ�");
			while (1) {
				Sleep(1000);
				system("cls");
				printf("�Ƿ����²��ң�\n1--��\t2-��\n");
				int choose = 0;
				scanf("%d", &choose);
				if (choose == 1) {
					break;
				}
				else if (choose == 2) {
					return;
				}
				else {
					printf("��������\n");
					Sleep(1000);
				}
			}
		}
		else {
			printf("��'E'��������ҳ\n");
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
//4.�޸�ָ����ϵ����Ϣ
void amendpre(addressBook* addressbook) {
	//printf("4\n");
	//���ڻ����ͬ��ͬ�յ��ˣ�������û���������Ҫ�޸ĵ��˵�����
	//�������������ȫ����ϵ�˴�ӡ������Ȼ�����û�ѡ��ǰ�����Ž����޸�
	int flag[MAX] = { -1 };
	int j = 0;
	while (1) {
		system("cls");
		printf("������Ҫ�޸���ϵ�˵�������");
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
			printf("δ�ҵ�Ҫ�޸ĵ��ˣ�\n");
			Sleep(1000);
			continue;
		}
		break;
	}
	while (1) {
		printf("������Ҫ�޸���ϵ�˵���ţ�");
		int num = 0;
		scanf("%d", &num);
		for (int i = 0; i < j; i++) {
			if (flag[i] == num) {
				//���û������޸���Ϣ
				printf("�޸ĺ�������");
				scanf("%s", &addressbook->pre[flag[i]].name);
				printf("�޸ĺ�������ƴ����");
				scanf("%s", &addressbook->pre[flag[i]].namecmp);
				printf("�޸ĺ��Ա�");
				scanf("%s", &addressbook->pre[flag[i]].sex);
				printf("�޸ĺ����䣺");
				scanf("%d", &addressbook->pre[flag[i]].age);
				printf("�޸ĺ�绰��");
				scanf("%s", &addressbook->pre[flag[i]].tel);
				printf("�޸ĺ�סַ��");
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
				printf("�޸���ϵ�˳ɹ���\n");
				Sleep(1000);
				return;
			}
		}
		printf("������������\n");
	}
}
//5.��ʾ������ϵ����Ϣ
void showpre(addressBook* addressbook) {
	//printf("5\n");
	system("cls");
	printf("��ǰͬͨѶ¼���� %d ����ϵ��\n", addressbook->size);
	printf("���\t\t����\t\t�Ա�\t\t����\t\t�绰\t\tסַ\n");
	for (int i = 0; i < addressbook->size; i++) {
		printf("[%d]\t\t%s\t\t%s\t\t%d\t\t%s\t\t%s\n", i,
			addressbook->pre[i].name,
			addressbook->pre[i].sex ,
			addressbook->pre[i].age,
			addressbook->pre[i].tel,
			addressbook->pre[i].address);
	}
	printf("��'E'��������ҳ\n");
	while (1) {
		char choose = 'c';
		scanf("%c", &choose);
		if (choose == 'E') {
			return;
		}
	}
}
//6.���������ϵ��
void emptypre(addressBook* addressbook) {
	//printf("6\n");
	system("cls");
	printf("�����Ҫɾ��������ϵ�ˣ�\n1--����\t2--ȷ��\n");
	while (1) {
		printf("��ѡ��");
		int choose = 0;
		scanf("%d", &choose);
		if (choose == 1) {
			return;
		}
		else if (choose == 2) {
			addressbook->size = 0;
			printf("ɾ���ɹ���");
			Sleep(1000);
			return;
		}
		else {
			printf("��������\n");
		}
	}
}
//0.�˳�

//��ӡ�˵�
int menu() {
	printf("---------------------------\n");
	printf("1.�����ϵ��\n");
	printf("2.ɾ��ָ����ϵ����Ϣ\n");
	printf("3.����ָ����ϵ����Ϣ\n");
	printf("4.�޸�ָ����ϵ����Ϣ\n");
	printf("5.��ʾ������ϵ����Ϣ\n");
	printf("6.���������ϵ��\n");
	printf("0.�˳�\n");
	printf("---------------------------\n");
	printf("���������ѡ��");
	int choose = 0;
	scanf("%d", &choose);
	return choose;
}
addressBook addressbook;
addressBook* p = &addressbook;
typedef void(*Address)(addressBook*);
int main() {
	//����һ��ת�Ʊ�ʡȥ������if else�ṹ
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
			printf("��������!\n");
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

//��˼���ܽ᣺

//Ϊ�˱��������ظ������û��������ֺ󣬻�Ҫ��������ţ��ⲻ�����ƣ����û�������ǲ������û�����Ĺ�������
//��ʵÿ��ģ�麯��������Ӧ�����û�ѡ���Ƿ������˵�����ֱ���˳�����ֻ��һС����������һ�㣬����Щû����һ��
//���޸���ϵ����Ϣ��һģ���У��û����뽫ѡ���޸ĵ���ϵ�˵�������Ϣȫ���޸�һ�飬û��ʵ���û�ѡ���ĸ���Ϣ���޸��ĸ���Ϣ
//�ڱ������У�����ϵ�˽��а��������������û��������ֶ�Ӧ��ƴ��Ȼ��ʵ�ֵģ�û�е��õ�������������ʵ����һ���ܣ�������

//����ͨѶ¼�Ļ��������Ѿ�ʵ�֣�������˵���������������޸ĵ�
