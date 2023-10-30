#include <iostream>
#include <stack>

void sortStack(std::stack<int>& stack) 
{

    std::stack<int> sorted_stack;
    std::stack<int> buff;

    while (!stack.empty()) 
    {
    
        if (sorted_stack.empty() || sorted_stack.top() >= stack.top()) 
        {
            sorted_stack.push(stack.top());
        }
        else if (sorted_stack.top() < stack.top()) 
        {        
            while (!sorted_stack.empty() && sorted_stack.top() < stack.top()) 
            {
                buff.push(sorted_stack.top());
                sorted_stack.pop();
            }

            sorted_stack.push(stack.top());
            
            while(!buff.empty()) 
            {
                sorted_stack.push(buff.top());
                buff.pop();
            }
        }
        
        stack.pop();
    }

    stack = sorted_stack;
}

int main() {

    std::stack<int> input;

    input.push(1);
    input.push(-2);
    input.push(8);
    input.push(5);
    input.push(12);
    input.push(3);
    input.push(3);

    sortStack(input);

    while(!input.empty()) 
    {

        std::cout << input.top() << " ";
        input.pop();
    }
    std::cout << std::endl;

    return 0;

}