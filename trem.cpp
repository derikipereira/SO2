#include "trem.h"
#include <QtCore>

Trem::Trem(int ID, int x, int y, QSlider *slider) {
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = slider->value(); // Configura a velocidade com base no controle deslizante
    this->slider = slider;
}

void Trem::run() {
    while (true) {
        switch (ID) {
        case 1: // Trem 1 (quadrado superior esquerdo)
            if (isSafeToMove(10, 0)) {
                x += 10;
            }
            else if (isSafeToMove(0, 10)) {
                y += 10;
            }
            else if (isSafeToMove(-10, 0)) {
                x -= 10;
            }
            else {
                y -= 10;
            }
            emit updateGUI(ID, x, y);
            break;
        case 2: // Trem 2 (quadrado superior direito)
            if (isSafeToMove(10, 0)) {
                x += 10;
            }
            else if (isSafeToMove(0, 10)) {
                y += 10;
            }
            else if (isSafeToMove(-10, 0)) {
                x -= 10;
            }
            else {
                y -= 10;
            }
            emit updateGUI(ID, x, y);
            break;
        case 3: // Trem 3 (quadrado inferior esquerdo)
            if (isSafeToMove(10, 0)) {
                x += 10;
            }
            else if (isSafeToMove(0, -10)) {
                y -= 10;
            }
            else if (isSafeToMove(-10, 0)) {
                x -= 10;
            }
            else {
                y += 10;
            }
            emit updateGUI(ID, x, y);
            break;
        case 4: // Trem 4 (quadrado inferior direito)
            if (isSafeToMove(10, 0)) {
                x += 10;
            }
            else if (isSafeToMove(0, -10)) {
                y -= 10;
            }
            else if (isSafeToMove(-10, 0)) {
                x -= 10;
            }
            else {
                y += 10;
            }
            emit updateGUI(ID, x, y);
            break;
        case 5: // Trem 5 (trilho comum na parte inferior)
            if (isSafeToMove(10, 0)) {
                x += 10;
            }
            else if (isSafeToMove(-10, 0)) {
                x -= 10;
            }
            emit updateGUI(ID, x, y);
            break;
        default:
            break;
        }
        // Ajusta a velocidade com base no controle deslizante
        velocidade = slider->value();
        msleep(velocidade);
    }
}

bool Trem::isSafeToMove(int dx, int dy) {
    QMutex mutexRegiao0;
    QMutex mutexRegiao1;
    QMutex mutexRegiao2;
    QMutex mutexRegiao3;
    QMutex mutexRegiao4;
    QMutex mutexRegiao5;
    QMutex mutexRegiao6;

    if (dx > 0) {
        if (x + dx > 220 && y == 30) {
            if (!mutexRegiao0.tryLock()) {
                return false;
            }
            mutexRegiao0.unlock();
        }
        else if (x + dx > 430 && y == 30) {
            if (!mutexRegiao1.tryLock()) {
                return false;
            }
            mutexRegiao1.unlock();
        }
    }
    else if (dx < 0) {
        if (x + dx < 60 && y == 30) {
            if (!mutexRegiao2.tryLock()) {
                return false;
            }
            mutexRegiao2.unlock();
        }
        else if (x + dx < 350 && y == 150) {
            if (!mutexRegiao3.tryLock()) {
                return false;
            }
            mutexRegiao3.unlock();
        }
        else if (x + dx < 600 && y == 150) {
            if (!mutexRegiao4.tryLock()) {
                return false;
            }
            mutexRegiao4.unlock();
        }
    }
    else if (dy > 0) {
        if (y + dy > 150 && x == 220) {
            if (!mutexRegiao5.tryLock()) {
                return false;
            }
            mutexRegiao5.unlock();
        }
    }
    else if (dy < 0) {
        if (y + dy < 30 && x == 60) {
            if (!mutexRegiao6.tryLock()) {
                return false;
            }
            mutexRegiao6.unlock();
        }
    }

    return true;
}
