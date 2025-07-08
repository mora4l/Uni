/*
accesso ad array con aritmetica dei puntatori
1D : *(a+i)
2D: *(*(nomearray+i)+j)



aggiungere un valore ad un elemento di un array di puntatori:
(*puntatore+i)=new tipovariabile (valore)

array di n puntatori a funzione con due tipi di parametro
tiporitorno (*pf)(parametro1,parametro2)={funzione1, ... , funzione n};

passare un array di puntatori ad una funzione:
tipovariabile (*nomearray)[n];

restituire un array di puntatori :
tipovariabile(*nomefunzione(parametri))[dimensionearray];

dichiarare un array  dinamico:
tipovariabile *nomearray=new tipovariabile[dimensione];


dichiarare un array di struct:
nomestruct *nomearray[dimensione];
e per inserirci nuovi dati, dentro al for apposito scrivi per ogni iterazione:
nomearray[i]=new nomestruct;

assegnare un puntatore ad un puntatore ad un array di n puntatori 
tipovariabile **array=new tipovariabile *[dimensione]

allocare dinamicamente n array e ne assegnarne i puntatori all'array puntato da arrayX
arrayX[i]=new tipovariabile [n]

/////////////////////////////////////////////////////////////////////////
allocazione dinamica della memoria

array di oggetti:
Oggetto *nomearray= new Oggetto[dim];

oggetto singolo dinamico:
Oggetto *nomeoggetto=new Oggetto;



allochi dinamicamente un array X di  n oggetti di classe Classe, assegnando il tiponumero al parametro T

Classe<tiponumero> *X[]=new Classe<tiponumero>[n]

///////////////////////////////////////////////////////////////////////////////////

selettore = getter

per un puntatore ad array:
tipologia_numero * Classe::get_NomePuntatore()const{
    return NomePuntatore;
}

///////////////////////////////////////////////////////////////////////////////////

operatore di estrazione:
std::ostream &operator<<(std::ostream &out,Oggetto &nuovooggetto) {

out<< ...

}

operatore di inserimento:
std::istream &operator>>(std::istream,Oggetto &nuovooggetto){

in.nuovooggetto.attributo;

}


operatore di assegnamento:

const NomeClasse &NomeClasse::operator=(const NomeClasse &ogettoNuovo){

    if(this!= &oggettoNuovo){

    attributo=oggettoNuovo.attributo;

    (con puntatori ad array:
    delete[] puntatore;

    puntatore=new tipologiaNumero[dim];

    for(){
    puntatore[i]=oggettoNuovo.puntatore[i];
    }
    )
    }

    return *this;
}

operatori di confronto:

 L’operatore <= per il quale una scarpa è minore o uguale di un’altra se il numero della scarpa è minore o uguale 
del numero dell’altra scarpa. 

bool Scarpa::operator<=(Scarpa &s)const {
    return this->_numero <= _numero;
    }

*/