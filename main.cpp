#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

class Login
{
public:
    Login()
    {
        intro();
    }

    void intro()
    //Introduce the program
    {
        cout << "Welcome to Your Health, a program designed to meet your fitness"
             << " needs. Your Health gives you the opportunity to take advantage"
             << " of our expert personal trainers in order to design a custom"
             << " workout plan to meet your health needs. Let's get started.\n\n";
    }

    void obtainLogin()
    //Obtain username & password & convert password to a binary string as a hint to the user
    //Precondition: obtain the username & password
    //Postcondition: pass password to a function to convert it to a binary string & display it
    {
        cout << "Please create a username of type characters with no space: ";
        getline(cin, username);

        isInputStr(username); //validate input as type char w/ no spaces

        cout << "Please create a password of type integer only: ";
        cin >> pass;
        cout << endl;

        pass = validateInteger(pass); //validate input as type integer

        cout << endl;

        cout << "Note the following binary string as your password hint should you forget"
             << " your password. If you entered a negative integer, the binary is in two's"
             << " complement:\n";

        intToBinary(pass); //convert password to a binary string & display it
        cout << endl;
    }

/**********************************************************************************
                                 REQUIREMENT 1 & 2, Project 4
***********************************************************************************
1 - if int input is >= 0, then password is converted to binary string & displayed.
2 - if int input is < 0, then password is converted to two's complement & displayed.

***********************************************************************************
***********************************************************************************/
    void intToBinary(int intInput)
    //Convert an integer to its binary representation
    //Precondition: requires int input
    //Postcondition: returns binary representation of int input as a string
    {
        if(intInput >= 0) //decimal to binary
        {
            highestDec = log(intInput) / log (2); //log base 2 of integer input
            highestDec = pow(2, highestDec); //highest decimal that the integer input is divisible by
            binaryCount = highestDec; //binaryCount is the number series of the decimal system

            while(binaryCount >= 1) //work down to 1 bit
            {
                if(highestDec >= binaryCount) //if int input is divisible by the decimal number
                {
                    binaryStr += '1';
                    intInput -= highestDec; //integer input remaining to convert to binary
                    highestDec = log(intInput) / log (2); //log base 2 of integer input
                    highestDec = pow(2, highestDec); //highest decimal that the integer input is divisible by
                }
                else if (highestDec < binaryCount) //if int input is not divisible by the decimal number
                {
                    binaryStr += '0';
                }
                binaryCount /= 2; //next decimal number in the series
            }
            cout << binaryStr << endl; //output binary string
        }
        else if(intInput < 0) //decimal to two's complement
        {
            intInput = abs(intInput); //obtain positive representation of input
            highestDec = log(intInput) / log (2); //log base 2 of integer input
            highestDec = pow(2, highestDec); //highest decimal that the integer input is divisible by
            binaryCount = highestDec; //binaryCount is the number series of the decimal system

            while(binaryCount >= 1) //work down to 1 bit
                {
                    if(highestDec >= binaryCount) //if int input is divisible by the decimal number
                    {
                        binaryStr += '1';
                        intInput -= highestDec; //integer input remaining to convert to binary
                        highestDec = log(intInput) / log (2); //log base 2 of integer input
                        highestDec = pow(2, highestDec); //highest decimal that the integer input is divisible by
                    }
                    else if (highestDec < binaryCount) //if int input is not divisible by the decimal number
                    {
                        binaryStr += '0';
                    }
                    binaryCount /= 2; //next decimal number in the series
                }


                //Convert positive binary representation to two's complement
                binaryStr.insert(0, "0"); //add leading zero

                //Flip the bits of the binary string
                for(int i = 0; i < binaryStr.size(); i++)
                {
                    if(binaryStr[i] == '0')
                    {
                        binaryStr[i] = '1';
                    }
                    else
                    {
                        binaryStr[i] = '0';
                    }
                }


                //Add 1 to the binary string
                if(binaryStr.back() == '0')
                {
                    binaryStr.back() = '1';
                }
                else
                {
                    int lastChar = binaryStr.size() - 1; //position of last char in string
                    string binaryStrCopy = binaryStr; //to add +1 for each iteration

                    for(int i = (binaryStr.size() - 1); i >= 0; i--)
                    {
                        if(binaryStr[i] == '1' && (binaryStr[i + 1] == '1' || i == lastChar))
                        {
                            binaryStrCopy[i] = '0';
                        }
                        else
                        {
                            binaryStrCopy[i] = '1';
                        }
                    }
                    binaryStr = binaryStrCopy;
                }

/**********************************************************************************
                                 REQUIREMENT 3 & 4
***********************************************************************************
3 - Pre-defined macro __DATE__ used below.
4 - binary string & date output

***********************************************************************************
***********************************************************************************/
            cout << binaryStr << ", established on " << __DATE__ << endl; //output binary string
        }
    }

