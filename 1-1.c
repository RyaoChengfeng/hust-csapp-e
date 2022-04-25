#include <stdio.h>
void int_representation() {
    int x = -65539;   // 65539 = 65536+3;
    unsigned int y = 0xFFFEFFFD;

//  以16进制的形式，从低字节到高字节，写出x,y 对应单元中的内容
//  x : FD FF FE FF
//  y : FD FF FE FF
//  内存观察结果：
    printf("16进制 %x %x ; 十进制： %d %d\n", x, y, x, y);
    printf("有符号数 %d ; 无符号数 %u \n", x, y);
    printf("无符号数 %u ; 有符号数 %d \n", x, y);

//  请解释看到的显示结果的原因
//  x和y在内存中的存储方式是不同的，x是有符号数，x中的最高位是符号位，用1表示负。y是无符号数，字长的全部二进制位均表示数值位

    return;
}


void short_representation() {
    short x = -32767;
    unsigned short y = 32769;
//  以16进制的形式，从低字节到高字节，写出x,y 对应单元中的内容
//  x : 01 80
//  y : 01 80
//  内存观察结果：
    printf("16进制 %08x %08x ; 十进制： %d %d\n", x, y, x, y);
    printf("有符号数 %d ; 无符号数 %u \n", x, y);
    printf("无符号数 %hu ; 有符号数 %hd \n", x, y);
//  请解释看到的显示结果的原因:
// 同上，x是有符号数，y是无符号数

//  注，对于整数类型，传递的是 4个字节的数据, 与格式串中的写法无关 

//  即使 用 %hu  %hd 来控制显示short 类型的数据，也是传 4个字节的数据 

//  请观察 printf 语句对应的反汇编代码 

//  请解释为什么要约定传 对整型变量要传 4个字节的数据？
// 32位寄存器的大小为4字节，方便处理4个字节的数据

    return;

}


void float_representation() {
    float x = 12.625;
    double y = 12.625;

//  以16进制的形式，从低字节到高字节，写出x,y 对应单元中的内容
//  x : 00 00 4A 41
//  y : 00 00 00 00 00 40 29 40

//  内存观察结果：
    return;
}


void string_representation() {
    char str[16] = "hello, 12345!";

// 请反汇编，看是如何给 str 数组赋值的？ 
//    (gdb) disassemble
//    Dump of assembler code for function string_representation:
//    0x0000555555555276 <+0>:	endbr64
//    0x000055555555527a <+4>:	push   %rbp
//    0x000055555555527b <+5>:	mov    %rsp,%rbp
//    0x000055555555527e <+8>:	sub    $0x20,%rsp
//    0x0000555555555282 <+12>:	mov    %fs:0x28,%rax
//    0x000055555555528b <+21>:	mov    %rax,-0x8(%rbp)
//    0x000055555555528f <+25>:	xor    %eax,%eax
//    0x0000555555555291 <+27>:	movabs $0x31202c6f6c6c6568,%rax
//    0x000055555555529b <+37>:	movabs $0x2135343332,%rdx
//    0x00005555555552a5 <+47>:	mov    %rax,-0x20(%rbp)
//    0x00005555555552a9 <+51>:	mov    %rdx,-0x18(%rbp)
//    => 0x00005555555552ad <+55>:	nop
//    0x00005555555552ae <+56>:	mov    -0x8(%rbp),%rax
//    0x00005555555552b2 <+60>:	xor    %fs:0x28,%rax
//    0x00005555555552bb <+69>:	je     0x5555555552c2 <string_representation+76>
//                                        0x00005555555552bd <+71>:	call   0x555555555060 <__stack_chk_fail@plt>
//                                                                                                             0x00005555555552c2 <+76>:	leave
//    0x00005555555552c3 <+77>:	ret
//    End of assembler dump.

// "hello, 12345!" 存放在何处？观察内存中的存放形式

//    (gdb) x /15xd str
//    0x7fffffffe150:	104	101	108	108	111	44	32	49
//    0x7fffffffe158:	50	51	52	53	33	0	0

    return;
}


int main(int argc, char *argv[]) {
    int_representation();
    short_representation();
    float_representation();
    string_representation();
    return 0;
}