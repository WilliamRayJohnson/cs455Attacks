/* vul_prog.c */

#include<stdio.h>
#include<stdlib.h>

#define SECRET1 0x44
#define SECRET2 0x55

int main(int argc, char *argv[])
{
    char user_input[100];
    int *secret;
    int a, b, c, d; /* other variables, not used here.*/
    
    /*
     * If the address of secret[1] contains following special characters, 0x0A (newline),
     * 0x0C (form feed), 0x0D(return), or 0x20 (space), please uncomment
     * the following two lines of code, re-compile and
     * make it a set-uid program. Please make sure the address does not
     * contain any special characters. Then we are ready to go.
     */
    
    //int *dummy;
    //dummy = (int *) malloc(2*sizeof(int));


    /* The secret value is stored on the heap */
    secret = (int *) malloc(2*sizeof(int));
    
    /* getting the secret */
    secret[0] = SECRET1; secret[1] = SECRET2;
    
    printf("The variable secret's address is 0x%8x (on stack)\n", (unsigned int)&secret);
    printf("The variable secret's value is 0x%8x (on heap)\n", (unsigned int)secret);
    printf("secret[0]'s address is 0x%8x (on heap)\n", (unsigned int)&secret[0]);
    printf("secret[1]'s address is 0x%8x (on heap)\n", (unsigned int)&secret[1]);

    printf("Please enter a string\n");
    scanf("%s", user_input); /* getting a string from user */
    
    /* Vulnerable place */
    printf(user_input);
    printf("\n");
    
    /* Verify whether your attack is successful */
    printf("The original secrets: 0x%x -- 0x%x\n", SECRET1, SECRET2);
    printf("The new secrets:      0x%x -- 0x%x\n", secret[0], secret[1]);
    return 0;
}
