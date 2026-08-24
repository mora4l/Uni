#if !defined(SYNTAX_H)
#define SYNTAX_H

#include <vector>
#include <string>

class Visitor;

struct Block{
    void accept(Visitor& visitor); 
};

struct Program{
    virtual void accept(Visitor& visitor) const = 0  ; 
    std::vector<Block*> Block ;
};

// struct Block : public Stmt_block {} ; 


// struct Operator : public Block{
//     Operator(int o , Block* lop , Block* rop ) : opCode_{ o } , left_ {lop} , right_{rop}{}
//     ~Operator() = default ; 
//     Operator(Operator const& other) = default ; 
//     Operator& operator = (Operator const& other) = default ; 

//     void accept(Visitor& visitor) const; 

//     int opCode_ ; 
//     Block* left_ ; 
//     Block* right_ ; 
// };

// struct Variable : public Block{
// 	Variable(std::string id) : id_{ id } { }
//     ~Variable() = default;
//     Variable(Variable const& other) = default;
//     Variable& operator=(Variable const& other) = default;

// 	void accept(Visitor& visitor) const;

//     std::string id_ ; 
// };

// struct Number : public Block{
//     Number(int num) : num_{ num } { }
//     ~Number() = default ; 
//     Number(Number const& other) = default ; 
//     Number& operator= (Number const& other) = default ; 

//     void accept(Visitor& visitor) const ; 

//     int num_;
// };

#endif