    /******** Validate Char Input *********/
    bool validateInput(string input)
    //Determine whether input are characters.
    //Precondition: requires string input from isInputStr function.
    //Postcondition: returns false if input is not of type char.
    {
        for(int i = 0; i < input.size(); i++)
        {
            if(input[i] <= '9')
            {
                return false;
            }
        }
        return true;
    }

    void isInputStr(string input)
    //If input is not of type Char, continuously ask user for the correct input.
    //Precondition: requires string argument to pass to function ValidateInput().
    //Postcondition: continues to obtain input until ValidateInput returns true.
    {
        while(validateInput(input) == false)
        {
            cin.clear();
            cout << "Please only use characters with no space: ";
            getline(cin, input);
        }
    }

    /******** Validate Integer Input *********/
    bool isInputInt(string input)
    //Determine whether input are characters.
    //Precondition: requires string input from ifNotInt function.
    //Postcondition: returns false if input is not of type char.
    {
        if(input[0] == '-')
        {
            input[0] = '1';
        }

        for(int i = 0; i < input.size(); i++)
        {
            if(input[i] <= '0' || input[i] > '9')
            {
                return false;
            }
        }

        return true;
    }

    int ifNotInt(string input)
    //If input is not of type Char, continuously ask user for the correct input.
    //Precondition: requires string argument to pass to function ValidateInput().
    //Postcondition: continues to obtain input until ValidateInput returns true.
    {
        while(isInputInt(input) == false)
        {
            cout << "That is not an integer. Please enter an integer: ";
            cin.clear();
            getline(cin, input);
        }

        if(isInputInt(input) == true) //if input is int, convert string to int
        {
            int outputInt;
            istringstream(input) >> outputInt;
            return outputInt;
        }
    }

    string intToString(int input)
    //converts integer to string
    //Precondition: requires integer argument.
    //Postcondition: returns integer in as string type
    {
        //convert integer to string
        string stringVersion;
        ostringstream convert;
        convert << input;
        stringVersion = convert.str();
        return stringVersion;
    }

    int validateInteger(int x)
    //Main function to be called to validate an integer
    //Precondition: to be called as int x = validateInteger(int x)
    //Postcondition: validates or obtains proper int & returns it
    {
        string xStr;
        int outputInt;

        xStr = intToString(x);
        return ifNotInt(xStr);
    }
    /*****************************************/

private:
    string username;
    int pass;

    //intToBinary()
    string binaryStr; //binary string representing integer input
    int highestDec; //highest decimal integer input is divisible by
    int binaryCount; //binaryCount is the number series of the decimal system
};


