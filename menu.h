#pragma once
#ifndef MENU_H
#define MENU_H
#include <stdio.h>

//  函数名称：show_menu
//  输入参数：无
//  返回值：  无
//  功能：显示如下菜单

/**************************************************
0. 退出
1. 增加学生信息
2. 修改学生信息
3. 删除学生信息
4. 查询学生信息
5. 显示所有学生信息
**************************************************/

void show_menu(void);

int  get_menu_index(void);

#endif // MENU_H
