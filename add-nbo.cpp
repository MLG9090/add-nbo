#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){

    FILE* fp;
    int32_t num1;
    int32_t num2;
    int32_t sum;
    
    fp = fopen(argv[1],"rb");
    fread(&num1,sizeof(num1),1,fp);
    num1 = htonl(num1);

    fp = fopen(argv[2],"rb");
    fread(&num2,sizeof(num2),1,fp);
    num2 = htonl(num2);

    sum = num1 + num2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",num1,num1,num2,num2,sum,sum);
    fclose(fp);

    return 0;
}
