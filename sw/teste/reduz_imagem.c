/***********************************************************
 * ....................................................... *
 * . Este Programa comprime uma imagem, reduzindo - a  a . *
 * . metade do seu tamanho original. Esta deve ser PPM e . *
 * . quadrada, podendo ou nao ser colorida................ *
 * . Adaptado do trabalho de: ............................ *
 * ......Aluno: Raphael De Bianchi Carvalho............... *
 * ......RA: 095041....................................... *
 * ......Matéria: MC920................................... *
 * ......Professor: Neucimar J. Leite..................... *
 * ......Trabalho: Coeficiente de Correlação de Pearson... *
 * ......Adaptação por : Marcus Botacin .................. *
 * ....................................................... *
 **********************************************************/

#include <stdlib.h>
#include <stdio.h> 
#include <math.h>
#include <string.h>
#include <malloc.h>

/* **************************************************************** */
/* Sem Alteração */

/*definem os em que linha e coluna e matrizL esta no intdice i*/
#define matlLin(m,i) (i / ((MatrizL *)m)->nc) 
#define matlCol(m,i) (i % ((MatrizL *)m)->nc)
/*define qual o indice da matrizL dado a linha e coluna*/
#define matlInd(m,l,c) (c + ((MatrizL *)m)->tblin[l])


/* Tipo abstrato Matriz (Implementação Linear): estrutura seqüencial e
   estática. */

typedef struct matrizl {
  int *info;   /* informação, vetor de inteiros */
  int nl,nc;    /* número de elementos na linha e na coluna, respectivamente*/
  int *tblin;   /* tabela de acesso rápido às linhas da matriz */
} MatrizL;


MatrizL *matlCria(int *nl, int *nc);//inicializa a matrizL dados nl(número de linhas) e nc (número de colunas)
void  matlDestroi(MatrizL *m);//libera a memŕia da matrizL m


/* **************************************************************** */

/* variaveis internas transformadas em ponteiro visando recuperar os dados do header da imagem */
MatrizL *LerImagem(char *arqimg,char *type,int *nc,int *nl,int *max);//le imagem PGM do tipo P5 ou P2 e retorna uma matrizL

/*sem alteração */

/* **************************************************************** */

double meanl(MatrizL *m);//calcula a média dos pixesl
double pcc (MatrizL *matl1, MatrizL *matl2);//calcula o coeficiente de correlação de Pearson


/* **************************************************************** */

/*Função principal usa os paremetros de argv[] para ler as duas imagens a ser comparada. As imagens tem 
 * que ter o mesmo numero de linhas e colunas. É utilizado a extenção .pgm para as imagens
*/
/*##############################################################################*/

/* função alterada para a nova finalidade */
/* argv[1] é a imagem de entrada */
/* argv[2] é a imagem de saida */

int main (int argc, char *argv[]){
    MatrizL *mat1;
	char type[10]; /* tipo passado como ponteiro para LerImagem */
	int nc,nl,max; /* tambem passado para ler imagem */
    mat1 = LerImagem (argv[1],type,&nc,&nl,&max); /*le a imagem e traz o header nos ponteiros */
      int i;

     

	//gravar no arquivo de saida

	/*abre o arquivo saida */	
	FILE *p;
	p=fopen(argv[2],"w");

	/* imprime o header para conferencia (pode descartar) */
	printf("type %s\t",type);
	printf("nc %d nl %d\n",nc/2,nl/2); //reduz a metade
	printf("max %d\n",max);

	/*imprime o novo header no arquivo saida */
	fprintf(p,"%s\n",type); //mesmo tipo de arquivo
	fprintf(p,"%d %d\n",nc/2,nl/2); //metade do tamanho
	fprintf(p,"%d\n",max); //mesma intensidade

	// uso para debug, desconsiderar
	//fprintf(p,"%s","P5 ");
	//fprintf(p,"%d ",mat1->nc);
	//fprintf(p,"%d ",mat1->nl);
	//fprintf(p,"%d\n",max);

	int nimp=0; //limita a 12 colunas por linha no arquivo saida
	int ncol,nlin; //conta numero de coluna e linha 
	
	//este for foi retirado do método pearson
	 for (i=0; i<((mat1->nc)*(mat1->nl)); i++){ //itera sobre todos os dados 

	//o trecho abaixo nao é utilizado nesta adaptação
	/* **************************************************************** */
	 // n = n + ((matl1->info[i] - m1)*(matl2->info[i] - m2));
	 // d1 = d1 + (pow(matl1->info[i]-m1,2));
	 // d2 = d2 + (pow(matl2->info[i]-m2,2));
	/* **************************************************************** */


	//no trecho abaixo se dá o calculo da média e a gravação no arquivo de saida */
	//algoritmo: calcular a média de um quadrado (4 pontos) e usar este como ponto unico
	//do novo arquivo (de saida). assim, reduz - se para a metade 

	ncol= i%mat1->nc; //supondo quadradas;
	nlin=i/mat1->nl; //calcula a linha e a coluna atual

	if(nlin%2==1) //deve estar na linha de baixo para pegar o quadrado acima
	{
		//deve ser o segundo da linha para formar o quadrado com  o anterior
		if(ncol%2==1) {
			if((nimp+1)%12==0) { //verificar se deu 12 colunas, insere espaço ou pula linha
	 		fprintf(p,"%d\n",(mat1->info[i]+mat1->info[i-1]+mat1->info[i-mat1->nl]+mat1->info[i-mat1->nl-1])/4);
			}else{
			fprintf(p,"%d ",(mat1->info[i]+mat1->info[i-1]+mat1->info[i-mat1->nl]+mat1->info[i-mat1->nl-1])/4);
			}
			//os calculos são o mesmo, apenas pula linha ou nao
			//o calculo é a média entre a posição atual, o anterior (lado esquerdo),
			// e os respectivos da linha acima

			nimp++;
		}
	}

      }




	
	fclose(p);
	//fim da gravacao
    matlDestroi(mat1);
    
return 0;    
}


