#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<string.h>


int password();

void addrecord();

void viewrecord();

void editrecord();

void editpassword();

void deleterecord();


struct record

{
    
    char time[6];
    
    char name[30];
    
    char place[25];
    
    char duration[10];
    
    char note[500];
    
} ;
int main()

{
    
    int ch;
    
    printf("\n\n\t***********************************\n");
    
    printf("\t*PASSWORD PROTECTED PERSONAL DIARY*\n");
    
    printf("\t***********************************");
    
    
    while(1)
        
        
    {
        
        printf("\n\n\t\tMAIN MENU:");
        
        printf("\n\n\tADD RECORD\t[1]");
        
        printf("\n\tVIEW RECORD\t[2]");
        
        printf("\n\tEDIT RECORD\t[3]");
        
        printf("\n\tDELETE RECORD\t[4]");
        
        printf("\n\tEDIT PASSWORD\t[5]");
        
        printf("\n\tEXIT\t\t[6]");
        
        printf("\n\n\tENTER YOUR CHOICE:");
        
        scanf("%d",&ch);
        
        
        switch(ch)
        
        {
                
            case 1:
                
                addrecord();
                
                break;
                
                
            case 2:
                
                viewrecord();
                
                break;
                
                
            case 3:
                
                editrecord();
                
                break;
                
                
            case 4:
                
                deleterecord();
                
                break;
                
                
            case 5:
                
                editpassword();
                
                break;
                
                
            case 6:
                
                printf("\n\n\t\tTHANK YOU FOR USING THE SOFTWARE ");
                
                getch();
                
                exit(0);
                
                
            default:
                
                printf("\nYOU ENTERED WRONG CHOICE..");
                
                printf("\nPRESS ANY KEY TO TRY AGAIN");
                
                getch();
                
                break;
                
        }
        
        system("cls");
        
    }
    
    return 0;
    
}

void editpassword(){
	system("cls");
	printf("\n");
	
	char pass[15]={0};
	char confirm[15]={0},ch;
	
	
	FILE *fp;
	fp=fopen("SE","wb");
	
	if(fp==NULL){
		
		
		fp=fopen("SE","wb");
		
		if(fp==NULL)
		{
			printf("SYSTEM ERROR.....");
			
			getch();
			
			return ;
		}
		
		fclose(fp);
		
		 printf("\nSYSTEM RESTORED...\nYOUR PASSWORD IS 'ENTER'\n PRESS ENTER TO CHANGE PASSWORD\n\n");
	
	     getch();
	}
	
	 fclose(fp);
	 
	 check=password();
	 
	 if(check==1){
	 	
	 	return ;
	 }
	 
	 do{
	 	
	 	if(check==0)
	 	
	 	{
	 		i=0;
	 		
	 		choice=0;
	 		
	 		printf("\n\n\tENTER THE NEW PASSWORD:");
	 		
	 		fflush(stdin);
	 		
	 		pass[0]=getch();
	 		
			 while(pass[i]!='\r'){
			 	
			 	
			 	if(pass[i]=='\b'){
			 		
			 		i--;
			 		
			 		printf("\b");
			 		
			 		printf(" ");
			 		
			 		printf("\b");
			 		
			 		pass[i]=getch();
			 		
				 }
				 
				 else
				 {
				 	
				 	printf("*");
				 	
				 	i++;
				 	
				 	pass[i]=getch();
				 }
			 }
			 
			 pass[i]='\0';
            
            i=0;
            
            printf("\n\tCONFIRM PASSWORD:");
            
            confirm[0]=getch();
            
             while(confirm[i]!='\r')
                
            {
                
                if(confirm[i]=='\b')
                    
                {
                    
                    i--;
                    
                    printf("\b");
                    
                    printf(" ");
                    
                    printf("\b");
                    
                    confirm[i]=getch();
                    
                }
                
                 
                else
                    
                {
                    
                    printf("*");
                    
                    i++;
                    
                    confirm[i]=getch();
                    
                }
                
            }
		 }
	 }
}
