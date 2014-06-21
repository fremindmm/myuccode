#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//c字符串的常见操 作 //1 给字符串赋值
int main() {
	//1 赋值 （= 改地址  strcpy 改值）
	char* s1 = "abc";//只读常量区
	char s2[10] = "abc";//数组可以看成一个常指针 （不能改地址，（=）只能初始化），某些时候和指针有区别（sizeof 数组）int* test() {retrun arr};,不能在返回值直接写数组
	s1 = "123";//Y
	strcpy(s1,"123");//段错误，修改只读区的值
	s2 = "123";//常指针不能改地址
	strcpy(s2,"123");//值是可以改的
	char* s3 = malloc(10);
	strcpy(s3,"abc");//Y
	s3 = "123";//N 改地址，指向了只读区 堆的指针丢失内存泄漏
	printf("s3 =%s\n",s3);
	free(s3);//free()失败，内存泄漏
//数组型 统用strcpy  赋值
	//char* 指针型 指向堆栈区使用 strcpy()赋值 但：指向只读区不能用strcpy只读区只能用= 改值
	//2 求字符串的有效长度用strlen() ，求buf整体大小容量sizeof（）
	char buf[50] ="abc";
	printf("size =%d,length = 3",sizeof(buf),strlen(buf));
	//3 字符串的比较(== 比的是地址，一般都用strcmp（）来比较 比的才是值) 
//	char* s4 = "abc";
//	char* s5 = "abc";
	char* s4[10] = "abc";
	char* s5[10] = "abc";
	printf("%d",s4==s5);
	printf("%d",strcmp(s4,s5));
// 4 用指针草组字符串
	char* s6 = "zhangfei,123";//用户名 密码 拆分
//1 先拆分
	int len = strlen(s6);
	char name[len] = {};//可变大小不能初始化 清buf
	char passwd[len] = {};
	memset(name,0,len);//string.h (void*s,int c,size_t n) 清buf
	memset(passwd,0,len);
	int i,flag = 0,pos = 0;
	for(i = 0;i < len;i++){
		if(*(s6+i) == ','){ 
			flag = 1;
			pos = i;
			continue;
		}
		if(!flag) name[i] = *(s6+i);
		else passwd[i-pos-1] = *(s6+i);
		
	}

//while(s6 == '\0')
//5 字符串的拼接
char fpath[20] = "/home/tarena";
char fname[20] = "a.txt";
char pname[50] = {};
/*strcpy(pname,fpath);
strcat(pname,'/');
strcat(pname,fname);*/
sprintf(pname,"%s/%s",fpath,fname);
printf("pname= %s\n",pname);
//6 字符串和其他类型的转换 sprintf()和sscanf()
int x = 100;
char bufx[10] = {};
sprintf(bufx,"%d",x);//其他类型转字符串
printf("%s\n",bufx);//字符串转其他类型
int y;
sscanf(bufx,"%d",&y);
printf("y = %d\n",y);














}
