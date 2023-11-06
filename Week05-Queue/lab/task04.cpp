#include <iostream>
#include <queue>

int lastManStanding(int n, int k) 
{
    if(n <= 0 || k <= 0) 
    {
        return -1;
    }
    
    int winner;

    std::queue<int> q;
    for(int i = 1; i <= n; ++i) 
    {
        q.push(i);
    }

    while(!q.empty()) 
    {

        for(int i = 1; i < k; ++i) 
        {
        
            q.push(q.front());
            q.pop();
        }

        winner = q.front();

        q.pop();
    }

    return winner;
}

int main() {

    int n, k;

    std::cout << "Number of players: ";
    std::cin >> n;
    std::cout << "Number of jumps: ";
    std::cin >> k;
    std::cout << "Then the winner is " << lastManStanding(n, k) << std::endl;

    return 0;

}