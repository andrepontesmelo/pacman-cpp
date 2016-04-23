#include "DirecaoFixa.h"

DirecaoFixa* DirecaoFixa::cima = new DirecaoFixa(CIMA, 0, -1, "cima");
DirecaoFixa* DirecaoFixa::baixo = new DirecaoFixa(BAIXO, 0, 1, "baixo");
DirecaoFixa* DirecaoFixa::esquerda = new DirecaoFixa(ESQUERDA, -1, 0, "esq");
DirecaoFixa* DirecaoFixa::direita = new DirecaoFixa(DIREITA, 1, 0, "dir");

bool DirecaoFixa::opostos_setados = false;

DirecaoFixa* DirecaoFixa::Obter_pelo_codigo(int cod)
{
	switch (cod)
	{
		case CIMA:
			return cima;
			break;
		case BAIXO:
			return baixo;
			break;
		case ESQUERDA:
			return esquerda;
			break;
		case DIREITA:
			return direita;
			break;
		default:
			stringstream msg;			
			msg << "Codigo invalido em DirecaoFixa::Obter_pelo_codigo(int cod), cod=" << cod;
			
			throw new Excessao(msg.str());
	}
}

DirecaoFixa* DirecaoFixa::Oposto()
{
	if (!opostos_setados)
		Setar_opostos();

#ifdef DEBUG
	if (oposto == 0)
		throw new ExcessaoReferenciaNula("oposto", "DirecaoFixa::Oposto()");
#endif

	return oposto;
}

void DirecaoFixa::Setar_opostos()
{
	cima->Set_oposto(baixo);
	baixo->Set_oposto(cima);
	esquerda->Set_oposto(direita);
	direita->Set_oposto(esquerda);

	opostos_setados = true;
}


/*DirecaoFixa* DirecaoFixa::Obter_seguindo(Posicao* superior_esquerdo, Posicao* superior_direito, Posicao* inferior_esquerdo, Posicao* inferior_direito)
{


}

*/
