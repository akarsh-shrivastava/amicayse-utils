#ifndef AMICAYSE_TREE_H_INCLUDED
    #define AMICAYSE_TREE_H_INCLUDED
    #include <string>
    #include <vector>
    #include <map>

    namespace amicayse
    {
        class TreeNode
        {
            public:
            std::vector<TreeNode*> children;
            
            void add_child(TreeNode* child){
                this->children.push_back(child);
            }

            ~TreeNode(){
                for (std::vector<TreeNode*>::iterator i = children.begin(); i != children.end(); i++)
                    delete *i;
            }

            virtual void inorder() = 0;
            virtual void preorder() = 0;
            virtual void postorder() = 0;
        };

    }
#endif
