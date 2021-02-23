/* Gabriel Corzo */
    
#include <iostream>
#include <string>
#include <cstdlib>  // contains the rand() and srand() function 
#include <ctime>    // time() function
using namespace std;

int main()
{
    srand(time(0)); // initialize random seed generator to current time: 
					// needed to generate a different sequence of random numbers
					// each time you run your program

    // Add your code to play the dice game here
    cout << "Welcome to my dice game!\nIf you roll a 7 or 11, you win! If you roll a 2, 3 or 12, you lose! Otherwise, the sum is your point.";
    char val; // stores player's input
    cout << "\nPress s to start the game or x to exit. ";
    cin >> val;

    // Start game
    if (val == 's' || val == 'S'){

        // Generate two random numbers between 1 and 6
        int n1 = rand()%6+1, n2 = rand()%6+1, sum = n1 + n2;

        // Win condition
        if (sum == 7 || sum == 11){
            cout << n1 << '+' << n2 << '=' << sum << endl;
            cout << "\nYou won!" << endl;

        // Lose condition
        }else if (sum == 2 || sum == 3 || sum == 12){
            cout << n1 << '+' << n2 << '=' << sum << endl;
            cout << "\nYou lost!" << endl;
        
        // Point condition
        }else{
            int n3, n4, sum2 = 0;

            // Roll again condition
            while (sum2 != 7 || sum2 != sum){
                // Generate two new random numbers from 1 to 6
                n3 = rand()%6+1;
                n4 = rand()%6+1;
                sum2 = n3 + n4;
                cout << n3 << '+' << n4 << '=' << sum2 << endl;
            }
            
            // Lose condition
            if (sum2 == 7){
                cout << n3 << '+' << n4 << '=' << sum2 << endl;
                cout << "\nYou lost!" << endl;
            
            // Win condition
            }else{
                cout << n3 << '+' << n4 << '=' << sum2 << endl;
                cout << "\nYou won!" << endl;
            }
        }
    
    // Exit game
    }else if (val == 'x' || val == 'X'){
        cout << "The game has been exited." << endl;
    
    }else{
        cout << "\nPress s to start the game or x to exit. ";
    }
}