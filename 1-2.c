#include <string.h>
#include <stdio.h>

typedef struct student {
    char name[8];
    short age;
    float score;
    char remark[200];
} student;

// 将 old_s[3] 中的所有信息依次紧凑存放到 一个字符数组中，
// 然后从 message 转换到结构数组 new_s[3]中。
// 打印压缩前、解压后的结果，以及压缩前、压缩后存放数据的长度。
student old_s[3];    // old_s[0].name 为自己的姓名;
student new_s[3];

// s为结构数组的起始地址；
// sno 为学生人数；
// buf 为压缩区域存储区的首地址;
// 返回压缩后的字节数。
int pack_student_bytebybyte(student *s, int sno, char *buf) {
    char *p = buf;
    for (int i = 0; i < sno; i++) {
        int k = 0;
        while (s[i].name[k] != '\0') {
            *(p + k) = s[i].name[k];
            k++;
        }
        *(p + k) = '\0';
        p += k + 1;
        for (int j = 0; j < sizeof(s->age); ++j) {
            *(p + j) = *((char *) &(s[i].age) + j);
        }
        p += sizeof(s->age);
        for (int j = 0; j < sizeof(s->score); ++j) {
            *(p + j) = *((char *) &(s[i].score) + j);
        }
        p += sizeof(s->score);
        k = 0;
        while (s[i].remark[k] != '\0') {
            *(p + k) = s[i].remark[k];
            k++;
        }
        *(p + k) = '\0';
        p += k + 1;
    }
    return p - buf;
}

int pack_student_whole(student *s, int sno, char *buf) {
    char *p = buf;
    for (int i = 0; i < sno; i++) {
        strcpy(p, s[i].name);
        p += strlen(s[i].name) + 1; // 需要加上结尾的 '\0'
        memcpy(p, &s[i].age, sizeof(s->age));
        p += 2;
        memcpy(p, &s[i].score, sizeof(s->score));
        p += 4;
        memcpy(p, s[i].remark, sizeof(s->remark));
        p += strlen(s[i].remark) + 1;
    }
    return p - buf;
}


// buf 为压缩区域存储区的首地址;
// len为buf中存放数据的长度；
// s为存放解压数据的结构数组的起始地址；
// 返回解压的人数。
int restore_student(char *buf, int len, student *s) {
    char *p = buf;
    int cnt_student = 0;
    while (p - buf < len) {
        int j = 0;
        while (*(p + j) != '\0') {
            s[cnt_student].name[j] = *(p + j);
            ++j;
        }
        s[cnt_student].name[j] = '\0';
        p += j + 1;
        memcpy(&s[cnt_student].age, p, 2);
        p += 2;
        memcpy(&s[cnt_student].score, p, 4);
        p += 4;
        j = 0;
        while (*(p + j) != '\0') {
            s[cnt_student].remark[j] = *(p + j);
            ++j;
        }
        s[cnt_student].remark[j] = '\0';
        p += j + 1;
        cnt_student++;
    }
    return cnt_student;
}

int show(student *s, int sno) {
    for (int i = 0; i < sno; i++) {
        printf("{%s, %d, %f, %s}\n", s[i].name, s[i].age, s[i].score, s[i].remark);
    }
    return 0;
}

// 在两个函数中，除了使用参数提供的信息外，不准使用其他的外部信。
// pack_student_bytebybyte要求一个字节一个字节的向buf中写数据；
// pack_student_whole要求对short、float字段都只能用一条语句整体写入，用strcpy实现串的写入。
// 第一个记录压缩（即old_s[0]）要调用pack_student_bytebybyte；
// 第2-3个记录压缩要调用pack_student_whole。

int main() {
    student a = {"zhangsa", 20, 99.9, "good"};
    old_s[0] = a;
    student b = {"lisi", 21, 88.8, "bad"};
    old_s[1] = b;
    student c = {"wangwu", 22, 77.7, "middle"};
    old_s[2] = c;

    // 压缩
    char buf[1024];
    printf("压缩前的长度：%lu\n", sizeof(old_s));
    int len1 = pack_student_bytebybyte(old_s, 1, buf);     // byte压缩
    int len2 = pack_student_whole(old_s + 1, 2, buf + len1);  // whole压缩
    printf("压缩后的长度: %d\n", len1 + len2);
    printf("\n");
    // 解压
    printf("压缩前的数据：\n");
    show(old_s, 3);
    int cnt =  restore_student(buf, len1+len2, new_s);
    printf("解压后的数据：\n");
    printf("学生数：%d\n",cnt);
    show(new_s, 3);

    return 0;
}