// [~VICTOR MANOEL MARTINS] // 

#include <iostream>
#include <string>

using namespace std;

    //Armazena informações de participantes

    typedef struct Participante{
        int id;
        string nome;
        int semestre;
        int ano_ingresso;
        string curso;
    }Participante;


    //Esturura 'Node' representando cada node da lista

    struct Node {
        Participante data; // -> Contém dados do participante
        Node *proximo; // -> Ponteiro para o próximo node da lista
    };
    
    struct Lista{
        Node *begin = NULL;
        int autoId = 1;
    };


    void addParticipante(Lista *list, string nome, int semestre, int ano_ingresso, string curso){
        Node *node = new Node;

        if (node == NULL) {
            cerr << "Acabou a memória. " << endl;
            exit(1);
        }

        node->data.id = newId(list);
        node->data.nome = nome;
        node->data.semestre = semestre;
        node->data.ano_ingresso = ano_ingresso;
        node->data.curso = curso;

        node->proximo = list->begin;

        list->begin = node;
    };

    void newId(Lista *list){
        return list->autoId++;

    };

    //Função Inserir os Participantes
    void insertParticipante(){
        string nome, curso;
        int semestre, ano_ingresso;

        cout << "Digite o Nome Completo: ";
        cin >> nome;
        cout << "Digite o Semestre ingressado: ";
        cin >> semestre;
        cout << "Digite o Ano ingressado: ";
        cin >> ano_ingresso;
        cout << "Digite o Curso de escolha (DMS|SI|GE): ";
        cin >> curso;

        addParticipante(Lista *list, nome, semestre, ano_ingresso, curso);
        cout << "Participante criado" << endl;
    };

    //Função Menu Principal
    void Menu(){
        cout << "*------------------------------*" << endl;
        cout << "Menu Principal:" << endl;
        cout << "1. Inserir novos participantes" << endl;
        cout << "2. Editar informações participantes" << endl;
        cout << "*------------------------------*" << endl;
    }

int main(){

    int opcao;

    Menu();
    cout << "Escolha uma opcao: ";
    cin >> opcao;
    

    return 0;
}