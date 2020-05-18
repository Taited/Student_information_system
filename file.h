#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "student.h"

#define MAX_LINE 15
#define DATA_PATH ("C:\\Users\\admin\\Desktop\\Student_Information_System\\database.txt")

FILE* get_file(char* read_mode);
bool read_file_in_line(FILE* file);
void close_file(FILE* file);
