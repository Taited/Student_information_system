#include "student.h"
#include "file.h"

bool init_list(ListHead* pList)
{
    pList->head_node = NULL;
    pList->list_length = 0;
    return true;
}

bool load_student_from_file(ListHead* pList)
{
    FILE* file = get_file("r");
    if (file == NULL)
    {
        printf("There is something wrong with the file.\n");
        return false;
    }

    while (true)
    {
        char buf[5][MAX_LINE]; // 5表示一个学生有5行的信息
        for (int i = 0; i < 5; i++)
        {
            if (fgets(buf[i], MAX_LINE, file) != NULL)
            {
                int len = strlen(buf[i]);
                buf[i][len - 1] = '\0';  // 去掉换行字符
                //printf("%s\n", buf[i]);
            }
            else
            {
                //printf("Loading successfully!\n");
                close_file(file);
                return true;
            }
        }

        Node* p_node;
        p_node = create_node();
        strcpy(p_node->student.no, buf[0]);
        strcpy(p_node->student.name, buf[1]);
        p_node->student.gender = buf[2][0];  // 表示只读入一个字符, M/F
        p_node->student.age = atoi(buf[3]);  // 将字符串转换为数字
        strcpy(p_node->student.phone, buf[4]);
        add_node(pList, p_node);
    }

    return false;
}

bool save_information(ListHead* pList)
{
    FILE* file = get_file("w");
    if (file == NULL)
    {
        printf("There is something wrong with the file.\n");
        return false;
    }

    for (int i = 1; i <= pList->list_length; i++)
    {
        Node* tempNode = traverse_list_to_position(pList, i);
        if (tempNode == NULL)
        {
            return false;
        }
        fprintf(file, "%s\n", tempNode->student.no);
        fprintf(file, "%s\n", tempNode->student.name);
        fprintf(file, "%c\n", tempNode->student.gender);
        fprintf(file, "%d\n", tempNode->student.age);
        fprintf(file, "%s\n", tempNode->student.phone);
    }
    close_file(file);
    return true;
}

Node* create_node(void)
{
    Node* p_temp_node;
    p_temp_node = (Node*)malloc(sizeof(Node));  // 申请内存
    memset(p_temp_node, 0, sizeof(Node));// 初始化
    p_temp_node->pnext = NULL;
    return p_temp_node;
}

bool copy_to_student(Student* pstudent, Student* item)
{
    strcpy(pstudent->no, item->no);
    strcpy(pstudent->name, item->name);
    pstudent->gender = item->gender;
    pstudent->age = item->age;
    strcpy(pstudent->phone, item->phone);
    return true;
}

Student* get_input_to_student(void)
{
    Student* pstudent = NULL;
    pstudent = (Student*)malloc(sizeof(Student));
    memset(pstudent, 0, sizeof(Student));// 初始化
    printf("Please input the name of student: ");
    scanf("%s", &(pstudent->name));
    getchar();
    printf("Please input the number of student: ");
    scanf("%s", &(pstudent->no));
    printf("Please input the gender of student: ");
    scanf("%s", &(pstudent->gender));
    printf("Please input the age of student: ");
    scanf("%hd", &(pstudent->age));
    printf("Please input the phone of student: ");
    scanf("%s", &(pstudent->phone));
    return pstudent;
}

Node* traverse_list_to_position(ListHead* pList, int position)
{
    if (position < 1 || position > (pList->list_length))
    {
        printf("The position is out of range! Type again.\n");
        return NULL;
    }

    
    Node* temp = pList->head_node;
    if (temp == NULL)
    {
        printf("There is no infomation!\n");
        return NULL;
    }

    int counter = 1;
    while (counter != position)
    {
        counter += 1;
        temp = temp->pnext;
    }

    if (temp == NULL)
    {
        printf("There is something wrong with the code!\n");
        return NULL;
    }
    else
    {
        return temp;
    }
}

bool add_node(ListHead* pList, Node* item)
{
    if (pList == NULL)
    {
        printf("The information list is empty!\n");
        return false;
    }

    if (pList->list_length == 0 && pList->head_node == NULL)
    {
        pList->head_node = item;
        pList->list_length += 1;
        return true;
    }

    Node* temp = pList->head_node;
    while (temp->pnext != NULL)
    {
        temp = temp->pnext;
    }
    temp->pnext = item;
    pList->list_length += 1;
    return true;
}

void insert_student(ListHead* pList)
{
    // 将输入数据存入结构体中
    Student* pstudent = NULL;
    pstudent = get_input_to_student();  

    // 数据存入节点中
    Node* pnew = create_node();
    copy_to_student(&(pnew->student), pstudent);

    // 数据输入链表中
    add_node(pList, pnew);
    printf("\ninsert_student! \n");
}

bool delete_student(ListHead* pList)
{
    int position;
    printf("Please enter the index of the student:");
    scanf("%d", &position);
    // 对输入检查
    if (position<1 || position>pList->list_length)
    {
        printf("There is a mistake of the selected position. Try again.\n");
        return false;
    }
    
    Node* temp;
    // 特殊情况
    printf("The deleted information of student is below:\n");
    if (position == 1)
    {
        temp = pList->head_node;
        print_student(&(temp->student));
        pList->head_node = temp->pnext;
        free(temp);
    }
    else
    {
        temp = traverse_list_to_position(pList, position - 1);
        Node* deleted_node = temp->pnext;
        temp->pnext = deleted_node->pnext;
        print_student(&(deleted_node->student));
        free(deleted_node);
    }
    printf("delete_student! \n");
    return true;
}

bool update_student(ListHead* pList)
{
    int position;
    printf("Please enter the index of the student:");
    scanf("%d", &position);
    // 对输入进行检查
    if (position <1 || position >pList->list_length)
    {
        printf("There is a mistake in the selected position. Try again.\n");
        return false;
    }

    // 得到待修改的节点
    Node* temp;
    if (position == 1)
    {
        temp = pList->head_node;
    }
    else
    {
        temp = traverse_list_to_position(pList, position);
    }

    // 将输入数据存入结构体中
    Student* pstudent = NULL;
    pstudent = get_input_to_student();

    // 数据存入节点中
    copy_to_student(&(temp->student), pstudent);

    // 打印
    print_student(&(temp->student));
    printf("update_student! \n");
    return true;
}

Node* select_student(ListHead* pList)
{
    int position;
    printf("Please enter the index of the student:");
    scanf("%d", &position);
    // 对输入进行检查
    if (position <1 || position >pList->list_length)
    {
        printf("There is a mistake in the selected position. Try again.\n");
        return NULL;
    }
    //
    Node* temp;
    if (position == 1)
    {
        temp = pList->head_node;
    }
    else
    {
        temp = traverse_list_to_position(pList, position);
    }
    if (temp != NULL)
    {
        printf("The selected student information is :\n");
        print_student(&(temp->student));
    }
    return temp;
}

bool show_all_student(ListHead* pList)
{
    Node* p_temp = pList->head_node;
    if (p_temp == NULL)
    {
        printf("There is no student infomation on the database!\n");
        return false;
    }
    int counter = 0;
    printf("\n");
    while (p_temp != NULL)
    {
        Student student = p_temp->student;
        print_student(&student);
        counter += 1;
        printf("The student index is: %d\n", counter);
        p_temp = p_temp->pnext;
    }
    printf("\n");
    return true;
}

void print_student(Student* student)
{
    printf("--------------------\n");
    printf("no: %s\n", student->no);
    printf("name: %s\n", student->name);
    printf("gender: %c\n", student->gender);
    printf("age: %d\n", student->age);
    printf("phone: %s\n", student->phone);
}
