#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "const.h"

typedef struct
{
    char  no[STUDENT_NO_LEN];
    char  name[STUDENT_NAME_LEN];
    char  gender;
    short age;
    char  phone[STUDENT_PHONE_LEN];
}Student;

typedef struct node
{
    Student student;    // 数据域
    struct node* pnext; // 指针域
}Node;

typedef struct
{
    int list_length;    //链表元素个数
    Node* head_node;    //头结点
}ListHead;

Node* create_node(void);

bool copy_to_student(Student* pstudent, Student* item);

bool add_node(ListHead* pList, Node* item);

Student* get_input_to_student(void);

Node* traverse_list_to_position(ListHead* pList, int position);

bool init_list(ListHead* pList);

bool load_student_from_file(ListHead *pList);

void insert_student(ListHead* pList);

bool delete_student(ListHead* pList);

bool update_student(ListHead* pList);

Node* select_student(ListHead* pList);

bool show_all_student(ListHead* pList);

void print_student(Student* student);

bool save_information(ListHead* pList);
#endif // STUDENT_H
