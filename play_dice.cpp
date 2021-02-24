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
    cout << "Welcome to my dice game! If you roll a 7 or 11, you win! If you roll a 2, 3 or 12, you lose!\nOtherwise, the sum is your point and you roll again until you roll the point value or a 7. If you roll the point value, you win!\nIf you roll a 7, you lose!";
    char val; // stores player's inputs
    cout << "\nPress s to start the game or x to exit. ";
    cin >> val;

    while (val == 's' || val == 'S'){ // Start game

        int n1 = rand()%6+1, n2 = rand()%6+1, sum = n1 + n2; // Generate two random numbers between 1 & 6, initialize sum
        cout << n1 << '+' << n2 << '=' << sum << endl; // Display sum

        if (sum == 7 || sum == 11){ // Win condition
            cout << "You won!" << endl;

        }else if (sum == 2 || sum == 3 || sum == 12){ // Lose condition
            cout << "You lost!" << endl;
        
        }else{ // Point condition
            int point = sum;
            cout << "Your point is " << point << endl;
            bool not_win = true, not_loss = true;

            while (not_win == true && not_loss == true){ // Next roll or roll again

                n1 = rand()%6+1; // Generate two new random numbers 
                n2 = rand()%6+1; // between 1 & 6
                sum = n1 + n2; // Initialize new sum
                cout << n1 << '+' << n2 << '=' << sum << endl; // Display new sum
                
                if (sum == 7){ // Loss condition
                    not_loss = false;

                
                }else if (sum == point){ // Win condition
                    not_win = false;
                }
            }

            if (not_loss == false){ // Loss condition
                cout << "You lost!" << endl;
            
            }else{ // Win condition
                cout << "You won!" << endl;
            }
        }

        cout << "Do you want to play again? Press s to start a new game or x to exit. "; // Ask to play again
        cin >> val;
    }
    
    if (val == 'x' || val == 'X'){ // Exit game
        cout << "The game has been exited." << endl;
    
    }else{
        cout << "\nPress s to start the game or x to exit. ";
    }
}