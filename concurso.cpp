#include "concurso.h"
#include <iostream>

void ImprimeLinha(char ch, unsigned char qtd)
{
	for (unsigned short i = 1; i <= qtd; i++) std::cout << ch;
	std::cout << std::endl;
}

std::istream& operator>>(std::istream& is, horario& h)
{
	is >> h.hora;
	is.ignore();
	is >> h.minuto;
	return is;
}

std::ostream& operator<<(std::ostream& os, horario& h)
{
	os << (h.hora < 10 ? "0" : "");
	os << h.hora;
	os << ":";
	os << (h.minuto < 10 ? "0" : "");
	os << h.minuto;
	return os;
}

unsigned short operator-(horario& hFim, horario& hInicio)
{
	unsigned short hrFim = hFim.hora, minFim = hFim.minuto;

	if (hFim.minuto < hInicio.minuto)
	{
		hrFim--;
		minFim += 60;
	}
	return ((hrFim - hInicio.hora) * 60) + (minFim - hInicio.minuto);
}

void ResumoParticipante(questao q[], unsigned char qtd)
{
	for (unsigned char i = 0; i < qtd; i++)
	{
		std::cout << "\t" << char(i + 65) << " ";
		std::cout << "(" << q[i].dificuldade << ") ";
		std::cout << q[i].inicio << " as " << q[i].fim;
		std::cout << " (" << q[i].fim - q[i].inicio << " min)\n";
	}
}

void ResumoQuestao(questao q)
{
	std::cout << "(" << q.dificuldade << ") ";
	std::cout << q.inicio << " as " << q.fim;
	std::cout << " (" << q.fim - q.inicio << " min)\n";
}

media Estatisticas(questao q[], unsigned short tam, unsigned short indice, unsigned short passo)
{
	media m = { 0.0f, 0.0f };
	unsigned short qtd = 0;
	for (unsigned char i = 0; i < tam; i += passo)
	{
		m.dificuldade += q[indice + i].dificuldade;
		m.tempo += q[indice + i].fim - q[indice + i].inicio;
		qtd++;
	}
	m.dificuldade /= qtd;
	m.tempo /= qtd;
	return m;
}

void CadastroInicial(participante* p, questao* q, unsigned short qtP, unsigned short qtQ)
{
	unsigned short k = 0;
	for (unsigned short i = 0; i < qtP; i++)
	{
		ImprimeLinha('-', 13);
		std::cout << "Participante: ";
		std::cin >> p[i].nome;
		p[i].ptrQuestao = &q[k];
		ImprimeLinha('-', 13);
		for (unsigned short j = 0; j < qtQ; j++)
		{
			std::cout << "Questao " << char(j + 65);
			std::cout << "\n\tDificuldade: ";
			std::cin >> q[k].dificuldade;
			std::cout << "\tInicio: ";
			std::cin >> q[k].inicio;
			std::cout << "\tFim: ";
			std::cin >> q[k].fim;
			k++;
		}
		ImprimeLinha('-', 13);
		ImprimeLinha(' ', 0);
	}
}

void ImprimeResumoParticipante(participante* p, unsigned short qtP, unsigned short qtQ)
{
	for (unsigned char i = 0; i < qtP; i++)
	{
		std::cout << p[i].nome << ":\n";
		ResumoParticipante(p[i].ptrQuestao, qtQ);
	}
}

void ImprimeResumoQuestao(participante* p, unsigned short qtP, unsigned short qtQ)
{
	for (unsigned char i = 0; i < qtQ; i++)
	{
		std::cout << "Questao " << char(65 + i) << ":\n";
		for (unsigned char j = 0; j < qtP; j++)
		{
			std::cout << "\t" << p[j].nome << " ";
			ResumoQuestao(*(p[j].ptrQuestao + i));
		}
	}
}

void ImprimeEstatisticas(questao* q, unsigned short qtP, unsigned short qtQ)
{
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::cout.precision(2);
	
	for (unsigned char i = 0; i < qtQ; i++)
	{
		media m = Estatisticas(q, qtQ * qtP, i, qtP);
		std::cout << "Questao " << char(65 + i) << ": ";
		std::cout << "Dificuldade (" << m.dificuldade << ") - ";
		std::cout << "Tempo (" << m.tempo << " minutos)\n";
	}
	media c = Estatisticas(q, qtQ * qtP, unsigned short(0), unsigned short(1));
	std::cout << "Concurso:  Dificuldade (" << c.dificuldade << ") - Tempo (" << c.tempo << " minutos)\n";
}