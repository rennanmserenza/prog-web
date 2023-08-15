#include <cstdio>
#include <climits>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Heap
{
    public:
    Heap();
    Heap(int n, int dados[]);
    ~Heap();
    void escreve_niveis();
    void escreve(const string& prefixo = "", int i = 0);
    void insere(int p);
    int consulta_maxima();
    int extrai_maxima();
    void altera_prioridade(int i, int p);
    
    private:
    vector<int> S;

    int pai(int i);
    int esquerdo(int i);
    int direito(int i);
    void troca(int i, int j);
    void desce(int i);
    void sobe(int i);
};


//*************************************
//*** IMPLEMENTAÇÕES DA CLASSE HEAP ***
//*************************************

Heap::Heap() {
  // Construtor padrão
}

Heap::Heap(int n, int dados[]) :
  S(dados, dados + n) {
  // Construtor com dados iniciais (constrói uma max-heap)
  for (int i = (n / 2) - 1; i >= 0; i--) {
    desce(i);
  }
}

Heap::~Heap() {
  // Destrutor padrão
}

void Heap::escreve_niveis() {
  int escritos = 0, fim_nivel = 1;

  for(auto const& elemento: S) {
    // Imprime os elementos por níveis
    printf("%d ", elemento);
    if (++escritos == fim_nivel) {
      putchar('\n');
      fim_nivel *= 2;
      escritos = 0;
    }
  }
  putchar('\n');
}

void Heap::escreve(const string& prefixo, int i) {
  if (i < (int) S.size()) {
    bool ehEsquerdo = i % 2 != 0;
    bool temIrmao = i < (int) S.size()-1;
    
    printf(prefixo.c_str());
    printf(ehEsquerdo and temIrmao ? "├──" : "└──" );

    printf("%d\n", S[i]);
      
    escreve(prefixo + (ehEsquerdo ? "│   " : "    "), esquerdo(i));
    escreve(prefixo + (ehEsquerdo ? "│   " : "    "), direito(i));
  }
}

int Heap::pai(int i) {
  return (i - 1) / 2;
}

int Heap::esquerdo(int i) {
  return 2 * (i + 1) - 1;
}

int Heap::direito(int i) {
  return 2 * (i + 1);
}

void Heap::troca(int i, int j) {
  // Troca os elementos nas posições i e j
  int aux = S[i];
  S[i] = S[j];
  S[j] = aux;
}

void Heap::desce(int i) {
  // Move o elemento na posição i para baixo na árvore para manter a propriedade de max-heap
  int esq = esquerdo(i);
  int dir = direito(i);
  int maior = i;

  if (esq < (int) S.size() && S[esq] > S[maior]) {
    maior = esq;
  }

  if (dir < (int) S.size() && S[dir] > S[maior]) {
    maior = dir;
  }

  if (maior != i) {
    troca(i, maior);
    desce(maior);
  }
}

void Heap::sobe(int i) {
  // Move o elemento na posição i para cima na árvore para manter a propriedade de max-heap
  while (i > 0 && S[pai(i)] < S[i]) {
    troca(i, pai(i));
    i = pai(i);
  }
}

void Heap::insere(int p) {
  // Insere um elemento na heap e mantém a propriedade de max-heap
  S.push_back(p);
  sobe(S.size()-1);
}

int Heap::consulta_maxima() {
  // Retorna o elemento de maior prioridade (raiz da heap)
  if (S.empty()) {
    return INT_MIN; // Retorna o menor inteiro em caso de heap vazia
  }
  return S[0];
}

int Heap::extrai_maxima() {
  // Extrai e remove o elemento de maior prioridade (raiz da heap)
  if (S.empty()) {
    return INT_MIN; // Retorna o menor inteiro em caso de heap vazia
  }
  
  int maximo = S[0];
  S[0] = S.back();
  S.pop_back();
  desce(0);

  return maximo;
}

void Heap::altera_prioridade(int i, int p) {
  // Altera a prioridade de um elemento na heap e ajusta a posição do elemento na heap
  if (i < 0 || i >= (int) S.size()) {
    return; // Índice inválido
  }

  int antiga_prioridade = S[i];
  S[i] = p;

  if (p > antiga_prioridade) {
    sobe(i);
  } else if (p < antiga_prioridade) {
    desce(i);
  }
}

int main(void)
{
  Heap h;

  for (int i = 1; i <= 10; i++)
    h.insere(i);
  printf("h:\n");
  h.escreve();

  h.extrai_maxima();
  printf("h:\n");
  h.escreve();

  h.altera_prioridade(0, -3);
  printf("h:\n");
  h.escreve();

  return 0;

  int v[] = {1,2,3,4,5};
  
  Heap h2(5, v);
  h2.insere(15);
  printf("h2:\n");
  h2.escreve();

  Heap h3(h2);
  h2.insere(30);
  printf("h3:\n");
  h3.escreve();

  Heap h4 = h2;
  h2.insere(40);
  printf("h4:\n");
  h4.escreve();
  
  h = h2;
  h.insere(100);
  printf("h2:\n");
  h2.escreve();
  printf("h:\n");
  h.escreve();

  h = Heap(5, v);
  printf("h:\n");
  h.escreve();
  
  return 0;
}
