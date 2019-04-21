#include<stdio.h>
#include<math.h>
#define N (3)
#define EPS (1e-10)
   int GaussSeidel(double A[N][N],double *b,double *x,int max_iter)
 {
	int fg = 0;
int confg = 0;
	int i,j;
	int k;	//試行回数
	double tmp;
	double e = 0.0;
	double diasum = 0;
	double nondiasum = 0;
	
	/*対角優位であるかの判定*/
	for(i = 0;i < N;i++){
	   for(j = 0;j < N;j++){
		if(i == j) diasum += fabs(A[i][j]);
		else nondiasum += fabs(A[i][j]);
			}
	   }
	if(diasum > nondiasum) fg = 1;
	
	/*反復計算*/
	for(k = 0;k < max_iter;++k){
	　　e = 0.0;
		for(i = 0;i < N;i++){
		　tmp = x[i];
		　x[i] = b[i];
			for(j = 0;j < N;j++){
				if(i != j) x[i] -= A[i][j]*x[j];
			}
			x[i] = x[i] / A[i][i];
			e += fabs(tmp - x[i]);//絶対誤差
		}
	if(e <= EPS) break;	
 }
	/*収束・発散判定*/
	if(fg == 0 && confg == 0 ){
	   printf("The calculation has diverged.\n");
				}
	else {
	   printf("The calculation has converged.\n");
	  }

	printf("max_iter = %d　k = %d\n",max_iter,k);
	printf("e = %lf\n",e);

   return 1;
}

   int main(){
	int max_iter;
	int i,j;
	double A[N][N];
	double b[N];
	double x[N] = {0};

	/*最大繰り返し数の入力*/
	printf("Input max_iter.\n");
	scanf("%d",&max_iter);

	/*行列Aの入力*/
	for(i = 0;i < N;i++){
		for(j = 0;j < N;j++){
	printf("Input value to matrix A[%d][%d]\n ",i+1,j+1);
	scanf("%lf",&A[i][j]);
	}
     }
	/*行列bの入力*/
	for(i = 0;i < N;i++){
		printf("Input value to vector b[%d]",i+1);
		scanf("%lf",&b[i]);
		}
	
	/*ガウスザイデル関数呼び出し*/
	GaussSeidel(A,b,x,max_iter);

	for(i = 0;i < N;i++){
		printf("x[%d] = %lf\n",i,x[i]);
	}
	return 0;
   }