class FitnessPlans
{
public:
    FitnessPlans()
    //Choose a fitness goal from a menu list
    //Precondition: provide fitness options
    //Postcondition: obtain fitness selection
    {
        userStats(); //obtain user stats


        while(quit == false)
        {
            fitnessMenu(); //display the fitness menu & obtain user selection


            switch(fitnessSelection)
            {
                case 1:
                {
                    //Lose body fat
                    loseFatIntro();
                    weeklyWorkout();
                    break;
                }
                case 2:
                {
                    //Maintain current weight
                    maintainWeightIntro();
                    break;
                }
            }
        }




/**********************************************************************************
                                 REQUIREMENT 5 & 6
***********************************************************************************
5 - Input user's weight as a double in lbs.
6 - convert weight to kg & typecast as int & output.

***********************************************************************************
***********************************************************************************/
    void userStats()
    //Obtain stats from user to determine level of fitness
    //Precondition: obtain current weight & target weight in lbs
    //Postcondition: convert weight to kg & typecast as int & output to user
    {
        cout << "Okay, let's start by finding out a little about you.\n";

        cout << "What is your current weight in pounds. Include the decimal place: ";
        cin >> currentWeight;

        cout << "What is your target weight in pounds. Include the decimal place: ";
        cin >> targetWeight;
        cout << endl;

        //Convert weight in lbs to kg & typecast as int & output
        currentWeightKg = currentWeight / 2.20462;
        targetWeightKg = targetWeight / 2.20462;
        cout << "Your current weight in Kilograms is " << int(currentWeightKg) << endl;
        cout << "Your target weight in kilograms is " << int(targetWeightKg) << endl;
        cout << "We like to view our weight in kilograms. It's easier on the eyes :)\n\n";
    }


    void fitnessMenu()
    //Display the fitness menu and obtain which fitness goal the user desires
    {
        //Display fitness options
        cout << "Which fitness goal are you interested in?\n";
        cout << "1 - Lose body fat\n";
        cout << "2 - Maintain current weight\n";
        cout << "Please enter the corresponding number as an integer: ";
        cin >> fitnessSelection;
        cout << endl;


/**********************************************************************************
                                 REQUIREMENT 7, 8, 9
***********************************************************************************
7 - Conditional if-statement used to ensure current & target weight match weight loss.
8 - Logical operators used for two criterias of the if-statement
9 - While loop used to validate that current weight > target weight for fat loss.

***********************************************************************************
***********************************************************************************/
        //Determine whether fitnessSelection is consistent with user stats
        bool planInput = false;
        while(planInput != true)
        {
            if(fitnessSelection == 1 && currentWeight <= targetWeight)
            {
                cout << "Your target weight is less than your current weight.\n"
                     << "Please enter your current weight: ";
                cin >> currentWeight;
                cout << "Please enter your target weight: ";
                cin >> targetWeight;
                cout << endl;
            }
            else
                planInput = true;
        }
    }

/**********************************************************************************
                          REQUIREMENT 12 - Debugging Tricks
***********************************************************************************
During the integer to binary string conversation for the password hint, the most
useful trick was the print statement for the iteration of sequence of 'i' as well as
the char value at 'i'. This allowed me to parallel my binary conversion steps I had
layed out in excel. Other tricks used were the equality operators. Perhaps the most
useful of all tricks is the class below, ValidateInteger, where the user's input
is validated before further code is executed. I find this the best, because it could
prevent logic errors that could otherwise be missed.

***********************************************************************************
***********************************************************************************/


/**********************************************************************************
                                REQUIREMENT 13, 14
***********************************************************************************
13 - Please note that various custom functions have been defined in this class.
14 - The various custom functions in this class thus far demonstrates how a large
block of code is decomposed into logical sections that may even be reused, such as
the fitness menu function, or the fat loss selection function.
***********************************************************************************
***********************************************************************************/


/**********************************************************************************
                                REQUIREMENT 15, 16
***********************************************************************************
15 - An example of a variable with a scope only accessible from within a defined
block is the fitness menu function directly above these comments. It defines a bool type
variable planInput for the purpose of its internal loop. Then this variable is no longer
required.
16 - Passing mechanism. Please note the passing mechanism utilized in the validateInteger
function series. Because in C++ strings are pointers, the variable input is passed by
reference, which means that the function could alter the string directly in memory. If
a programmer wishes not to alter a variable in memory, then a variable by value should
be passed.
***********************************************************************************
***********************************************************************************/

    void loseFatIntro()
    //
    //Precondition: called by switch fitnessSelection
    //Postcondition: Determine whether user stats match fitness goal of fat loss.
    {
        cout << "So you want to lose body fat. Here are some quick facts. 1 lb of fat"
             << " equals 3,500 calories. A safe weight loss goal is to aim for 2 lbs"
             << " of fat loss per week, which means depriving your body of 7,000"
             << " calories of its normal needs (calories required to maintain your current"
             << " weight per week. This can be done in two ways, by exercise or your caloric"
             << " intake.";

        cout << endl << endl;

        cout << "Can you see how weight loss could get complicated real fast with calorie counting? Just"
             << " imagine calculating your body's caloric needs over several weeks and then tracking"
             << " how much you eat each day. We have a much simpler way to lose weight. Let your body"
             << " talk to you.";

        cout << endl << endl;

        cout << "Your body talks to you in 3 ways when it comes to calories:\n"
             << "1 - you feel hungry\n"
             << "2 - you feel satisfied\n"
             << "3 - your feel full";

        cout << endl << endl;

        cout << "To lose weight, number 1 and 3 should never apply to you. That is, you should never"
             << " feel hungry and you should never feel full. If you feel hungry, your body is already"
             << " slowing its metabolism due to going into starvation mode. If you are full, then you"
             << " overate and will gain weight or at the very least certainly maintain your current weight.";

        cout << endl << endl;

        cout << "So that leaves us with number 2, to feel satisfied. However, the sweet spot for losing weight"
             << " is in between number 1 and 2, you don't want to feel hungry, but you don't want to feel satisfied"
             << " either. Use this as a rule of thumb: You had a nice meal, you feel almost satisfied, all you need"
             << " is another couple of bites. If you stop before eating the last 2-3 bites, you will certainly lose "
             << " weight if this concept is applied for every meal. Try it if you don't believe us.";

        cout << "To enhance your weight loss, let's establish a workout routine as well, which means more calories"
             << " burned, therefore, more weight loss. Remember, the concept of weight loss is very simple. It's just"
             << " calories in and calories out.";

        cout << endl << endl;

        cout << "The workout routine will consist of either cardiovascular exercise or weight lifting. It does not matter"
             << " which cardio machine you use or what type of weight training you do. We are simply interested in burning"
             << " calories. We are going to start slow, with only 1 cardio  and 1 weight day per week";

        cout << endl << endl;
    }


/**********************************************************************************
                                REQUIREMENT 18, 20
***********************************************************************************
18 - Please note the use of various string variables in the "Private declaration"
of the class as well as the use of the string array weekdays[][] below.
20 - A multi-dimensional array is established for a 2d calendar to plan on which
week days the type of workout to be done.
***********************************************************************************
***********************************************************************************/
    void weeklyWorkout()
    {
        //Cardio = 0, Weights = 1, cheatDay = 2
        string weekdays[][7] = {{"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"},{} };

        //Which day to do cardio
        cout << "From the following list, which day would you like to do cardio?" << endl;
        cout << " 1 - Mon\n 2 - Tue\n 3 - Wed\n 4 - Thu\n 5 - Fri\n 6 - Sat\n 7 - Sun\n";
        cout << "Please select the number representing the week: ";
        cin >> cardio;
        weekdays[1][cardio-1] = "Cardio";
        cout << endl;

        //Which day to do weight lifting
        cout << "From the following list, which day would you like to do weights?" << endl;
        cout << " 1 - Mon\n 2 - Tue\n 3 - Wed\n 4 - Thu\n 5 - Fri\n 6 - Sat\n 7 - Sun\n";
        cout << "Please select the number representing the week: ";
        cin >> liftWeights;
        weekdays[1][liftWeights-1] = "Weights";
        cout << endl;

        //Which day to cheat
        cout << "And you may have a cheat day, a day you can eat and do whatever you want. On which"
             << " which day would you like your cheat day?" << endl;
        cout << " 1 - Mon\n 2 - Tue\n 3 - Wed\n 4 - Thu\n 5 - Fri\n 6 - Sat\n 7 - Sun\n";
        cout << "Please select the number representing the week: ";
        cin >> cheat;
        weekdays[1][cheat-1] = "Cheat";
        cout << endl;

        //Display workout plan
        cout << "Well don, here is your workout plan. Try it:\n\n";
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 7; j++)
            {
                cout << weekdays[i][j];

                cout << "\t";
            }
            cout << endl;
        }

