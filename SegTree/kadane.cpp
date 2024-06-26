//Kadane ou Subarray de soma máxima
void kadane(vector<int>& vet)
{
	int max_atual = 0, max_total = -1;
	int size_vet = vet.size();

	for(int i = 0; i < size_vet; i++)
	{
		max_atual = max_atual + vet[i];
		
		if(max_atual < 0)
			max_atual = 0;
		if(max_atual > max_total)
			max_total = max_atual;
	}
	
	cout << "Soma maxima: " << max_total << endl;
}
/*
	Implementação do algoritmo de Kruskal
	Para detectar ciclos iremos utilizar o algoritmo Union-Find que detecta
	ciclos em grafos NÃO direcionados.
*/

class Aresta{
	int vertice1, vertice2, peso;

public:

	Aresta(int v1, int v2, int peso){
		vertice1 = v1;
		vertice2 = v2;
		this->peso = peso;
	}

	int obterVertice1(){
		return vertice1;
	}

	int obterVertice2(){
		return vertice2;
	}

	int obterPeso(){
		return peso;
	}

	// sobrescrita do operador "<"
	bool operator < (const Aresta& aresta2) const{
		return (peso < aresta2.peso);
	}
};

class Grafo{
	int V; // número de vértices
	vector<Aresta> arestas; // vetor de arestas

public:

	Grafo(int V){
		this->V = V;
	}

	// função que adiciona uma aresta
	void adicionarAresta(int v1, int v2, int peso){
		Aresta aresta(v1, v2, peso);
		arestas.push_back(aresta);
	}

	// função que busca o subconjunto de um elemento "i"
	int buscar(int subset[], int i){
		if(subset[i] == -1)
			return i;
		return buscar(subset, subset[i]);
	}

	// função para unir dois subconjuntos em um único subconjunto
	void unir(int subset[], int v1, int v2){
		int v1_set = buscar(subset, v1);
		int v2_set = buscar(subset, v2);
		subset[v1_set] = v2_set;
	}

	/// função que roda o algoritmo de Kruskal
	void kruskal(){
		vector<Aresta> arvore;
		int size_arestas = arestas.size();

		// ordena as arestas pelo menor peso
		sort(arestas.begin(), arestas.end());

		// aloca memória para criar "V" subconjuntos
		int * subset = new int[V];

		// inicializa todos os subconjuntos como conjuntos de um único elemento
		memset(subset, -1, sizeof(int) * V);

		for(int i = 0; i < size_arestas; i++){
			int v1 = buscar(subset, arestas[i].obterVertice1());
			int v2 = buscar(subset, arestas[i].obterVertice2());

			if(v1 != v2){
				// se forem diferentes é porque NÃO forma ciclo, insere no vetor
				arvore.push_back(arestas[i]);
				unir(subset, v1, v2); // faz a união
			}
		}

		int size_arvore = arvore.size();

		// mostra as arestas selecionadas com seus respectivos pesos
		for(int i = 0; i < size_arvore; i++){
			char v1 = 'A' + arvore[i].obterVertice1();
			char v2 = 'A' + arvore[i].obterVertice2();
			cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].obterPeso() << endl;
		}
	}
};
