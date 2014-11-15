#include <stdio.h>
#include <locale.h>
#include "polyn.h"

//constante de inicialização de Polyn
#define INITIAL_COEF_VALUE 0
#define FALSE 0
#define TRUE 1

//prototipo de funções privadas

/* 
Descricao: imprime um termo do polinômio com sinal obrigatório
Entrada: coeficiente e expoente do termo, respectivamente
Saida: termo do polinômio legível na interface de saída
Restrições:
*/
void printTerm(float c, int e, int isFirst);

/* 
Descricao: quebra a linha da interface de saída 
Entrada: 
Saida: 
Restrições:
*/
void breakLine();

/* 
Descricao: retorna a potência de "a" elevado a "b"
Entrada: base "a" e expoente "b"
Saida: potência de "a" elevado a "b"
Restrições: "b" deve ser um Natural
*/
float restrictedPow(float a, int b);

/* 
Descricao: retorna a raiz quadrada de x
Entrada: x
Saida: raiz quadrada de x
Restrições: x deve ser um Real não negativo
*/
float sqrt(const float x);

//funções de inicialização

polyn initPolyn(){
	polyn p;
	p.x0=INITIAL_COEF_VALUE;
	p.x1=INITIAL_COEF_VALUE;
	p.x2=INITIAL_COEF_VALUE;
	p.x3=INITIAL_COEF_VALUE;
	p.x4=INITIAL_COEF_VALUE;
	p.x5=INITIAL_COEF_VALUE;
	p.x6=INITIAL_COEF_VALUE;
	p.x7=INITIAL_COEF_VALUE;
	p.x8=INITIAL_COEF_VALUE;
	p.x9=INITIAL_COEF_VALUE;
	return p;
}

root initRoot(){
	root r;
	r.r1=0;
	r.r2=0;
	r.status=0;
	return r;
}

//funções de I/O

polyn scanTo(polyn p){
	while(1){
		float coef=0;
		int exp=0;
		scanf("%f %d",&coef,&exp);	
		if(coef==0&&exp==0){
			return p;
		}else if(coef==0||exp>9||exp<0){
			//invalida a entrada caso o termo possua grau 0 ou o expoente do termo seja menor que 0 ou maior que 9
			puts("Entrada inválida.");
		}else{
			//soma o coeficiente de entrada com o que já havia no polinômio
			p = setCoef(p,exp,(getCoef(p,exp)+coef));
		}
	}
}

void printPolyn(polyn p){
	int biggerExp=getBiggerExp(p);	
	//printa o primeiro termo com sinal só se for negativo
	printTerm(getCoef(p,biggerExp),biggerExp,TRUE);
	int i;
	for(i=biggerExp-1; i>=0; i--){
		//printa os demais termos sempre com sinal, seja positivo ou negativo
		printTerm(getCoef(p,i),i,FALSE);
	}
	breakLine();
	return;
}

void printTerm(float c, int e, int isFirst){
	if(c==0&&!isFirst){
		return;
	}
	//o primeiro termo do polinômio a ser printado só exibe seu sinal se for negativo
	if(isFirst){
		//printa somente o coeficiente de x^0
		if(e==0){
			printf("%g",c);
		//printa o termo no formato cx, e omite c se for igual a 1
		}else if(e==1){
			if(c==1){
				printf("x");
			}else if(c==-1){
				printf("-x");
			}else{
				printf("%gx",c);
			}
		//printa o termo no formato cx^e, e omite c se for igual a 1
		}else{
			if(c==1){
				printf("x^%d",e);
			}else if(c==-1){
				printf("-x^%d",e);
			}else{
				printf("%gx^%d",c,e);
			}
		}
	//mesma lógica do caso anterior, mas printa sempre o sinal do coeficiente do termo
	}else{
		if(e==0){
			printf("%+g",c);
		}else if(e==1){
			if(c==1){
				printf("+x");
			}else if(c==-1){
				printf("-x",e);
			}else{
				printf("%+gx",c);
			}
		}else{
			if(c==1){
				printf("+x^%d",e);
			}else if(c==-1){
				printf("-x^%d",e);
			}else{
				printf("%+gx^%d",c,e);
			}
		}
	}
	return;
}

