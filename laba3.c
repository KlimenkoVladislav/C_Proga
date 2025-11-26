#include <stdio.h>

int chislo_up(int c_i, int c_j, int c_n, int flag){
	if (flag>0){return chislo_up(flag, c_j, c_n, 0)+(c_i-(c_n-c_j+1));}
	else{
		if (c_i<2){return c_j;}
		if (c_i>=2){return 3+4*(c_n-2*(c_i-1))+chislo_up(c_i-1, c_j, c_n, 0);}
	}
}
int chislo_down(int c_i, int c_j, int c_n, int flag){
	if (flag>0){return chislo_down(c_n+1-flag, c_j, c_n, 0)-(c_i-(c_n-c_j+1));}
	else{
		if (c_i==c_n){return 3*(c_n-1)-c_j+2;}
		if (c_i<c_n){return 3+4*((c_n-4)+(c_n-c_i)-3*(c_n-c_i-1))+chislo_down(c_i+1, c_j, c_n, 0);}
	}
}

int main(){
	int ogr_r = 1, ogr_l = 0;
	int n; scanf("%d", &n);
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (i==1 && j<10){printf("0%d ", j);}
			else if (i==1){printf("%d ", j);}
			if (i==n && (3*(n-1)-j+2)<10){printf("0%d ", 3*(n-1)-j+2);}
			else if (i==n){printf("%d ", 3*(n-1)-j+2);}
			if (i>1 && i<n){
				if ((i<=(n/2+1) && n%2==1) || (i<=(n/2) && n%2==0)){
					if (j<=ogr_l && chislo_down(i, j, n, j)>9){printf("%d ", chislo_down(i, j, n, j));}
					else if (j>n-ogr_r && chislo_up(i, j, n, n-j+1)>9){printf("%d ", chislo_up(i, j, n, n-j+1));}
					else if (j>ogr_l && j<=n-ogr_r && chislo_up(i, j, n, 0)>9){printf("%d ", chislo_up(i, j, n, 0));}
					if (j<=ogr_l && chislo_down(i, j, n, j)<10){printf("0%d ", chislo_down(i, j, n, j));}
					else if (j>n-ogr_r && chislo_up(i, j, n, n-j+1)<10){printf("0%d ", chislo_up(i, j, n, n-j+1));}
					else if (j>ogr_l && j<=n-ogr_r && chislo_up(i, j, n, 0)<10){printf("0%d ", chislo_up(i, j, n, 0));}
				}
				if ((i>(n/2+1) && n%2==1) || (i>(n/2) && n%2==0)){
					if (j<=ogr_l && chislo_down(i, j, n, j)>9){printf("%d ", chislo_down(i, j, n, j));}
					else if (j>n-ogr_r && chislo_up(i, j, n, n-j+1)>9){printf("%d ", chislo_up(i, j, n, n-j+1));}
					else if (j>ogr_l && j<=n-ogr_r){printf("%d ", chislo_down(i, j, n, 0));}
					if (j<=ogr_l && chislo_down(i, j, n, j)<10){printf("0%d ", chislo_down(i, j, n, j));}
					else if (j>n-ogr_r && chislo_up(i, j, n, n-j+1)<10){printf("0%d ", chislo_up(i, j, n, n-j+1));}
				}
			}
		}
		printf("\n");
		if (i>1 && i<n){
			if ((i==(n/2+1) && n%2==1) || (i==(n/2) && n%2==0)){ogr_r = n-i-1; ogr_l = n-i-1;}
			if ((i<(n/2+1) && n%2==1) || (i<(n/2) && n%2==0)){ogr_r++; ogr_l++;}
			if ((i>(n/2+1) && n%2==1) || (i>(n/2) && n%2==0)){ogr_r--; ogr_l--;}
		}
	}
}