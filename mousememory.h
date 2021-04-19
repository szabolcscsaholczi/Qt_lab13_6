#ifndef MOUSEMEMORY_H
#define MOUSEMEMORY_H

#include <QObject>
#include <QDebug>
#include <QPoint>


class MouseMemory : public QObject
{
public:
    explicit MouseMemory(QObject *parent = 0);

    Q_INVOKABLE void test();// makro
    Q_INVOKABLE void clear();
    Q_INVOKABLE void save();
    Q_INVOKABLE void add(double x, double y);
    Q_INVOKABLE void add(QPointF point);
};

#endif // MOUSEMEMORY_H
