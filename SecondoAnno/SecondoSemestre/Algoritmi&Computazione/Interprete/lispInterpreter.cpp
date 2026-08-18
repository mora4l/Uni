#include <iostream>
#include <fstream>
#include <stdlib.h>

int main(int argc,char* argv[]){
    if(argc < 2){
        std::cerr <<"Non è stato inserito nessun file da linea di comando " << std::endl;
        std::cerr<< "Utilizzo : " <<std::endl;
        std::cerr << argv[0] << "<filename"<<std::endl;
        return EXIT_FAILURE; //grazie a stdlib
    }

    std::ifstream programmadafile;

    try{
        programmadafile.open(argv[1]);
    }catch(std::exception& e){
        std::cerr << "Non è stato possibile aprire il file "<<argv[1]<<"a causa di "<<std::endl  ; 
        std::cerr<< e.what()<<std::endl; 
        return EXIT_FAILURE; 
    }





    return EXIT_SUCCESS;
}
