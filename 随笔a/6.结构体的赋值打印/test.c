#include<stdio.h>
struct Student
{
    char name[20];
    char subject[20];
    int score;
};
int main()
{
    struct Student s={"陈彤","Linux课程设计",100};
    printf("%s %s %d\n",s.name,s.subject,s.score);
    return 0;
}
