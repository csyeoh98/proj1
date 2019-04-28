#include <stdio.h>
#include "menu.h"// Task selection with a ﬁle header.

int main(){
    printmenu();//call out file header task selection function.
    return 0;
}

char *encrypted1(){ //* is used to denote that “encrypted1()” is pointer variable and not a normal variable.
    char cipher;//declare an empty character variable to store characters.
    int i,key;//declare i and key as integer to use in function
    static char code[1000];//A static int variable remains in memory while the program is running.
    strcpy(code,message());// copies the string pointed to, by message() to code.
	printf("Key:");
	scanf("%d", &key);//read in an integer value that the user enters on the keyboard and place that value into key.
	for(i=0;code[i]!='\0';i++){ //the end of any string is marked by the ASCII value 0 is represented in C as '\0'.
		cipher = code[i];//Store each string elements into cipher for further steps.
		if(cipher >='a' && cipher <='z'){
			cipher = cipher-32;//Changing every lowercase letter to uppercase letter.
		}
		if(cipher >='A' && cipher <='Z'){
		    cipher =cipher+key;//encrypting by adding the letter with key.
		        if(cipher >'Z'){
				    cipher =cipher-26;//If the letter after adding key drop out of word 'Z', this code leads it back to word 'A'
			}
		}
		code[i]=cipher;//returning all letters back to string.
	}
	return code;// return all the string elements.
}

char *descrypted1(){
    static char message[1000];
    char cipher;
	int key,i;
	strcpy(message,code());
	printf("Key:");
	scanf("%d", &key);
	for(i=0; message[i]!='\0';++i){
		cipher =message[i];
		if(cipher >='a' && cipher <='z'){
			cipher = cipher-32;
		}
		if(cipher >='A' && cipher <='Z'){
			cipher =cipher -key;//decrypting by minus the cipher by key.
			if(cipher <'A'){
				cipher=cipher+26;//If the letter after minus key drop out of 'A',this code leads it back to word 'Z'
			}
		}
	message[i] = cipher;
	}
	return message;
}

