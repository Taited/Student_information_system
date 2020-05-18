#include"menu.h"

void show_menu(void)
{
    printf("/**************************************************/ \n");
    printf("       0. Exit\n");
    printf("       1. Insert student info\n");
    printf("       2. Delete student info\n");
    printf("       3. Update student info\n");
    printf("       4. Select student info\n");
    printf("       5. Print  student info\n");
    printf("       6. Save   changes\n");
    printf("/**************************************************/ \n");
}

int  get_menu_index(void)
{
    int index;
    printf("Please input menu index: ");
    scanf("%d", &index);
    printf("\n");
    return index;
}
