#ifndef _MY_STACK_H_
#define _MY_STACK_H_
namespace my_stack
{
	class stack
	{
	private:
		int* mass;
		int size;
		int cap;
		void extend(const int num = 2);
	public:
		stack(const int col = 2);
		~stack();
		int pop();
		void push(int data);
		int get_size();
		int get_result();
	};
}
#endif
