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

  int password()

{
    
    char pass[15]={0},check[15]={0},ch;
    
    FILE *fpp;
    
    int i=0,j;
    
    printf("::FOR SECURITY PURPOSE::");
    
    printf("::ONLY THREE TRIALS ARE ALLOWED::");
    
    for(j=0;j<3;j++)
        
    {
        
        i=0;
        
        printf("\n\n\tENTER THE PASSWORD:");
        
        pass[0]=getch();
        
        while(pass[i]!='\r')
            
        {
            
            if(pass[i]=='\b')
                
            {
                
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
        
        fpp=fopen("SE","r");
        
        if (fpp==NULL)
            
        {
            
            printf("\nERROR WITH THE SYSTEM FILE...[FILE MISSING]\n");
            
            getch();
            
            return 1;
            
        }
        
        else
            
            i=0;
        
        while(1)
            
        {
            
            ch=fgetc(fpp);
            
            if(ch==EOF)
                
            {
                
                check[i]='\0';
                
                break;
                
            }
            
            check[i]=ch-5;
            
            i++;
            
        }
        
        if(strcmp(pass,check)==0)
            
        {
            
            printf("\n\n\tACCESS GRANTED...\n");
            
            return 0;
            
        }
        
        else
            
        {
            
            printf("\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n");
            
        }
        
    }
    
    printf("\n\n\t::YOU ENTERED WRONG PASSWORD::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\tPRESS ANY KEY TO GO BACK...");
    
    getch();
    
    return 1;
    
}


void editpassword(){
	system("cls");
	printf("\n");
	
	char pass[15]={0};
	char confirm[15]={0};
	char ch;
	
	
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
            
            
            confirm[i]='\0';
            
            if(strcmp(pass,confirm)==0)
                
            {
                
                fp=fopen("SE","wb");
                
                if(fp==NULL)
                    
                {
                    
                    printf("\n\t\tSYSTEM ERROR");
                    
                    getch();
                    
                    return ;
                    
                }
                
                i=0;
                
                while(pass[i]!='\0')
                    
                {
                    
                    ch=pass[i];
                    
                    putc(ch+5,fp);
                    
                    i++;
                    
                }
                
                    putc(EOF,fp);
                
                fclose(fp);
                
            }
            
            else
                
            {
                
                printf("\n\tTHE NEW PASSWORD DOES NOT MATCH.");
                
                choice=1;
                
                
            }
            
            
        }
        
    }while(choice==1);
    
    
      
    printf("\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...");
    
    getch();
    
}


void deleterecords()
{
	
	system("cls");
	
	FILE *fp,*fptr;
	
	struct record file ;
    
    char filename[15],another = 'Y' ,time[10];;
    
    int choice,check;
    
    printf("\n\n\t\t*************************\n");
    
    printf("\t\t* WELCOME TO DELETE MENU*");
    
    printf("\n\t\t*************************\n\n");
    
    check = password();
    
    if(check==1)
        
    {
        
        return ;
        
    }
    
    
    while ( another == 'Y' )
        
    {
        
        printf("\n\tHOW WOULD YOU LIKE TO DELETE.");
        
        printf("\n\t#DELETE WHOLE RECORD\t\t\t[1]");
        
        printf("\n\t#DELETE A PARTICULAR RECORD BY TIME\t[2]");
        
        do
            
        {
            
            printf("\n\t\tENTER YOU CHOICE:");
            
            scanf("%d",&choice);
            
            
       switch(choice)
           
      {
                   
	    case 1:
                    
                    printf("\n\tENTER THE DATE OF RECORD TO BE DELETED:[yyyy-mm-dd]:");
                    
                    fflush(stdin);
                    
                    gets(filename);
                    
                    fp = fopen (filename, "wb" ) ;
                    
                    if ( fp == NULL )
                        
                    {
                        
                        printf("\nTHE FILE DOES NOT EXISTS");
                        
                        printf("\nPRESS ANY KEY TO GO BACK.");
                       
                          getch();
                        
                        return ;
                        
                    }
                    
                    fclose(fp);
                    
                    remove(filename);
                    
                    printf("\nDELETED SUCCESFULLY...");
                    
                    break;
                    
                       case 2:
                    
                    printf("\n\tENTER THE DATE OF RECORD:[yyyy-mm-dd]:");
                    
                    fflush(stdin);
                    
                    gets(filename);
                    
                    fp = fopen (filename, "rb" ) ;
                    
                    if ( fp == NULL )
                        
                    {
                        
                        printf("\nTHE FILE DOES NOT EXISTS");
                        
                        printf("\nPRESS ANY KEY TO GO BACK.");
                        
                        getch();
                        
                        return ;
                        
                    }
                    
                    fptr=fopen("temp","wb");
                    
                    if(fptr==NULL)
                        
                    {
                        
                        printf("\nSYSTEM ERROR");
                        
                        printf("\nPRESS ANY KEY TO GO BACK");
                        
                        getch();
                        
                        return ;
                        
                    }
                    
                    printf("\n\tENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:");
                    
                    fflush(stdin);
                    
                    gets(time);
                    
                    while(fread(&file,sizeof(file),1,fp)==1)
                        
                    {
                        
                        if(strcmp(file.time,time)!=0)
                            
                            fwrite(&file,sizeof(file),1,fptr);
                        
                    }
                    
                    
                    fclose(fp);
                    
                    fclose(fptr);
                    
                    remove(filename);
                    
                    rename("temp",filename);
                    
                    printf("\nDELETED SUCCESFULLY...");
                    
                    break;
                    
                      default:
                    
                    printf("\n\tYOU ENTERED WRONG CHOICE");
                    
                    break;
                    
            }
            
        }while(choice<1||choice>2);
        
        
        
        printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
        
        fflush(stdin);
        
        scanf("%c",&another);
        
    }
    
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    
    getch();


}		

