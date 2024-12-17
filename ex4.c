/******************
Name:
ID:
Assignment:
*******************/

#include <stdio.h>
#define MIN_NUMBER 0
int task1_robot_paths(int x, int y);
float task2_human_pyramid(float arr[5][5], int row , int col);
int task3_parenthesis_validator(char expected);
void task4_queens_battle();
void task5_crossword_generator();

int main()
{
    int task = -1;
    do
    {
        printf("Choose an option:\n"
               "1. Robot Paths\n"
               "2. The Human Pyramid\n"
               "3. Parenthesis Validation\n"
               "4. Queens Battle\n"
               "5. Crossword Generator\n"
               "6. Exit\n");

        if (scanf("%d", &task))
        {
            scanf("%*c");
            switch (task)
            {
            case 6:
                printf("Goodbye!\n");
                break;
            case 1: {
                int column , row ;
                printf("Please enter the coordinates of the robot (column, row):\n");
                scanf("%d %d", &column, &row);
                if (column < MIN_NUMBER || MIN_NUMBER > row)
                    printf(" %d" , MIN_NUMBER);
                else {
                    printf("The total number of paths the robot can take to reach home is: %d\n" ,task1_robot_paths(column, row) );
                }
                break;
            }
            case 2: {
                printf("Please enter the weights of the cheerleaders:\n");
                int column = 5 ,row = 5,negative_weight = 0;
                float list[row][column];
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j <= i; j++) {
                        scanf("%f", &list[i][j]);
                        if (list[i][j] < MIN_NUMBER) {
                            printf("Negative weights are not supported.\n");
                            negative_weight = 1;
                        }
                    }
                    if(negative_weight)
                        break;
                }
                if(!negative_weight) {
                    for (int i = 0; i < row; i++) {
                        for (int j = 0; j <= i; j++) {
                            printf("%.2f ", task2_human_pyramid(list,i, j));
                        }
                        printf("\n");
                    }
                }
                break;
            }
            case 3:
                printf("Please enter a term for validation:\n");
                if (task3_parenthesis_validator('\0')) {
                    printf("The parentheses are balanced correctly.\n");
                } else {
                    printf("The parentheses are not balanced correctly.\n");
                }
                break;
            case 4:
                task4_queens_battle();
                break;
            case 5:
                task5_crossword_generator();
                break;
            default:
                printf("Please choose a task number from the list.\n");
                break;
            }
        }
        else
        {
            scanf("%*s");
        }

    } while (task != 6);
}

int task1_robot_paths(int x, int y)
{
    int n = 0, m = 0 ;
    if (x == MIN_NUMBER && y == MIN_NUMBER)
        return 1;
    if (x > MIN_NUMBER)
       n =task1_robot_paths(x - 1, y);
    if (y > MIN_NUMBER)
       m =task1_robot_paths(x, y - 1);
    return n + m ;
}

float task2_human_pyramid(float arr[5][5], int row , int col)
{
    if( col == MIN_NUMBER && row == MIN_NUMBER)
        return arr[row][col];
    if (row >= col && col > MIN_NUMBER)
        return arr[row][col] + task2_human_pyramid(arr, row -1, col - 1)/2 + task2_human_pyramid(arr, row -1, col)/2;
    if(col == MIN_NUMBER && row > col)
        return arr[row][col] + task2_human_pyramid(arr, row -1, col)/2 ;
    if (col > row)
       return 0;
}

int task3_parenthesis_validator(char expected)
{
    char c;

    // Read the next character (this will avoid issues caused by leftover newline characters)
    if (scanf("%c", &c) != 1)
        return 0;  // If input fails, return 0 (false)

    // Base case: If newline is encountered, return 1 if expected is '\0'
    if (c == '\n') {
        return expected == '\0';  // Ensure all parentheses are matched
    }

    // Check for opening parentheses and recursively validate
    if (c == '(') {
        if (!task3_parenthesis_validator(')')) return 0;
    } else if (c == '[') {
        if (!task3_parenthesis_validator(']')) return 0;
    } else if (c == '{') {
        if (!task3_parenthesis_validator('}')) return 0;
    } else if (c == '<') {
        if (!task3_parenthesis_validator('>')) return 0;
    } else if (c == ')' || c == ']' || c == '}' || c == '>') {
        // If an unexpected closing parenthesis is found
        return c == expected;
    }

    // Continue reading the next character
    return task3_parenthesis_validator(expected);
}

void task4_queens_battle()
{

}

void task5_crossword_generator()
{
    // Todo
}