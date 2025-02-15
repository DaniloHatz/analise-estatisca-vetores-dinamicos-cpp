#include "concurso.h"
#include <iostream>

using namespace std;

int main()
{
	unsigned short qtdParticipantes, qtdQuestoes;

	ImprimeLinha('*', 43);
	cout << "Concurso de Programacao\n";

	cout << "\nQual o numero de participantes? ";
	cin >> qtdParticipantes;
	participante* participantes = new participante[qtdParticipantes];

	cout << "Qual o numero de questoes? ";
	cin >> qtdQuestoes;
	questao* questoes = new questao[qtdQuestoes * qtdParticipantes];

	cout << endl;
	ImprimeLinha('*', 43);
	
	CadastroInicial(participantes, questoes, qtdParticipantes, qtdQuestoes);

	cout << endl;
	ImprimeLinha('*', 43);
	ImprimeLinha('-', 23);
	
	cout << "Resumo por Participante\n";
	
	ImprimeLinha('-', 23);

	ImprimeResumoParticipante(participantes, qtdParticipantes, qtdQuestoes);

	ImprimeLinha('-', 18);
	cout << endl;
	ImprimeLinha('-', 18);
	
	cout << "Resumo por Questao\n";
	ImprimeLinha('-', 18);

	ImprimeResumoQuestao(participantes, qtdParticipantes, qtdQuestoes);

	ImprimeLinha('-', 18);
	cout << endl;
	ImprimeLinha('-', 12);
	
	cout << "Estatisticas\n";
	ImprimeLinha('-', 12);
	
	ImprimeEstatisticas(questoes, qtdParticipantes, qtdQuestoes);

	cout << endl;
	ImprimeLinha('*', 43);
	cout << endl;

	delete[] questoes;
	delete[] participantes;
	return 0;
}
