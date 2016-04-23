
#ifndef IOBSERVADOR_H
#define IOBSERVADOR_H

class IObservador
{
	public:
		void virtual Atualiza(int acao) = 0;
		virtual ~IObservador() {}
};

#endif
