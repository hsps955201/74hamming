#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int main() {
    int m = 0;
	

    printf("輸入所想要的矩陣大小(從1開始)：");
    scanf("%d", &m);

    
    int num=0;
    int row=0;
    int vernum=0;
    
    for(int i=m;i>0;){
    	i=(i-i%2)/2;
    	vernum++;
	}
	int a[m][vernum];
	int aa[m][vernum]={0};
	int c=m-vernum;
	int data[c];

    for(int i = 0; i < m; i++) {
        for(int j = 0 ; j < vernum; j++) {
        	row=vernum-j;
        	num=i+1;
        	int p= pow(2,row);
        	if(num % p >= p/2)
				{	
					a[i][j]=1;
				}
				else
					a[i][j]=0;
        }
    }


    for(int i = 0; i < vernum; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d",a[j][i]);
        }
         printf("\n");
    }
    
    printf("\n");
 	printf("Enter %d bit data :",c);
    printf("\n");
    for(int i=0;i<c;i++)    
    scanf("%d",&data[i]);
    
    printf("\nHamming code----- Encoding\n");
    printf("\n");
    printf("\nEncoded data: ");
    
    int test[vernum];
	int tempnum=0;
	int checknum=0; 
//	for(int j=0;j<pow(2,vernum);j++){
	for(int j=0;j<m;j++){
    	for(int s=0;s<vernum;s++){
    		data[s+c]=0;
    		tempnum++;
    		int q=pow(2,s+1);
    		if(j%q>=q/2){
    			data[c+s]=1;
			}
			printf("\n");
			printf("%d",tempnum);
			printf(" ");
			printf("%d",a[0][0]);
			printf("%d",aa[0][0]);
			printf("\n");

		}
		printf("\n");
    	
		for(int k=0;k<vernum;k++){
			test[k]=0;
    	    for(int l=0;l<m;l++){
      			test[k]+=(data[l]*a[l][k]);
        		test[k]=test[k]%2;//module2
        	}
  		}
  		int testsum=0;
  		
  		for(int g=0;g<vernum;g++){
  			testsum+=test[g];
		  }
  		if(testsum==0){
  			for(int x=0;x<m;x++){
  				checknum=1;
  				printf("%d",data[x]);
			}
			break;
		}
		
	}
	if(checknum==0){
			printf("No solution!!");
			exit(1);
			
	}
	
	printf("\n");
								
									
printf("\nHamming code----- Decoding\n");
printf("\n");
printf("輸入錯誤向量:");
printf("\n");

int rdata[m]={0};
int idata[m]={0};

for(int i=0;i<m;i++){			
        
		
        scanf("%d",&rdata[i]);//輸入 
        idata[i]=data[i]+rdata[i];
		idata[i]=idata[i]%2;
               	}
    printf("\n");
    printf("所接收的資料:");
    printf("\n");    
										
 	for(int i=0;i<m;i++){
 		printf("%d",idata[i]);
 					}
 					
printf("\n");
printf("所得徵狀:");
printf("\n");

int syndrome[vernum]={0};
int jplus;
    for(int i=0;i<vernum;i++)
    {   
    	syndrome[i]=0;
    	//printf("\n");
        for(int j=0;j<m;j++){
      /* printf("%d",idata[j]);
         printf("\n");
        printf("%d",a[j][i]);
        printf("\n");
         if(a[j][i]==0)
        {
        	a[j][i]=a[j+1][i+1];
		}*/
        syndrome[i]+=idata[j]*a[j][i];
        /*printf("%d",syndrome[i]);
        printf("\n");*/
    }
        syndrome[i]=syndrome[i]%2;//module2
        /*printf("\n");
          printf("\n");*/
        printf("%d",syndrome[i]);
        //printf("\n");
    }
    for(int j=0;j<m;j++){
    	jplus=j;
    /*	printf("\n"); 
    	printf("%d",jplus); 
    	printf("\n"); */
    	int check=0;
		for(int g=0;g<vernum;g++){
			if(syndrome[g]==a[j][g]){
				check++;
				printf("%d",check);
			}
		}
		
    if (check>=vernum){
    	jplus--;
    	break;
	}
    }
    jplus++; 
	
    
    if(jplus==m)
    printf("\nNo Error \n");
    else
    {
        printf("\nError recieved at bit number %d of data\n",jplus+1
		);
        idata[jplus]=!idata[jplus];
        printf("\nCorrect data should be : ");
        for(int i=0;i<m;i++)
            printf("%d",idata[i]);
    }
    
    system("pause");
    return 0;
}
