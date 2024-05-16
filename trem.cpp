#include "trem.h"
#include <QSemaphore>

QSemaphore semaforoRegiao0(1);
QSemaphore semaforoRegiao1(1);
QSemaphore semaforoRegiao2(1);
QSemaphore semaforoRegiao3(1);
QSemaphore semaforoRegiao4(1);
QSemaphore semaforoRegiao5(1);
QSemaphore semaforoRegiao6(1);



Trem::Trem(int ID, int x, int y, QSlider *slider) {
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->slider = slider;
    velocidade = slider->maximum(); // Inicializa a velocidade máxima
}

void Trem::run() {
    while (true) {
        // Aguarde até que o valor do slider seja maior que 0
        while (slider->value() == 0) {
            continue;
        }
        velocidade = slider->maximum() - slider->value();
        moveTrem();
    }
}

void Trem::moveTrem() {
    if (ID == 1) {
        if (x < 390 && y == 30) {
            x += 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
        }
        else if(x == 390 && y == 30){
            semaforoRegiao0.acquire();
            msleep(velocidade);
            x += 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            x += 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            for (int i = 0; i < 10; ++i) {
                y += 10;
                emit updateGUI(ID, x, y);
                msleep(velocidade);
            }
            semaforoRegiao0.release();
        } else if (x == 410 && y == 130) {
            semaforoRegiao2.acquire();
            y += 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            y += 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            for (int i = 0; i < 11; ++i) {
                x -= 10;
                emit updateGUI(ID, x, y);
                msleep(velocidade);
            }
            semaforoRegiao2.release();
        } else if (x == 300  && y == 150) {
            semaforoRegiao1.acquire();
            msleep(velocidade);
            for (int i = 0; i < 16; ++i) {
                x -= 10;
                emit updateGUI(ID, x, y);
                msleep(velocidade);
            }
            semaforoRegiao1.release();
        } else if (y > 30 && y <= 150 && x == 140) {
            y -= 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
        }


    } else if (ID == 2) {
        if (x < 680 && y == 30) {
            x += 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
        } else if (x == 680 && y == 130) {
            semaforoRegiao4.acquire();
            msleep(velocidade);
            y += 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            y += 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            for (int i = 0; i < 11; ++i) {
                x -= 10;
                emit updateGUI(ID, x, y);
                msleep(velocidade);
            }
            semaforoRegiao4.release();
        }else if (x == 570 && y == 150) {
            semaforoRegiao3.acquire();
            msleep(velocidade);
            for (int i = 0; i < 14; ++i) {
                x -= 10;
                emit updateGUI(ID, x, y);
                msleep(velocidade);
            }
            semaforoRegiao3.release();
        }else if (x == 430 && y == 150) {
            semaforoRegiao0.acquire();
            x -= 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            x -= 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            for (int i = 0; i < 12; ++i) {
                y -= 10;
                emit updateGUI(ID, x, y);
                msleep(velocidade);
            }
            semaforoRegiao0.release();
        } else if (y >= 30 && y < 150 && x == 680) {
            y += 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
        }

    } else if (ID == 3) {
        if (x < 120 && y == 150) {
            x += 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
        } else if(x == 120 && y == 150){
            semaforoRegiao1.acquire();
            msleep(velocidade);
            for (int i = 0; i < 14; ++i) {
                x += 10;
                emit updateGUI(ID, x, y);
                msleep(velocidade);
            }
            semaforoRegiao1.release();
        }
        //y >= 150 && y < 270 && x == 280
        else if (y == 150 && x == 260) {
            semaforoRegiao5.acquire();
            msleep(velocidade);
            x += 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            x += 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            for (int i = 0; i < 12; ++i) {
                y += 10;
                emit updateGUI(ID, x, y);
                msleep(velocidade);
            }
            semaforoRegiao5.release();
        } else if (x > 10 && x <= 280 && y == 270) {
            x -= 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
        }
        else if (y > 150 && y <= 270 && x == 10) {
            y -= 10;      
            emit updateGUI(ID, x, y);
            msleep(velocidade);
        }
    } else if (ID == 4) {
        if (x < 390  && y == 170) {
            semaforoRegiao2.acquire();
            y -= 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            y -= 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            for (int i = 0; i < 11; ++i) {
                x += 10;
                emit updateGUI(ID, x, y);
                msleep(velocidade);
            }
            semaforoRegiao2.release();
        } else if(x < 390  && y == 150){
            semaforoRegiao3.acquire();
            for (int i = 0; i < 11; ++i) {
                x += 10;
                emit updateGUI(ID, x, y);
                msleep(velocidade);
            }
            semaforoRegiao3.release();
        } else if(x == 390 && y == 150){
            semaforoRegiao3.acquire();
            for (int i = 0; i < 14; ++i) {
                x += 10;
                emit updateGUI(ID, x, y);
                msleep(velocidade);
            }
            semaforoRegiao3.release();
        } else if (y == 150 && x == 530) {
            semaforoRegiao6.acquire();
            x += 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            x += 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            for (int i = 0; i < 12; ++i) {
                y += 10;
                emit updateGUI(ID, x, y);
                msleep(velocidade);
            }
            semaforoRegiao6.release();
        } else if (x > 300 && x <= 550 && y == 270) {
            x -= 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
        } else if (y == 270 && x == 300) {
            semaforoRegiao2.acquire();
            semaforoRegiao5.acquire();
            x -= 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            x -= 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            for (int i = 0; i < 10; ++i) {
                y -= 10;
                emit updateGUI(ID, x, y);
                msleep(velocidade);
            }
            semaforoRegiao5.release();
            semaforoRegiao2.release();
        }

    } else if (ID == 5) {
        if (x < 820 && y == 150) {
            x += 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
        } else if (x == 550 && y == 170) {
            semaforoRegiao4.acquire();
            msleep(velocidade);
            y -= 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            y -= 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            for (int i = 0; i < 13; ++i) {
                x += 10;
                emit updateGUI(ID, x, y);
                msleep(velocidade);
            }
            semaforoRegiao4.release();
        }else if (y >= 150 && y < 270 && x == 820) {
            y += 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
        } else if (x > 570 && x <= 820 && y == 270) {
            x -= 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
        } else if (y == 270 && x == 570) {
            msleep(velocidade);
            semaforoRegiao4.acquire();
            semaforoRegiao6.acquire();
            x -= 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            x -= 10;
            emit updateGUI(ID, x, y);
            msleep(velocidade);
            for (int i = 0; i < 10; ++i) {
                y -= 10;
                emit updateGUI(ID, x, y);
                msleep(velocidade);
            }
            semaforoRegiao6.release();
            semaforoRegiao4.release();
        }
    }
}
