#include<stdio.h>//�����ݿ��е��ú���
#include<stdlib.h>//��ϵͳ���ݿ���ú���
#include<time.h>//����ʱ�亯��
#include<math.h>//������ѧ����
int duoweishu3(int f);//����˷���λ��
int duoweishu1(int f);//����ӷ���λ��
int duoweishu2(int f);//���������λ��

int main(void)//������ִ��
{
	int op;
	printf("����������\n1.��ѧϰ�ӷ�\n2.��ѧϰ����\n3.��ѧϰ�˷�\n4.ѧϰ�Ӽ���������\n");//�����û�
	scanf("%d",&op);//ѡ�����ļ�������
//*****************************************************�˷�
	if(op==3){
	int a,b,c,n,i,d,f;
	double e;
	srand(time(NULL));//�������
	e=0;
	a=1+rand()%9;//�����
    b=1+rand()%9;//�����
	d=1+rand()%4;//�����
	printf("�������Ѷȼ���1���������һλ�����⣬2���������λ�����⣬�Դ�����");//�����û�
	scanf("%d",&f);//ѡ���������
   
	if(f==1)
	{
	for(n=1;n<=10;n++){//�л�ѧ��ѭ��
	printf("How much is%d times %d?\n",a,b);
	scanf("%d",&c);
	
	for(i=1;i<10;i++){//����ѭ��
	if(c!=a*b)//�������
	{
	switch(d){//�����ѡ���ӡ���
	case 1:printf("No.Please try again.\n");
		break;

	case 2:printf("Wrong.try once more.\n");
		break;

	case 3:printf("Don't give up!\n");
		break;

	case 4:printf("NO.Keep trying.\n");
		break;
	}//end switch
        printf("How much is%d times %d?\n",a,b);//���´�ӡ
		scanf("%d",&c);
	    d=1+rand()%4;//���¸�ֵ	
		
	}//end if
    if(c==a*b)//������ȷ
	{	
	switch(d){//�����ѡ���ӡ���
	case 1:printf("Very good!\n");
		break;

	case 2:printf("Excellent!\n");
		break;

	case 3:printf("Nice work!\n");
		break;

	case 4:printf("Keep up the good work!\n");
		break;
	}//end switch
		a=1+rand()%9;//���¸�ֵ
        b=1+rand()%9;//���¸�ֵ
		printf("How much is%d times %d?\n",a,b);//���´�ӡ
	    scanf("%d",&c);
		d=1+rand()%4;//���¸�ֵ
		e++;
	}//end if
	}//end second first
	printf("��ȷ��Ϊ%f\n",e/10);

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
//******************************************************************�ӷ�
		if(op==1){
	int a,b,c,n,i,d,f;
	double e;
	srand(time(NULL));//�������
	e=0;
	a=1+rand()%9;//�����
    b=1+rand()%9;//�����
	d=1+rand()%4;//�����
	printf("�������Ѷȼ���1���������һλ�����⣬2���������λ�����⣬�Դ�����");//�����û���Ϣ
	scanf("%d",&f);
    
	if(f==1)//ѡ���������
	{
	for(n=1;n<=10;n++){//�л�ѧ��ѭ��
	printf("How much is%d plus %d?\n",a,b);
	scanf("%d",&c);
	
	for(i=1;i<10;i++){//����ѭ��
	if(c!=a+b)//�������
	{
	switch(d){//�������ӡ������
	case 1:printf("No.Please try again.\n");
		break;

	case 2:printf("Wrong.try once more.\n");
		break;

	case 3:printf("Don't give up!\n");
		break;

	case 4:printf("NO.Keep trying.\n");
		break;
	}//end switch
        printf("How much is%d plus %d?\n",a,b);//���´�ӡ
		scanf("%d",&c);
	    d=1+rand()%4;//���¸�ֵ
				
	}//end if
    if(c==a+b)//������ȷ
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
		a=1+rand()%9;//���¸�ֵ
        b=1+rand()%9;//���¸�ֵ
		printf("How much is%d plus %d?\n",a,b);
	    scanf("%d",&c);
		d=1+rand()%4;//���¸�ֵ
		e++;//��ȷ����
	}//end if
	}//end second first
	printf("��ȷ��Ϊ%f\n",e/10);

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
		duoweishu1(f);//�ӷ���λ��
	}
	}//end first if
//*****************************************************************************************����
if(op==2){//ѡ���������
	int a,b,c,n,i,d,f;
	double e;
	srand(time(NULL));//ʱ�亯��
	e=0;
	a=1+rand()%9;//�����
    b=1+rand()%9;//�����
	d=1+rand()%4;//�����
	printf("�������Ѷȼ���1���������һλ�����⣬2���������λ�����⣬�Դ�����");
	scanf("%d",&f);
   
	if(f==1)//һλ��
	{
	for(n=1;n<=10;n++){//�л�ѧ��ѭ��
	printf("How much is%d minus %d?\n",a,b);//��ʾ�û�
	scanf("%d",&c);
	
	for(i=1;i<10;i++){//����ѭ��
	if(c!=a-b)//�������
	{
	switch(d){//�����������
	case 1:printf("No.Please try again.\n");
		break;

	case 2:printf("Wrong.try once more.\n");
		break;

	case 3:printf("Don't give up!\n");
		break;

	case 4:printf("NO.Keep trying.\n");
		break;
	}//end switch
        printf("How much is%d minus %d?\n",a,b);//���´�ӡ
		scanf("%d",&c);
	    d=1+rand()%4;//���¸�ֵ
				
	}//end if
    if(c==a-b)//������ȷ
	{	
	switch(d){//�����������
	case 1:printf("Very good!\n");
		break;

	case 2:printf("Excellent!\n");
		break;

	case 3:printf("Nice work!\n");
		break;

	case 4:printf("Keep up the good work!\n");
		break;
	}//end switch
		a=1+rand()%9;//���¸�ֵ
        b=1+rand()%9;//���¸�ֵ
		printf("How much is%d minus %d?\n",a,b);
	    scanf("%d",&c);
		d=1+rand()%4;//���¸�ֵ
		e++;//��ȷ����
	}//end if
	}//end second first
	printf("��ȷ��Ϊ%f\n",e/10);

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
		duoweishu2(f);//������λ��
	}
	}//end first if
//***********************************************************************************��ϼ���
if(op==4){
	int a,b,c,n,i,d,f,j;
	double e;
	srand(time(NULL));
	e=0;
	j=1+rand()%3;//��ֵ
	a=1+rand()%9;//��ֵ
    b=1+rand()%9;//��ֵ
	d=1+rand()%4;//��ֵ
	printf("�������Ѷȼ���1���������һλ�����⣬2���������λ�����⣬�Դ�����");
	scanf("%d",&f);
	if(f==1)//һλ������
	{
	for(n=1;n<=10;n++){//��ѧ��ѭ��
		for(i=1;i<10;i++){//����ѭ��
		switch(j){
		case 3:printf("How much is%d times %d?\n",a,b);//�����ѡ��˷�
	scanf("%d",&c);
	
	if(c!=a*b)//�������
	{
	switch(d){//���������
	case 1:printf("No.Please try again.\n");
		break;

	case 2:printf("Wrong.try once more.\n");
		break;

	case 3:printf("Don't give up!\n");
		break;

	case 4:printf("NO.Keep trying.\n");
		break;
	}//end switch
        printf("How much is%d times %d?\n",a,b);//���´�ӡ
		scanf("%d",&c);
	    d=1+rand()%4;//���¸�ֵ
		
	}//end if
    if(c==a*b)//������ȷ
	{	
	switch(d){//���������
	case 1:printf("Very good!\n");
		break;

	case 2:printf("Excellent!\n");
		break;

	case 3:printf("Nice work!\n");
		break;

	case 4:printf("Keep up the good work!\n");
		break;
	}//end switch
		a=1+rand()%9;//���¸�ֵ
        b=1+rand()%9;//���¸�ֵ
		printf("How much is%d times %d?\n",a,b);
	    scanf("%d",&c);//���¸�ֵ
		d=1+rand()%4;//���¸�ֵ
		e++;
		j=1+rand()%3;//���¸�ֵ
	}//end if
	break;
		case 1:printf("How much is%d plus %d?\n",a,b);//�����ѡ��ӷ�
	scanf("%d",&c);
	
	if(c!=a+b)//�������
	{
	switch(d){//���������
	case 1:printf("No.Please try again.\n");
		break;

	case 2:printf("Wrong.try once more.\n");
		break;

	case 3:printf("Don't give up!\n");
		break;

	case 4:printf("NO.Keep trying.\n");
		break;
	}//end switch
        printf("How much is%d plus %d?\n",a,b);//���´�ӡ
		scanf("%d",&c);
	    d=1+rand()%4;//���¸�ֵ
		
				
	}//end if
    if(c==a+b)//������ȷ
	{	
	switch(d){//�������ӡ���
	case 1:printf("Very good!\n");
		break;

	case 2:printf("Excellent!\n");
		break;

	case 3:printf("Nice work!\n");
		break;

	case 4:printf("Keep up the good work!\n");
		break;
	}//end switch
		a=1+rand()%9;//���¸�ֵ
        b=1+rand()%9;//���¸�ֵ
		printf("How much is%d plus %d?\n",a,b);
	    scanf("%d",&c);//���¸�ֵ
		d=1+rand()%4;//���¸�ֵ
		e++;//��ȷ����
		j=1+rand()%3;//���¸�ֵ
	   	}//end IF
	break;
		case 2:printf("How much is%d minus %d?\n",a,b);//�������ӡ����
	scanf("%d",&c);
	
	if(c!=a-b)//�������
	{
	switch(d){//�������ӡ���
	case 1:printf("No.Please try again.\n");
		break;

	case 2:printf("Wrong.try once more.\n");
		break;

	case 3:printf("Don't give up!\n");
		break;

	case 4:printf("NO.Keep trying.\n");
		break;
	}//end switch
        printf("How much is%d minus %d?\n",a,b);//���´�ӡ
		scanf("%d",&c);
	    d=1+rand()%4;//���¸�ֵ
		
				
	}//end if
    if(c==a-b)
	{	
	switch(d){//�����������
	case 1:printf("Very good!\n");
		break;

	case 2:printf("Excellent!\n");
		break;

	case 3:printf("Nice work!\n");
		break;

	case 4:printf("Keep up the good work!\n");
		break;
	}//end switch
		a=1+rand()%9;//���¸�ֵ
        b=1+rand()%9;//���¸�ֵ
		printf("How much is%d minus %d?\n",a,b);
	    scanf("%d",&c);//���¸�ֵ
		d=1+rand()%4;//���¸�ֵ
		e++;//��ȷ����
		j=1+rand()%3;//���¸�ֵ
	}//end if
	break;
}//end switch
}

	printf("��ȷ��Ϊ%f\n",e/10);

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
	else//��ϼ����λ��
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
			system("pause");//����system("pause")�����ݶ�����������Ա㿴����Ļ��
}//end main
//***********************************************************************************�˷���λ��
int duoweishu3(int f)
{
int a,b,c,n,i,d,h,g;
	double e;
	e=0;
srand(time(NULL));
h=(int)pow(10,f);
a=1+rand()%(int)(h-1);//ѡ��λ��
b=1+rand()%(int)(h-1);//ѡ��λ��
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
	printf("��ȷ��Ϊ%f\n",e/10);

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
//******************************************************************�ӷ���λ��
int duoweishu1(int f)
{
int a,b,c,n,i,d,h,g;
	double e;
	e=0;
srand(time(NULL));
h=(int)pow(10,f);
a=1+rand()%(int)(h-1);//ѡ��λ��
b=1+rand()%(int)(h-1);//ѡ��λ��
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
	printf("��ȷ��Ϊ%f\n",e/10);

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
//***********************************************************************************************������λ��
int duoweishu2(int f)
{
int a,b,c,n,i,d,h,g;
	double e;
	e=0;
srand(time(NULL));
h=(int)pow(10,f);
a=1+rand()%(int)(h-1);//ѡ��λ��
b=1+rand()%(int)(h-1);//ѡ��λ��
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
	printf("��ȷ��Ϊ%f\n",e/10);

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


