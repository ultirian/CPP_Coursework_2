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
    {
        stringstream line_stream(line);

        while (getline(line_stream, word, ','))
            delimited_line.push_back(word);

        // If index 1 [AccountNumber] == account number input.
        if (stoi(delimited_line[1]) == accountnumberin && stoi(delimited_line[3]) == pinin)
        {
            if (duplicateUsernameCheck(usernamein) == false)
            {
                // index 4 [Username] is now local input new_username
                delimited_line[4] = usernamein;
                account_number_found = true;
            }

            if(passwordCheck(passwordin) == true)
            {
                cout << "pass is here!:" << passwordin << endl;
                delimited_line[5] = passwordin;

            }

            if(duplicateUsernameCheck(usernamein) == true)
            {
                cout << "Username already taken!: " << endl;
            }

        }

        for (const auto& str : delimited_line)
            output_stream << str << ",";
        output_stream << "\n";

        delimited_line.clear();
    }
    if (!account_number_found)
        cout << "Account number not found" << endl;

    input_stream.close();
    output_stream.close();

}


