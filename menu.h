char *encrypted1();
char *descrypted1();
char *encrypted();
char *descrypted();
void descrypted2();
void descrypted3();
char *message();
char *code();
//Declaration of all functions that are used for the task selection.
void printmenu(){ //void function does not return a value after the function executes.
    int flag=0;//declare flag as 0 for user to enter integer for menu task selection.
    printf("press 1 for rotation cipher encryption\npress 2 for rotation cipher descryption\n");
    printf("press 3 for substitution cipher encryption\npress 4 for substitution cipher descryption\n");
    printf("press 5 for rotation cipher descryption without key\n");
    printf("press 6 for substitution cipher descryption with give text only\n");
    printf("Enter number:");
    //print out all information.
    scanf("%d",&flag); //read in an integer value that the user enters on the keyboard and place that value into flag.
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
    //if user enters one of the integers, program will run the following code.
}