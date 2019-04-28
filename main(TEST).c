/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
char *encrypted1();
char *descrypted1();
char *encrypted();
char *descrypted();
char *descrypted2();
char *descrypted3();

int main(){
    int flag=0;
    printf("press 1 for rotation cipher encryption\npress 2 for rotation cipher descryption\n");
    printf("press 3 for substitution cipher encryption\npress 4 for substitution cipher descryption\n");
    printf("press 5 for rotation cipher descryption without key\n");
    printf("press 6 for substitution cipher descryption with give text only\n");
    printf("Enter number:");
    scanf("%d",&flag);
    if(flag==1){
        printf("Encrypted message: %s", encrypted1());
    }else if(flag==2){
        printf("Descrypted message: %s", descrypted1());
    }else if(flag==3){
        printf("Encrypted message: %s", encrypted());
    }else if(flag==4){
        printf("Descrypted message: %s", descrypted());
    }else if(flag==5){
        descrypted2();
    }else if(flag==6){
        descrypted3();
    }else{
        printf("Please enter a valid number");
    }
    return 0;
}
char *encrypted1(){
    char cipher;
    static char code[1000];
    int i,key;
    printf("Message to encrypt:");
	scanf(" %[^\n]s", &code);//[^\n] is to solve the spacing problem that scanf have
	printf("Key:");
	scanf("%d", &key);
	for(i=0;code[i]!='\0';i++){ //the end of any string is marked by the ASCII value 0 is represented in C as '\0'.
		cipher = code[i];
		if(cipher >='a' && cipher <='z'){
			cipher = cipher-32;
		}
		if(cipher >='A' && cipher <='Z'){
		    cipher =cipher+key;
		        if(cipher >'Z'){
				    cipher =cipher-26;
			}
		}
		code[i]=cipher;
	}
	return code;
}

char *descrypted1(){
    static char message[1000];
    char cipher;
	int key,i;
	printf("Message to decrypt:");
	scanf(" %[^\n]s", &message);
	printf("Key:");
	scanf("%d", &key);
	for(i=0; message[i]!='\0';++i){
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
	return message;
}

char *encrypted(){
    char alpha[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char store[26];
    char STORE;
    char TEXT;
    static char text[100];
    int i,j,k;
    printf("Enter the plain text :");
    scanf(" %[^\n]s",&text);
    printf("Enter 26 capital letter:");
    scanf("%s",&store);
    for(k=0;store[i]!='\0';i++){ //the end of any string is marked by the ASCII value 0 is represented in C as '\0'.
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
    for(i=0;text[i]!='\0';i++){ //the end of any string is marked by the ASCII value 0 is represented in C as '\0'.
		TEXT = text[i];
		if(TEXT >='a' && TEXT <='z'){
			TEXT = TEXT-32;
		}
		text[i]=TEXT;
    }
    for(i=0;i<sizeof(text)/sizeof(text[0]);i++){
        for(j=0;j<sizeof(alpha)/sizeof(alpha[0]);j++){
            if(text[i]==alpha[j]){
        text[i]=store[j];
        break;
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
    static char text[100];
    int i,j,k;
    printf("Enter the cipher text :");
    scanf(" %[^\n]s",&text);
    printf("Enter 26 capital letter:");
    scanf("%s",&store);
    for(k=0;store[i]!='\0';i++){ //the end of any string is marked by the ASCII value 0 is represented in C as '\0'.
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
    for(i=0;text[i]!='\0';i++){ //the end of any string is marked by the ASCII value 0 is represented in C as '\0'.
		TEXT = text[i];
		if(TEXT >='a' && TEXT <='z'){
			TEXT = TEXT-32;
		}
		text[i]=TEXT;
    }
    for(i=0;i<sizeof(text)/sizeof(text[0]);i++){
        for(j=0;j<sizeof(alpha)/sizeof(alpha[0]);j++){
            if(text[i]==store[j]){
        text[i]=alpha[j];
        break;
        }
    }
    }
    return text;
}

char *descrypted2(){
    static char message[1000];
    char cipher;
	int key,i;
	printf("Message to decrypt:");
	scanf(" %[^\n]s", &message);
	for(key=0;key<26;key++){
	    for(i=0; message[i]!='\0';++i){
		cipher =message[i];
		if(cipher >='a' && cipher <='z'){
			cipher = cipher-32;
		}
		if(cipher >='A' && cipher <='Z'){
			cipher =cipher -key;
			if(cipher <'A'){
				cipher=cipher+26;
			}
			message[i] = cipher;
		}
	}
	printf("Decrypted message: %s\n", message);
	}
    return message;
}

char *descrypted3(){
    char chr,repl_chr;
       char string[1000];
       char STRING;
       int i;
       int c = 0, count[26] = {0}, x;
       printf("Enter a string:");
       scanf(" %[^\n]s",string);
     for(i=0;string[i]!='\0';i++){ //the end of any string is marked by the ASCII value 0 is represented in C as '\0'.
		STRING = string[i];
		if(STRING >='a' && STRING <='z'){
			STRING = STRING-32;
		}
		string[i]=STRING;
     }
       while (string[c] != '\0') {
       /** Considering characters from 'a' to 'z' only and ignoring others. */
     
          if (string[c] >= 'A' && string[c] <= 'Z') {
             x = string[c] - 'A';
             count[x]++;
          }
     
          c++;
       }
       for (c = 0; c < 26; c++){
           if(count[c]>0){
             printf("%c occurs %d times in the string.\n", c + 'A', count[c]);
           }
       }
       int yes=0;
    while(yes<=2){
    printf("Enter 1 for replacement, Enter 2 if done :");
    scanf("%d", &yes);
    if(yes==1){
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
               string[j]=BIG;
           }
           if(string[j]==chr)
           {
               string[j]=repl_chr;
           }
           
           j++; 
     }
    printf("%s\n",string);
    }else if(yes==2){
              printf("%s\n",string);
              break;
          }else{
              printf("Please enter a valid number");
          }
    }
}




