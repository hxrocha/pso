#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pso.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btnSair_clicked()
{
    this->close();
}

void MainWindow::on_btnCalcular_clicked()
{
    QUANTIDADEPARTICULAS = ui->edParticulas->text().toInt();
    struct particula populacaoParticulas[QUANTIDADEPARTICULAS];
    float avaliacao[QUANTIDADEPARTICULAS];
    struct melhor melhorParticula;
    int iteracoes = ui->edIteracoes->text().toInt();
    struct ponto v;
    float w = 1.0;
    float ca = 0.99;
    float csa =2.0;
    float cpa = 2.0;
    iniciaParticulas(populacaoParticulas,&melhorParticula);

    for(int g=1;g <= iteracoes;g++){
            ui->progressBar->setValue((int)(100.0/iteracoes*g));
            for(int i=0;i<QUANTIDADEPARTICULAS;i++){
            v.x =  w* populacaoParticulas[i].velocidade.x +
                   static_cast <float> (rand()) / static_cast <float> (RAND_MAX)*
                    cpa*(populacaoParticulas[i].melhorpontoDestaParticula.x -
                         populacaoParticulas[i].p.x) +
                   static_cast <float> (rand()) / static_cast <float> (RAND_MAX)*
                    csa* (melhorParticula.posicao.x - populacaoParticulas[i].p.x);
            v.y = w*populacaoParticulas[i].velocidade.y +
                    static_cast <float> (rand()) / static_cast <float> (RAND_MAX)*
                     cpa*(populacaoParticulas[i].melhorpontoDestaParticula.y -
                          populacaoParticulas[i].p.y) +
                    static_cast <float> (rand()) / static_cast <float> (RAND_MAX)*
                     csa* (melhorParticula.posicao.y - populacaoParticulas[i].p.y);
           populacaoParticulas[i].p.x =  populacaoParticulas[i].p.x + v.x;
           populacaoParticulas[i].p.y =  populacaoParticulas[i].p.y + v.y;
           populacaoParticulas[i].custo =  calculaCusto(populacaoParticulas[i].p);
            if(populacaoParticulas[i].custo < populacaoParticulas[i].melhorCusto){
                populacaoParticulas[i].melhorCusto =populacaoParticulas[i].custo;
                populacaoParticulas[i].melhorpontoDestaParticula = populacaoParticulas[i].p;
            }
            if(populacaoParticulas[i].custo < melhorParticula.custo){
                melhorParticula.custo = populacaoParticulas[i].custo;
                melhorParticula.posicao = populacaoParticulas[i].p;
            }

       }
       w = w *ca;
    }
    ui->edX->setText(QString::number(melhorParticula.posicao.x,'f',4));
    ui->edY->setText(QString::number(melhorParticula.posicao.y,'f',4));






   /* imprimeParticula(particulas);
    avaliaParticulas(avaliacao,particulas);
    for(int i=0;i<QUANTIDADEPARTICULAS;i++)
        printf("%f ",avaliacao[i]);
*/

}

void MainWindow::on_btnPlotar_clicked(){



}
