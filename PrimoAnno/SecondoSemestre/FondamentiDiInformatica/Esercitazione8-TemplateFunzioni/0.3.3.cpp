#include <iostream>
using namespace std;

template <typename T>
class array{
    public : 
    array(){
        _dim=0 ; 
        _pdata=nullptr;
    }

    array(int n ){
        if(n>0){
            _dim=n;
            _pdata=new T [_dim];

            if((n<0)||(_pdata==nullptr)){
                _pdata=nullptr;
                _dim=0 ;
            }
        }
    }

    array(const array &a){
        if((a._dim>0)&&(a._pdata!=nullptr)){
            
            _dim=a._dim;
            T *_pdata=new T[_dim];
            for(int i = 0 ; i<_dim ; i++){
                _pdata[i]=a._pdata[i];
            }
        }else{
            _dim=0 ; 
            _pdata=nullptr; 
        }
    }

    ~array(){
        delete [] _pdata  ;
    }

    int get_size()const{
        return _dim ; 
    }
    
    const T* get_value(int index)const{
        if((index>=0)&&(index<=_dim-1)){
            return _pdata[index];
        }else{
            return NULL;
        }
    }

    const T* get_array()const{
        return _pdata;
    }

    int set_size(int n ){
        int ret=1;
        if(n<0){
            ret =0 ; 
        }else{

            T *_pdata2=new T[n];
            if(!_pdata2){
                ret=0  ; 
            }else{

                if(n>_dim){
                    n=n-(n-_dim);
                }
                for(int i =0  ;i<n;i++){
                    _pdata2[i]=_pdata[i];
                }
                delete [] _pdata;
        
                _pdata=_pdata2;
                _dim=n;
            }
            }


        return ret ; 
    }

    int set_value(int index, T data){
        int ret2=1;
        if((index <0)||_pdata==nullptr){
            ret2=0 ; 
        }else{

            if((index>=0)&&(index <=_dim-1)){
                _pdata[index]=data;
            }
        }
        return ret2 ;
    }

    int set_array(T data,int n ){
        int ret3=1;

        if((_pdata!=nullptr)||(n<0)){
            ret3=0 ; 
        }else{
            if(n=_dim){
    
    
    
    
                for(int i = 0 ;i<n;i++){
                    _pdata[i]=data[i];
                }
            }
            
        }


        return ret3;
    }

    array& operator=(const array &a){

        if(this!=&a){
        if(_pdata!=nullptr){
            
            delete[] _pdata;
        }
            if((a._pdata!=nullptr)&&(a._dim>0)){
                _dim=a._dim;
                _pdata=new T[_dim];
                for(int i = 0 ;i<_dim;i++){
                    _pdata[i]=a._pdata[i];
                }
            }else{
                _pdata=nullptr;
                _dim=0 ; 
            }
        }

        return *this;
    }

    const void print(){
        cout<<"stampo gli elementi:"<<endl;
        for(int i = 0 ; i<_dim ; i++){
            cout<<_pdata[i];
        }
    }

    void read(){
        for(int i = 0 ; i<_dim ; i++){
            cin>>_pdata[i];
        }
    }
    

    private : 

    T *_pdata ; 
    int _dim ;
};

int main(){
array<int> a(10) ; 
cout<<"inserisci da tastiera gli elementi"<<endl;
a.read();
a.print();
    return 0 ; 
}