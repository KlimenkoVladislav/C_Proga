#include <stdio.h>
/*
int main(){
	int n; printf("Введите число: "); scanf("%d", &n);
	int b = 1;
	for (int i=0; i<32; i++)
	{
		if(b<<i == n){printf("Да\n"); b = 0; break;}
	}
	if (b!=0){printf("Нет\n");}
}
*/
int main(){
	int a; printf("Введите число: "); scanf("%d", &a);
	int kol = 0;
	for (int i = 0; i<32; i++){
		if (((a>>i)&1)==0){kol+=1;}
	}
	printf("%d\n", kol);
}