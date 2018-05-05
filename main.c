#include "KMP.h"
#include "KMP.c"

/*Работает не вся строка, начинается не с 1, а с 0 элемента
Работа сделана на 4 +/-
*/

/*ПОИСК ПО ШАБЛОНУ +
ЧТЕНИЕ ИЗ ФАЙЛА НЕСКОЛЬКИХ СТРОК +
*/

int main(int argc, char *argv[])
{
	FILE *in;
	char str[1000];
	int counter = 1;
	int pos;

	if (argc != 3) {
		printf("Параметры заданы неверно\n");
		return 1;
	}

	in = fopen(argv[2], "r");
	if (in == NULL) {
		printf("Ошибка открытия файла\n");
		return 1;
	}

	while (!feof(in)) {
	fgets(str, 1000, in);
	if (str[strlen(str) - 1] == '\n')
	    str[strlen(str) - 1] = '\0';
	pos = seek_substring_KMP(str, argv[1]);
	if (pos >= 0){
	    printf("%d: %d\n", counter, pos);
	counter++;
	}else if(pos == -1){
	    printf("Такой подстроки нет(\n");
	counter++;
	}
	}
    fclose(in);

    return 0;
}
