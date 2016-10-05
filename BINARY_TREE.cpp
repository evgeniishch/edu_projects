//
//  main.cpp
//  BINARY_SEARCH_TREE
//
//  Created by user on 07.02.16.
//  Бинарное дерево.
//

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

void show(Node *&Tree) //обход
{
    if (Tree!=NULL) //Пока не встретится пустое звено
    {
        show(Tree->left); //Рекурсивная функция для вывода левого поддерева
        cout<<Tree->data<<" "; //Отображаем корень дерева
        show(Tree->right); //Рекурсивная функция для вывода правого поддерева
    }
}

void add_node(int x,Node *&MyTree) //Функция добавления звена в дерево
{
    if (NULL==MyTree)  //То, о чем я в самом начале писал. Если дерева нет, то сеем семечко
    {
        MyTree=new Node; //Выделяем память под звено дерева
        MyTree->data=x; //Записываем данные в звено
        MyTree->left=MyTree->right=NULL; //Подзвенья инициализируем пустотой во избежание ошибок
    }
    
    if (x<MyTree->data)   //Если нововведенный элемент x меньше чем элемент x из семечка дерева, уходим влево
    {
        if (MyTree->left!=NULL) add_node(x,MyTree->left); //При помощи рекурсии заталкиваем элемент на свободный участок
        else //Если элемент получил свой участок, то
        {
            MyTree->left=new Node;  //Выделяем память левому подзвену. Именно подзвену, а не просто звену
            MyTree->left->left=MyTree->left->right=NULL; //У левого подзвена будут свои левое и правое подзвенья, инициализируем их пустотой
            MyTree->left->data=x; //Записываем в левое подзвено записываемый элемент
        }
    }
    
    if (x>MyTree->data)   //Если нововведенный элемент x больше чем элемент x из семечка дерева, уходим вправо
    {
        if (MyTree->right!=NULL) add_node(x,MyTree->right); //При помощи рекурсии заталкиваем элемент на свободный участок
        else //Если элемент получил свой участок, то
        {
            MyTree->right=new Node;  //Выделяем память правому подзвену. Именно подзвену, а не просто звену
            MyTree->right->left=MyTree->right->right=NULL; //У правого подзвена будут свои левое и правое подзвенья, инициализируем их пустотой
            MyTree->right->data=x; //Записываем в правое подзвено записываемый элемент
        }
    }
}



int main(int argc, const char * argv[]) {
    using namespace std;
    int x,n=20;
    int Arr[20];
    Node *Tree = NULL;
    for (int i=0;i<20;i++){
        Arr[i]= 1 + rand() % 20;
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
    
  //  sort(Arr, Arr+20);
    
    for (int i=0;i<20;i++){
        cout<<Arr[i]<<" ";
    }
    for (int i=0;i<20;i++){
        add_node(Arr[i],Tree);
    }
    cout<<endl;
    show(Tree); 
    
    
    
    
    return 0;
}
