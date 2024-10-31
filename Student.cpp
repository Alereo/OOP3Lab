#include "Student.h"
#include <string>
using namespace std;
BOOST_CLASS_IMPLEMENTATION(Student_Mullayarov, boost::serialization::level_type::object_serializable)

Student_Mullayarov::Student_Mullayarov()
{
    mark = age = 0;
    name = " ";
    surname = " ";
}

void Student_Mullayarov::showStudent(ostream& out)
{
    out << "Имя студента: " << name << endl << "Фамилия студента: " << surname << endl << "Возраст студента: " << age << endl << "Средняя оценка по предметам: " << mark << endl;
}

void Student_Mullayarov::createStudent(istream& in)
{
    bool exceptionOccured = true;
    string temp;
    string name;
    cout << "Введите имя студента\n";
    in >> ws;
    getline(in, temp);

    while ((temp = checkStr(temp)) == "Ошибка ввода строки") {

        cout << temp << endl;
        getline(in, temp);
    }
    name = temp;

    cout << "Введите фамилию студента\n";
    in >> ws;
    getline(in, temp);
    while ((temp = checkStr(temp)) == "Ошибка ввода строки") {

        cout << temp << endl;
        getline(in, temp);
    }
    surname = temp;
    cout << "Введите возраст \n";
    in >> ws;
    getline(in, temp);
    while (exceptionOccured) {
        try {
            age = checkInt(temp);
            if (age < 18) {
                throw std::invalid_argument("");
            }
            exceptionOccured = false;
        }
        catch (invalid_argument) {
            exceptionOccured = true;
            cout << "Ошибка ввода :( Не верен возраст" << endl;
            getline(in, temp);
        }
    }
    exceptionOccured = true;
    cout << "Ввeдите среднюю оценку\n";
    in >> ws;
    getline(in, temp);
    while (exceptionOccured) {
        try {
            mark = checkDouble(temp);
            if (mark < 0.0 || mark > 5.0) {
                throw std::invalid_argument("");
            }
            exceptionOccured = false;
        }
        catch (invalid_argument) {
            exceptionOccured = true;
            cout << "Не верна оценка - ошибка ввода :(" << endl;
            getline(in, temp);
        }
    }
}

void Student_Mullayarov::draw(QPainter& painter,int x, int* y, int* arrayLens){
    QTextLayout textLayout;
    QFont font("Arial", 12);
    //arrayLens[0] - name.size()
    textLayout.setFont(font);
    cout << "Dlina: " << arrayLens[0] << endl;
    QString text = QString("%1 %2 %3 %4")
                       .arg(QString::fromStdString(name),arrayLens[0] + 1)
                       .arg(QString::fromStdString(surname),arrayLens[1] + 1)
                       .arg(age,arrayLens[2] + 1)
                       .arg(mark, arrayLens[3] + 1);

    painter.drawText(x, *y, text); // Draw the text
    cout << "dgdg";
    *(y)+=30;
}

int* Student_Mullayarov::countLen(){
    int* array = new int[6];
    array[0] = name.length();
    array[1] = surname.length();
    array[2] = 2;
    array[3] = 1;
    array[4] = 0;
    array[5] = 0;
    return array;
}

//ofstream& Student_Mullayarov::operator<<(ofstream& fout)
//{
//    fout << "Имя студента: " << name << endl << "Фамилия студента: " << surname << endl << "Возраст студента: " << age << endl << "Средняя оценка по предметам: " << mark << endl;
//    return fout;
//}

//ifstream& Student_Mullayarov::operator>>(ifstream& fin)
//{
//    string line;
//    getline(fin, line);
//    name = line.substr(line.find_first_of(':') + 2);
//    getline(fin, line);
//    surname = line.substr(line.find_first_of(':') + 2);
//    getline(fin, line);
//    age = std::stoi(line.substr(line.find_first_of(':') + 2));
//    getline(fin, line);
//    mark = std::stod(line.substr(line.find_first_of(':') + 2));
//    return fin;
//}




Student_Mullayarov::~Student_Mullayarov()
{
}

//ostream& operator<<(ostream& out, Student_Mullayarov* s)
//{
//    out << "Имя студента: " << s->name << endl << "Фамилия студента: " << s->surname << endl << "Возраст студента: " << s->age << endl << "Средняя оценка по предметам: " << s->mark << endl;
//    return out;
//}

//istream& operator>>(istream& in, Student_Mullayarov* s)
//{
//    bool exceptionOccured = true;
//    string temp;
//    string name;
//    cout << "Введите имя студента\n";
//    in >> ws;
//    getline(in, temp);
//
//    while ((temp = checkStr(temp)) == "Ошибка ввода строки" ) {
//
//        cout << temp << endl;
//        getline(in, temp);
//    }
//    s->name = temp;
//    //if ((temp = checkStr(temp)) != "Ошибка ввода строки") {
//    //    s->name = temp;
//    //}
//    //else {
//    //    std::cout << "Не верно имя для студента - ошибка ввода :(" << endl;
//    //}
//    cout << "Введите фамилию студента\n";
//    in >> ws;
//    getline(in, temp);
//    while ((temp = checkStr(temp)) == "Ошибка ввода строки") {
//
//        cout << temp << endl;
//        getline(in, temp);
//    }
//    s->surname = temp;
//    //if ((temp = checkStr(temp)) != "Ошибка ввода строки") {
//    //    s->surname = temp;
//    //}
//    //else {
//    //    std::cout << "Не верна фамилия для студента - ошибка ввода :(" << endl;
//    //}
//    cout << "Введите возраст \n";
//    in >> ws;
//    getline(in, temp);
//    while (exceptionOccured) {
//        try {
//            s->age = checkInt(temp);
//            if (s->age < 18) {
//                throw std::invalid_argument("");
//            }
//            exceptionOccured = false;
//        }
//        catch (invalid_argument) {
//            exceptionOccured = true;
//            cout << "Ошибка ввода :( Не верен возраст" << endl;
//            getline(in, temp);
//        }
//    }
//    exceptionOccured = true;
//    cout << "Ввeдите среднюю оценку\n";
//    in >> ws;
//    getline(in, temp);
//    while (exceptionOccured) {
//        try {
//            s->mark = checkDouble(temp);
//            if (s->mark < 0.0 || s->mark > 5.0) {
//                throw std::invalid_argument("");
//            }
//            exceptionOccured = false;
//        }
//        catch (invalid_argument) {
//            exceptionOccured = true;
//            cout << "Не верна оценка - ошибка ввода :(" << endl;
//            getline(in, temp);
//        }
//    }
//    return in;
//}



//ifstream& operator>>(ifstream& fin, Student_Mullayarov* s)
//{
//    string line;
//    getline(fin, line);
//    s->name = line.substr(line.find_first_of(':') + 2);
//    getline(fin, line);
//    s->surname = line.substr(line.find_first_of(':') + 2);
//    getline(fin, line);
//    s->age = std::stoi(line.substr(line.find_first_of(':') + 2));
//    getline(fin, line);
//    s->mark = std::stod(line.substr(line.find_first_of(':') + 2));
//    return fin;
//}

