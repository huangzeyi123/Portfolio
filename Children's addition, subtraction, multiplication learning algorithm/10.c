#include<stdio.h>//从数据库中调用函数
#include<stdlib.h>//从系统数据库调用函数
#include<time.h>//调用时间函数
#include<math.h>//调用数学函数
int duoweishu3(int f);//定义乘法多位数
int duoweishu1(int f);//定义加法多位数
int duoweishu2(int f);//定义减法多位数

int main(void)//主函数执行
{
	int op;
	printf("请输入数字\n1.仅学习加法\n2.仅学习减法\n3.仅学习乘法\n4.学习加减乘随机组合\n");//提醒用户
	scanf("%d",&op);//选择做的计算类型
//*****************************************************乘法
	if(op==3){
	int a,b,c,n,i,d,f;
	double e;
	srand(time(NULL));//随机函数
	e=0;
	a=1+rand()%9;//随机数
    b=1+rand()%9;//随机数
	d=1+rand()%4;//随机数
	printf("请输入难度级别，1代表仅出现一位数问题，2代表出现两位数问题，以此类推");//提醒用户
	scanf("%d",&f);//选择计算类型
   
	if(f==1)
	{
	for(n=1;n<=10;n++){//切换学生循环
	printf("How much is%d times %d?\n",a,b);
	scanf("%d",&c);
	
	for(i=1;i<10;i++){//题数循环
	if(c!=a*b)//输入错误
	{
	switch(d){//随机数选择打印语句
	case 1:printf("No.Please try again.\n");
		break;

	case 2:printf("Wrong.try once more.\n");
		break;

	case 3:printf("Don't give up!\n");
		break;

	case 4:printf("NO.Keep trying.\n");
		break;
	}//end switch
        printf("How much is%d times %d?\n",a,b);//重新打印
		scanf("%d",&c);
	    d=1+rand()%4;//重新赋值	
		
	}//end if
    if(c==a*b)//输入正确
	{	
	switch(d){//随机数选择打印语句
	case 1:printf("Very good!\n");
		break;

	case 2:printf("Excellent!\n");
		break;

	case 3:printf("Nice work!\n");
		break;

	case 4:printf("Keep up the good work!\n");
		break;
	}//end switch
		a=1+rand()%9;//重新赋值
        b=1+rand()%9;//重新赋值
		printf("How much is%d times %d?\n",a,b);//重新打印
	    scanf("%d",&c);
		d=1+rand()%4;//重新赋值
		e++;
	}//end if
	}//end second first
	printf("正确率为%f\n",e/10);

	if(e<8){
		printf("Please ask your instructor for extra help.\n");
		e=0;
	}//end if
	else{
		printf("Congratulation,you are ready to go to the next level\n");
		e=0;
	}//end else
	}//end first for
	}//end second if
	else
	{
		duoweishu3(f);
	}
	}//end first if
//******************************************************************加法
		if(op==1){
	int a,b,c,n,i,d,f;
	double e;
	srand(time(NULL));//随机函数
	e=0;
	a=1+rand()%9;//随机数
    b=1+rand()%9;//随机数
	d=1+rand()%4;//随机数
	printf("请输入难度级别，1代表仅出现一位数问题，2代表出现两位数问题，以此类推");//提醒用户信息
	scanf("%d",&f);
    
	if(f==1)//选择计算类型
	{
	for(n=1;n<=10;n++){//切换学生循环
	printf("How much is%d plus %d?\n",a,b);
	scanf("%d",&c);
	
	for(i=1;i<10;i++){//题数循环
	if(c!=a+b)//输入错误
	{
	switch(d){//随机数打印随机语句
	case 1:printf("No.Please try again.\n");
		break;

	case 2:printf("Wrong.try once more.\n");
		break;

	case 3:printf("Don't give up!\n");
		break;

	case 4:printf("NO.Keep trying.\n");
		break;
	}//end switch
        printf("How much is%d plus %d?\n",a,b);//重新打印
		scanf("%d",&c);
	    d=1+rand()%4;//重新赋值
				
	}//end if
    if(c==a+b)//输入正确
	{	
	switch(d){
	case 1:printf("Very good!\n");
		break;

	case 2:printf("Excellent!\n");
		break;

	case 3:printf("Nice work!\n");
		break;

	case 4:printf("Keep up the good work!\n");
		break;
	}//end switch
		a=1+rand()%9;//重新赋值
        b=1+rand()%9;//重新赋值
		printf("How much is%d plus %d?\n",a,b);
	    scanf("%d",&c);
		d=1+rand()%4;//重新赋值
		e++;//正确题数
	}//end if
	}//end second first
	printf("正确率为%f\n",e/10);

	if(e<8){
		printf("Please ask your instructor for extra help.\n");
		e=0;
	}//end if
	else{
		printf("Congratulation,you are ready to go to the next level\n");
		e=0;
	}//end else
	}//end first for
	}//end second if
	else
	{
		duoweishu1(f);//加法多位数
	}
	}//end first if
//*****************************************************************************************减法
if(op==2){//选择计算类型
	int a,b,c,n,i,d,f;
	double e;
	srand(time(NULL));//时间函数
	e=0;
	a=1+rand()%9;//随机数
    b=1+rand()%9;//随机数
	d=1+rand()%4;//随机数
	printf("请输入难度级别，1代表仅出现一位数问题，2代表出现两位数问题，以此类推");
	scanf("%d",&f);
   
	if(f==1)//一位数
	{
	for(n=1;n<=10;n++){//切换学生循环
	printf("How much is%d minus %d?\n",a,b);//提示用户
	scanf("%d",&c);
	
	for(i=1;i<10;i++){//题数循环
	if(c!=a-b)//输入错误
	{
	switch(d){//随机数输出语句
	case 1:printf("No.Please try again.\n");
		break;

	case 2:printf("Wrong.try once more.\n");
		break;

	case 3:printf("Don't give up!\n");
		break;

	case 4:printf("NO.Keep trying.\n");
		break;
	}//end switch
        printf("How much is%d minus %d?\n",a,b);//重新打印
		scanf("%d",&c);
	    d=1+rand()%4;//重新赋值
				
	}//end if
    if(c==a-b)//输入正确
	{	
	switch(d){//随机数输出语句
	case 1:printf("Very good!\n");
		break;

	case 2:printf("Excellent!\n");
		break;

	case 3:printf("Nice work!\n");
		break;

	case 4:printf("Keep up the good work!\n");
		break;
	}//end switch
		a=1+rand()%9;//重新赋值
        b=1+rand()%9;//重新赋值
		printf("How much is%d minus %d?\n",a,b);
	    scanf("%d",&c);
		d=1+rand()%4;//重新赋值
		e++;//正确题数
	}//end if
	}//end second first
	printf("正确率为%f\n",e/10);

	if(e<8){
		printf("Please ask your instructor for extra help.\n");
		e=0;
	}//end if
	else{
		printf("Congratulation,you are ready to go to the next level\n");
		e=0;
	}//end else
	}//end first for
	}//end second if
	else
	{
		duoweishu2(f);//减法多位数
	}
	}//end first if
//***********************************************************************************混合计算
if(op==4){
	int a,b,c,n,i,d,f,j;
	double e;
	srand(time(NULL));
	e=0;
	j=1+rand()%3;//赋值
	a=1+rand()%9;//赋值
    b=1+rand()%9;//赋值
	d=1+rand()%4;//赋值
	printf("请输入难度级别，1代表仅出现一位数问题，2代表出现两位数问题，以此类推");
	scanf("%d",&f);
	if(f==1)//一位数计算
	{
	for(n=1;n<=10;n++){//换学生循环
		for(i=1;i<10;i++){//题数循环
		switch(j){
		case 3:printf("How much is%d times %d?\n",a,b);//随机数选择乘法
	scanf("%d",&c);
	
	if(c!=a*b)//输入错误
	{
	switch(d){//随机输出语句
	case 1:printf("No.Please try again.\n");
		break;

	case 2:printf("Wrong.try once more.\n");
		break;

	case 3:printf("Don't give up!\n");
		break;

	case 4:printf("NO.Keep trying.\n");
		break;
	}//end switch
        printf("How much is%d times %d?\n",a,b);//重新打印
		scanf("%d",&c);
	    d=1+rand()%4;//重新赋值
		
	}//end if
    if(c==a*b)//输入正确
	{	
	switch(d){//随机输出语句
	case 1:printf("Very good!\n");
		break;

	case 2:printf("Excellent!\n");
		break;

	case 3:printf("Nice work!\n");
		break;

	case 4:printf("Keep up the good work!\n");
		break;
	}//end switch
		a=1+rand()%9;//重新赋值
        b=1+rand()%9;//重新赋值
		printf("How much is%d times %d?\n",a,b);
	    scanf("%d",&c);//重新赋值
		d=1+rand()%4;//重新赋值
		e++;
		j=1+rand()%3;//重新赋值
	}//end if
	break;
		case 1:printf("How much is%d plus %d?\n",a,b);//随机数选择加法
	scanf("%d",&c);
	
	if(c!=a+b)//输入错误
	{
	switch(d){//随机输出语句
	case 1:printf("No.Please try again.\n");
		break;

	case 2:printf("Wrong.try once more.\n");
		break;

	case 3:printf("Don't give up!\n");
		break;

	case 4:printf("NO.Keep trying.\n");
		break;
	}//end switch
        printf("How much is%d plus %d?\n",a,b);//重新打印
		scanf("%d",&c);
	    d=1+rand()%4;//重新赋值
		
				
	}//end if
    if(c==a+b)//输入正确
	{	
	switch(d){//随机数打印语句
	case 1:printf("Very good!\n");
		break;

	case 2:printf("Excellent!\n");
		break;

	case 3:printf("Nice work!\n");
		break;

	case 4:printf("Keep up the good work!\n");
		break;
	}//end switch
		a=1+rand()%9;//重新赋值
        b=1+rand()%9;//重新赋值
		printf("How much is%d plus %d?\n",a,b);
	    scanf("%d",&c);//重新赋值
		d=1+rand()%4;//重新赋值
		e++;//正确题数
		j=1+rand()%3;//重新赋值
	   	}//end IF
	break;
		case 2:printf("How much is%d minus %d?\n",a,b);//随机数打印减法
	scanf("%d",&c);
	
	if(c!=a-b)//输入错误
	{
	switch(d){//随机数打印语句
	case 1:printf("No.Please try again.\n");
		break;

	case 2:printf("Wrong.try once more.\n");
		break;

	case 3:printf("Don't give up!\n");
		break;

	case 4:printf("NO.Keep trying.\n");
		break;
	}//end switch
        printf("How much is%d minus %d?\n",a,b);//重新打印
		scanf("%d",&c);
	    d=1+rand()%4;//重新赋值
		
				
	}//end if
    if(c==a-b)
	{	
	switch(d){//随机数输出语句
	case 1:printf("Very good!\n");
		break;

	case 2:printf("Excellent!\n");
		break;

	case 3:printf("Nice work!\n");
		break;

	case 4:printf("Keep up the good work!\n");
		break;
	}//end switch
		a=1+rand()%9;//重新赋值
        b=1+rand()%9;//重新赋值
		printf("How much is%d minus %d?\n",a,b);
	    scanf("%d",&c);//重新赋值
		d=1+rand()%4;//重新赋值
		e++;//正确题数
		j=1+rand()%3;//重新赋值
	}//end if
	break;
}//end switch
}

	printf("正确率为%f\n",e/10);

	if(e<8){
		printf("Please ask your instructor for extra help.\n");
		e=0;
	}//end if
	else{
		printf("Congratulation,you are ready to go to the next level\n");
		e=0;
	}//end else
	}//end first for
	}//end second if
	else//混合计算多位数
	{
		switch(j){
		case 1:	duoweishu1(f);
			break;
		case 2:	duoweishu2(f);
			break;	
		case 3: duoweishu3(f);
			break;
		}		
	}
	}
			system("pause");//调用system("pause")函数暂定程序的运行以便看清屏幕。
}//end main
//***********************************************************************************乘法多位数
int duoweishu3(int f)
{
int a,b,c,n,i,d,h,g;
	double e;
	e=0;
srand(time(NULL));
h=(int)pow(10,f);
a=1+rand()%(int)(h-1);//选择位数
b=1+rand()%(int)(h-1);//选择位数
d=1+rand()%4;
{
	for(n=1;n<=10;n++){
	printf("How much is%d times %d?\n",a,b);
	scanf("%d",&c);
	
	for(i=1;i<10;i++){
	if(c!=a*b)
	{
	switch(d){
	case 1:printf("No.Please try again.\n");
		break;

	case 2:printf("Wrong.try once more.\n");
		break;

	case 3:printf("Don't give up!\n");
		break;

	case 4:printf("NO.Keep trying.\n");
		break;
	}//end switch
        printf("How much is%d times %d?\n",a,b);
		scanf("%d",&c);
	    d=1+rand()%4;
		
		
	}//end if
    if(c==a*b)
	{	
	switch(d){
	case 1:printf("Very good!\n");
		break;

	case 2:printf("Excellent!\n");
		break;

	case 3:printf("Nice work!\n");
		break;

	case 4:printf("Keep up the good work!\n");
		break;
	}//end switch
		a=1+rand()%(int)(h-1);
        b=1+rand()%(int)(h-1);
		printf("How much is%d times %d?\n",a,b);
	    scanf("%d",&c);
		d=1+rand()%4;
		e++;
	}//end if
	}//end second first
	printf("正确率为%f\n",e/10);

	if(e<8){
		printf("Please ask your instructor for extra help.\n");
		e=0;
	}//end if
	else{
		printf("Congratulation,you are ready to go to the next level\n");
		e=0;
	}
	}
}
}
//******************************************************************加法多位数
int duoweishu1(int f)
{
int a,b,c,n,i,d,h,g;
	double e;
	e=0;
srand(time(NULL));
h=(int)pow(10,f);
a=1+rand()%(int)(h-1);//选择位数
b=1+rand()%(int)(h-1);//选择位数
d=1+rand()%4;
{
	for(n=1;n<=10;n++){
	printf("How much is%d plus %d?\n",a,b);
	scanf("%d",&c);
	
	for(i=1;i<10;i++){
	if(c!=a+b)
	{
	switch(d){
	case 1:printf("No.Please try again.\n");
		break;

	case 2:printf("Wrong.try once more.\n");
		break;

	case 3:printf("Don't give up!\n");
		break;

	case 4:printf("NO.Keep trying.\n");
		break;
	}//end switch
        printf("How much is%d plus %d?\n",a,b);
		scanf("%d",&c);
	    d=1+rand()%4;
		
		
	}//end if
    if(c==a+b)
	{	
	switch(d){
	case 1:printf("Very good!\n");
		break;

	case 2:printf("Excellent!\n");
		break;

	case 3:printf("Nice work!\n");
		break;

	case 4:printf("Keep up the good work!\n");
		break;
	}//end switch
		a=1+rand()%(int)(h-1);
        b=1+rand()%(int)(h-1);
		printf("How much is%d plus %d?\n",a,b);
	    scanf("%d",&c);
		d=1+rand()%4;
		e++;
	}//end if
	}//end second first
	printf("正确率为%f\n",e/10);

	if(e<8){
		printf("Please ask your instructor for extra help.\n");
		e=0;
	}//end if
	else{
		printf("Congratulation,you are ready to go to the next level\n");
		e=0;
	}
	}
}
}
//***********************************************************************************************减法多位数
int duoweishu2(int f)
{
int a,b,c,n,i,d,h,g;
	double e;
	e=0;
srand(time(NULL));
h=(int)pow(10,f);
a=1+rand()%(int)(h-1);//选择位数
b=1+rand()%(int)(h-1);//选择位数
d=1+rand()%4;
{
	for(n=1;n<=10;n++){
	printf("How much is%d minus %d?\n",a,b);
	scanf("%d",&c);
	
	for(i=1;i<10;i++){
	if(c!=a-b)
	{
	switch(d){
	case 1:printf("No.Please try again.\n");
		break;

	case 2:printf("Wrong.try once more.\n");
		break;

	case 3:printf("Don't give up!\n");
		break;

	case 4:printf("NO.Keep trying.\n");
		break;
	}//end switch
        printf("How much is%d minus %d?\n",a,b);
		scanf("%d",&c);
	    d=1+rand()%4;
		
		
	}//end if
    if(c==a-b)
	{	
	switch(d){
	case 1:printf("Very good!\n");
		break;

	case 2:printf("Excellent!\n");
		break;

	case 3:printf("Nice work!\n");
		break;

	case 4:printf("Keep up the good work!\n");
		break;
	}//end switch
		a=1+rand()%(int)(h-1);
        b=1+rand()%(int)(h-1);
		printf("How much is%d minus %d?\n",a,b);
	    scanf("%d",&c);
		d=1+rand()%4;
		e++;
	}//end if
	}//end second first
	printf("正确率为%f\n",e/10);

	if(e<8){
		printf("Please ask your instructor for extra help.\n");
		e=0;
	}//end if
	else{
		printf("Congratulation,you are ready to go to the next level\n");
		e=0;
	}
	}
}
}


