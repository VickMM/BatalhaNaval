#include <iostream>

//protótipos das funções, assinaturas ou cabeçalhos (o mais comum é assinatura)

void zerarCampoBatalha(void);
void exibirCampoBatalha(void);
void posicionarObj(int tipoObj, int lin, int col);
void lancarMissel(int lin, int col);
void verificaVida(int obj);

int MAT[5][5];
int vidaSub = 4;
int vidaPA = 4;
int qtdMissel = 15;

int main(){
	zerarCampoBatalha();
	verificaVida(1);
	verificaVida(2);
	exibirCampoBatalha();
	
	int linha;
	int coluna;
	int tipo;
	int resposta;
	int qtdMissel;
	int missel;
	int count = 4;
	
	printf("Deseja iniciar o jogo? Digite 1 - SIM ou 0 - NAO: ");
	scanf("%i", &resposta);
	
	while(resposta == 1 && count <=4 && count > 0){
		
		printf("Batalha naval - personagens | 1- SUBMARINO, 2- PORTA AVIOES, 3- NAVIO\n");
		printf("SUBMARINOS: 4 | PORTA AVIOES: 4 | MISSEIS: 15\n");
		
		printf("\nInforme o personagem: "); 
		scanf("%i", &tipo);
		printf("Informe a linha: ");
		scanf("%i", &linha);
		printf("Informe a coluna: ");
		scanf("%i", &coluna);
		posicionarObj(tipo, linha, coluna);
		exibirCampoBatalha();
		printf("Lance um missel! Informe uma linha: \n");
		scanf("%i", &linha);
		printf("Agora informe uma coluna: \n");
		scanf("%i", &coluna);
		lancarMissel(linha, coluna);
		exibirCampoBatalha();
		verificaVida(1);
		verificaVida(2);
		count--;
		
		printf("Deseja continuar o jogo? Digite 1 - SIM ou 0 - NAO: ");
		scanf("%i", &resposta);
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
			//exibindo a matriz	
		for (int lin=0; lin<=4; lin++){
			for (int col=0; col<=4; col++){
				printf("%i", MAT[lin][col]);
			}
			printf("\n");		
		}
			 	
		printf("\n\n");
	}
    
    void posicionarObj(int tipoObj, int lin, int col){
    	
    	switch (tipoObj){
    		case 1:
    			if (lin != 0 && col != 0){
					printf("Campo ja ocupado!\n");
    			}else{
    				if (lin > 0 && lin <= 4 && col < 3){
    				MAT[lin][col] = 1;
    				MAT[lin][col+1] = 1;
					MAT[lin][col+2] = 1;
					MAT[lin-1][col+1]=1;
				} else{printf("Erro ao posicionar submarino!\n");}
				}
				
			break;
    		
    		case 2: 
    		    if (lin != 0 && col != 0){
					printf("Campo ja ocupado!\n");
    			}else{
    				if (lin <= 4 && col <=1){
    		    	MAT[lin][col] = 2;
    		    	MAT[lin][col+1] = 2;
    		    	MAT[lin][col+2] = 2;
    		    	MAT[lin][col+3] = 2;
				} else{printf("Erro ao posicionar porta-avioes!\n");}
				}
    		    
			break;
    		
    		case 3:
    			if (lin != 0 && col != 0){
					printf("Campo ja ocupado!\n");
    			}else{
    				if (lin <= 3 && col < 4){
    				MAT[lin][col] = 3;
    				MAT[lin][col+1] = 3;
				} else{printf("Erro ao posicionar navio!\n");}
				}
    			
			break;
    			
    		default: 
    		   printf("Insira um numero valido!\n");
    		break;
		}
	}
    void lancarMissel(int lin, int col){
    	qtdMissel=qtdMissel - 1;
    	if(MAT[lin][col] == 9){
    		printf("Voce acertou uma area ja destruida!\n");
		}else {
			if(MAT[lin][col] == 0){
			printf("***Agua!***\n\n");
			}else{	
				if(MAT[lin][col] == 1){
    				printf("Voce acertou parte do submarino!\n");
    				vidaSub--;
				} else{
					printf("Voce acertou parte do porta avioes!\n");
					vidaPA--;
					}
					MAT[lin][col]=9;		
				}
			}				
		}	
	void verificaVida(int obj){
		if(obj == 1){
			if(vidaSub == 0){
			   printf("Submarino totalmente destruido\n");	
			} else{
			   printf("Vida submarino = %d\n", vidaSub);	
			}   	   
		}
		else{
			if(vidaPA == 0){
			   printf("Porta avioes totalmente destruido\n");	
			} else{
			   printf("Vida porta avioes = %d\n", vidaPA);	
			}   	   
		}
	}
