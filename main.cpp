#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define N 1


 struct cadastroProduto{
  
  int codigoProduto, qtdEstoque, valorEstoque;
  char nomeProduto[50];
  float valorCusto, valorVenda;
  int status;  // 0 == INATIVO // 1 == ATIVO
  
 };



 
 //Declaracao de variaveis
  
  int cod;
  int i;
  int ini = 0;
  cadastroProduto p[10];
  int op;     //variavel para escolha de opções do menu      //
  int c = 1;    // variavel para o programa ficar em looping infinito até que seja escolhida a opçao sair
 


 void menu(){
  
  printf("##############################\n");
  printf("\nMenu: \n\n");
  printf("1 - Incluir \n");
  printf("2 - Alterar \n");
  printf("3 - Excluir \n");
  printf("4 - Imprimir na tela \n");
  printf("5 - Sair\n");
  printf("6 - Ajustar o valor de venda(em %%)\n");
  printf("7 - Mostrar o valor total do estoque");
  printf("\n\n##############################");
  printf("\nDigite uma opcao: ");
  scanf("%d", &op);
  
 }
 
 void incluir(){
  
  system("cls");
    printf("<INCLUIR>\n\n");
    printf("Digite os dados do  produto\n\n");
    
   for(i=0; i<N; i++)
   {
    printf("Codigo: ");
    scanf("%d", &p[ini].codigoProduto);
    fflush(stdin);
    printf("Nome do produto: ");
    gets(p[ini].nomeProduto);
    fflush(stdin);
    printf("Valor de custo: ");
    scanf("%f", &p[ini].valorCusto);
    fflush(stdin);
    printf("Valor de venda: ");
    scanf("%f", &p[ini].valorVenda);
    fflush(stdin);
    printf("Quantidade em estoque: ");
    scanf("%d", &p[ini].qtdEstoque);
    fflush(stdin);
    
    //p[i].valorEstoque = p[i].valorCusto*p[i].qtdEstoque;
    p[ini].status = 1;
    ini++;
   
    printf("Cadastrado com sucesso!\n\n", "OK");
    system("cls");
   }
  
 }
 
 void alterar(){
  
  system("cls");
    
    printf("\n");
    printf("<ALTERAR> \n");
    printf("Digite o codigo do produto que sera alterado: ");
    scanf("%d", &cod);
    
    
   for(i=0; i<ini; i++){
   // printf("STATUS %d", p[ini].status);
    if(p[i].codigoProduto == cod){
    printf("Informe os novos dados do produto\n");
    printf("Novo Codigo: ");
    scanf("%d", &p[i].codigoProduto);
    fflush(stdin);
    printf("Novo nome do produto: ");
    gets(p[i].nomeProduto);
    fflush(stdin);
    printf("Novo valor de custo: ");
    scanf("%f", &p[i].valorCusto);
    fflush(stdin);
    printf("Novo valor de venda: ");
    scanf("%f", &p[i].valorVenda);
    fflush(stdin);
    printf("Nova quantidade em estoque: ");
    scanf("%d", &p[i].qtdEstoque);
    fflush(stdin);
    
    
   
    
    printf("Alterado com sucesso!\n\n", "OK");
    system("cls");
  }
   if(p[i].codigoProduto != cod){
    printf("O Codigo informado nao consta no registro.\n\n");
    }

   }
  
 }
 
 void excluir(){
  
   system("cls");
   printf("<EXCLUIR> \n");
    printf("Digite o codigo do produto que sera excluido: ");
     scanf("%d", &cod);
    
    for(i=0; i<ini; i++){
     if(p[i].codigoProduto == cod){
     p[i].status = 0;

    printf("\n\n");
     }
    }
  
 
   printf("Registro excluido com sucesso!\n\n", "OK");
   system("cls");
  
  
 }
 
 
 void imprimir(){
  
  system("cls");
   printf("<IMPRIMIR> \n");
    for(i=0; i<ini; i++){
     if(p[i].status == 1){
    printf("Dados do produto: \n");
    printf("\nCodigo do produto: %d", p[i].codigoProduto);
    printf("\nNome do produto: %s", p[i].nomeProduto);
    printf("\nValor de custo: R$ %.2f", p[i].valorCusto);
    printf("\nValor de venda: R$ %.2f", p[i].valorVenda);
    printf("\nQuantidade em estoque: %d", p[i].qtdEstoque);
    printf("\nValor do estoque: R$ %.2f", p[i].valorCusto*p[i].qtdEstoque);
    printf("\n");
     if(p[i].status < 1){
     printf("\n<vazio>\n");
    }
     
    }
    
  }
  /*
  for(i=0; i<ini; i++){
     if(p[i].status == 1){
    printf("\nValor total do estoque: R$ %.2f", p[i].totalEstoque);
    printf("\n");
     if(p[i].status < 1){
     printf("\n<vazio>\n");
    }
     
    }
   
  }
  */
    printf("\nAperte qualquer tecla para sair.");
   getch();
   system("cls");
  
  
 }
 
 
 void sair(){
  
  exit(1);
 }
 
