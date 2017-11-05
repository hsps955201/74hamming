#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int main() {
    //int m = 0;
    //int n = 0;
    int y = 0;
    //printf("輸入二維陣列維度(m*n)：");
    //scanf("%d*%d", &m, &n);
    printf("---Hamming code---");
    printf("\n");
    printf("\n");
    printf("以下請輸入一個數字即可，從1開始，每個數字都會對應到hamming code所需的矩陣");
    printf("\n");
    printf("\n");
    printf("example:");
    printf("\n");
    printf("\n");
    printf("當y=1的時候，會產生7*3的相對應矩陣");
    printf("\n");
    printf("0001111");
    printf("\n");
    printf("0110011");
    printf("\n");
    printf("1010101");
    printf("\n");
    printf("\n");
    printf("故以此類推，y=2時會產生15*4...等");
    printf("\n");
    printf("\n");
    printf("輸入編號數字(y)：");
    scanf("%d", &y);
    int z = pow(2,2+y)-1;
    int a[z][y+2];
    int num=0;
    int row=0;
    int vernum=0;

    for(int i = 0; i < z; i++) {
        for(int j = 0 ; j < y+2; j++) {
        	row=y+2-j;
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

    for(int i = 0; i < y+2; i++) {
        for(int j = 0; j < z; j++) {
            printf("%d",a[j][i]);
        }
         printf("\n");
    }
    for(int i=z;i>0;){
    	i=(i-i%2)/2;
    	vernum++;
	}
	int c=z-vernum;
	int data[c];

 	printf("Enter %d bit data :",c);
    printf("\n");
    for(int i=0;i<c;i++)    
    scanf("%d",&data[i]);
    
    printf("\nHamming code----- Encoding\n");
    printf("\nEncoded data ");
    
    int test[vernum];
	 
	for(int j=0;j<pow(2,vernum);j++){
    	for(int i=0;i<vernum;i++){
    		data[i+c]=0;
    		int q=pow(2,i+1);
    		if(j%q>=q/2){
    			data[c+i]=1;
			}
		}
    	
		for(int k=0;k<vernum;k++){
			test[k]=0;
    	    for(int l=0;l<z;l++){
      			test[k]+=(data[l]*a[l][k]);
        		test[k]=test[k]%2;//module2
        	}
  		}
  		int testsum=0;
  		for(int g=0;g<vernum;g++){
  			testsum+=test[g];
		  }
  		if(testsum==0){
  			for(int x=0;x<z;x++){
  				printf("%d",data[x]);
			}
			break;
		}
	}
	
	
	printf("\n");
								
									
printf("\nHamming code----- Decoding\n");
printf("輸入錯誤向量:");
printf("\n");

int rdata[z]={0};
int idata[z]={0};

for(int i=0;i<z;i++){			
        
		
        scanf("%d",&rdata[i]);//輸入 
        idata[i]=data[i]+rdata[i];
		idata[i]=idata[i]%2;
               	}
    printf("\n");
    printf("所接收的資料:");
    printf("\n");    
										
 	for(int i=0;i<z;i++){
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
        for(int j=0;j<z;j++){
      //  printf("%d",idata[j]);
        syndrome[i]+=idata[j]*a[j][i];
    }
        syndrome[i]=syndrome[i]%2;//module2
        printf("%d",syndrome[i]);
    }
    for(int j=0;j<z;j++){
    	jplus=j;
    	int check=0;
		for(int g=0;g<vernum;g++){
			if(syndrome[g]==a[j][g]){
				check++;
			}
		}
    if (check>=vernum){
        jplus--;
    	break;
	}
    }
	
    jplus++;
    if(jplus==z)
    printf("\nNo Error \n");
    else
    {
        printf("\nError recieved at bit number %d of data\n",jplus+1
		);
        idata[jplus]=!idata[jplus];
        printf("\nCorrect data should be : ");
        for(int i=0;i<z ;i++)
            printf("%d",idata[i]);
    }
    system("pause");
    return 0;
}
