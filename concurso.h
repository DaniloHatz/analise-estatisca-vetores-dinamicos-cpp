#ifndef CONCURSO_H
#define CONCURSO_H

#include <iostream>

struct horario
{
	unsigned short hora, minuto;
};

struct questao
{
	unsigned short dificuldade;
	horario inicio, fim;
};

struct media
{
	float dificuldade, tempo;
};

struct participante
{
	char nome[20];
	questao* ptrQuestao;
};

void ImprimeLinha(char, unsigned char);

std::istream& operator>>(std::istream&, horario&);

std::ostream& operator<<(std::ostream&, horario&);

unsigned short operator-(horario&, horario&);

void ResumoParticipante(questao[], unsigned char);

void ResumoQuestao(questao);

media Estatisticas(questao[], unsigned short, unsigned short, unsigned short);

void CadastroInicial(participante*, questao*, unsigned short, unsigned short);

void ImprimeResumoParticipante(participante*, unsigned short, unsigned short);

void ImprimeResumoQuestao(participante*, unsigned short, unsigned short);

void ImprimeEstatisticas(questao*, unsigned short, unsigned short);

#endif