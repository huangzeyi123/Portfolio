#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//定义的职工信息结构体
typedef struct Staff {
	char name[32];
	char idCard[32];
	char waterCard[32];
	char sex[16];
	int age;
	int workAge;
	char apartment[32];
	char workPosition[32];
	char housePhone[16];
	char telePhone[16];

	struct Staff *next;
}Staff;

//插入薪水结构体
typedef struct Water {
	char waterCard[32];
	char name[32];
	int water;
	int drink;
	int electric;
	int clean;
	int tv;
	int tax;
	int real;
	int special;

	struct Water *next;
}Water;

Staff *sHead = NULL;
Staff *sTail = NULL;
Water *wHead = NULL;
Water *wTail = NULL;

//输出函数
void Print(char str[]) {
	if (str == "staff") {
		Staff *head = sHead;
		while (head != NULL) {
			printf("%s %s %s %s %d %d %s %s %s %s \n", head->name, head->idCard, head->waterCard, head->sex, head->age, 
				head->workAge, head->apartment, head->workPosition, head->housePhone, head->telePhone);
			head = head->next;
		}
	} else {
		if (str == "water") {
			Water *head = wHead;
			while (head != NULL) {
				printf("%s %s %d %d %d %d %d %d %d %d \n", head->waterCard, head->name, head->water, head->drink, head->electric,
					head->clean, head->tv, head->tax, head->real, head->special);
				head = head->next;
			}
		} else {
			printf("%s\n", "Nothing to Print!");
		}
	}
}

//插入职工信息队列
void inStaff(Staff *staff) {
	if (sHead == NULL) {
		sHead = staff;
		sTail = staff;
	} else {
		sTail->next = staff;
		staff->next = NULL;
		sTail = staff;
	}
}

//插入工资队列
void inWater(Water *water) {
	if (wHead == NULL) {
		wHead = water;
		wTail = water;
	} else {
		wTail->next = water;
		water->next = NULL;
		wTail = water;
	}
}

//读取存储在文本中的职工信息，并插入队列
void initStaff (char str[]) {
	char buffer[1024];
	char *ch;
	int index = 0;

	FILE *fp  = fopen(str, "r");
	if (fp == NULL) {
		printf("%s\n", "Error!");
		return ;
	}
	while (!feof(fp)) {
		fgets(buffer, 1024, fp);
		Staff *staff = malloc(sizeof(Staff));
		ch = (char *)strtok(buffer, " ");
		while (ch != NULL) {
			//printf("%s\n", ch);
			switch (index) {
				case 0: 
					strcpy(staff->name, ch);
					break;
				case 1: 
					strcpy(staff->idCard, ch);
					break;
				case 2: 
					strcpy(staff->waterCard, ch);
					break;
				case 3: 
					strcpy(staff->sex, ch);
					break;
				case 4: 
					staff->age = atoi(ch);
					break;
				case 5: 
					staff->workAge = atoi(ch);
					break;
				case 6: 
					strcpy(staff->apartment, ch);
					break;
				case 7: 
					strcpy(staff->workPosition, ch);
					break;
				case 8: 
					strcpy(staff->housePhone, ch);
					break;
				case 9: 
					strcpy(staff->telePhone, ch);
					break;
				default:
					break;
			}
			index++;
			ch = (char *)strtok(NULL, " ");	
		}
		index = 0;
		inStaff(staff);
        //printf("%s\n", buffer);
	}
	printf("\n");
	fclose(fp);
}

//判断当前队列是否含有相同的身份证号码
int empty(char id[]) {
	Staff *head = sHead;
	while (head != NULL) {
		if (!strcmp(head->idCard, id)) {
			return 1;
		}
		head = head->next;
	}
	return 0;
}

Staff* selectStaffById(char id[]) {
	if (empty(id)) {
		Staff *head = sHead;
		while (head != NULL) {
			if (!strcmp(head->idCard, id)) {
				return head;
			}
			head = head->next;
		}
	} else {
		printf("%s\n", "Error, No This Id Card!");
		return NULL;
	}
}

