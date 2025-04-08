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