char *encrypted(){
    char alpha[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    //create an initial normal alphabet row as old alphabet.
    char store[26];// create an array for 26 elements to store the new alphabetes.
    char STORE;
    char TEXT;
    static char text[1000];
    int i,j;
    strcpy(text,message());
    printf("Enter 26 capital letter:");
    scanf("%s",&store);
    for(i=0;store[i]!='\0';i++){ 
		STORE = store[i];
		if(STORE >='a' && STORE <='z'){
			STORE = STORE-32;
		}
		store[i]=STORE;
    }
    printf("\ncharacter replace\n");
    printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    printf("||||||||||||||||||||||||||\n");
    printf("%s\n",store);//store the new alphabets that are going to substitute the old ones.
    for(i=0;text[i]!='\0';i++){ 
		TEXT = text[i];
		if(TEXT >='a' && TEXT <='z'){
			TEXT = TEXT-32;
		}
		text[i]=TEXT;
    }
    for(i=0;i<strlen(text);i++){//within each and every text.
        for(j=0;j<strlen(alpha);j++){//and within each and every normal alphabet
            if(text[i]==alpha[j]){//when the text meets the old normal alphabet, it will then replaced by the new substitue alphabet.
        text[i]=store[j];
        break;//The break statement terminates the loop.
        }
    }
    }
    return text;
}

char *descrypted(){
    char alpha[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char store[26];
    char STORE;
    char TEXT;
    static char text[1000];
    int i,j;
    strcpy(text,code());
    printf("Enter 26 capital letter:");
    scanf("%s",&store);
    for(i=0;store[i]!='\0';i++){ 
		STORE = store[i];
		if(STORE >='a' && STORE <='z'){
			STORE = STORE-32;
		}
		store[i]=STORE;
    }
    printf("\ncharacter replace\n");
    printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    printf("||||||||||||||||||||||||||\n");
    printf("%s\n",store);
    for(i=0;text[i]!='\0';i++){ 
		TEXT = text[i];
		if(TEXT >='a' && TEXT <='z'){
			TEXT = TEXT-32;
		}
		text[i]=TEXT;
    }
    for(i=0;i<strlen(text);i++){
        for(j=0;j<strlen(alpha);j++){
            if(text[i]==store[j]){//If the text meets the new substitue alphabet, it will then replaced by the old alphabet.
        text[i]=alpha[j];
        break;
        }
    }
    }
    return text;
}

void descrypted2(){
    char message[100];
    char test[100];
    char cipher;
	int key,i;
	strcpy(test,code());
	for(key=0;key<26;key++){//To test the result of every different key.
	    strcpy(message,test);//To use the initial message for further steps in this loop.
	    for(i=0; message[i]!='\0';i++){
		cipher =message[i];
		if(cipher >='a' && cipher <='z'){
			cipher = cipher-32;
		}
		if(cipher >='A' && cipher <='Z'){
			cipher =cipher -key;
			if(cipher <'A'){
				cipher=cipher+26;
			}
		}
	message[i] = cipher;
	}
	printf("Key %d and decrypted message: %s\n",key, message);
	}
	char MESSAGE[1000];
    char CIPHER;
	int KEY,j;
	printf("Enter the correct key:");
	scanf(" %d", &KEY);//Enter the correct rotation amount based on the previous result
	printf("Message:");
	scanf(" %[^\n]", &MESSAGE);
	for(j=0; MESSAGE[j]!='\0';j++){
		CIPHER =MESSAGE[j];
		if(CIPHER >='a' && CIPHER <='z'){
			CIPHER = CIPHER-32;
		}
		if(CIPHER >='A' && CIPHER <='Z'){
			CIPHER =CIPHER -KEY;
			if(CIPHER <'A'){
				CIPHER=CIPHER+26;
			}
		}
	MESSAGE[j] = CIPHER;
	}
	printf("\nMessage is %s",MESSAGE);//print out the final correct encrypted message.
    return ;
}

void descrypted3(){
    char chr,repl_chr;
    char string[1000];
    char STRING;
    int i;
    int c = 0, count[26] = {0}, x;
    strcpy(string,code());
    for(i=0;string[i]!='\0';i++){ 
		STRING = string[i];
		if(STRING >='a' && STRING <='z'){
			STRING = STRING-32;
		}
		string[i]=STRING;
     }
       while (string[c] != '\0') {
          if (string[c] >= 'A' && string[c] <= 'Z') {
             x = string[c] - 'A';//x will be the ASCII value of the alphabet
             count[x]++;// count the frequency of the same repeated alphabet.
          }
          c++;//next alphabet
       }
       for (c = 0; c < 26; c++){
           if(count[c]>0){
             printf("%c occurs %d times in the string.\n", c + 'A', count[c]);// count only letter that are entered.
           }
       }
    int work=0;//create an initial integer for user to enter number for task selection.
    while(work<=2){
    printf("Enter 1 for replacement, Enter 2 if done :");
    scanf("%d", &work);
    if(work==1){
    printf("\nEnter character to be replaced: ");
    scanf(" %s", &chr);
    printf("\nEnter replacement character: ");
    scanf(" %s", &repl_chr);
    int j=0;
    char BIG;
    while(string[j]!='\0')
     {
         if(string[j]==repl_chr){
               BIG=string[j];
               BIG = BIG +32;
               string[j]=BIG;// To seperate the same alphabet before and after changing.
           }
           if(string[j]==chr)
           {
               string[j]=repl_chr;//replace the old alphabet with new alphabet
           }
           j++; // Do the same thing to all the same alphabet.
     }
    printf("%s\n",string);
    }else if(work==2){
              printf("MESSAGE :%s\n",string);
              break;
          }else{
              printf("Please enter a valid number");
          }
    }
}

char *message() //declaring a string is going to be returned by this function.(encryption)
{
   FILE *fptr;//to declare a pointer of type file. 
    char static code[1000];//declare a string to store message.
    fptr = fopen("C:\\message.txt","w");//fopen() function is to create a new file or to open an existing file. 
   printf("Message to encrypt: ");
   scanf(" %[^\n]s",&code);
   fprintf(fptr,"%s",code);
   fscanf(fptr,"%[^\n]s", &code);
   //This program takes a string from user and stores in the file message.txt.
   //For reading and writing to a text file, we use the functions fprintf() and fscanf().
   return code;//return the message that are written to the file and read.
}

char *code(){//declaring a string is going to be returned by this function.(decryption)
    FILE *fptr;
    char static message[1000];
    fptr = fopen("C:\\code.txt","w");
   printf("Message to decrypt: ");
   scanf(" %[^\n]s",&message);
   fprintf(fptr,"%s",message);
   fscanf(fptr,"%[^\n]s", &message);
   return message;
}
