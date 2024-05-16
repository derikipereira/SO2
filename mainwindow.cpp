#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Crie os trens com seus IDs, posições iniciais, e referências das barras deslizantes
    trem1 = new Trem(1, 140, 30, ui->horizontalSliderT1);
    trem2 = new Trem(2, 410, 30, ui->horizontalSliderT2);
    trem3 = new Trem(3, 10, 150, ui->horizontalSliderT3);
    trem4 = new Trem(4, 280, 150, ui->horizontalSliderT4);
    trem5 = new Trem(5, 550, 150, ui->horizontalSliderT5);

    Trem* trems[6] = {nullptr, trem1, trem2, trem3, trem4, trem5};

    for (int i = 1; i <= 5; i++) {
        trems[i]->start();
    }
    // Conecte os sinais de atualização de velocidade das barras deslizantes às funções
    // de atualização de velocidade dos trens
    connect(ui->horizontalSliderT1, SIGNAL(valueChanged(int)), this, SLOT(atualizarVelocidadeTrem1(int)));
    connect(ui->horizontalSliderT2, SIGNAL(valueChanged(int)), this, SLOT(atualizarVelocidadeTrem2(int)));
    connect(ui->horizontalSliderT3, SIGNAL(valueChanged(int)), this, SLOT(atualizarVelocidadeTrem3(int)));
    connect(ui->horizontalSliderT4, SIGNAL(valueChanged(int)), this, SLOT(atualizarVelocidadeTrem4(int)));
    connect(ui->horizontalSliderT5, SIGNAL(valueChanged(int)), this, SLOT(atualizarVelocidadeTrem5(int)));

    // Conecte os sinais UPDATEGUI à função UPDATEINTERFACE para atualizar a posição dos trens
    connect(trem1, SIGNAL(updateGUI(int, int, int)), this, SLOT(updateInterface(int, int, int)));
    connect(trem2, SIGNAL(updateGUI(int, int, int)), this, SLOT(updateInterface(int, int, int)));
    connect(trem3, SIGNAL(updateGUI(int, int, int)), this, SLOT(updateInterface(int, int, int)));
    connect(trem4, SIGNAL(updateGUI(int, int, int)), this, SLOT(updateInterface(int, int, int)));
    connect(trem5, SIGNAL(updateGUI(int, int, int)), this, SLOT(updateInterface(int, int, int)));

}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
