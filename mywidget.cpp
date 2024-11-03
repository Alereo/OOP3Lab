#include "mywidget.h"



MyWidget::MyWidget(QWidget *parent)
    : QWidget{parent}
{

}


void MyWidget::paintEvent(QPaintEvent *event){
    QWidget::paintEvent(event);

    QPainter painter(this); // Создаем объект QPainter для рисования
    QTextLayout textLayout;
    // Устанавливаем шрифт для текста
    QFont font("Arial", 12, QFont::Bold);
    painter.setFont(font);
    QFontMetrics metrics(font);
    int *arrayMaxLen = new int[6];
    // QString textTable = QString("   Имя   \n        Фамилия     \nВозраст     Оценка     \nДолжность     \nКоличество предметов");

    int nameWidth = metrics.boundingRect(QString::fromStdString("Имя")).width();
    int surnameWidth = metrics.boundingRect(QString::fromStdString("Фамилия")).width();
    int ageWidth = metrics.boundingRect(QString::fromStdString("Возраст")).width();
    int markWidth = metrics.boundingRect(QString::fromStdString("Оценка")).width();
    int positionWidth = metrics.boundingRect(QString::fromStdString("Должность")).width();
    int subjectsWidth = metrics.boundingRect(QString::fromStdString("Количество предметов")).width();
    int* arrayTableName = new int[6];
    // cout << "nameWidth: "<<nameWidth << endl;
    // cout << "surnameWidth: "<< surnameWidth << endl;
    arrayTableName[0] = nameWidth;
    arrayTableName[1] = surnameWidth;
    arrayTableName[2] = ageWidth;
    arrayTableName[3] = markWidth;
    arrayTableName[4] = positionWidth;
    arrayTableName[5] = subjectsWidth;
    if (group.students.size()!=0){
        group.countLenMax(arrayMaxLen,arrayTableName);
        // for(int i =0; i < 6 ; i++){
        //     arrayMaxLen[i] *= 2;
        // }
        // QString textTable = QString("%1 %2 %3 %4 %5 %6")
        //                         .arg(QString::fromStdString("Имя").rightJustified(arrayMaxLen[0] + 1))
        //                         .arg(QString::fromStdString("Фамилия").rightJustified(arrayMaxLen[1] + 1))
        //                         .arg(QString::fromStdString("Возраст").rightJustified(arrayMaxLen[2] + 1))
        //                         .arg(QString::fromStdString("Оценка").rightJustified(arrayMaxLen[3] + 1))
        //                         .arg(QString::fromStdString("Должность").rightJustified(arrayMaxLen[4] + 1))
        //                         .arg(QString::fromStdString("Количество предметов").rightJustified(arrayMaxLen[5] + 1));
        int y = 50;
        int x = 10;
        int dx = 50;
        painter.drawText(x, 20, QString::fromStdString("Имя"));
        x += arrayMaxLen[0] + dx;
        painter.drawText(x, 20, QString::fromStdString("Фамилия"));
        x += arrayMaxLen[1] + dx;
        painter.drawText(x, 20, QString::fromStdString("Возраст"));
        x += arrayMaxLen[2] + dx;
        painter.drawText(x, 20, QString::fromStdString("Оценка"));
        x += arrayMaxLen[3] + dx;
        painter.drawText(x, 20, QString::fromStdString("Должность"));
        x += arrayMaxLen[4] + dx;
        painter.drawText(x, 20, QString::fromStdString("Количество предметов"));
        x += arrayMaxLen[5] + dx;


        int ytable = 25;
        for (int i = 0; i < group.students.size() + 1; i++){

            painter.drawLine(0, ytable, x, ytable);
            ytable += metrics.height() + 10;
        }

        int xtable = 10;
        for (int i = 0; i < 6; i++){
            xtable += arrayMaxLen[i] + dx;
            painter.drawLine(xtable, 0, xtable, ytable - (metrics.height() + 10));
        }
        // for (int var = 0; var < 6; ++var) {
        //     cout << "namber: " << arrayMaxLen[var];
        // }
        x = 10;
        // painter.drawText(10, 30, textTable);
        group.drawStudents(painter,&x,&y, arrayMaxLen);
        delete[] arrayMaxLen;
    }



}

void MyWidget::load(const QString& path)
{
            std::cout << "d1";
    group.load(path);
                    std::cout << "d";
        for(auto student : group.students){
        std::cout << "d";
        }
}

void MyWidget::save(const QString& path)
{
    std::ofstream out(path.toStdWString(), std::ofstream::binary);
    boost::archive::binary_oarchive ar(out);
    ar << group.students;
}

void MyWidget::clean()
{
    group.students.clear();
    update();
}

// void MyWidget::onSetLabels(bool labels)
// {
//     showLabels = labels;
//     update();
// }

void MyWidget::onSetWidth(int w)
{
    resize(w, height());
    repaint();
}

void MyWidget::onSetHeight(int h)
{
    resize(width(), h);
    repaint();
}



// void MyWidget::drawInfo(QPainter& painter, const Group_Mullayarov& data) {
//     QFontMetrics fm = painter.fontMetrics(); // Получение метрик шрифта

//     // Определение ширины столбцов
//     int widthName = fm.horizontalAdvance("sstring");
//     // ... (ширина других столбцов) ...

//     int x = 0;
//     int y = 0;

//     std::for_each(data.students.begin(), data.students.end(),
//                   std::bind(&MyWidget::drawStudentInfo, this, std::placeholders::_1,
//                             std::ref(painter), x, y, widthName));
// }

// void MyWidget::drawStudentInfo(const Student_Mullayarov& student, QPainter& painter,
//                      int& x, int& y, int widthName, ...) {
//     QString qstr = QString::fromStdString(student.name);
//     painter.drawText(x,y,qstr);
//     // ... (отрисовка остальных данных студента) ...
//     x += widthName; // Перемещение координаты x для следующего столбца
// }

