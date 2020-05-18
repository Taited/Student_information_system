// Encoding: GB2312
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "student.h"
#include "const.h"
#include "file.h"

int main(void)
{
    int menuIndex = 0;
    ListHead std_info;
    // 列表初始化
    init_list(&std_info);
    load_student_from_file(&std_info);

    while (1)
    {
        show_menu();
        menuIndex = get_menu_index();
        switch (menuIndex)
        {
        case EXIT_PROGRAM:
            return 0;

        case INSERT_STUDNET:
            insert_student(&std_info);
            system("pause");
            system("cls");
            break;

        case DELETE_STUDNET:
            delete_student(&std_info);
            system("pause");
            system("cls");
            break;

        case UPDATE_STUDNET:
            update_student(&std_info);
            system("pause");
            system("cls");
            break;

        case SELECT_STUDNET:
            select_student(&std_info);
            system("pause");
            system("cls");
            break;

        case SHOW_ALL_STUDNET:
            show_all_student(&std_info);
            system("pause");
            system("cls");
            break;

        case SAVE_STUDNET:
            save_information(&std_info);
            system("pause");
            system("cls");
            break;
        }
    }

    return 0;
}
