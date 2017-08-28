#include <iostream>
#include <string>
#include <sstream>
template <class T>
class Node
{
public:
    T data;
    Node *left, *right;
};
template <class T>
class newSet
{
private:
	Node<T>* Head;
	int size;
	void Add(const T& key, Node<T>** buf)
	{
		if ((*buf) == NULL) 
		{
			(*buf) = new Node<T>; 
			(*buf)->data = key;
			(*buf)->left = (*buf)->right = NULL; 
			if(Head == NULL)
				Head = (*buf);
			return; 
		}
		if (key > (*buf)->data) 
			Add(key, &(*buf)->right); 
		else
			Add(key, &(*buf)->left); 
	}
	void walkForPrint(Node<T>* n)
	{
        if(n != NULL)
        {
                walkForPrint(n->left);
                std::cout << n->data << std::endl;
                walkForPrint(n->right);
        }
	}
	Node<T>* erase(const T& key, Node<T>* buf)
	{
		if(!buf) 
			return buf;
		if(key == buf->data)
		{
			Node<T>* p1;
			Node<T>* p2;
			if(buf->left == buf->right)
			{
				delete buf;
				return NULL;
			}
			else
				if(buf->left == NULL)
				{ 
					p1 = buf->right;
					delete buf;
					return p1;
				}
				else
					if(buf->right == NULL)
					{
						p1 = buf->left;
						delete buf;
						return p1;
					}
					else
					{
						p1 = buf->right;
						p2 = buf->right;
						if(Head->data == key)
						{
							while(p1->left)
								p1 = p1->left;
							p1->left = Head->left;
							delete Head;
							Head = p2;
							return p2;
						}
						while(p1->left)
							p1 = p1->left;
						p1->left = buf->left;
						delete buf;
						return p2;
					}
		}
		if(key > buf->data) 
			buf->right = erase(key, buf->right);
		else 
			buf->left = erase(key, buf->left);
		return buf;
	}
		void Destroy(Node<T>* n)
	{
		if (n != NULL)
    	{
        	Node<T>* r = n->right;
        	Node<T>* l = n->left;
        	Destroy(r);
        	Destroy(l);
        	delete n;
        }
    }
public:
	int get_size()
	{
		return size;
	}
	newSet(): size(0), Head(NULL)
	{};
	newSet(const T& n): size(1), Head(NULL)
	{
		this->Insert(n);
	};
	bool FindNode(const T& key)
    {
        Node<T>* buf = Head;
        while((buf != NULL) && (buf->data != key))
		{
            if(key < (buf->data))
                buf = buf->left;
            else
                buf = buf->right;
		}
		if(buf != NULL)
			return true;
		else
			return false;
    }
	void Insert(const T& key)
	{
		if(FindNode(key))
		{
			//std::string forReturn = "Cant add element:" + std::to_string(key) + " because we have it";
			throw std::runtime_error("forReturn");
		}
		else
		{
			Add(key, &Head);
			size++;
		}
	}
	void Print()
	{
		walkForPrint(Head);
	}
	T& Max()
    {
		Node<T>* buf = Head;
        while((buf->right) != NULL)
            buf = buf->right;
        return buf->data;
    }
	T& Min()
    {
		Node<T>* buf = Head;
        while((buf->left) != NULL)
            buf = buf->left;
        return buf->data;
    }
	void Erase(const T& key)
	{
		if(!FindNode(key))
		{
			//std::string forReturn = "Cant delete element:" + std::to_string(key) + " because we have it";
			throw std::runtime_error("forReturn");
		}
		else
		{
			erase(key,Head);
			size--;
		}
	}
    ~newSet()
    {
    	if(Head != NULL)
    		Destroy(Head);
    }
};
