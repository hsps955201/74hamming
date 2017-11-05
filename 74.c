#include<stdio.h>
#include<stdlib.h>
int  data[7]; //4 
int  encoded[7],edata[7],syndrome[3],rdata[7],test[3];//8
int  hmatrix[3][7] = {
                    0,0,0,1,1,1,1,
                    0,1,1,0,0,1,1,
                    1,0,1,0,1,0,1
                    };

int main(){
    int x,i,j,k,l;
   	
    printf("Enter 4 bit data : ");
    printf("\n");
    for(i=0;i<4;i++)    
    scanf("%d",&data[i]);
    
    printf("\nHamming code----- Encoding\n");
    printf("\nEncoded data ");

    for(j=0;j<8;j++){
    	data[4]=0;
    	data[5]=0;
    	data[6]=0;
    	if(j%8>=4){
    		data[4]=1;
		}
		if(j%4>=2){
			data[5]=1;
		}
		if(j%2==1){
			data[6]=1;
		}
		for(k=0;k<3;k++){
			test[k]=0;
    	    for(l=0;l<7;l++){
      			test[k]+=(data[l]*hmatrix[k][l]);
        		test[k]=test[k]%2;//module2
        	}
  		}
  		if(test[0]+test[1]+test[2]==0){
  			for(x=0;x<7;x++){
  				printf("%d",data[x]);
			}
			break;
		}
	}
											
printf("\n");
								
									
printf("\nHamming code----- Decoding\n");
printf("輸入錯誤向量: ");
printf("\n");


for(i=0;i<7;i++){			
        
		
        scanf("%d",&rdata[i]);//輸入 
        edata[i]=data[i]+rdata[i];
		edata[i]=edata[i]%2;
               	}
    printf("\n");
    printf("所接收的資料:");
    printf("\n");    
										
 	for(i=0;i<8;i++){
 		printf("%d",edata[i]);
 					}
 					
printf("\n");
printf("所得徵狀:");
printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<7;j++)
        syndrome[i]+=(edata[j]*hmatrix[i][j]);
        syndrome[i]=syndrome[i]%2;//module2
        printf("%d",syndrome[i]);
    }
    for(j=0;j<7;j++){
	
    if((syndrome[0]==hmatrix[0][j]) && (syndrome[1]==hmatrix[1][j])&& (syndrome[2]==hmatrix[2][j]))
    break;
    }
	
    
    if(j==7)
    printf("\nNo Error \n");
    else
    {
        printf("\nError recieved at bit number %d of data\n",j+1);
        edata[j]=!edata[j];
        printf("\nCorrect data should be : ");
        for(i=0;i<7;i++)
            printf("%d",edata[i]);
    }
    return 0;
}
        
        
