// PROJECT : Library management system.
#include<stdio.h>
#include<string.h>
#define MAX_BOOKS 100
typedef struct
{
    int Book_ID;
    char book_name[20];
    char author[20];
    int IsBorrowed;
}Library;
Library Book[MAX_BOOKS];
int count=0;
void add()
{
    if(count>=MAX_BOOKS)
    {
        printf("Maximum limit reached");
        return;
    }
    int ID;
    char book_name[20];
    char author[20];
    printf("enter book ID: ");
    scanf("%d",&Book[count].Book_ID);
    printf("enter book name: ");
    scanf("%s",&Book[count].book_name);
    printf("enter author name: ");
    scanf("%s",&Book[count].author);
    count++;
    printf("Added Successfully.\n");
}
void view()
{
    int i;
    for(i=0;i<count;i++)
    {
        printf("book name: %s\n book ID: %d\n book author: %s\n",Book[i].book_name,
        Book[i].Book_ID,Book[i].author);
    }
}
void search()
{
    int ID;
    printf("enter book ID: ");
    scanf("%d",&ID);
    for(int i=0;i<=count;i++)
    {
        if(Book[i].Book_ID==ID)
        {
            printf("Book ID: %d\n",Book[i].Book_ID);
            printf("Book name: %s\n",Book[i].book_name);
            printf("Book author: %s\n",Book[i].author);
            return;
        }
    }
    printf("Invalid ID!\n");
}
void borrow()
{
    int ID,i;
    printf("enter ID: ");
    scanf("%d",&ID);
    for(i=0;i<=count;i++)
    {
        if(Book[i].Book_ID==ID)
        {
            if(!Book[i].IsBorrowed)
            {
                Book[i].IsBorrowed=1;
                printf("book is borrowed successfully.\n");
            }
            else
            {
                printf("book is already borrowed.\n");
            }
        }
        return;
        printf("Invalid ID.\n");
    }
}
void returned()
{
    int ID;
    printf("enter ID: ");
    scanf("%d",&ID);
    for(int i=0;i<=count;i++)
    {
        if(Book[i].Book_ID==ID)
        {
            if(Book[i].IsBorrowed)
            {
                Book[i].IsBorrowed=0;
                printf("Returned successfully.\n");
            }
            else
            {
                printf("Already returned.\n");
            }
        }
        return;
        printf("Invalid ID!\n");
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("1. Add Book.\n");
        printf("2. View all Book.\n");
        printf("3. Search Book.\n");
        printf("4. Is Borrowed?\n");
        printf("5. Returned?\n");
        printf("6. Exit.\n");
        printf("enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            add();
            break;
            case 2:
            view();
            break;
            case 3:
            search();
            break;
            case 4:
            borrow();
            break;
            case 5:
            returned();
            break;
            case 6:
            printf("Exiting the program.");
            return 0;
            break;
            default:
            printf("Invalid Choice!");
        }
    }
    return 0;
}