#ifndef PSO_H
#define PSO_H


#include<limits.h>

int QUANTIDADEPARTICULAS = 5;

struct ponto{
    float x,y;
};

struct particula{
    struct ponto p;
    struct ponto velocidade;
    float custo;
    struct ponto melhorpontoDestaParticula;
    float melhorCusto;
};
struct melhor{
    struct ponto posicao;
    float custo;
};


float calculaCusto(struct ponto p){
    return(p.x*p.x+p.y*p.y);
}


void iniciaParticulas(struct particula *particulas,struct melhor *melhorParticula){

    for(int i=0;i<QUANTIDADEPARTICULAS;i++){
        particulas[i].p.x = rand()%801/100.0-4.0;
        particulas[i].p.y = rand()%801/100.0-4.0;
        particulas[i].velocidade.x=0.0;
        particulas[i].velocidade.y=0.0;
        particulas[i].custo = calculaCusto(particulas[i].p);
        particulas[i].melhorpontoDestaParticula =
                particulas[i].p;
        particulas[i].melhorCusto = particulas[i].custo;
        if((particulas[i].custo < melhorParticula->custo) ||(i==0)){
            melhorParticula->posicao = particulas[i].p;
            melhorParticula->custo = particulas[i].custo;
        }
    }

}





#endif // PSO_H
