#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Função para cada aluno: le nome, 3 notas, calcula a media e define a situação
string processar_aluno(float &m1, float &m2, float &m3, float &media, string &situacao) {
    string nome;

    cout << "Digite o nome do aluno: " ;
    cin >> nome;

    cout<<endl<< "digite o valor da m1: " ;
    cin >> m1;

    cout<<endl<< "digite o valor da m2: " ;
    cin >> m2;

    cout<<endl<< "digite o valor da m3: " ;
    cin >> m3;

    media = (m1 + m2 + m3) / 3.0; //calcula a media

    //define a situação do aluno
    if (media >= 5.75) {
        situacao = "APROVADO";
    } else {
        situacao = "REPROVADO";
    }

    return nome; //retorna o nome do aluno
}

int main() {
    //vetores para armazenar os dados dos alunos
    string nomes[5];
    float notas_m1[5], notas_m2[5], notas_m3[5];
    float medias[5];
    string situacoes[5];

    //loop para processar os dadso
    for (int i = 0; i<5; i++) {
        cout<<endl<<"Aluno " << i + 1 <<" : "<<endl;
        
       // guarda os dados na posição i de cada aluno 
        nomes[i] = processar_aluno(
            notas_m1[i], 
            notas_m2[i], 
            notas_m3[i], 
            medias[i], 
            situacoes[i]
        );
    }

    // descobrir a maior media da turma
    int maior_media = 0;
    for (int i = 0; i<5; i++) {
        if (medias[i] > medias[maior_media]) { //atribui a primeira media como a maior e depois compara a media do aluno atual [i]  
            maior_media = i;
        }
    }

    //exibe a tabela final com os vetores preenchidos
    cout<<"NOME  ||  M1  ||  M2  ||  M3  ||  MEDIA  ||  SITUACAO  "<<endl;

    for (int i = 0; i < 5; i++) {
        cout<<nomes[i]<<"  ||  "<<notas_m1[i]<<"  ||  " <<notas_m2[i]<<"  ||  "<<notas_m3[i]<<"  ||  "<<medias[i]<<"  ||  "<<situacoes[i]<<endl;
    }

    //mostra quem teve a maior media
    cout<<endl<<"O aluno " << nomes[maior_media]<<" obteve a maior media:  "<<medias[maior_media]<<endl;

    return 0;
}