void printRoot(root r){
	//indica que houve uma falha no cálculo da raiz
	if(r.status==0){
		puts("Esta operação não está definida para o grau desse polinômio ou não há soluções reais.");
		return;
	}else if(r.r1==r.r2){	
		//caso haja apenas uma raiz
		printf("S={(%g,0)}\n",r.r1);
	}else{
		//caso haja duas raízes
		printf("S={(%g,0),(%g,0)}\n",r.r1,r.r2);
	}
}

void breakLine(){
	printf("\n");
}

//getter e setter de Polyn

float getCoef(polyn p, int exp){
	switch(exp){
                        case 0:
                                return p.x0;
                        case 1:
                                return p.x1;
                        case 2:
				return p.x2;
                        case 3:
                               	return p.x3;
                        case 4:
                                return p.x4;
                        case 5:
                                return p.x5;
                        case 6:
                                return p.x6;
                        case 7:
                                return p.x7;
                        case 8:
                                return p.x8;
                        case 9:
                                return p.x9;
			default:
				return 0;
	}
}

polyn setCoef(polyn p, int exp, float value){
	switch(exp){
	                case 0:
                                p.x0=value;
                                return p;
                        case 1:
                                p.x1=value;
                                return p;
                        case 2:
                                p.x2=value;
                                return p;
                        case 3:
                                p.x3=value;
                                return p;
                        case 4:
                                p.x4=value;
                                return p;
                        case 5:
                                p.x5=value;
                                return p;
                        case 6:
                                p.x6=value;
                                return p;
                        case 7:
                                p.x7=value;
                                return p;
                        case 8:
                                p.x8=value;
                                return p;
                        case 9:
                                p.x9=value;
                                return p;
			default:
				return p;
	}
}

//funções matemáticas polinomiais

int getBiggerExp(polyn p){
	int i;	
	for(i=9;i>0;i--){
		int coef=getCoef(p,i);
		if(coef){
			return i;
		}
	}
	return 0;
}

float calculateValue(polyn p, float x){
	float result=0;
	int i;
	//começa a substituição do maior termo do polinômio, para economizar ciclos de máquina
	for(i=getBiggerExp(p);i>=0;i--){
		result+=getCoef(p,i)*(restrictedPow(x,i));
	}
	return result;
}

polyn derivatePolyn(polyn p){

	int biggerExp=getBiggerExp(p);
	int i;	
	for(i=1;i<=biggerExp;i++){
		p = setCoef(p,i-1,getCoef(p,i)*i);
		//zera o maior termo do poinômio após derivá-lo
		if(i==biggerExp){
			p = setCoef(p,i,0);
		}
	}

	return p;	
}

polyn sumPolyn(polyn p, polyn p2){
	int i;
	//soma os coeficientes de um polinômio termo a termo começando do primeiro (x^0)
	for(i=0;i<10;i++){
		p = setCoef(p,i,getCoef(p,i)+getCoef(p2,i));
	}
	return p;
}
//resolve o polinômio se for de primeiro ou segundo grau
root solvePolyn(polyn p){
	root r = initRoot();
	int biggerExp = getBiggerExp(p);
	if(biggerExp==1){
		float root = -getCoef(p,0)/getCoef(p,1);
		r.r1 = root;
		r.r2 = root;
		r.status = 1;
	}else if(biggerExp==2){
		float a = getCoef(p,2);
		float b = getCoef(p,1);
		float c = getCoef(p,0);
		//calcula fórmula de bhaskara
		float delta = restrictedPow(b,2)-4*a*c;
		//só executa se delta for maior ou igual a zero, o que indica que há raiz(es) real(ais)
		if(delta>=0){
			r.r1 = (-b+sqrt(delta))/(2*a);
			r.r2 = (-b-sqrt(delta))/(2*a);
			r.status = 1;
		}
	}
	return r;
}

//funções matemáticas simples

float sqrt(const float x){
	//algoritmo que calcula uma aproximação para raiz quadrada
	if(x==0){
		return 0;	
	}
	int i=0; 
	while((i*i) <= x)
		i++;
	i--; 
	float p = (x-i*i)/(2*i); 
	float a = i+p; 
   	return a-(p*p)/(2*a);
} 

//função que só permite expoentes inteiros maiores ou iguais a 0
float restrictedPow(float a, int b){		
	float result = 1;
	while(b>0){
		result*=a;
		b--;
	}	
	return result;
}