//通过身份证号查询职工信息
void insertStaff() {
	Staff *staff = malloc(sizeof(Staff));

	printf("%s\n", "请输入你的身份证号： ");
	scanf("%s", &staff->idCard);
	if (empty(staff->idCard)) {
		printf("%s\n", "错误，请重新输入身份证号！");
		return ;
	}
	printf("%s\n", "请输入你的姓名： ");
	scanf("%s", &staff->name);
	printf("%s\n", "请输入你的工资卡号：");
	scanf("%s", &staff->waterCard);
	printf("%s\n", "请输入你的性别： ");
	scanf("%s", &staff->sex);
	printf("%s\n", "请输入你的年龄： ");
	scanf("%d", &staff->age);
	printf("%s\n", "请输入你的工龄： ");
	scanf("%d", &staff->workAge);
	printf("%s\n", "请输入你的部门：");
	scanf("%s", &staff->apartment);
	printf("%s\n", "请输入你的职位： ");
	scanf("%s", &staff->workPosition);
	printf("%s\n", "请输入你的家庭电话号码：");
	scanf("%s", &staff->housePhone);
	printf("%s\n", "请输入你的手机号码：");
	scanf("%s", &staff->telePhone);

	inStaff(staff);
	printf("%s\n", "成功录入！");
}

//插入员工薪水
void insertWater() {
	Water *water = malloc(sizeof(Water));

	printf("%s\n", "请输入你的工资卡号： ");
	scanf("%s", &water->waterCard);
	printf("%s\n", "请输入你的姓名：");
	scanf("%s", &water->name);
	printf("%s\n", "请输入你的工资：");
	scanf("%d", &water->water);
	printf("%s\n", "请输入你的水费： ");
	scanf("%d", &water->drink);
	printf("%s\n", "请输入你的电费：");
	scanf("%d", &water->electric);
	printf("%s\n", "请输入你的清洁费：");
	scanf("%d", &water->clean);
	printf("%s\n", "请输入你的闭路电视费：");
	scanf("%d", &water->tv);
	printf("%s\n", "请输入你的特别奖励：");
	scanf("%d", &water->special);
	if (water->water <= 1800) {
		water->tax = 0;
	} else {
		if (water->water <= 3400) {
			water->tax = (water->water - 1800) * 0.05;
		} else {
			water->tax = (water->water - 3400) * 0.1;
		}
	}
	water->real = water->water - water->drink - water->electric - water->clean - water->tv - water->tax + water->special;


	inWater(water);
	printf("%s\n", "成功录入！");
}

//通过身份证号删除职员信息
void deleteStaffById(char id[]) {
	if (!empty(id)) {
		printf("%s\n", "错误！没有该身份证号！");
		return ;
	}
	if (!strcmp(sHead->idCard, id)) {
		sHead = sHead->next;
		printf("删除职员身份证号： %s\n", id);
		return ;
	}
	Staff *pre = sHead;
	Staff *head = sHead;
	while (head != NULL) {
		if (!strcmp(head->idCard, id)) {
			pre->next = head->next;
			head->next = NULL;
			printf("删除职员身份证号： %s\n", id);
			return ;
		}
		pre = head;
		head = head->next;
	}
}

//通过身份证号更新职员信息
void updateStaffById(char id[]) {
	if (!empty(id)) {
		printf("%s\n", "错误！请重新输入身份证号！");
		return ;
	}
	Staff *head = sHead;
	while (head != NULL) {
		if (!strcmp(head->idCard, id)) {
			printf("%s\n", "请输入你的姓名;");
			scanf("%s", &head->name);
			printf("%s\n", "请输入你的工资卡号：");
			scanf("%s", &head->waterCard);
			printf("%s\n", "请输入你的性别： ");
			scanf("%s", &head->sex);
			printf("%s\n", "请输入你的年龄： ");
			scanf("%d", &head->age);
			printf("%s\n", "请输入你的工龄： ");
			scanf("%d", &head->workAge);
			printf("%s\n", "请输入你的部门：");
			scanf("%s", &head->apartment);
			printf("%s\n", "请输入你的职位：");
			scanf("%s", &head->workPosition);
			printf("%s\n", "请输入你的家庭电话号码： ");
			scanf("%s", &head->housePhone);
			printf("%s\n", "请输入你的手机号码： ");
			scanf("%s", &head->telePhone);
		}
		head = head->next;
	}
}

//统计年龄小于指定岁数的职员的数量
int countAgeLess(int age) {
	int index = 0;
	Staff *staff = sHead;
	while (staff != NULL) {
		if (staff->age <= age) {
			index += 1;
		}
		staff = staff->next;
	}
	return index;
}

//统计所有薪水
void countAllWater() {
	Water *water = wHead;
	int Water = 0, Drink = 0, Electric = 0, Clean = 0, TV = 0, Tax = 0, Real = 0, Special = 0;
	while (water != NULL) {
		Water += water->water;
		Drink += water->drink;
		Electric += water->electric;
		Clean += water->clean;
		TV += water->tv;
		Tax += water->tax;
		Real += water->real;
		Special += water->special;
		water = water->next;
	}
	printf("薪水:%d 水费:%d 电费:%d 清洁费:%d 闭路电视费:%d 税收:%d 实发工资:%d 特别奖励:%d \n", Water, Drink, Electric, Clean, TV, Tax, Real, Special);
}

