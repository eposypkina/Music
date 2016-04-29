#include "music.h"
// Загружает каталог из файла 
music* load(music *katalog, int *value)
{
	char s[str_length];
	char file[str_length];
        katalog = new music[0];
	cout << "Имя файла с данными: ";
	cin >> file;
	ifstream fout;
	fout.open(file);
	if(!fout)
	  {
	    cout<<"Невозможно прочитать файл\n";
	    getchar();
	        }
	else{       
        while(!fout.eof())
        {
		(*value)++;
		katalog = (music*)realloc(katalog, sizeof(music)*(*value));
		fout.getline(katalog[(*value) - 1].song,str_length);
		fout.getline(katalog[(*value) - 1].band,str_length);
		fout.getline(katalog[(*value) - 1].album,str_length);
		fout.getline(katalog[(*value) - 1].style,str_length);
		fout.getline(s,str_length);
		katalog[(*value) - 1].likes=atoi(s);
        }
	katalog[(*value)-1]=katalog[(*value)];
        (*value)--; 
	cout<<"Данные загружены из файла\n";
	getchar();
	fout.close();
	return katalog;
}    
}
//Вывод данных по поиску 
void show_entry(music entry)
{
cout<<"Название песни: "<<entry.song<<"\n";
cout<<"Группа: "<< entry.band<<"\n";
cout<<"Альбом: "<< entry.album<<"\n";
cout<<"Жанр: "<< entry.style<<"\n";
cout<<"Количество лайков: "<< entry.likes<<"\n";
return;
}
// Просмотр всего каталога
void show_katalog(music *katalog, int value)
{
	int i;
	if (value == 0)
	        {
	        system("clear");
		cout<<"Каталок пуст\n";
		}
	else {
		    for (i = 0; i < value; i++)
		    {
                      cout<<"************************************************\n";
                      cout<<"Запись № "<<i+1<<"\n";
                      cout<<"************************************************\n";
                      show_entry(katalog[i]);
                      cout<<"\n";
		    }
              }
return;   
}
// Ввод данных о новой песне
void add_music(music *entry){
        int i;
        char s[str_length];
        cout<<"Название пeсни: ";
        cin.ignore();
        cin.getline(entry->song,str_length);
        cout<<"Группа: ";
	cin.getline(entry->band,str_length);
	cout<<"Альбом: ";
	cin.getline(entry->album,str_length);
	cout<<"Жанр: ";
        cin.getline(entry->style,str_length);
        cout<<"Количество лайков: ";
        cin.getline(s,str_length);
	entry->likes=atoi(s);
	return;	
}
//Поиск музыки #1
void podmenu(music *katalog, int value)
{  
cout<<"<1> По группе \n<2> По песне \n<3> По альбому \n<4> По жанру \n<5> По количеству лайков \n<0> Отмена \n\n";
cout<<"==>";
char x;
cin>>x;
switch (x)
  {
	case '1': seek(katalog, value, 1);
		break;
	case '2': seek(katalog, value, 2);
		break;
        case '3': seek(katalog, value, 3);
        	break;
	case '4': seek(katalog, value, 4);
		break;
	case '5': seek(katalog, value, 5);
		break;
	case '0': break;
        default: cout<<"Неверный тип поиска";
	break;
  }
return;  
}
//cортировка по рейтингу
void rating(music *katalog, int value)
{
int i,j;
char flag;
music buffer;
  for (i = 0; i < value; i++)
  {
    for (j = i; j < value; j++)
    {
    flag = 0;
      if (katalog[i].likes < katalog[j].likes) flag = 1; 
       if (flag == 1)
       {
       buffer =katalog[i] ;
       katalog[i] = katalog[j];
       katalog[j] = buffer;
       }
    }		
  }
return;  
}
//----------------------------------------------------------------
// ПОИСК МУЗЫКИ #2
//----------------------------------------------------------------
void seek(music *katalog, int value, int seek_type)
{
        int i,j;
        char flag;
        string s;
music entry;
switch (seek_type)
	{
	case 1: 
		cout<<"Введите название группы для поиска: ";
		cin.ignore();
		cin.getline(entry.band,str_length);
		break;
	case 2:
		cout<<"Введите название песни для поиска: ";
                cin.ignore();
                cin.getline(entry.song,str_length);
               	break;
	case 3: 
		cout<<"Введите название альбома для поиска: ";
		cin.ignore();
		cin.getline(entry.album,str_length);
		break;
	case 4:
		cout<<"Введите жанр песни для поиска: ";
		cin.ignore();
		cin.getline(entry.style,str_length);
		break;
	case 5:
		cout<<"Введите количество лайков для поиска: ";
		cin>>entry.likes;
                break;  
	}
	system("clear");
	for (i = 0; i < value; i++)
	{
		flag = 0;
		switch (seek_type)
		{       
		        case 1: if (strcmp(katalog[i].band, entry.band) == 0) flag = 1; break; 
 		        case 2: if (strcmp(katalog[i].song, entry.song) == 0) flag = 1; break; 
			case 3: if (strcmp(katalog[i].album, entry.album) == 0) flag = 1; break;
			case 4: if (strcmp(katalog[i].style, entry.style) == 0) flag = 1; break;
			case 5: if (katalog[i].likes == entry.likes) flag = 1; break;
		}
		
		if (flag == 1)
		{
  			cout<<"***********************************************\n";
			cout<<"Запись №"<<i+1<<"\n";
			cout<<"***********************************************\n";
			show_entry(katalog[i]);
			cout<<"\n";
		}
	}
return;	
}
// Удаление записи из каталога
void remove_entry(music *katalog, int *value)
{
	int i,j,x;
	char s[str_length];
	cout<<"Введите номер песни для удаления: ";
	cin>>s;
	x=atoi(s);
	x--;
	if (x < 0 || x >= *value)
	{
		cout<<"Записи с таким номером не существует\n";
		return;
	}
	for (i = x; i < *value - 1; i++)
		katalog[i] = katalog[i + 1];
	(*value)--;
	cout<<"Запись удалена\n\n";
	return;
}
// Сохраняет каталог в файл
void save_music(music *katalog, int value, char *file)
{
	ofstream fin;
	fin.open(file, ios_base::out);
	int i;
	if (!fin)
	{
		cout<<"Не удалось сохранить данные в файл";
		return;
	}
	for(i = 0; i < value; i++)
	{
		fin<<katalog[i].song<<"\n";
		fin<<katalog[i].band<<"\n";
		fin<<katalog[i].album<<"\n";
		fin<<katalog[i].style<<"\n";
		fin<<katalog[i].likes<<"\n";
	}
	cout<<"Данные сохранены в файл " <<file<<"\n";
	fin.close();
}

