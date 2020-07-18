#ifndef UTILS_H_INCLUDED
    #define UTILS_H_INCLUDED  
    #include <iostream>
    #include <amicayse/tree.h>

    namespace amicayse
    {
        enum TokenType : int;
        enum NonTerminal : int;
        struct Token
        {
            TokenType type;
            std::string lexeme;
            int line;

            Token(TokenType tok, std::string lex, int l) : type(tok), lexeme(lex), line(l) {}
            void print() {
                std::cout<<((lexeme=="\n")?"\\n":lexeme)<<"\t"<<type<<"\t"<<line;
            }
            void println() {
                std::cout<<((lexeme=="\n")?"\\n":lexeme)<<"\t"<<type<<"\t"<<line<<"\n";
            }
            void operator=(Token const &t){
                this->type = t.type;
                this->lexeme = t.lexeme;
                this->line = t.line;
            }
        };
        class ParserException : std::exception{
            std::string s;
            public:
            ParserException(std::string e) {s=e;}
            const char* what() const throw(){
                return s.c_str();
            }
        };
        struct ParseTreeNode: public TreeNode
        {
            bool ter;
            NonTerminal nonTerminal;
            Token *terminal;

            ParseTreeNode(NonTerminal n){ter=false; nonTerminal=n;}
            ParseTreeNode(Token* t)     {ter=true;  terminal = t;}
            ~ParseTreeNode(){}

            void print_preorder(ParseTreeNode* root, int level){
                std::string indent;
                for (int i=0; i<level; ++i)
                    indent += "| ";
                if(*(indent.end()-1) == ' ')
                    indent.replace(indent.end()-1, indent.end(), 1, '_');
                std::cout<<indent;
                
                
                if(root->ter){
                    root->terminal->print(); std::cout<<std::endl;
                }
                else
                    std::cout<<root->nonTerminal<<std::endl;

                for (std::vector<TreeNode*>::iterator i = root->children.begin(); i != root->children.end(); ++i){
                    print_preorder((ParseTreeNode*)(*i), level+1);
                }
            }
            void preorder(){
                print_preorder(this, 0);
            }
            void postorder(){}
            void inorder(){}
        };
    }
#endif 