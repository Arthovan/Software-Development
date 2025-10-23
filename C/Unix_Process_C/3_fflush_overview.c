/*  fflush is a function which will allow us to clear output stream and some compiler 
    allows to clear the input stream as well

    Note : if this below code doesnt work then the compiler doesnt support the input clearing of the buffer
*/
#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    char ch;
    /*-------------- Error code ---------------- */
   printf("Enter the number :");
    scanf("%d",&num);
    printf("Enter the character: ");    
    //  During execution of this program when we type int in the command, then the above scanf only reads the integer value but stdin buffer still has "\n", this "\n" is considered as 
    //    input for this scanf. To avoid that we need to clear the stdin buffer before the next scanf(), so we can use the fflsuh function here
    scanf("%c",&ch);

    printf("Entered number : %d\n",num);
    printf("Entered character : %c\n",ch);

    /*-------------- Correct code ---------------- */
    printf("Enter the number :");
    scanf("%d",&num);
    printf("Enter the character: ");    
    fflush(stdin);  //   cleared the input stream buffer (stdin)
    scanf("%c",&ch);

    printf("Entered number : %d\n",num);
    printf("Entered character : %c\n",ch);

    return 0;
}
