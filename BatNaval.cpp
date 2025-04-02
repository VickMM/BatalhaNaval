#include <iostream>

//protótipos das funções, assinaturas ou cabeçalhos (o mais comum é assinatura)

void zerarCampoBatalha(void);
void exibirCampoBatalha(void);
void posicionarObj(int tipoObj, int lin, int col);
int MAT[5][5];

int main(){
    zerarCampoBatalha();
    exibirCampoBatalha();
    
    int linha;
    int coluna;
    int tipo;
    int cont;
    
    printf("Deseja iniciar o jogo? Digite 1 - SIM ou 0 - NAO: ");
    scanf("%i", &cont);
    
    while(cont == 1){
        
        printf("Batalha naval - personagens | 1- SUBMARINO, 2- PORTA AVIOES, 3- NAVIO");
        printf("\nInforme o personagem: "); 
        scanf("%i", &tipo);
        printf("Informe a linha: ");
        scanf("%i", &linha);
        printf("Informe a coluna: ");
        scanf("%i", &coluna);
        posicionarObj(tipo, linha, coluna);
        exibirCampoBatalha();
        
        printf("Deseja continuar o jogo? Digite 1 - SIM ou 0 - NAO: ");
        scanf("%i", &cont);
    }
    
    
}

    void zerarCampoBatalha(void){       
        for(int lin=0; lin<= 4; lin++){
            for (int col=0; col<=4; col++){
                MAT[lin][col]=0;
            }   
        }
    }
    
    void exibirCampoBatalha(void){
    // Exibindo a matriz    
        for (int lin = 0; lin <= 4; lin++){
            for (int col = 0; col <= 4; col++){
                printf("%i ", MAT[lin][col]); 
        }
            printf("\n"); 
        }
            printf("\n\n");
    }

    
    void posicionarObj(int tipoObj, int lin, int col){
        
        switch (tipoObj){
            case 1:
                if (MAT[lin][col] != 0){
                    printf("\nCampo ja ocupado\n");
                    break;
                } 
                if (lin > 0 && lin <= 4 && col < 3){
                    MAT[lin][col] = 1;
                    MAT[lin][col+1] = 1;
                    MAT[lin][col+2] = 1;
                    MAT[lin-1][col+1]=1;
                } else{
                    printf("Erro ao posicionar submarino!\n");
                }
            break;
            
            case 2: 
                if (MAT[lin][col] != 0){
                    printf("\nCampo ja ocupado\n");
                    break;
                } 
                if (lin <= 4 && col <=1){
                    MAT[lin][col] = 2;
                    MAT[lin][col+1] = 2;
                    MAT[lin][col+2] = 2;
                    MAT[lin][col+3] = 2;
                } else{
                    printf("Erro ao posicionar porta-avioes!\n");
                }
            break;
            
            case 3:
                if (MAT[lin][col] != 0){
                    printf("\nCampo ja ocupado\n");
                    break;
                } 
                if (lin <= 3 && col < 4){
                    MAT[lin][col] = 3;
                    MAT[lin][col+1] = 3;
                } else{
                    printf("Erro ao posicionar navio!\n");
                }
            break;
                
            default: 
               printf("Insira um numero valido!\n");
            break;
        }
    }