//统计所有税收
int countAllTax() {
	int Tax = 0;
	Water *water = wHead;
	while (water != NULL) {
		Tax += water->tax;
		water = water->next;
	}
	return Tax;
}

//按实际工资进行排序
void sortByReadlWater() {
	Water *head = wHead;
	Water *next = NULL;
	while (head != NULL) {
		next = head->next;
		while (next != NULL) {
			if (head->real <= next->real) {
				char ch1[32]; strcpy(ch1, head->waterCard); strcpy(head->waterCard, next->waterCard); strcpy(next->waterCard, ch1);
				char ch2[32]; strcpy(ch2, head->name); strcpy(head->name, next->name); strcpy(next->name, ch2);
				int temp = head->water; head->water = next->water; next->water = temp;
				temp = head->drink; head->drink = next->drink; next->drink = temp;
				temp = head->electric; head->electric = next->electric; next->electric = temp;
				temp = head->clean; head->clean = next->clean; next->clean = temp;
				temp = head->tv; head->tv = next->tv; next->tv = temp;
				temp = head->tax; head->tax = next->tax; next->tax = temp;
				temp = head->real; head->real = next->real; next->real = temp;
				temp = head->special; head->special = next->special; next->special = temp;
			}
			next = next->next;
		}
		head = head->next;
	}
	Print("薪水");
}

int main () {

	//Init
	initStaff("a.txt");

	//Print
	Print("staff");

	char id[32];
	char choice;
	int count = 0, x;

	while (1) {
		puts("        * * * *             系统操作              * * *");
		puts("        ***********************************************");
		puts("        *                                             *");
		printf("        *    1 ]. 插入员工信息	                     *\n");
		puts("        *                                             *");
		printf("        *    2 ]. 插入员工薪水                       *\n");
		puts("        *                                             *");
		printf("        *    3 ]. 通过身份证号查询员工               *\n");
		puts("        *                                             *");
		printf("        *    4 ]. 通过身份证号更新信息               *\n");
		puts("        *                                             *");
		printf("        *    5 ]. 通过身份证号删除信息               *\n");
		puts("        *                                             *");
		printf("        *    6 ]. 统计小于指定岁数的员工人数         *\n");
		puts("        *                                             *");
		printf("        *    7 ]. 统计所有员工薪水                   *\n");
		puts("        *                                             *");
		printf("        *    8 ]. 统计全年员工税收                   *\n");
		puts("        *                                             *");
		printf("        *    9 ]. 按实际薪水进行排序                 *\n");
		puts("        *                                             *");
		printf("        *    0 ]. 退出                               *\n");
		puts("        *                                             *");
		puts("        ***********************************************");
		printf(" 请输入 (0 到 9):");
		choice = getchar();

		puts("");
		getchar();
	 	switch (choice) {
			case '1':
				insertStaff();
				printf("\nPress Enter to continue...\n");
				getchar();
				break;
			case '2':
				insertWater();
				printf("\nPress Enter to continue...\n");
				getchar();
				break;
			case '3':
				printf("%s", "请输入身份证号：");
				scanf("%s", &id);
				Staff *head = selectStaffById(id);
				if (head != NULL) {
					printf("%s %s %s %s %d %d %s %s %s %s \n", head->name, head->idCard, head->waterCard, head->sex, head->age, 
						head->workAge, head->apartment, head->workPosition, head->housePhone, head->telePhone);
				}
				printf("\nPress Enter to continue...\n");
				getchar();
				break;
			case '4':
				printf("%s", "请输入身份证号：");
				scanf("%s", &id);
				updateStaffById(id);
				printf("\nPress Enter to continue...\n");
				getchar();
				break;
			case '5':
				printf("%s", "请输入身份证号：");
				scanf("%s", &id);
				deleteStaffById(id);
				printf("\nPress Enter to continue...\n");
				getchar();
				break;
			case '6':
				printf("%s", "请输入岁数：");
				scanf("%d", &x);
				count = countAgeLess(x);
				printf("%d: %d\n", x, count);
				printf("\nPress Enter to continue...\n");
				getchar();
				break;
			case '7':
				countAllWater();
				printf("\nPress Enter to continue...\n");
				getchar();
				break;
			case '8':
				count = countAllTax();
				printf("全年税收为： %d\n", count);
				printf("\nPress Enter to continue...\n");
				getchar();
				break;
			case '9':
				sortByReadlWater();
				printf("\nPress Enter to continue...\n");
				getchar();
				break;
			case '0':
				return 0;
				break;
			default:
				break;
		}	
	}

	return 0;
}