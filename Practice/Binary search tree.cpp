#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    int counter;
    Node* right;
    Node* left;

    Node(int v){
        value=v;
        counter=1;
        right=NULL;
        left=NULL;
    }

};
Node* root;





void inOrder(Node* parent){
    if(parent==NULL)
        return;
    inOrder(parent->left);
    for(int i=0; i<parent->counter; i++)
        printf("%d ", parent->value);
    inOrder(parent->right);
}






void insertV(Node* curr, int v){
    if(curr==NULL){
        curr = new Node(v);
        return;
    }

    while(true){
        if(curr->value<v){
            if(curr->right==NULL){
                curr->right=new Node(v);
               return;
            }
            curr=curr->right;
        }
        else if(curr->value>v){
            if(curr->left==NULL){
                curr->left=new Node(v);
                return;
            }
            curr=curr->left;
        }
        else if(curr->value==v){
            curr->counter++;
            return;
        }
    }
}




void searchV(Node* curr, int v){
    if(curr==NULL){
        return;
    }

    while(true){
        if(curr->value<v){
            if(curr->right==NULL){
                printf("Value %d not found\n",curr->value);
                return;
            }
            curr=curr->right;
        }
        else if(curr->value>v){
            if(curr->left==NULL){
                printf("Value %d not found\n",curr->value);
                return;
            }
            curr=curr->left;
        }
        else if(curr->value==v){
            printf("Value %d found %d times\n",curr->value,curr->counter);
            return;
        }
    }
}







int isBST(Node* root){
    if (root == NULL)
        return 1;
    if (root->left != NULL && root->left->value > root->value)
        return 0;
    if (root->right != NULL && root->right->value < root->value)
        return 0;
    if (!isBST(root->left) || !isBST(root->right))
        return 0;
    return 1;
}






int maxValue(Node* root){
    if(root==NULL){
        return 0;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    return root->value;
}





void subtree(Node* curr, int v){
    if(curr==NULL)
        return;

    while(curr->value!=v){
        if(curr->value<v){
            if(curr->right==NULL){
                printf("Value %d not found\n",curr->value);
                return;
            }
            curr=curr->right;
        }
        else if(curr->value>v){
            if(curr->left==NULL){
                printf("Value %d not found\n",curr->value);
                return;
            }
            curr=curr->left;
        }
    }
    inOrder(curr->left);
    for(int i=0; i<curr->counter; i++)
        printf("%d ", curr->value);
    inOrder(curr->right);
}





void deleteV(Node* curr, int v){
    if(curr==NULL)
        return;

    Node* par;
    while(curr->value!=v){
        if(curr->value<v){
            if(curr->right==NULL){
                printf("Value %d not found\n",curr->value);
                return;
            }
            par=curr;
            curr=curr->right;
        }
        else if(curr->value>v){
            if(curr->left==NULL){
                printf("Value %d not found\n",curr->value);
                return;
            }
            par=curr;
            curr=curr->left;
        }
    }

    if(curr->right==NULL && curr->left==NULL){
        free(curr);
        return;
    }

    if(curr->right!=NULL || curr->left!=NULL){
        Node* temp;
        if(temp->right==NULL){
            par->right=temp;
            temp->right==curr->right;
            free(curr);
        }

    Node* prev;
    while(temp->right!=NULL){
        prev=temp;
        temp=temp->right;
    }
    curr->value=temp->value;
    free(temp);
    prev->right=NULL;

    }
}







int upperBoundBST(Node* root, int v){
    if(root==NULL){
        return 0;
    }

    while(true){
        if(v>root->value){
            if(root->right==NULL){
                printf("Value %d not found\n",root->value);
                return 0;
            }
            root=root->right;
        }
        else if(v<root->value){
            if(root->left==NULL){
                printf("Value %d not found\n",root->value);
                return 0;
            }
            root=root->left;
        }
        else if(root->value==v){
            if(root->right!=NULL){
                root=root->right;
                while(root->left!=NULL){
                    root=root->left;
                }
                return root->value;
            }
            return 0;
        }
    }
}





int values[100105];
int valueSize=0;

void inorderTraversal(Node* root){
    if(root==NULL) return;
    inorderTraversal(root->left);
    values[valueSize]=root->value;
    valueSize++;
    inorderTraversal(root->right);
}







// Driver code
int main()
{
    Node* root=new Node(10);

    insertV(root,9);
    insertV(root,2);
    insertV(root,12);
    insertV(root,13);
    insertV(root,7);
    insertV(root,7);
    insertV(root,6);
    insertV(root,4);
    insertV(root,4);
    insertV(root,3);
    insertV(root,8);
    insertV(root,5);
    insertV(root,11);
    insertV(root,16);
    insertV(root,4);
    insertV(root,0);
    insertV(root,23);
    insertV(root,1);
    insertV(root,-3);



    printf("\nPrinting inorder: ");
    inOrder(root);
    printf("\n\n");

    inorderTraversal(root);
    printf("\nValues array: ");
    for(int i=0; i<valueSize; i++)
                printf("%d ",values[i]);

    if(isBST(root))
        printf("\nValid");
    else printf("\ninValid");

    printf("\nUpper Bound Value: %d",upperBoundBST(root,2));
    printf("\nMaximum Value: %d",maxValue(root));
    printf("\nPrinting Subtree: ");
    subtree(root,12);
    printf("\n\n");

    searchV(root,13);
    searchV(root,4);
    searchV(root,3);
    searchV(root,7);

    deleteV(root, 1);
    printf("\nPrinting inorder: ");
    inOrder(root);
    printf("\n\n");


    subtree(root,2);
    printf("\n\n");

}
