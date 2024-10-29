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
    QFont font("Arial", 16, QFont::Bold);
    painter.setFont(font);

    int y = 40;
    int x = 10;
    group.drawStudents(painter,x,&y);

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
}

void MyWidget::onSetHeight(int h)
{
    resize(width(), h);
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

