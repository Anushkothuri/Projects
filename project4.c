// PROJECT : Inventory management system.
#include<stdio.h>
#include<string.h>
#define ITEMS 100
typedef struct
{
    int ID;
    char name[20];
    int quantity;
    float price;
}Store;
Store store[ITEMS];
int count=0;
void add()
{
    if(count>=ITEMS)
    {
        printf("Maximum limit reached.");
        return;
    }
    printf("enter item ID: ");
    scanf("%d",&store[count].ID);
    printf("enter item name: ");
    scanf("%s",&store[count].name);
    printf("enter item quantity: ");
    scanf("%d",&store[count].quantity);
    printf("enter price: ");
    scanf("%f",&store[count].price);
    count++;
    printf("Item Added successfully.");
}
void view()
{ 
    for(int i=0;i<count;i++)
    {
       printf("item ID: %d\n",store[i].ID);
       printf("Item name: %s\n",store[i].name);
       printf("item quantity: %d\n",store[i].quantity);
       printf("item price: %f\n",store[i].price);
    }
}
void search()
{
    int ID;
    printf("enter item ID: ");
    scanf("%d",&ID);
    for(int i=0;i<=count;i++)
    {
        if(store[i].ID==ID)
        {
            printf("item ID: %d\n",store[i].ID);
            printf("item name: %s\n",store[i].name);
            printf("item quantity: %d\n",store[i].quantity);
            printf("item price: %f\n",store[i].price);
            return;
        }
    }
    printf("invalid ID!");
}
void update()
{
    int ID,quantity;
    printf("enter item ID: ");
    scanf("%d",&ID);
    for(int i=0;i<=count;i++)
    {
        if(store[i].ID==ID)
        {
            printf("new quantity: ");
            scanf("%d",&quantity);
            store[i].quantity = quantity;
            printf("after update: %d\n",store[i].quantity);
            return;
        }
    }
    printf("invalid ID!");
}
int main()
{
    int choice;
    while(1)
    {
        printf("1. Add item.\n");
        printf("2. View all items.\n");
        printf("3. Search item by ID.\n");
        printf("4. Update item quantity.\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
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
            update();
            break;
            case 5:
            printf("Exiting the program.");
            return 0;
            break;
            default:
            printf("Invalid statement.");
            break;
        }
        
    }
    return 0;
}