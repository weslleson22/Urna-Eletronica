
#include <stdio.h>
#include <string.h>
struct foo{
    char nome[30];
    int numero;
}bar[10];
int j,cont;
int CadastroChapa(){
    printf("Cadastro das Chapas\n");
    FILE *arq;
    char x,variavel[80];
    arq=fopen("chapasEleicoesCA.txt","r");
    if(arq==NULL)
        arq=fopen("chapasEleicoesCA.txt","w");
/*    pega tudo no arquivo e coloca na struct    */
    while(fscanf(arq,"%s", bar[cont].nome  ) != EOF &&/* nome limitado à apenas uma palavra */

          fscanf(arq,"%d",&bar[cont].numero ) != EOF ){
        printf("NUMERO ==> %d ",bar[cont].numero   );
        printf("NOME DA CHAPA ===> %s  \n"   ,bar[cont].nome   );


        cont++;
    }
    fclose(arq);
/*       cadastrar quantos quiser         */
    do{
        printf("\nPor favor responda qual o numero da Chapa)\n");
        printf("\nNumero: ");
        fflush(stdin);
        scanf("%d",&bar[cont].numero);
        printf("\nPor favor responda qual o nome da Chapa)");

        printf("\nNome: ");
        fflush(stdin);
        scanf("%s",bar[cont].nome);

        cont++;

        printf("Quer inserir outro  S/N ");
        fflush(stdin);
        scanf("%c",&x);
    }while(x !='n');
/*      salvar tudo no arquivo         */
    arq=fopen("chapasEleicoesCA.txt","w");/* cria o arquivo , e zera ele para gravar do começo */
    for(j=0;j<cont;j++){
        fprintf(arq, "%s "  ,bar[j].nome  );

        fprintf(arq, "%d\n"  ,bar[j].numero );
    }
    fclose(arq);
    return 0;

}
