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

void Student_Mullayarov::draw(QPainter& painter, int* x, int* y, int* arrayLens) {
    *x = 10;
    QFont font("Arial", 12);
    QFontMetrics metrics(font);
    // Создайте QString с отступами, чтобы текст не сливался
    // QString text = QString("%1 %2 %3 %4")
    //                    .arg(QString::fromStdString(name).leftJustified(arrayLens[0] + 1, ' '))
    //                    .arg(QString::fromStdString(surname).leftJustified(arrayLens[1] + 1, ' '))
    //                    .arg(QString::fromStdString(to_string(age)).leftJustified(arrayLens[2] + 1, ' '))
    //                    .arg(QString::fromStdString(to_string(mark)).rightJustified(arrayLens[3] + 1, ' '));


    // painter.drawText(x, *y, text); // Отрисовка текста

    // for (int i = 0; i < 6 ; i++){
    //     painter.drawText(x, *y, text);
    //     x += arrayLens[i] + 10;
    // }
    // cout << "x:" << x << endl;
            int dx = 50;
    painter.drawText(*x, *y, QString::fromStdString(name));
    *(x) += arrayLens[0] + dx;
        // cout << "x1:" << x << endl;
    painter.drawText(*x, *y, QString::fromStdString(surname));
        *(x) += arrayLens[1] + dx;
    painter.drawText(*x, *y, QString::fromStdString(to_string(age)));
        *(x) += arrayLens[2] + dx;
    painter.drawText(*x, *y, QString::number(round(mark * 100) / 100, 'f', 1));
        *(x) += arrayLens[3] + dx;
        cout << round(mark*100)/100;
    *(y) += metrics.height() + 10; // Обновление координаты y с учетом высоты текста

}

int* Student_Mullayarov::countLen(){
    QFont font("Arial", 12);
    QFontMetrics metrics(font);
    // Получите размеры текста для каждой части строки
    int nameWidth = metrics.boundingRect(QString::fromStdString(name)).width();
    int surnameWidth = metrics.boundingRect(QString::fromStdString(surname)).width();
    int ageWidth = metrics.boundingRect(QString::fromStdString(to_string(age))).width();
    int markWidth = metrics.boundingRect(QString::number(round(mark * 100) / 100, 'f', 1)).width();
    int* array = new int[6];
    // cout << "nameWidth: "<<nameWidth << endl;
    // cout << "surnameWidth: "<< surnameWidth << endl;
    array[0] = nameWidth;
    array[1] = surnameWidth;
    array[2] = ageWidth;
    array[3] = markWidth;
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

