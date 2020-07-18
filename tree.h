#ifndef AMICAYSE_TREE_H_INCLUDED
    #define AMICAYSE_TREE_H_INCLUDED
    #include <string>
    #include <vector>
    #include <map>

    namespace amicayse
    {
        struct TreeNode
        {
            std::vector<TreeNode*> children;
            
            void add_child(TreeNode* child){
                this->children.push_back(child);
            }
            void delete_all_subtrees(){
                for (std::vector<TreeNode*>::iterator i=children.begin(); i!=children.end(); ++i){
                    (*i)->delete_all_subtrees();
                    delete *i;
                }
            }
            ~TreeNode(){
                //std::cout<<this<<" deleted\n";
            }
            virtual void inorder() = 0;
            virtual void preorder() = 0;
            virtual void postorder() = 0;
        };

    }
#endif
