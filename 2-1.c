#include <stdio.h>
void int_representation()
{
    int  x = -65539;   // 65539 = 65536+3;
    unsigned int  y = 0xFFFEFFFD;
    //  以16进制的形式，从低字节到高字节，写出x,y 对应单元中的内容
    //  x :
    //  y :
    //  内存观察结果：
    printf("16进制 %x %x ; 十进制： %d %d\n", x, y,x,y);
    printf("有符号数 %d ; 无符号数 %u \n", x, y);
    printf("无符号数 %u ; 有符号数 %d \n", x, y);
    //  请解释看到的显示结果的原因
    return;
}

void short_representation()
{
    short  x = -32767;
    unsigned short  y = 32769;
    //  以16进制的形式，从低字节到高字节，写出x,y 对应单元中的内容
    //  x :
    //  y :
    //  内存观察结果：
    printf("16进制 %08x %08x ; 十进制： %d %d\n", x, y, x, y );
    printf("有符号数 %d ; 无符号数 %u \n", x, y);
    printf("无符号数 %hu ; 有符号数 %hd \n", x, y);
    //  请解释看到的显示结果的原因:
    //  注，对于整数类型，传递的是 4个字节的数据, 与格式串中的写法无关
    //  即使 用 %hu  %hd 来控制显示short 类型的数据，也是传 4个字节的数据
    //  请观察 printf 语句对应的反汇编代码
    //  请解释为什么要约定传 对整型变量要传 4个字节的数据？

    return;
}

void float_representation()
{
    float  x = 12.625;
    double y = 12.625;
    //  以16进制的形式，从低字节到高字节，写出x,y 对应单元中的内容
    //  x :
    //  y :
    //  内存观察结果：
    return;
}

void  string_representation()
{
    char str[16] = "hello, 12345!";
    // 请反汇编，看是如何给 str 数组赋值的？
    // "hello, 12345!" 存放在何处？观察内存中的存放形式
    return;
}

int main(int argc, char* argv[])
{
    int_representation();
    short_representation();
    float_representation();
    string_representation();
    return 0;
}