void alterarValorVenda(){
  
  float porcAlt;
  int escolha;
  
  printf("\n");
    printf("<ALTERAR VALOR DE VENDA> \n");
    printf("Digite o codigo do produto que sera alterado: ");
    scanf("%d", &cod);
    
    
   for(i=0; i<ini; i++){
   // printf("STATUS %d", p[ini].status);
    if(p[i].codigoProduto == cod){
    printf("Informe os novos dados do produto com o codigo %d\n", cod);
    printf("Reajustar o valor de venda em quantos %% ?: ");
    scanf("%f", &porcAlt);
    porcAlt = porcAlt/100;
    
    printf("Aumentar ou reduzir em %d %% ?\n", porcAlt);
    printf("1 - Aumentar\n");
    printf("2 - Reduzir\n");
    scanf("%d", &escolha);
    
    switch (escolha){
    
    case 1:
   
    p[i].valorVenda = p[i].valorVenda + p[i].valorVenda*porcAlt;
    
    break;
    
    case 2:
     
    p[i].valorVenda = p[i].valorVenda - p[i].valorVenda*porcAlt;
     
    break; 
   
    }
   }
    printf("Alterado com sucesso!\n\n", "OK");
    system("cls");
  }
 
 } 
 
 
 float mostrarValorTotalEstoque(){
  
  float totalEstoque=0;
  float total=0;
  system("cls");
   printf("<TOTAL> \n");

  for(i=0; i<ini; i++){
     if(p[i].status == 1){
      
    printf("\n %d %s\n", i, p[i].nomeProduto);
    printf("\n R$ %.2f \n", p[i].valorCusto); 
      
    totalEstoque = p[i].valorCusto*p[i].qtdEstoque;
    
    total+=totalEstoque;
    totalEstoque=0;
    
    printf("\n");
    
    
     
    }
   
   
  }
    printf("Valor total de estoque: R$ %.2f", total);
  
    printf("\nAperte qualquer tecla para sair.");
   
   getch();
   system("cls");
  
  
 }

 
 int main(){
  
  
  
  while(c>0){
  
   menu();
  
  
  switch(op){
   
   case 1:
    
    incluir();
    
   break;
    
    // ALTERAR
   case 2:
    
    alterar();

   break;
   
    // EXCLUIR
   case 3:
    
    excluir();
  
   break;
   
   
   
    // IMPRIMIR
   case 4:
    
    imprimir();
   
   break;
 
 
   case 5:
    sair();
   break;
   
   case 6:
    alterarValorVenda();
   break; 
   
   case 7:
    
    mostrarValorTotalEstoque();
   
   break; 
       
   default:
    printf("\nDigite uma opcao valida!\a");
    Sleep(500);
    system("cls");
   break;            
     
    }
    
  }
  
  
 }
