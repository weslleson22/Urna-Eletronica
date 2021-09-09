#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#define CLEAN_BUFF do{ int c; while((c = getchar()) != '\n' && c != EOF);}while(0) //substitui esse parte por getchar() se você preferir

#define MAX_SENHA 10
#define MAX_NUMERO 10

#define MAX_LOGIN 50


int Usuario( FILE* file, char* user, char* senha ) //Verifica se é um usuario valido
{
    setlocale(LC_ALL, "Portuguese");
	char tmpLogin[MAX_LOGIN];
	char tmpSenha[MAX_SENHA];


	fscanf(file, "%s", tmpLogin);

	while( !feof(file) )
	{
		if( !strcmp(tmpLogin, user) )
		{
			fscanf(file, "%s", tmpSenha);

			if( !strcmp(tmpSenha, senha) )
				return 1;
		}
		else
		{
			fscanf(file, "%*s");
		}

		fscanf(file, "%s", tmpLogin);
	}

	return 0;
}

char* CriaSenha()
{
    register int i;

	char* senha = (char*)malloc(sizeof *senha * MAX_SENHA);

    for(i = 0; i < MAX_SENHA; i++)
	{
        senha[i] = getch();
        if(senha[i] == '\r')
            break;
        else
            printf("*");
    }
	senha[i] = '\0';

	return senha;
}

int CadastroMesario()
{
	FILE* fpIN;

	int option = 0;

	char *user  = (char*)malloc(sizeof *user * MAX_LOGIN);
	char *senha,
		 *confirmaSenha;

	do
	{
		printf("1-Cadastrar\n2- Sair\n");
		scanf("%d", &option);
		CLEAN_BUFF;

		switch( option )
		{

			case 1:
				printf("Usuario: ");
				gets(user);

				do
				{
					printf("Senha: ");
					senha = CriaSenha();
					printf("\nConfirmacao de senha: ");
					confirmaSenha = CriaSenha();
					printf("\n");

					if( !strcmp(senha, confirmaSenha) )
						break;
					else
						printf("As senhas não são iguais. Tente novamente.\n");
				}while(1);

				fpIN = fopen("mesarioCA.txt", "a+");
				fprintf(fpIN, "%s %s\n", senha, user);
				fclose(fpIN);

				free(senha);
				free(confirmaSenha);
				printf("\nCADASTRO REALIZADO COM SUCESSO!\n");
			break;

			case 2:
				return 0;

			default:
				printf("Escolha 1, ou 2...\n");
			break;
		}

	}while( 1 );

	return (0);
}
