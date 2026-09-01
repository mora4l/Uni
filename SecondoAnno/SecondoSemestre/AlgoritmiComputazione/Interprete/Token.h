#if !defined(TOKEN_H)
#define TOKEN_H

#include <string>
#include <unordered_set>

struct Token
{ // faccio una struct e non una classe in quanto tutti i metodi sono pubblici , non ce niente di privato e quindi è uguale al fare una classe con solo elementi pubblici

    static constexpr int KWORD = 0; // parola chiave
    static constexpr int LP = 1;    // parentesi tonda di sinistra (
    static constexpr int RP = 2;    // parentesi tonda di destra )
    static constexpr int CONST = 3; // per i numeri associati alle variabili (ID)
    static constexpr int ID = 4;    // per i nomi delle variabili

    // static constexpr int IN =  1; //input //// qua ci sono dei token che (forse) ho sbagliato a dichiarare , ma li lascio per sicurezza
    // static constexpr int PRN =  2; //output
    // static constexpr int SET = 3; //set
    // static constexpr int WHL =  4; //while
    // static constexpr int IF =  5; //if
    // static constexpr int GT =  6; // >
    // static constexpr int LT =  7; // <
    // static constexpr int AND = 8 ; // &&
    // static constexpr int OR =  9; // ||
    // static constexpr int NOT =  10; // -
    // static constexpr int TRUE =  11;
    // static constexpr int FALSE = 12 ;
    // static constexpr int ADD =  13; // operatore +
    // static constexpr int SUB =  14; //operatore -
    // static constexpr int MUL =  15; //operatore *
    // static constexpr int DIV =  16; //operatore /
    // static constexpr int LP = 17; //parentesi tonda di sinistra (
    // static constexpr int RP = 18; //parentesi tonda di destra )
    // static constexpr int CONST = 19 ; //per i numeri associati alle variabili (ID)
    // static constexpr int ID =  20; //per i nomi delle variabili

    static constexpr const char *idleggibile[]{// old style perchè è un vettore di costanti
                                               "KWORD", "(", ")", "CONST", "ID"};

    static constexpr const char *tag2string[]{// old style perchè è un vettore di costanti
                                              "KWORD", "LP", "RP", "CONST", "ID"};
    /*
    - è giusto creare un insieme di parole chiave in quanto gli identificatori (ID) e le keywords (KWORD) potrebbero avere la stessa definizione a livello lessicale,
    quindi per evitare problemi devo definire una struttura che "isoli" le vere e proprie keywords

    -  uso unordered perche mi basta cosi , non mi serve un ordine preciso per memorizzare tutte le parole chiave
    */
    static std::unordered_set<std::string> parole_chiave;

    Token(int t, std::string w) : tag{t}, word{w} {} // costruttore di token con la string
    Token(int t, const char *w) : tag{t}, word{w} {}

    ~Token() = default;
    Token(Token const &) = default;
    Token &operator=(Token const &) = default;

    // l'overloading dell'operatore << non lo metto perche non credo mi serva per ora (18/8 sto creando il tokenizzatore )

    int tag;          // il tag è l'id
    std::string word; // la word è la stringa che lo identifica
};
std::ostream& operator<<(std::ostream & os, const Token & t);

#endif