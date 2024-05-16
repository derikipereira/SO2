#ifndef TREM_H
#define TREM_H

#include <QThread>
#include <QSlider>
#include <QSemaphore>

class Trem : public QThread {
    Q_OBJECT

public:
    Trem(int ID, int x, int y, QSlider *slider);
    void run() override;
    static Trem* trems[6];
    void setTrens(Trem* trems[]);

signals:
    void updateGUI(int, int, int);

private:
    int ID;
    int x, y;
    QSlider *slider;
    int velocidade;
    QSemaphore *semaphore; // Semáforo para controlar a velocidade de cada trem
    bool isSafeToMove(int dx, int dy);
    int  calculateRegiaoCritica();
    void moveTrem();
};

#endif // TREM_H
