#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#define str_length 100//Длина строки
using namespace std;
class music 
{
public:
char song[str_length];
char band[str_length];
char album[str_length];
char style[str_length];
int likes;
};
void podmenu(music *katalog, int value);//поиск музыки №1
void show_entry(music entry);//вывод данных по поиску
void show_katalog(music *katalog, int value);//просмотр всего каталога
void add_music(music *katalog);//добавление музыки
void remove_entry(music *katalog, int *value);//удаление записи
void save_music(music *katalog, int value, char *file);//сохранения каталога в файл
music* load(music *katalog, int *value);//загрузка каталога из файла
void seek(music *katalog, int value, int seek_type);//поиск музыки №2
void rating(music *katalog, int value);//сортировка по рейтингу

