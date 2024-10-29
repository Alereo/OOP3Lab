#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QPainter>
#include <QWidget>
#include <QFontMetrics>
#include "Group.h"
#include <QTextLayout>
class MyWidget : public QWidget
{
    friend class boost::serialization::access;
    Q_OBJECT
public:
    Group_Mullayarov group;
    explicit MyWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    // void drawInfo(QPainter& painter, const Group_Mullayarov& data);
    // void drawStudentInfo(const Student_Mullayarov& student, QPainter& painter,
    //                      int& x, int& y, int widthName, ...);
    void load(const QString& path);
    void save(const QString& path);
    void clean();

    //public slots:
    // void onSetLabels(bool);
    void onSetWidth(int);
    void onSetHeight(int);
signals:
};

#endif // MYWIDGET_H
