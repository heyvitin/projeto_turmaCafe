#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct Participantes {
    int id;
    string nome;
    int semestre;
    int anoIngresso;
    string curso;
} Participantes;

struct Node {
    Participantes participante;
    Node *proximo;
};

struct Lista {
    Node *inicio = NULL;
    int tamanho = 0;
    int proximoID = 1;
};

struct Contribuicao {
    int idParticipante;
    int mes;
    int ano;
    double valor;
    string curso; 
    Contribuicao *proximo;
};

struct ListaContribuicoes {
    Contribuicao *inicio = NULL;
    int tamanho = 0;
};

void inserirParticipanteTurmaCafe(Lista &lista) {
    Participantes novoParticipante;

    cout << "Insira o nome do participante: ";
    cin >> novoParticipante.nome;

    cout << "Insira o semestre do participante: ";
    cin >> novoParticipante.semestre;

    cout << "Insira o ano de ingresso do participante na Fatec Araras: ";
    cin >> novoParticipante.anoIngresso;

    cout << "Insira o curso do participante (DSM ou SI ou GE): ";
    cin >> novoParticipante.curso;

    novoParticipante.id = lista.proximoID;
    lista.proximoID++;

    Node *novoNo = new Node;
    novoNo->participante = novoParticipante;
    novoNo->proximo = NULL;

    if (lista.inicio == NULL) {
        lista.inicio = novoNo;
    } else {
        Node *temp = lista.inicio;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
    }

    lista.tamanho++;

    cout << "Participante adicionado com sucesso!" << endl;
}

void mostrarMenu() {
    cout << "----- Menu -----" << endl;
    cout << "1. Inserir novo participante da Turma do Cafe" << endl;
    cout << "2. Editar dados de um participante por ID" << endl;
    cout << "3. Mostrar participantes" << endl;
    cout << "4. Gravar participantes em arquivo" << endl;
    cout << "5. Cadastrar contribuicao" << endl;
    cout << "6. Gravar contribuicoes em arquivo" << endl; 
    cout << "7. Gravar contribuicoes por curso" << endl; 
    cout << "8. Sair" << endl;
    cout << "----------------" << endl;
}

void mostrarParticipantes(Lista &lista) {
    Node *atual = lista.inicio;
    while (atual != NULL) {
        cout << "ID: " << atual->participante.id << endl;
        cout << "Nome: " << atual->participante.nome << endl;
        cout << "Semestre: " << atual->participante.semestre << endl;
        cout << "Ano de Ingresso: " << atual->participante.anoIngresso << endl;
        cout << "Curso: " << atual->participante.curso << endl << endl;
        atual = atual->proximo;
    }
}

void editarParticipantePorID(Lista &lista) {
    int id;
    cout << "Insira o ID do participante que deseja editar: ";
    cin >> id;

    Node *atual = lista.inicio;
    while (atual != NULL) {
        if (atual->participante.id == id) {
            cout << "Participante encontrado:" << endl;
            cout << "ID: " << atual->participante.id << endl;
            cout << "Nome: " << atual->participante.nome << endl;
            cout << "Semestre: " << atual->participante.semestre << endl;
            cout << "Ano de Ingresso: " << atual->participante.anoIngresso << endl;
            cout << "Curso: " << atual->participante.curso << endl;

            cout << "Insira o novo nome do participante: ";
            cin >> atual->participante.nome;

            cout << "Insira o novo semestre do participante: ";
            cin >> atual->participante.semestre;

            cout << "Insira o novo ano de ingresso do participante na Fatec Araras: ";
            cin >> atual->participante.anoIngresso;

            cout << "Insira o novo curso do participante (DSM ou SI ou GE): ";
            cin >> atual->participante.curso;

            cout << "Participante editado com sucesso!" << endl;
            return;
        }
        atual = atual->proximo;
    }
    cout << "Participante com o ID fornecido não encontrado." << endl;
}

void lerParticipantesDeArquivo(Lista &lista) {
    ifstream arquivo("participantes.txt");
    if (arquivo.is_open()) {
        while (!arquivo.eof()) {
            Participantes novoParticipante;
            arquivo >> novoParticipante.id >> novoParticipante.nome >> novoParticipante.semestre >> novoParticipante.anoIngresso >> novoParticipante.curso;

            Node *novoNo = new Node;
            novoNo->participante = novoParticipante;
            novoNo->proximo = NULL;

            if (lista.inicio == NULL) {
                lista.inicio = novoNo;
            } else {
                Node *temp = lista.inicio;
                while (temp->proximo != NULL) {
                    temp = temp->proximo;
                }
                temp->proximo = novoNo;
            }

            lista.tamanho++;
        }
        arquivo.close();
        cout << "Participantes carregados com sucesso do arquivo." << endl;
        mostrarParticipantes(lista); 
    } else {
        cout << "Nao foi possível abrir o arquivo de participantes." << endl;
    }
}

void gravarParticipantesEmArquivo(Lista &lista) {
    ofstream arquivo("participantes.txt");
    if (arquivo.is_open()) {
        Node *atual = lista.inicio;
        while (atual != NULL) {
            arquivo << atual->participante.id << " "
                    << atual->participante.nome << " "
                    << atual->participante.semestre << " "
                    << atual->participante.anoIngresso << " "
                    << atual->participante.curso << endl;
            atual = atual->proximo;
        }
        arquivo.close();
        cout << "Participantes gravados com sucesso no arquivo." << endl;
    } else {
        cout << "Nao foi possivel abrir o arquivo de participantes para gravacao." << endl;
    }
}