        cout << endl;
        cout << "Would you like to go quit the program (y/n)?";
        cin >> userQuit;
        if(userQuit == 'y' || userQuit == 'Y')
        {
            quit = true;
        }

        cout << endl << endl;
    }


/**********************************************************************************
                                REQUIREMENT 23, 24
***********************************************************************************
23, 24 - Please note that this program utilized several classes, including the Login
and FitnessPlans class. And since a class is everything that a struct is and more,
that is, a class also includes private declarations in addition to public declerations,
it is my hope that the usage of class fulfills the struct criteria.
***********************************************************************************
***********************************************************************************/


    /******* MAINTAIN CURRENT WEIGHT CASE **********/
    void maintainWeightIntro()
    {
        cout << "Maintaining your current weight is actually quite simple, conceptually anyway."
             << " All you have to do is not over eat. What does that mean? It means eating to the point"
             << " where you are satisfied or you have 1 bite left before you are satisfied. You don't even"
             << " have to exercise.";

        cout << endl << endl;

        cout << "Think about it, you intake far more food then you spend time in the gym. If you control your"
             << " food intake, that will make a major factor in weight maintenance and even weight loss. For"
             << " example, you consume a can of coke in a matter of seconds, but it takes nearly an hour to burn"
             << " that 140 calories on the treadmill.";


        cout << endl << endl;

        cout << "It really is that simple. Now, if you are interested in a workout program, we recommend going back"
             << " to the main menu and choosing weight loss. It has valuable information and let's you create a workout"
             << " program.";

        cout << endl;

        cout << "Would you like to go to the main menu now? (y/n)";
        cin >> userQuit;
        if(userQuit == 'y' || userQuit == 'Y')
        {
            quit = false;
        }
        else
        {
            cout << "We hope you enjoyed this little informative program. Have a nice day. ";
        }

        cout << endl << endl;
    }


private:
    bool quit = false; //keep main menu running
    char userQuit;
    int fitnessSelection; //fitness goal chosen by user
    double currentWeight; //current weight in lbs
    double targetWeight; //current weight in lbs
    double currentWeightKg; //current weight in kg
    double targetWeightKg; //current weigh in kg
    int liftWeights; // days to lift weights
    int cardio; //day to do cardio
    int cheat; //day to do whatever
};


int main()
{

    Login userPassword;
    userPassword.obtainLogin();
    FitnessPlans userPlan;

    return 0;
}
