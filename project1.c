// PROJECT : Student data management.
#include<stdio.h>
#include<string.h>
#define MAX_STUDENTS 100
typedef struct 
{
    char name[20];
    int num;
    int age;
    float marks;
}Student;
Student students[MAX_STUDENTS];
int student_count=0;
void addstudent()
{
    if(student_count<=MAX_STUDENTS)
    {
        Student s;
        printf("enter student name: \n");
        scanf("%s",&s.name);
        printf("enter roll number: \n");
        scanf("%d",&s.num);
        printf("enter age: \n");
        scanf("%d",&s.age);
        printf("enter marks :\n");
        scanf("%f",&s.marks);
        students[student_count++]=s;
        printf("added successfully");
    }
    else
    {
        printf("student database is full.");
    }
}
void display()
{
    for(int i=0;i<student_count;i++)
    {
        printf("display student name: %s\n",students[i].name);
        printf("display roll number: %d\n",students[i].num);
        printf("display age: %d\n",students[i].age);
        printf("display marks: %f\n",students[i].marks);
    }
}
void search()
{
    int rollnumber;
    printf("enter roll number: \n");
    scanf("%d",&rollnumber);
    for(int i=0;i<student_count;i++)
    {
        if(students[i].num==rollnumber)
        {
            printf("student name: %s\n",students[i].name);
            printf("roll number: %d\n",students[i].num);
            printf("age: %d\n",students[i].age);
            printf("marks: %f\n",students[i].marks);
        }
        else
        {
            printf("number not found.");
        }
    }
}
void update()
{
    int rollnumber;
    printf("enter roll number to update: ");
    scanf("%d",&rollnumber);
    for(int i=0;i<student_count;i++)
    {
        if(students[i].num==rollnumber)
        {
            printf("enter new student name: \n");
            scanf("%s",&students[i].name);
            printf("enter new roll number: \n");
            scanf("%d",students[i].num);
            printf("enter new age: \n");
            scanf("%d",students[i].age);
            printf("enter new marks :\n");
            scanf("%f",students[i].marks);
            printf("Updated successfully.");
        }
        else
        {
            printf("number not found.");
        }
        
    }
}
void delete()
{
    int rollnumber;
    printf("enter roll number: ");
    scanf("%d",&rollnumber);
    for(int i=0;i<student_count;i++)
    {
        if(students[i].num==rollnumber)
        {
            for(int j=i;j<student_count-1;j++)
            {
                students[j]=students[j+1];
                student_count--;
            }
            printf("deleted successfully.");
        }
        else
        {
            printf("number not found.");
        }
    }
}
int main()
{
    int choice;
    while(1){
    printf("1. add student\n");
    printf("2. update details\n");
    printf("3. search\n");
    printf("4. display\n");
    printf("5. delete\n");
    printf("6. exit\n");
    printf("enter choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        addstudent();
        break;
        case 2:
        update();
        break;
        case 3:
        search();
        break;
        case 4:
        display();
        break;
        case 5:
        delete();
        break;
        case 6:
        return 0;
        break;
        default:
        printf("Invalid choice.");
        break;
    }
    }
    return 0;
}