/*##############################################################################*/
/*------------------------------------------------------------------------------*/
/*funcao alterada para calcular 3x o espaço alocado, assim considera imagens coloridas */
/* tambem troquei as variaveis locais por ponteiros */

MatrizL *matlCria(int *nl, int *nc) {
  MatrizL *ml = NULL;
  int i,j=0;
  
  if ( (ml = (MatrizL*) calloc(1,sizeof(MatrizL))) == NULL){ 
      printf("Erro\n");
      exit(-1);
  }
  else {
    
    if ( (ml->info = (int*)calloc(3*((*nl)*(*nc)),sizeof(int))) == NULL){
	printf("Erro\n");
	exit(-1);
    }
    
    if ( (ml->tblin =(int*) calloc(3*(*nl),sizeof(int))) == NULL){
	printf("Erro\n");
	exit(-1);
    }
    ml->nl=3*(*nl); ml->nc=(*nc);
    for (i=0; i<(3*(*nl)*(*nc)); i+=(*nc))
      ml->tblin[j++] = i;
  }
  return(ml);
}

/* funcao nao alterada */
/*------------------------------------------------------------------------------*/
void  matlDestroi(MatrizL *m) {
  if ( m == NULL )
    printf("Estrutura inexistente!\n");
  else {
    if (m->tblin == NULL)
      printf("Estrutura inexistente!\n");
    else
      free(m->tblin);
    if (m->info == NULL)
      printf("Estrutura inexistente!\n");
    else
      free(m->info);
    free(m);
  }
}

/* assim como criar, ponteiros e 3x o tamanho */
/*------------------------------------------------------------------------------*/
MatrizL *LerImagem(char *arqimg,char *type,int *nc,int *nl,int *max){
  int l,c;
  //char type[10];
  unsigned char *img;
  MatrizL *m;
  FILE *ent;
  //int max2;  
  /* ler imagem tipo P5 (PGM BINÁRIA) */

  ent = fopen(arqimg,"rb");
  fscanf(ent,"%s",type);
  fscanf(ent,"%d %d",nc,nl);
  fscanf(ent,"%d",max);
  if (strcmp(type,"P5") == 0){
      img = (unsigned char *) calloc(3*(*nl)*(*nc),sizeof(unsigned char));
      fread(img,3*(*nl)*(*nc),sizeof(unsigned char),ent);
      fclose(ent);
      
      /* copia para matriz */

      m = matlCria(nl,nc);
      for (l=0; l < 3*m->nl; l++)
	for (c=0; c < m->nc; c++)
	  m->info[matlInd(m,l,c)] = (int)img[matlInd(m,l,c)];
      free(img);
  }
  /*le imagem tipo P2 (PGM ASCII)*/
  else {
      m = matlCria(nl,nc);
      fgetc(ent);
      for (l=0; l < 3*m->nl; l++)
	for (c=0; c < m->nc; c++)
	    fscanf(ent,"%d",&m->info[matlInd(m,l,c)]);
  }
  
  return(m);
}


/* nao modificado e nao utilizado */
/*------------------------------------------------------------------------------*/
double meanl(MatrizL *m){
     double mean = 0.0;
     int i;
     
     for (i=0; i<((m->nc)*(m->nl)); i++){
	  mean = mean + m->info[i];
     }
     mean = mean / ((m->nc)*(m->nl));
     
return mean;
}


/* nao modificado e nao utilizado */
/*------------------------------------------------------------------------------*/
double pcc (MatrizL *matl1, MatrizL *matl2){
      double r, m1, m2, n, d1, d2;
      int i;
      
      n=0;
      d1=0;
      d2=0;
      
      m1 = meanl(matl1);      
      m2 = meanl(matl2);
      
      for (i=0; i<((matl1->nc)*(matl1->nl)); i++){
	  n = n + ((matl1->info[i] - m1)*(matl2->info[i] - m2));
	  d1 = d1 + (pow(matl1->info[i]-m1,2));
	  d2 = d2 + (pow(matl2->info[i]-m2,2));
      }
      r = n / ((sqrt(d1))*(sqrt(d2)));

return r;
}
/*------------------------------------------------------------------------------*/
