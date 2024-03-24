#include "listaD.h"

int main(){
    
    Aluno a, b, c;
    
    Lista *l = criar();
    Lista *l2 = criar();
    
    strcpy(b.nome, "b");
    b.mat = 2;
    b.n1 = 2;
    inserirFim(l2, b);

    strcpy(c.nome, "c");
    c.mat = 3; 
    c.n1 = 3;
    inserirFim(l2, c);

    int pos1, pos2;
    
    int op;
    do{
        printf("\n-------------------------------------------------------------------------------"
            "\n1)Cadastrar aluno.\n2)Remover aluno.\n3)Listar alunos cadastrados.\n"
            "4)Mostrar dados do aluno com maior nota.\n5)Remover todos os alunos.\n6)Trocar dois elementos"
            "\n7)Se l eh equivalente a l2\n8)Remover repeticoes\n9)Sair.\n=> ");
        scanf("%d", &op);
        // SIM EU USEI SWITCH CASE!
        switch(op){
            
            case 1:
                printf("Informe o nome do aluno: ");
                setbuf(stdin, NULL);
                scanf("%30[^\n]", a.nome);
                setbuf(stdin, NULL);
                printf("Informe a matricula: ");
                scanf("%d", &a.mat);
                printf("Informe a nota: ");
                scanf("%f", &a.n1);
                inserirFim(l, a);
                break;
            case 2:
                printf("Informe a matricula do aluno a ser removido: ");
                scanf("%d", &a.mat);
                removerItem(l, a.mat);
                break;
            case 3:
                if(tamanho(l)==0)
                    printf("Nao existem alunos!");
                else
                    mostrar(l); 
                break;
            case 4:
                maiorNota(l);
                break;
            case 5:
                removerNos(l, tamanho(l));
                break;
            case 6:
                printf("Informe as posicoes a serem trocadas: ");
                scanf("%d %d", &pos1, &pos2);
                troca(l, pos1, pos2);
                break;
            case 7:
                printf("Sendo l2: "); mostrar(l2);
                if(equivalente(l,l2) == 0)
                    printf("l1 e l2 sao equivalentes!\n");
                else
                    printf("l1 e l2 nao sao equivalentes!\n");
                break;
            case 8:
                removerRepts(l);
                printf("Lista sem repeticoes: "); mostrar(l);
                break; 
            case 9:
                limpar(l);
                printf("Tchau!\n");
                break;   
            default:
                printf("Opcao invalida!\n\n");
                break;
        }
    }while(op != 9);
    
    return 0;
    
}