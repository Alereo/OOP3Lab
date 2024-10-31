#include "Head_Student.h"


Headman_Mullayarov::Headman_Mullayarov()
{
    position = "";
    amount_subjects = 0;
}

Headman_Mullayarov::~Headman_Mullayarov()
{
}

void Headman_Mullayarov::showStudent(ostream& out)
{
    Student_Mullayarov::showStudent(out);
    out << "Должность: " << position << endl;
    out << "Количество учебных предметов " << amount_subjects << endl;
}

void Headman_Mullayarov::createStudent(istream& in)
{
    string temp;
    bool exceptionOccured = true;
    Student_Mullayarov::createStudent(in);
    cout << "Введите должность студента\n";
    in >> ws;
    getline(in, temp);
    while ((temp = checkStr(temp)) == "Ошибка ввода строки") {

        cout << temp << endl;
        getline(in, temp);
    }
    position = temp;
    cout << "Введите количество учебных предметов \n";
    in >> ws;
    getline(in, temp);
    while (exceptionOccured) {
        try {
            amount_subjects = checkInt(temp);
            if (amount_subjects <= 0) {
                throw std::invalid_argument("");
            }
            exceptionOccured = false;
        }
        catch (invalid_argument) {
            exceptionOccured = true;
            cout << "Ошибка ввода :( Не верно количество" << endl;
            getline(in, temp);
        }
    }

}
int* Headman_Mullayarov::countLen(){
    int* array = new int[6];
    array[0] = name.length();
    array[1] = surname.length();
    array[2] = 2;
    array[3] = 1;
    array[4] = 9;
    array[5] = 1;
    return array;
}

void Headman_Mullayarov::draw(QPainter& painter,int x, int* y, int* arrayLens){
    QTextLayout textLayout;
    QFont font("Arial", 12);
    textLayout.setFont(font);

    QString text = QString("%1 %2 %3 %4")
                       .arg(QString::fromStdString(name),arrayLens[0] - name.size())
                       .arg(QString::fromStdString(surname),arrayLens[1] - surname.size())
                       .arg(age,arrayLens[2] - 2)
                       .arg(mark, arrayLens[3] - 1)
                       .arg(QString::fromStdString(position),abs(static_cast<int>(arrayLens[4] - position.size())))
                       .arg(amount_subjects,arrayLens[5] - 1);
    painter.drawText(x, *y, text); // Draw the text
    *(y)+=30;
}

