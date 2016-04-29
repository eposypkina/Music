#include "music.h"
int main() {
	int value = 0;						
        int katalog_size = 0;				
	music *katalog =0;										
	char x;	
	char file[str_length];	 			
        while(1){
        system("clear");
        cout<<" (^_^)(^_^)(^_^)(^_^)\n";
        cout<<"<1> Просмотр каталога \n";
        cout<<"<2> Добавление музыки \n";
        cout<<"<3> Удаление музыки \n";
        cout<<"<4> Сохранение данных \n";
        cout<<"<5> Загрузка данных \n";
        cout<<"<6> Поиск музыки  \n";
        cout<<"<7> Сортировка по рейтингу  \n";
        cout<<"<0> Выход \n\n\n";
        cout<<"==> ";
        cin>>x;  
        switch (x)
        {
        case '1'://просмотр каталога 
                system("clear"); 
                cout<<"Каталог музыки\n\n";
                show_katalog(katalog, value);
                getchar();
                getchar(); 
                break;
       case '2'://добавление музыки
                system("clear");
	        cout<<"Добавление новой записи\n";
                value++;
                if (katalog_size <= value)
                {
                        katalog_size++;
                        katalog = (music*)realloc(katalog, sizeof(music) * katalog_size);
                }
                add_music(&katalog[value - 1]);
                cout<<"Запись добавлена\n\n";
                getchar();
                break; 
        // удаление
        case '3':
                system("clear");
                cout<<"<1> Удаление всех записей \n<2> Удаление одной записи \n\n";
                cout<<"==>";
                 cin>>x;  
                  switch (x)
                  {
                  case'2':
                    system("clear");
                    cout<<"Удаление записи\n\n";
                    remove_entry(katalog, &value);
                    getchar();
                    break;
                  case'1':
                    system("clear");
                    cout<<"Удаление....\n\n";
                    if(value!=0)
                    delete [] katalog;
                    value=0;
                    getchar();
                    break;
                  default:cout<<"Неправильный ввод\n";
                  }
                getchar();
                break;
       // Сохранение данных
        case '4':
                system("clear");
                cout<<"Имя файла для сохранения: ";
                cin>>file;
                save_music(katalog, value, file);
                getchar();
                break;
      // загрузка из файла
		case '5':
		        system("clear");
			katalog = load(katalog,&value);
			katalog_size = value;
                        getchar();
                        break;

		// поиск
		case '6':
		system("clear");
               	podmenu(katalog, value);
                getchar();
                break;
                //сортировка по рейтингу
                case '7':
		system("clear");
		if(value > 1){
		cout<<"Сортировка...\n";
		getchar();
               	rating(katalog, value);}
                getchar();
                break;
                // выход
		case '0':
		        if(value!=0)
		        delete []katalog;
		        system("clear");
			return 0;
			default:cout<<"Неправильный ввод\n";
        }
} 
} 
