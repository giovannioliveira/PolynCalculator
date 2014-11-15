#include "polyn.h"

#define CALCULATE_VALUE 0
#define CALCULATE_ROOT 1
#define DERIVATE 2
#define SUM 3
#define ALL 4
#define EXIT 5

#define FALSE 0
#define TRUE 1

void UIcalculateValue();
void UIcalculateRoot();
void UIderivate();
void UIsum();
void UIall();
int repeatOperation();
polyn scanPolyn();

int main(){
	puts("Bem vindo a calculadora polinomial Polyn 1.0. Selecione uma das opções do menu a seguir:");
	menu:	
	puts("\nMenu de opções:");
	printf("%d -> Calcular o valor do polinômio para um dado valor de x\n", CALCULATE_VALUE);
	printf("%d -> Calcular as raízes do polinômio (para polinômios de 1º e 2º grau)\n", CALCULATE_ROOT);
	printf("%d -> Calcular a derivada do polinômio\n", DERIVATE);
	printf("%d -> Calcular a soma de dois polinômios\n", SUM);
	printf("%d -> Realizar as operações 0, 1, 2 e 3\n", ALL);
	printf("%d -> Sair do programa\n", EXIT);
	int opc;
	scanf("%d", &opc);
	switch(opc){
		case CALCULATE_VALUE:
			UIcalculateValue();
			goto menu;

		case CALCULATE_ROOT:
			UIcalculateRoot();
			goto menu;

		case DERIVATE:
			UIderivate();
			goto menu;


		case SUM:
			UIsum();
			goto menu;

		case ALL:
			UIall();
			goto menu;

		case EXIT:
			puts("Encerrando programa. Obrigado por usar Polyn ! - YWHW");
			return 0;
		default: 
			puts("Opção inválida. Por favor, escolha uma função válida.");
	}
}

void UIcalculateValue(){
	while(1){
		polyn p = scanPolyn();
		printf("P(x) = ");
		printPolyn(p);
		puts("Entre com o valor de x: ");
		float x;
		scanf("%f", &x);
		printf("\nP(%g) = %g\n", x, calculateValue(p,x));
		//ver função
		if(!repeatOperation()){
			return;
		}
	}
}

void UIcalculateRoot(){
	while(1){
		polyn p = scanPolyn();
		printf("P(x) = ");
		printPolyn(p);
		root r = solvePolyn(p);
		printRoot(r);
		//ver função
		if(!repeatOperation()){
			return;
		}
	}
}

void UIderivate(){
	while(1){
		polyn p = scanPolyn();
		printf("P(x) = ");
		printPolyn(p);
		p = derivatePolyn(p);
		printf("P'(x) = ");
		printPolyn(p);
		//ver função
		if(!repeatOperation()){
			return;
		}
	}
}

void UIsum(){
	while(1){
		polyn p = initPolyn();
		puts("\nEntre com o primeiro polinômio a ser somado, separando coeficiente e expoente por espaço. Ex.: 2x² deve ser escrito 2 2. Obs.: 0 0 encerra o modo de entrada: ");
		p = scanTo(p);
		printf("P(x) = ");
		printPolyn(p);
		polyn p2 = initPolyn();
		puts("\nEntre com o segundo polinômio a ser somado: ");	
		p2 = scanTo(p2);
		printf("Q(x) = ");
		printPolyn(p2);
		printf("\nP(x) + Q(x) = ");
		p = sumPolyn(p,p2);
		printPolyn(p);	
		//ver função
		if(!repeatOperation()){
			return;
		}
	}
}

void UIall(){
	while(1){
		float x1 = 0;
		float x2 = 0;
		polyn p = initPolyn();
		puts("\nEntre com o primeiro polinômio que deseja operar, separando coeficiente e expoente por espaço. Ex.: 2x² deve ser escrito 2 2. Obs.: 0 0 encerra o modo de entrada: ");
		p = scanTo(p);
		printf("P(x) = ");
		printPolyn(p);
		puts("\nEntre com o valor de x para P(x): ");
		scanf("%f", &x1);
		polyn p2 = initPolyn();
		//variável que indicia se há um segundo polinômio para operar
		int has2 = 0;
		//loop que verifica se há um segundo polinômio para operar
		while(1){
			char c;
			printf("\nDeseja realizar a operação com outro polinômio (s/n)? ");
			scanf("%c", &c);
			scanf("%c", &c);
			if(c == 's'){
				puts("\nEntre com o segundo polinômio que deseja operar: ");	
				p2 = scanTo(p2);
				printf("Q(x) = ");
				printPolyn(p2);
				puts("\nEntre com o valor de x para Q(x): ");
				scanf("%f", &x2);
				//seta em 1 a variável que indica se há um segundo polinômio para operar
				has2 = TRUE;
				break;
			}else if(c == 'n'){
				//não que a variável que indica se há um segundo polinômio para operar, que permanece xom 0
				break;
			}else{
				puts("Opção inválida. Por favor, escolha uma opção válida.");
			}
		}
		printf("\nP(%g) = %g\n", x1, calculateValue(p,x1));
		polyn aux = derivatePolyn(p);
		printf("P'(x) = ");
		printPolyn(aux);
		root r = solvePolyn(p);
		printf("Raiz de P(x): ");
		printRoot(r);	
		//se há um segundo polinômio para operar
		if(has2){
			printf("\nQ(%g) = %g\n", x2, calculateValue(p2,x2));
			aux = derivatePolyn(p2);
			printf("Q'(x) = ");
			printPolyn(aux);
			root r2 = solvePolyn(p2);
			printf("Raiz de Q(x): ");
			printRoot(r2);	
			//retorna a soma dos dois polinômios
			printf("\nP(x) + Q(x) = ");
			p = sumPolyn(p,p2);
			printPolyn(p);		
		}
		//ver função
		if(!repeatOperation()){
			return;
		}
	}
}

//essa função verifica se o usuário deseja realizar novamente a última operação com outros valores de entrada
int repeatOperation(){
	while(1){
		char c;
		printf("\nDeseja realizar a operação novamente com outro outros valores de entrada (s/n)? ");
		scanf("%c", &c);
		scanf("%c", &c);
		if(c == 's'){
			return TRUE;
		}else if(c == 'n'){
			return FALSE;
		}else{
			puts("\nOpção inválida. Por favor, escolha uma opção válida.");
		}
	}
}

polyn scanPolyn(){
	polyn p = initPolyn();
	puts("\nEntre com o polinômio que deseja operar, separando coeficiente e expoente por espaço. Ex.: 2x² deve ser escrito 2 2. Obs.: 0 0 encerra o modo de entrada: ");
	p = scanTo(p);
	return p;
}
