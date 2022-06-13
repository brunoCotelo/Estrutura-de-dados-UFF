#include <iostream>
using namespace std;

class No
{
private:
	No *esq, *dir;
	int chave;

public:
	No(int chave)
	{
		this->chave = chave;
		esq = NULL;
		dir = NULL;
	}

	int getChave()
	{
		return chave;
	}
	
	// funções getters e setters

	No* getEsq()
	{
		return esq;
	}

	No* getDir()
	{
		return dir;
	}

	void setEsq(No *no)
	{
		esq = no;
	}

	void setDir(No *no)
	{
		dir = no;
	}
};

class Arvore
{
private:
	No *raiz;

public:
	Arvore()
	{
		raiz = NULL;
	}

	void inserir(int chave)
	{
		if(raiz == NULL) // verifica se a árvore está vazia
			raiz = new No(chave); // cria um novo nó
		else
			inserirAux(raiz, chave);
	}

	void inserirAux(No *no, int chave)
	{
		// se for menor, então insere à esquerda
		if(chave < no->getChave())
		{
			// verifica se a esquerda é nulo
			if(no->getEsq() == NULL)
			{
				No *novo_no = new No(chave);
				no->setEsq(novo_no); // seta o novo_no à esquerda
			}
			else
			{
				// senão, continua percorrendo recursivamente
				inserirAux(no->getEsq(), chave);
			}
		}
		// se for maior, então insere à direita
		else if(chave > no->getChave())
		{
			// verifica se a direita é nulo
			if(no->getDir() == NULL)
			{
				No *novo_no = new No(chave);
				no->setDir(novo_no); // seta o novo_no à direita
			}
			else
			{
				// senão, continua percorrendo recursivamente
				inserirAux(no->getDir(), chave);
			}
		}
		// se for igual, não vai inserir
		// não pode existir 2 chaves iguais
	}

	No* getRaiz()
	{
		return raiz;
	}

	void emOrdem(No* no)
	{
		if(no != NULL)
		{
			emOrdem(no->getEsq());
			cout << no->getChave() << " ";
			emOrdem(no->getDir());
		}
	}

  void preordem(No* no){
    if(no){
      printf("%d ", no->getChave());
      preordem(no->getEsq());
      preordem(no->getDir());
    }
  }

  void posordem(No* no){
    if(no){
      posordem(no->getEsq());
      posordem(no->getDir());
      printf("%d ", no->getChave());
    }
  }

  void somaFolhas(No *no){
    int soma = 0;
    if(no->getEsq() == NULL && no->getDir() == NULL){
      soma += no->getChave();
      cout << "if";
    }
    else if(no->getEsq()){
        somaFolhas(no->getEsq());
        cout << "if2";
    }
    else if(no->getDir()){
        somaFolhas(no->getDir());
        cout << "if3";
    }
  }
};

int main(int argc, char *argv[])
{
	Arvore arv;

	// insere as chaves
	arv.inserir(8);
	arv.inserir(3);
	arv.inserir(10);
	arv.inserir(14);
	arv.inserir(13);
	arv.inserir(1);
	arv.inserir(6);
	arv.inserir(4);
	arv.inserir(7);

	// percorre em ordem iniciando da raiz
	cout << "Percorrendo em ordem...\n";
	arv.emOrdem(arv.getRaiz());
  puts("\n");
  arv.posordem(arv.getRaiz());
  puts("\n");
  arv.preordem(arv.getRaiz());
  puts("\n");
  arv.somaFolhas(arv.getRaiz());

	return 0;
}