/**@<mypas.c>::**/

/*
1:
*/

#include <stdio.h>
#include <stdlib.h>
#include <lexer.h>
#include <string.h>
#include <mypas.h>
#include <vmachine.h>
#define MAX_NUM_DE_COMANDOS 64 //para leitura_comandos
#define TAMANHO_MAX_DE_CADA_COMANDO 256 //para leitura_comandos
void leitura_comandos();
FILE *source_code;
char palavra_de_saida[] = "done";
extern int lookahead; // @ parser.c

int main (int argc, char *argv[], char *envp[])
{
  if (argc == 1) {
    //para remover o modo de leitura de comandos direto do terminal comente as 2 linhas seguintes e descomente a terceira linha seguinte
    leitura_comandos();
    source_code = fopen("comandos","r");
    //source_code = stdin;
  } else {
    source_code = fopen (argv[1], "r");
    if (source_code == NULL) {
      fprintf (stderr, "%s: cannot open %s... exiting\n",
      argv[0], argv[1]);
      exit (-1);
    }
  }

  lookahead = gettoken (source_code);
  // printf("||| lookahead: %c |||\n", lookahead);
  mypas ();

  printf("\n");

  exit (0);
}
void leitura_comandos()
{
  FILE* comandos;
  comandos = fopen("comandos","w+");
  int i=0,numero_de_comandos=-1;
  char entrada[MAX_NUM_DE_COMANDOS][TAMANHO_MAX_DE_CADA_COMANDO];
  printf("\nBem vindo ao MyPas!\n");
  printf("Digite os comandos e aperte enter.\nDigite '%s' para sair...\n\n",palavra_de_saida);

  do
  {
    numero_de_comandos++;
    scanf("%s",entrada[numero_de_comandos]);
  } while (strcmp(palavra_de_saida,entrada[numero_de_comandos]));

  do
  {
    fprintf(comandos,entrada[i]);
    if((i+1)!=numero_de_comandos)
    fprintf(comandos,"\n");
    i++;
  } while (i<numero_de_comandos);
  fclose(comandos);
  printf("____________________________________\n\n");

}