void cadastrarContribuicao(Lista &lista, ListaContribuicoes &listaContribuicoes) {
    int id;
    cout << "Insira o ID do participante para cadastrar a contribuicao: ";
    cin >> id;

    
    Node *atual = lista.inicio;
    bool participanteEncontrado = false;
    string cursoParticipante;
    while (atual != NULL) {
        if (atual->participante.id == id) {
            participanteEncontrado = true;
            cursoParticipante = atual->participante.curso;
            break;
        }
        atual = atual->proximo;
    }

    if (!participanteEncontrado) {
        cout << "Participante com o ID fornecido nao encontrado." << endl;
        return;
    }

    Contribuicao novaContribuicao;
    novaContribuicao.idParticipante = id;
    novaContribuicao.curso = cursoParticipante;

    cout << "Insira o mes da contribuicao: ";
    cin >> novaContribuicao.mes;

    cout << "Insira o ano da contribuicao: ";
    cin >> novaContribuicao.ano;

    cout << "Insira o valor da contribuicao: ";
    cin >> novaContribuicao.valor;

    Contribuicao *novoNo = new Contribuicao;
    novoNo->idParticipante = novaContribuicao.idParticipante;
    novoNo->mes = novaContribuicao.mes;
    novoNo->ano = novaContribuicao.ano;
    novoNo->valor = novaContribuicao.valor;
    novoNo->curso = novaContribuicao.curso;
    novoNo->proximo = NULL;

    if (listaContribuicoes.inicio == NULL) {
        listaContribuicoes.inicio = novoNo;
    } else {
        Contribuicao *temp = listaContribuicoes.inicio;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
    }

    listaContribuicoes.tamanho++;

    cout << "Contribuicao cadastrada com sucesso!" << endl;
}

void gravarContribuicoesEmArquivo(ListaContribuicoes &listaContribuicoes) {
    ofstream arquivo("contribuintes.txt");
    if (arquivo.is_open()) {
        Contribuicao *atual = listaContribuicoes.inicio;
        while (atual != NULL) {
            arquivo << atual->idParticipante << " "
                    << atual->mes << " "
                    << atual->ano << " "
                    << atual->valor << " "
                    << atual->curso << endl;
            atual = atual->proximo;
        }
        arquivo.close();
        cout << "Contribuicoes gravadas com sucesso no arquivo." << endl;
    } else {
        cout << "Nao foi possivel abrir o arquivo de contribuicoes para gravacao." << endl;
    }
}

void gravarContribuicoesPorCurso(ListaContribuicoes &listaContribuicoes) {
    Contribuicao *atual = listaContribuicoes.inicio;
    ofstream arquivoDSM("contribuintes_DSM.txt");
    ofstream arquivoSI("contribuintes_SI.txt");
    ofstream arquivoGE("contribuintes_GE.txt");

    if (arquivoDSM.is_open() && arquivoSI.is_open() && arquivoGE.is_open()) {
        while (atual != NULL) {
            if (atual->curso == "DSM") {
                arquivoDSM << "ID do Participante: " << atual->idParticipante << endl;
                arquivoDSM << "Mes: " << atual->mes << endl;
                arquivoDSM << "Ano: " << atual->ano << endl;
                arquivoDSM << "Valor: " << atual->valor << endl << endl;
            } else if (atual->curso == "SI") {
                arquivoSI << "ID do Participante: " << atual->idParticipante << endl;
                arquivoSI << "Mes: " << atual->mes << endl;
                arquivoSI << "Ano: " << atual->ano << endl;
                arquivoSI << "Valor: " << atual->valor << endl << endl;
            } else if (atual->curso == "GE") {
                arquivoGE << "ID do Participante: " << atual->idParticipante << endl;
                arquivoGE << "Mes: " << atual->mes << endl;
                arquivoGE << "Ano: " << atual->ano << endl;
                arquivoGE << "Valor: " << atual->valor << endl << endl;
            }
            atual = atual->proximo;
        }
        arquivoDSM.close();
        arquivoSI.close();
        arquivoGE.close();
        cout << "Contribuicoees gravadas com sucesso nos arquivos separados." << endl;
    } else {
        cout << "Nao foi possivel abrir todos os arquivos para gravacao." << endl;
    }
}

int main() {
    Lista listaParticipantes;
    ListaContribuicoes listaContribuicoes;

    int opcao;
    do {
        mostrarMenu();
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                inserirParticipanteTurmaCafe(listaParticipantes);
                break;
            case 2:
                editarParticipantePorID(listaParticipantes);
                break;
            case 3:
                mostrarParticipantes(listaParticipantes);
                break;
            case 4:
                gravarParticipantesEmArquivo(listaParticipantes);
                break;
            case 5:
                cadastrarContribuicao(listaParticipantes, listaContribuicoes);
                break;
            case 6:
                gravarContribuicoesEmArquivo(listaContribuicoes);
                break;
            case 7:
                gravarContribuicoesPorCurso(listaContribuicoes);
                break;
            case 8:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opcao invalida. Escolha novamente." << endl;
        }

    } while (opcao != 8);

    return 0;
}
