
#include <iostream>
 
using namespace std;
 
template <class T>
class Node
{
public:
    T data;
    Node *parent, *left, *right;
};

template <class T>
class mySet
{
private:
	Node<T>* Head;
	int size;
	Node<T>* FindNode(T n)
    {
        Node<T>* x = Head;
 
        while((x != NULL)&&(x->data != n))
            if(n < (x->data))
                x = x->left;
            else
                x = x->right;
        return x;
    }
	void inorder_walk(Node<T>* n)
	{
        if(n != 0)
        {
                inorder_walk(n->left);
                cout<<n->data<<endl;
                inorder_walk(n->right);
        }
	}
	T getBegin(Node<T>* x)
    {
        while((x->left) != NULL)
            x = x->left;
        return x->data;
    }
    T getEnd(Node<T>* x)
    {
        while((x->right) != NULL)
            x = x->right;
        return x->data;
    }
	void insert(T n)
    {
        Node<T>* z = new Node<T>;
        Node<T>* y = NULL;
        Node<T>* x = Head;
 
        z->data = n;
 
        while(x != NULL)
        {
            y = x;
            if((z->data) < (x->data))
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if(y == NULL)
            Head = z;
        else
        {
            if((z->data)<(y->data))
                y->left = z;
            else
                y->right = z;
        }
        z->left = NULL;
        z->right = NULL;
    }
	void erasePrivate(T n)
    {
        Node<T>* pointer = Head;
        Node<T>* parent  = NULL;
 
        while((pointer != NULL) && (pointer->data != n))
        {
            parent = pointer;
            if(n < (pointer->data))
                pointer = pointer->left;
            else
                pointer = pointer->right;
        }
 
        if(pointer != NULL)
        {
            Node<T>* removed = NULL;
 
            if ((pointer->left == NULL) || (pointer->right == NULL))
            {   
                Node<T>* child = NULL;
                removed = pointer;
 
                if((pointer->left) != NULL)
                    child = pointer->left;
                else 
                    if((pointer->right) != NULL)
                        child = pointer->right;
 
                if(parent == NULL)
                    Head = child;
                else
                {
                    if((parent->left) == pointer)
                        parent->left = child;
                    else
                        parent->right = child;
                }
            }
            else // (pointer->left != NULL && pointer->right != NULL)
            {
                Node<T>* mostLeft = pointer->right;
                Node<T>* mostLeftParent = pointer;
            
                while ((mostLeft->left) != NULL)
                {
                    mostLeftParent = mostLeft;
                    mostLeft = mostLeft->left;
                }
 
                pointer->data = mostLeft->data;
                removed = mostLeft;
 
                if((mostLeftParent->left) == mostLeft)
                    mostLeftParent->left = NULL;
                else
                    mostLeftParent->right = mostLeft->right;
            }
            delete removed;
        }
    }
public:
	int getSize()
	{
		return size;
	}
    mySet() : Head(NULL),size(0)
    {
    }
	void add(T n)
	{
		if(FindNode(n) == NULL)
		{
			insert(n);
			size++;
		}
		else
			throw runtime_error("Cant add element because we have it");
}
	void erase(T n)
	{
		if(FindNode(n) != NULL)
		{
			erasePrivate(n);
			size--;
		}
		else
			throw runtime_error("Cant delete element beacuse it doesnt exist");
	}
    mySet(T n): size(1)
    {
        Insert(n);
    }
    void Find(T n)
    {
    	if(FindNode(n) == NULL)
    		cout<< "NO elem" << endl;
    	else
    		cout << "there is such elem" << endl;
    }
	T Min()
	{
		return getBegin(Head);
	}
	T Max()
	{
		return getEnd(Head);
	}
void Print()
{
	inorder_walk(Head);
}
};
 
