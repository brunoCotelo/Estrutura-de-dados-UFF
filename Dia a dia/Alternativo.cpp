#include<iostream>
#include <queue>
#include <stack>
using namespace std;

int menu(){
  int opcao;
  cout << endl << "Digite:" << endl <<  "1 - Para adicionar elementos na pilha" << endl << "2 - Para remover elementos da pilha" << endl << "3 - Para mostrar o topo da pilha" << endl << "4 - Para mostrar a pilha" << endl << "-> ";
  scanf("%d", &opcao);
  cin >> opcao;
  return opcao;
}

void vazia(){
	cout << "\nA pilha esta vazia!" << endl;
}

void print(queue<int> fila1){
  if(!fila1.empty()){
    queue<int> filaPrint;
    filaPrint = fila1;
    cout << "Pilha: ";
    while(!filaPrint.empty()){
      cout << filaPrint.front() << " -> ";
      filaPrint.pop();
    }
    cout << endl;
  }
  else{
    vazia();
  }
}

int main(){
  queue<int> fila1;
  queue<int> fila2;
  int op, num = 1;
  op = menu();
    while(op != 5){
      switch(op){
            case 1:
              cout << endl <<"Digite o numero que deseja adicionar na pilha: ";
              cin >> num;
              cout << endl;
              if(fila1.empty() && fila2.empty()){
                fila1.push(num);
              }
              else{
                fila2.push(num);
                while(!fila1.empty()){
                  fila2.push(fila1.front());
                  fila1.pop();
                }
                while(!fila2.empty()){
                  fila1.push(fila2.front());
                  fila2.pop();
                }
              }
              break;
            case 2:
              if(!fila1.empty()){
								cout << endl << "Removendo valor do topo da pilha" << endl;
              	fila1.pop();
							}
							else{
							vazia();
							}
							break;
            case 3:
              if(!fila1.empty()){
								cout << endl << "Valor do topo da pilha: " << fila1.front() << endl;
							}
							else{
								vazia();
							}
							break;
						case 4:
							print(fila1);
							break;
      }
      op = menu();
    }
    cout << endl << endl <<"Fim do programa =)";
}
