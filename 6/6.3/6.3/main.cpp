#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

struct info {

    string name;
    int age;
    int year;
    string gender;
    double performance;

};

void rand_gender(string& gender) {

    int g_event = rand() % 2;

    if (g_event == 0) gender = "male";
    if (g_event == 1) gender = "female";

}

void rand_name(string& name) {

    int surname_event = rand() % 10;
    int name_event = rand() % 10;
    int patronim_event = rand() % 10;


    if (name == "male") {

        switch (surname_event) {

        case 0: name = "Смирнов "; break;
        case 1: name = "Иванов "; break;
        case 2: name = "Кузнецов "; break;
        case 3: name = "Соколов "; break;
        case 4: name = "Попов "; break;
        case 5: name = "Лебедев "; break;
        case 6: name = "Козлов "; break;
        case 7: name = "Новиков "; break;
        case 8: name = "Морозов "; break;
        case 9: name = "Петров "; break;

        };

        switch (name_event) {

        case 0:    name += "Александр "; break;
        case 1: name += "Дмитрий "; break;
        case 2: name += "Максим "; break;
        case 3: name += "Сергей "; break;
        case 4: name += "Андрей "; break;
        case 5: name += "Алексей "; break;
        case 6: name += "АртЄм "; break;
        case 7: name += "Николай "; break;
        case 8: name += "Кирилл "; break;
        case 9: name += "Михаил "; break;


        };

        switch (patronim_event) {

        case 0:    name += "Александрович"; break;
        case 1: name += "Алексеевич"; break;
        case 2: name += "Николаевич"; break;
        case 3: name += "Иванович"; break;
        case 4: name += "Владимирович"; break;
        case 5: name += "Георгиевич"; break;
        case 6: name += "Васильевич"; break;
        case 7: name += "Валерьевич"; break;
        case 8: name += "Викторович"; break;
        case 9: name += "Петрович"; break;


        };

    }
    else {

        switch (surname_event) {

        case 0: name = "Смирнова "; break;
        case 1: name = "Иванова "; break;
        case 2: name = "Кузнецова "; break;
        case 3: name = "Соколова "; break;
        case 4: name = "Попова "; break;
        case 5: name = "Лебедева "; break;
        case 6: name = "Козлова "; break;
        case 7: name = "Новикова "; break;
        case 8: name = "Морозова "; break;
        case 9: name = "Петрова "; break;

        };

        switch (name_event) {

        case 0:    name += "Анастасия "; break;
        case 1: name += "Инна "; break;
        case 2: name += "Валерия "; break;
        case 3: name += "Елена "; break;
        case 4: name += "Александра "; break;
        case 5: name += "Алина "; break;
        case 6: name += "Ирина "; break;
        case 7: name += "Екатерина "; break;
        case 8: name += "Полина "; break;
        case 9: name += "Ольга "; break;

        };

        switch (patronim_event) {

        case 0:    name += "Александровна"; break;
        case 1: name += "Алексеевна"; break;
        case 2: name += "Николаевна"; break;
        case 3: name += "Ивановна"; break;
        case 4: name += "Владимировна"; break;
        case 5: name += "Георгиевна"; break;
        case 6: name += "Васильевна"; break;
        case 7: name += "Юрьевна"; break;
        case 8: name += "Викторовна"; break;
        case 9: name += "Петровна"; break;

        };


    }

}

double float_random() {

    double integer_part = (double)(rand() % 6) + 4;
    double fractional_part = (double)(rand() % 10) / 10;

    return integer_part + fractional_part;

}

void rand_fill_info(info* student, int N) {

    srand(time(0));

    for (int i = 0; i < N; i++) {


        string info_str = "";

        rand_gender(info_str);
        student[i].gender = info_str;

        rand_name(info_str);
        student[i].name = info_str;


        student[i].year = rand() % 5 + 1;

        student[i].age = rand() % 4 + 17 + student[i].year;

        student[i].performance = float_random();

    };

}



int main() {

    const int N = 10;

    info student[N];

    rand_fill_info(student, N);

    ofstream fout;
    string pathG ="";
    fout.open(pathG);
    for (int i = 0; i<10; i++){
        cout<<student[i].name<<" "<<student[i].age<<" "<<student[i].gender<<" "<<student[i].year<<" "<<student[i].performance<<" "<<"\n";
    }
    
    
return 0;
}
