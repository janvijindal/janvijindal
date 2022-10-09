#include<iostream>
using namespace std;

class trienode{

public:
  char data;
  trienode* child[26];
  bool isterminal;

  trienode(char ch){
    data=ch;
    for(int i=0;i<26;i++){
        child[i]=NULL;
        
    }
    isterminal=false;

  }



};

class trie{

public:
     trienode* root;

     trie(){
        root=new trienode('\0');
     }


     void insertutil(trienode* root,string word){
        //base case
        if(word.length()==0){
            root->isterminal=true;
            return;
        }
        
        int index=word[0]-'A';
       
        trienode* children;
       

        if(root->child[index] != NULL){
            //bsss child ko agge leke gye
            children=root->child[index];
        }

        else{
            //present nahi hai
            //toh ik new node bnayo child ke liye
            children=new trienode(word[0]);
            root->child[index]=children;
        }

        //recursion
        insertutil(children,word.substr(1));

     }

   void insertword(string word){
    insertutil(root,word);
   }

 bool searchutil(trienode* root,string word){
   if(word.length()==0){
     return root->isterminal;
   }
   int index=word[0]-'A';
   trienode* children;

   if(root->child[index] != NULL){
            //bsss child ko agge leke gye
            children=root->child[index];
        }

   else{
     return false;
   }

  //recursive call
   return searchutil(children,word.substr(1));
   

  
   
 }

 bool searchword(string word){
     return searchutil(root,word);
   }

};
int main(){

 trie *t= new trie();
 t->insertword("janvi");
  cout<<"milgyaa:"<<t->searchword("janvi")<<endl;


}
