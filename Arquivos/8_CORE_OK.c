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


#define ADDR (10*1024*1024)
#define DEV_ADDR (20*1024*1024)

    	

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


void filter()
{
	int i;
	for(i=0;i<10;i++)
	{
		//filtering
	}
}


volatile int *lock=ADDR;
  volatile int *dev=DEV_ADDR;

	MatrizL *mat1;
	char type[10]; /* tipo passado como ponteiro para LerImagem */
	int nc,nl,max; /* tambem passado para ler imagem */
	FILE *p;
	int count=1;
	int *data1,*data2,*data3,*data4,*data5,*data6,*data7,*data8;
	int end1=0,end2=0,end3=0,end4=0,end5=0,end6=0,end7=0,end8=0;
/* **************************************************************** */

/*Função principal usa os paremetros de argv[] para ler as duas imagens a ser comparada. As imagens tem 
 * que ter o mesmo numero de linhas e colunas. É utilizado a extenção .pgm para as imagens
*/
/*##############################################################################*/

/* função alterada para a nova finalidade */
/* argv[1] é a imagem de entrada */
/* argv[2] é a imagem de saida */

int main (int argc, char *argv[]){
	int me;
	int i,lim;

	while(*lock);
	me=count;
  	printf("proc %d\n",count);
  	count++;
  	*lock=0;
	//exit(0);




	if(*lock==0)
	{
		if(!p) {
		printf("%d pegou o lock e vai abrir arquivo\n",me);
		

	if(argc!=3)
	{
		printf("erro nos parametros\n");
		exit(0);
	}
	//printf("comecou\n");


    	mat1 = LerImagem (argv[1],type,&nc,&nl,&max); /*le a imagem e traz o header nos ponteiros */
	//printf("leu matriz\n");
	//exit(0);


	data1=(int*)malloc((nc/2)*(nl/2)*3*sizeof(int));
	if(data1==NULL)
	{
		printf("nao alocou\n");
	}
	data2=(int*)malloc((nc/2)*(nl/2)*3*sizeof(int));
	if(data2==NULL)
	{
		printf("nao alocou\n");
	}
	data3=(int*)malloc((nc/2)*(nl/2)*3*sizeof(int));
	if(data3==NULL)
	{
		printf("nao alocou\n");
	}
	data4=(int*)malloc((nc/2)*(nl/2)*3*sizeof(int));
	if(data4==NULL)
	{
		printf("nao alocou\n");
	}
 	data5=(int*)malloc((nc/2)*(nl/2)*3*sizeof(int));
	if(data5==NULL)
	{
		printf("nao alocou\n");
	}    
	data6=(int*)malloc((nc/2)*(nl/2)*3*sizeof(int));
	if(data6==NULL)
	{
		printf("nao alocou\n");
	}
	data7=(int*)malloc((nc/2)*(nl/2)*3*sizeof(int));
	if(data7==NULL)
	{
		printf("nao alocou\n");
	}
	data8=(int*)malloc((nc/2)*(nl/2)*3*sizeof(int));
	if(data8==NULL)
	{
		printf("nao alocou\n");
	}


	//gravar no arquivo de saida

	/*abre o arquivo saida */	
	p=fopen(argv[2],"w");

	/* imprime o header para conferencia (pode descartar) */
	//printf("type %s\n",type);
	//printf("nc %d nl %d\n",nc/2,nl/2); //reduz a metade
	//printf("max %d\n",max);

	/*imprime o novo header no arquivo saida */
	fprintf(p,"%s\n",type); //mesmo tipo de arquivo
	fprintf(p,"%d %d\n",nc/2,nl/2); //metade do tamanho
	fprintf(p,"%d\n",max); //mesma intensidade

	// uso para debug, desconsiderar
	//fprintf(p,"%s","P5 ");
	//fprintf(p,"%d ",mat1->nc);
	//fprintf(p,"%d ",mat1->nl);
	//fprintf(p,"%d\n",max);
	}


	*lock = 0; //libera lock
	} //fim do lock -> escreveu o header

	while(*lock); //para garantir que esperou o outro
	if(me==1)
	{
	i=0;lim=((mat1->nc)*(mat1->nl))/8;
	}
	if(me==2)
	{
	i=((mat1->nc)*(mat1->nl))/8;
	lim=2*((mat1->nc)*(mat1->nl))/8;
	}
	if(me==3)
	{
	i=2*((mat1->nc)*(mat1->nl))/8;
	lim=3*((mat1->nc)*(mat1->nl))/8;
	}
	if(me==4)
	{
	i=3*((mat1->nc)*(mat1->nl))/8;
	lim=4*((mat1->nc)*(mat1->nl))/8;
	}
	if(me==5)
	{
	i=4*((mat1->nc)*(mat1->nl))/8;
	lim=5*((mat1->nc)*(mat1->nl))/8;
	}
	if(me==6)
	{
	i=5*((mat1->nc)*(mat1->nl))/8;
	lim=6*((mat1->nc)*(mat1->nl))/8;
	}
	if(me==7)
	{
	i=6*((mat1->nc)*(mat1->nl))/8;
	lim=7*((mat1->nc)*(mat1->nl))/8;
	}
	if(me==8)
	{
	i=7*((mat1->nc)*(mat1->nl))/8;
	lim=8*((mat1->nc)*(mat1->nl))/8;
	}





	printf("%d vai pegar data com i= %d e lim= %d\n",me,i,lim);
	*lock=0;


	int nmatriz=0;
	int nimp=0; //limita a 12 colunas por linha no arquivo saida
	int ncol,nlin; //conta numero de coluna e linha 

	//printf("escreveu header.agora data\n");
	
	//este for foi retirado do método pearson
	 for (; i<lim; i++){ //itera sobre todos os dados 

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


	filter();
	//int lol=0;
	//for(;lol<5;lol++);

	if(nlin%2==1) //deve estar na linha de baixo para pegar o quadrado acima
	{
		//deve ser o segundo da linha para formar o quadrado com  o anterior
		if(ncol%2==1) {
			while(*lock);
			*dev=mat1->info[i];
			*dev=mat1->info[i-1];
			*dev=mat1->info[i-mat1->nl];
			*dev=mat1->info[i-mat1->nl-1];
			/*if((nimp+1)%12==0) { //verificar se deu 12 colunas, insere espaço ou pula linha
	 			fprintf(p,"%d\n",*dev);
			}else{
				fprintf(p,"%d ",*dev);
			}*/
			if(me==1)
			{
				data1[nmatriz]=*dev;
			}else if(me==2){
				data2[nmatriz]=*dev;
			}else if(me==3){
				data3[nmatriz]=*dev;
			}else if(me==4){
				data4[nmatriz]=*dev;
			}else if(me==5){
				data5[nmatriz]=*dev;
			}else if(me==6){
				data6[nmatriz]=*dev;
			}else if(me==7){
				data7[nmatriz]=*dev;
			}else{
				data8[nmatriz]=*dev;
			}



			*lock=0;
			nmatriz++;
			//os calculos são o mesmo, apenas pula linha ou nao
			//o calculo é a média entre a posição atual, o anterior (lado esquerdo),
			// e os respectivos da linha acima

			nimp++;
		}
	}

      }

	
	while(*lock);
	printf("%d chegou\n",me);
	if(me==1) 	end1=1;
	if(me==2) 	end2=1;
	if(me==3)	end3=1;
	if(me==4)	end4=1;
	if(me==5)	end5=1;
	if(me==6)	end6=1;
	if(me==7)	end7=1;
	if(me==8)	end8=1;
	*lock=0;
	
	if(me==2 && end1==end2==end3==end4==end5==end6==end7==end8==1)
	{
		printf("sucesso\n");
		int tam = (((mat1->nc)*(mat1->nl)))/32;
		int s;
		for(s=0;s<tam;s++)
                {
                        if((s+1)%12==0)
                        {
                                fprintf(p,"%d\n",data1[s]);
                        }else{
                                fprintf(p,"%d ",data1[s]);
                        }
                }
		for(s=0;s<tam;s++)
                {
                        if((s+1)%12==0)
                        {
                                fprintf(p,"%d\n",data2[s]);
                        }else{
                                fprintf(p,"%d ",data2[s]);
                        }
                }	
		for(s=0;s<tam;s++)
                {
                        if((s+1)%12==0)
                        {
                                fprintf(p,"%d\n",data3[s]);
                        }else{
                                fprintf(p,"%d ",data3[s]);
                        }
                }
		for(s=0;s<tam;s++)
                {
                        if((s+1)%12==0)
                        {
                                fprintf(p,"%d\n",data4[s]);
                        }else{
                                fprintf(p,"%d ",data4[s]);
                        }
                }
		for(s=0;s<tam;s++)
                {
                        if((s+1)%12==0)
                        {
                                fprintf(p,"%d\n",data5[s]);
                        }else{
                                fprintf(p,"%d ",data5[s]);
                        }
                }
		for(s=0;s<tam;s++)
                {
                        if((s+1)%12==0)
                        {
                                fprintf(p,"%d\n",data6[s]);
                        }else{
                                fprintf(p,"%d ",data6[s]);
                        }
                }
		for(s=0;s<tam;s++)
                {
                        if((s+1)%12==0)
                        {
                                fprintf(p,"%d\n",data7[s]);
                        }else{
                                fprintf(p,"%d ",data7[s]);
                        }
                }
		for(s=0;s<tam;s++)
                {
                        if((s+1)%12==0)
                        {
                                fprintf(p,"%d\n",data8[s]);
                        }else{
                                fprintf(p,"%d ",data8[s]);
                        }
                }

		fclose(p);
	}

	exit(0);

/*
	while(1)
	{

	//precisa fazer um novo fim, esse supoe que o proc1 sempre termina antes
	while(*lock);
	//printf("%d chegou primeiro\n",me);
	if(me==end+1)
	{
		end++;

	if(me==1)
	{
		int s=0;
		for(s=0;s<nmatriz;s++)
		{
			if((s+1)%12==0)
			{
				fprintf(p,"%d\n",data1[s]);
			}else{
				fprintf(p,"%d ",data1[s]);
			}
		}

		
		*lock=0;
	}

	if(me==2)
	{
		int s=0;
		for(s=0;s<nmatriz;s++)
		{
			if((s+1)%12==0)
			{
				fprintf(p,"%d\n",data2[s]);
			}else{
				fprintf(p,"%d ",data2[s]);
			}
		}

		

		*lock=0;
	}

	if(me==3)
	{
		int s=0;
		for(s=0;s<nmatriz;s++)
		{
			if((s+1)%12==0)
			{
				fprintf(p,"%d\n",data3[s]);
			}else{
				fprintf(p,"%d ",data3[s]);
			}
		}
		*lock=0;
	}

	if(me==4)
	{
		int s=0;
		for(s=0;s<nmatriz;s++)
		{
			if((s+1)%12==0)
			{
				fprintf(p,"%d\n",data4[s]);
			}else{
				fprintf(p,"%d ",data4[s]);
			}
		}
		*lock=0;
	}
	if(me==5)
	{
		int s=0;
		for(s=0;s<nmatriz;s++)
		{
			if((s+1)%12==0)
			{
				fprintf(p,"%d\n",data5[s]);
			}else{
				fprintf(p,"%d ",data5[s]);
			}
		}
		*lock=0;
	}
	if(me==6)
	{
		int s=0;
		for(s=0;s<nmatriz;s++)
		{
			if((s+1)%12==0)
			{
				fprintf(p,"%d\n",data6[s]);
			}else{
				fprintf(p,"%d ",data6[s]);
			}
		}
		*lock=0;
	}

	if(me==7)
	{
		int s=0;
		for(s=0;s<nmatriz;s++)
		{
			if((s+1)%12==0)
			{
				fprintf(p,"%d\n",data7[s]);
			}else{
				fprintf(p,"%d ",data7[s]);
			}
		}
		*lock=0;
	}


	//parte de terminar é complicada, por hora vou fechar só
	//printf("acabou data \n");
	if(me==8)
	{
		int s=0;
		for(s=0;s<nmatriz;s++)
		{
			if((s+1)%12==0)
			{
				fprintf(p,"%d\n",data2[s]);
			}else{
				fprintf(p,"%d ",data2[s]);
			}
		}
		fclose(p);
		//fim da gravacao
		//printf("fechou arquivo\n");
		free(data1);
		free(data2);
		free(data3);
		free(data4);
		free(data5);
		free(data6);
		free(data7);
		free(data8);


		
	    	matlDestroi(mat1);

		*lock=0;
		exit(0);
	} //IF == 8
	}else { *lock=0;
		filter();
	
	 } //IF
	} //WHILE

*/
	//printf("matou matriz\n");
   
exit(0); 
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
 // printf("abriu arquivo\n");
  fscanf(ent,"%s",type);
  fscanf(ent,"%d %d",nc,nl);
  fscanf(ent,"%d",max);
  //printf("leu entradas\n");
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
     // printf("to no else\n");
      m = matlCria(nl,nc);
     // printf("criou matriz\n");
      fgetc(ent);
     // printf("pegou char\n");
     // printf("linha %d\n",m->nl);
     // printf("coluna %d\n",m->nc);
	//int cont=0;	
      for (l=0; l < 3*m->nl; l++)
      {
	for (c=0; c < m->nc; c++)
	{
	    //printf("vai ler\n");
	    fscanf(ent,"%d",&m->info[matlInd(m,l,c)]);
		//if(cont%1000==0)
	    //printf("parou no scanf %d\n",cont);
	 	//cont++;
	}
      }
  }
  //printf("saiu do for\n");
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
