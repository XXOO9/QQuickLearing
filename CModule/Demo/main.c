#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long int offset;
    unsigned char code[2] = {0};
    unsigned char buffer[32];       //存储一个汉字所用的32个字节
    unsigned char i,j;
    FILE *fp = NULL;

    puts("请输入一个汉字:");
    gets((char*)code);
    printf("区码:%d 位码:%d\n", code[0], code[1]);      //显示区位码
    offset = ((code[0] - 0xa1) * 94 + code[1] - 0xa1) * 32;     //计算绝对偏移地址
    printf("偏移值为: %ld\n", offset);

    fp = fopen("./hzk16.dat", "rb");  //二进制只读方式打开,261KB
    if (fp == NULL )                //如果打开失败
    {
        printf("打开字库失败\n");
        return 0;
    }

    fseek(fp,offset,0);             //根据偏移寻找到该字字模的第一个字节
    for (i = 0; i < 32; ++i) {       //连续读取32个字节
        buffer[i] = fgetc(fp);
    }

    for (i = 0; i < 32; ++i) {       //将32个字节顺序打印
        for (j = 0; j < 8; ++j) {
            if (buffer[i] & 0x80) {
                printf("@@");
            }else{
                printf("  ");
            }
            buffer[i] <<= 1;
        }
        if (i % 2) {
            printf("\n");           //如果i%2==1说明该字节是靠后的那个字节，显示完后要换行
        }
    }

    return EXIT_SUCCESS;
}
