#include "file.h"

FILE* get_file(char* read_mode)
{
	FILE *file = fopen(DATA_PATH, read_mode);
	return file;
}

bool read_file_in_line(FILE* file)
{
	char buf[MAX_LINE];
	
	if (file == NULL)
	{
		printf("There is something wrong with the file.\n");
		return false;
	}
	
	while (fgets(buf, MAX_LINE, file) != NULL)
	{
		int len = strlen(buf);
		buf[len - 1] = '\0';  // È¥µô»»ÐÐ×Ö·û
		printf("%s\n", buf);
	}
	return true;
}

void close_file(FILE* file)
{
	fclose(file);
}