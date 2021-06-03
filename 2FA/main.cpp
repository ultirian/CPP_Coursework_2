    //
    // Created by Chris on 19/11/2020.
    //

    // Includes required libraries.
    #include <iostream>
    #include <string>
    #include <sstream>
    #include <istream>
    #include <ctime>
    #include <fstream>
    #include <vector>
    #include <cmath>

    // namespaces, may not be a good idea for complex programs.
    using namespace std;

    // Call functions
    void build_complete_login(int &accountnumberin, int &pinin, string &usernamein, string &passwordin);
    void trigger_user_login();
    void new_user();
    void writeOut(string n, int ac, int a, int p);
    bool duplicateUsernameCheck(const string& input);
    bool passwordCheck(string &input);
    int vowelCount(string nameIn);
    int enterAge();
    int enterAcct();
    int numberReverse(int ageIn);
    int genPin(int vowel_count, int reverse_age);
    string insertName();
    string insertUsername();
    string insertPassword();

    int switch_option = 0;

    // Main Program
    /* Uses case switch option to select if user would like to register new user or log in and update username
     * and password */
    int main() {

        cout << "Welcome to the USW Cyber App!" << endl;
        // Main Menu
        cout << "Please select an option:" << endl;
        cout << "1: Register Account" << endl;
        cout << "2: Log In & Update User / Password" << endl;
        cin >> switch_option;

        // Switches
        switch (switch_option)
        {
            //Create Account func
            case 1:{
                new_user();
            }

            case 2:
                trigger_user_login();

            default:
                cout << "Invalid selection!: " << endl;
                //loop invalid option
                main();
        }

    }

    /* Function that takes input from user for account and pin number IF this matches then it triggers New user
     * and new password function before writing the output to file. */

    void build_complete_login(int &accountnumberin, int &pinin, string &usernamein, string &passwordin)
    {

        // Stream class to read from files
        ifstream input_stream("../2FA_users.txt");
        // Stream class to write on files
        ofstream output_stream("../2FA_usersTmp.txt");

        // Vector container representing array that can change in size.
        vector<string> delimited_line;
        // Strings for manipulation.
        string line, word;
        // Set user found to false.
        bool account_number_found = false;

        // get line input_stream into line.
        while (getline(input_stream, line))
        {   // Stream line by line
            stringstream line_stream(line);
            // Unpacks for vector
            while (getline(line_stream, word, ','))
                delimited_line.push_back(word);

            // If index 1 [AccountNumber] == account number input.
            if (stoi(delimited_line[1]) == accountnumberin && stoi(delimited_line[3]) == pinin)
            {
                if (!duplicateUsernameCheck(usernamein))
                {
                    // index 4 [Username] is now local input new_username
                    delimited_line[4] = usernamein;
                    account_number_found = true;
                }

                if(passwordCheck(passwordin))
                {
                    cout << "pass is here!:" << passwordin << endl;
                    delimited_line[5] = passwordin;

                }

                if(duplicateUsernameCheck(usernamein))
                {
                    cout << "Username already taken!: " << endl;
                }

            }
            // Writes out to output_stream (../2FA_usersTmp.txt)
            for (const auto& str : delimited_line)
                output_stream << str << ",";
            output_stream << "\n";

            // Clears delimited line.
            delimited_line.clear();
        }
        if (!account_number_found)
            cout << "Account number not found" << endl;

        input_stream.close();
        output_stream.close();

        // removing the existing file
        remove("../2FA_users.txt");

        // renaming the updated file with the existing file name
        rename("../2FA_usersTmp.txt", "../2FA_users.txt");
    }

    /* Function that initially triggers log in process and make username, this creates variables that can be passed
     * by reference to build_complete_login() */
    void trigger_user_login()
    {
        int act_usr_input;
        int usr_pin_in;
        string usr_n_in;
        string usr_pw_in;
        cout << "Please input assigned account number: " << endl;
        cin >> act_usr_input;
        cout << "Please input assigned pin number: " << endl;
        cin >> usr_pin_in;
        cout << "|| Username Registration ||" << endl;
        usr_n_in = insertUsername();
        cout << "|| Pin Number Registration ||" << endl;
        usr_pw_in = insertPassword();
        build_complete_login(act_usr_input, usr_pin_in, usr_n_in, usr_pw_in);
    }

    /* CASE 1 selection to enter account number and pin, using functions genPin() and numberReverse to generate pin.
     * Then passes all information to initial writeout function writeOut */
    void new_user()
    {
        string full_name = insertName();
        int user_age = enterAge();
        int account_number = enterAcct();
        int generated_pin = genPin(vowelCount(full_name), numberReverse(user_age));
        cout << "Hello: " << full_name << endl;
        cout << "Your account number has been created: " << account_number << endl;
        cout << "Your unique pin number is: " << generated_pin << endl;
        writeOut(full_name, account_number, user_age, generated_pin);
        main();
    }

    /* Writeout function for case 1 to input account number and pin this also writes a null username and null
     * password for delimiter_line size to be set and also so that users cannot use these null outputs. */
    void writeOut(string n, int ac, int a, int p)
    {
        fstream uOut;
        uOut.open("../2FA_users.txt", ios::out | ios:: app);
        uOut << n << "," << ac << "," << a << "," << p << "," << "username_null" << "," << "password_null" << "\n";
        uOut.close();
    }

    /* Checks for duplicate username in file by iterating through file looking at every user, downside is that it also
     * iterates through names and usernames and numbers but the preference for these not to be used may be advantageous.*/
    bool duplicateUsernameCheck(const string& input)
    {
        ifstream input_stream("../2FA_users.txt");
        string line;

        // string username_input;
        // Init found
        bool found = false;

        while(getline(input_stream, line, ',') && !found)
        {
            // Keep checking until the end of string.
            if(line.find(input) != string::npos){
                // cout << "Testing for line: " << line << endl;
                found = true;
                // cout << "Duplicate Username Found!!" << endl;

            }
        }

        if (!found)
        {
            // cout << "Username Free" << endl;
            found = false;
        }
        // cout << "Condition is:" << found << endl;
        return found;
    }

    /* Bool function to return true and false by breaking down the score using if else statements and also some maths for
     * password length score. This could be improved by mapping scores and also using modulo */
    bool passwordCheck(string &input)
    {

        int password_length_count = input.length();

        int password_length_score = min(max((int)round((float)(password_length_count - 13) * 0.5), 0), 3);

        int password_upper_case_count = 0;
        int password_numbers_count = 0;
        int password_symbol_count = 0;

        for (char character : input){
            if (isupper(character))
                password_upper_case_count++;
            else if (isdigit(character))
                password_numbers_count++;
            else if (!isalpha(character) && !isspace(character))
                password_symbol_count++;

        }
        int password_upper_case_score = password_upper_case_count;
        if (password_upper_case_count > 4) password_upper_case_score = 3;

        int password_numbers_score = password_numbers_count;
        if (password_numbers_count > 3) password_numbers_score = 3;

        int password_symbol_score = password_symbol_count;
        if (password_symbol_count > 3) password_symbol_score = 3;

        int final_score = (password_length_score + password_upper_case_score + password_numbers_score + password_symbol_score);
        cout << "final_score: " << final_score << endl;

        if (final_score < 3)
        {
            cout << "Invalid Password"<< endl;
            return false;
        }
        if (final_score < 6)
        {
            cout << "Weak Password"<< endl;
            return false;
        }
        if (final_score < 9)
        {
            cout << "Medium Password"<< endl;
            return false;
        }
        if (final_score >= 12)
        {
            cout << "Strong Password!" << endl;
            return true;
        }
        return 0;
    }

    /* Vowel counter based on for loop takes nameIn from combined name functions and counts vowels for return */
    int vowelCount(string nameIn)
    {
        int vowelCount;
        vowelCount = 0;
        // For every word in name | if i is less then 150 (max varsize for nameIn) could also use nameIn.length();
        // but this is a more robust range based loop (modernize-loop-convert, 2017).
        for(int i = 0; i < 150; ++i)
        {   // Check if vowel is present and if true
            if(nameIn[i]=='a' || nameIn[i]=='e' || nameIn[i]=='i' ||
               nameIn[i]=='o' || nameIn[i]=='u' || nameIn[i]=='A' ||
               nameIn[i]=='E' || nameIn[i]=='I' || nameIn[i]=='O' ||
               nameIn[i]=='U')
            {   // Increase vowel count by 1
                ++vowelCount;
            }
        }
        // Return vowel count
        return vowelCount;
    }
    /* As functions can only usually return one output without using vectors and tuples these functions are split
     * it also aids in formatting the name for write-out by adding a space variable inbetween all returns.*/
    int enterAge()
    {
        int a;
        cout << "Please enter your age:";
        cin >> a;
        return a;
    }

    int enterAcct()
    {
        int an;
        cout << "Please enter account number:";
        cin >> an;
        return an;
    }

    /* Reverses number using power of 10 and dividing down */
    int numberReverse(int ageIn) {
        int rn = 0;

        // while numbers remain
        while (ageIn > 0)
        {   // reverse number * 10 add age in modulo 10
            rn = rn*10 + ageIn%10;
            // age in /10 for result.
            ageIn = ageIn/10;
        }
        return rn;
    }

    /* 3 numbers are generated from vowel count and the reverse age first digit uses a generated random number from
     * srand and rand then the first digit is moved to the beginning of the line with the remainder added on for return */
    int genPin(int vowel_count, int reverse_age)
    {
        //first digit pin var
        int firstDigitP = 0;
        // vowel count multiplied by reversed age
        int tpin = vowel_count * reverse_age;
        // If pin sum is less then 1000 generate random number.
        // The average vowel per word is 2 vowels per word so unlikely
        // for vCount to be > 10.
        if(tpin < 1000){

            // Can be predicted if user / attacker controls time.
            srand((unsigned) time(nullptr));
            firstDigitP = rand() % 9 +1;
        }
        //conversion of two ints into one string. First number first then rest of pin.
        ostringstream oss;
        // stream string first digit first then rest of pin.
        oss << firstDigitP << tpin;
        istringstream iss(oss.str());
        int pinOut;
        // String out as int
        iss >> pinOut;
        // Return concatenated string.
        return pinOut;
    }

    /* Insert name function adding spaces inbetween for writeOut() */
    string insertName()
    {

        char firstName[50];
        char middleName[50];
        char lastName[50];
        const string spc = " ";
        //Discards characters until new line is found, stops skipping of inputs.
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter first name:" << endl;
        cin.getline(firstName, 50);
        cout << "Please enter middle name:" << endl;
        cin.getline(middleName, 50);
        cout << "Please enter last name:" << endl;
        cin.getline(lastName, 50);
        // Adds String together for return.
        string full_name_local = firstName + spc + middleName + spc + lastName;
        return full_name_local;
    }

    /* Entry of username with check for return to be used with trigger function */
    string insertUsername()
    {
        string new_username;

        do {
            cout << "Please enter the desired username" << endl;
            cin >> new_username;
            if (duplicateUsernameCheck(new_username)){
                cout << "Username in use, please try again." << endl;
            }
        }
        while (duplicateUsernameCheck(new_username));

        if (!duplicateUsernameCheck(new_username)){
            return new_username;
        }

    }

    /* Password insertation function with comparison from double entry, is also checked by the function */
    string insertPassword()
    {
        //Initial password
        string password_input;
        string password_comparison_input;

        // Keeps looping until all conditions are met.
        do {
            cout << "Please insert desired password: " << endl;
            cin >> password_input;
            //Pasword confirmation
            cout << "Please Re-enter desired password: " << endl;
            cin >> password_comparison_input;
            if (password_comparison_input != password_input){
                cout << "Passwords do not match! please try again." << endl;
            }
            else if (!passwordCheck(password_input)) {
                cout << "Password to weak! please try again." << endl;
            }
        }
        while (password_comparison_input != password_input || (!passwordCheck(password_input)) );

        if (password_comparison_input == password_input){
            return password_input;
        }

        // weak password catch.
        else
            cout << "Password to weak please re-enter." << endl;

    }

