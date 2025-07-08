#include <iostream>
#define R 30
#define C 60
using namespace std;

class prenotazioni{

    public :

    prenotazioni();
    prenotazioni(int id,int posti[R][C],double prezzomin,double prezzomax);
    prenotazioni(const prenotazioni &p);
    ~prenotazioni();

    int get_id()const;
    int get_posti(int r,int c)const;
    double get_prezzomin()const;
    double get_prezzomax()const;

    void set_id(int id);
    void set_posti(int posti[R][C]);
    void set_prezzomin(double prezzomin);
    void set_prezzomax(double prezzomax);

    const prenotazioni& operator=(const prenotazioni &r);
    bool operator!=(const prenotazioni &r)const;
    friend std::istream &operator>>(istream &is,prenotazioni &p);
    friend std::ostream &operator<<(ostream &os,const prenotazioni &p);

    const int * posti_prenotati()const ;

    
    private:

    int _id;
    int _posti[R][C];
    double _prezzomin;
    double _prezzomax;
};

prenotazioni::prenotazioni(){
    _id=0;
    for(int i =0 ; i<R;i++){
        for(int j=0;j<C;j++){
            _posti[i][j]=0;
        }
    }
    _prezzomin=0;
    _prezzomax=0;
}
prenotazioni::prenotazioni(int id,int posti[R][C],double prezzomin,double prezzomax){
    _id=id;
    for(int i =0 ; i<R;i++){
        for(int j=0;j<C;j++){
            _posti[i][j]=posti[i][j];
        }
    }
    _prezzomin=prezzomin;
    _prezzomax=prezzomax;
}
prenotazioni::prenotazioni(const prenotazioni &r){
    _id=r._id;
    for(int i =0 ; i<R;i++){
        for(int j=0;j<C;j++){
            _posti[i][j]=r._posti[i][j];
        }
    }
    _prezzomin=r._prezzomin;
    _prezzomax=r._prezzomax;
}
prenotazioni::~prenotazioni(){}

int prenotazioni::get_id()const{
    return _id;
}
int prenotazioni::get_posti(int r,int c)const{
    return _posti[r][c];
}
double prenotazioni::get_prezzomin()const{
    return _prezzomin;
}
double prenotazioni::get_prezzomax()const{
    return _prezzomax;
}

void prenotazioni::set_id(int id){
    _id=id;
}
void prenotazioni::set_posti(int posti[R][C]){
        for(int i =0 ; i<R;i++){
        for(int j=0;j<C;j++){
            _posti[i][j]=posti[i][j];
        }
    }
}
void prenotazioni::set_prezzomin(double prezzomin){
    _prezzomin=prezzomin;
}
void prenotazioni::set_prezzomax(double prezzomax){
    _prezzomax=prezzomax;
}

const prenotazioni& prenotazioni::operator=(const prenotazioni &r){

    if(this!=&r){
    _id=r._id;
    for(int i =0 ; i<R;i++){
        for(int j=0;j<C;j++){
            _posti[i][j]=r._posti[i][j];
        }
    }
    _prezzomin=r._prezzomin;
    _prezzomax=r._prezzomax;
    }
    return *this;
}

bool prenotazioni::operator!=(const prenotazioni &r)const{
    if((_id!=r._id)||(_prezzomin!=r._prezzomin)||(_prezzomax!=r._prezzomax)){
        return true;
    }
    for(int i =0 ; i<R;i++){
        for(int j=0;j<C;j++){

            if(_posti[i][j]!=r._posti[i][j]){
                return true;
            }
        }
    }

    return false;

}
  
std::istream &operator>>(istream &is,prenotazioni &p){
    is>>p._id;
            for(int i =0 ; i<R;i++){
        for(int j=0;j<C;j++){
            is>>p._posti[i][j];
        }
    }
    is>>p._prezzomin>>p._prezzomax;

    return is;
    

}

std::ostream &operator<<(ostream &os,const prenotazioni &p){
        os<<p._id;
            for(int i =0 ; i<R;i++){
        for(int j=0;j<C;j++){
            os<<p._posti[i][j];
        }
    }
    os<<p._prezzomin<<p._prezzomax;
    return os;
}

const int * prenotazioni::posti_prenotati()const {
    int p[R];
    int conta=0;
    
        for(int i =0 ; i<R;i++){
        for(int j=0;j<C;j++){
            if(_posti[i][j]==1){
                conta++;
            }
        }
        p[i]=conta;
        conta=0;
    }
    return p;
}
int main(){

    return 0;
}